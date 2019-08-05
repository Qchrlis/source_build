#include "static_malloc.h"

union chunk;

struct info {
  union chunk* prev;
  union chunk* next;
  size_t size;
};
struct node {
  struct info info;
  size_t used;
};

union chunk {
  unsigned char data[sizeof (struct node)];
  struct node node;
};

// Static storage memory, block count 0x1 << 20, block size is 32 bytes,
// Total memory is 32MB, init 64KB each time.
enum {CHUNK_MAX = 0x1 << 20,
      CHUNK_DELTA = 0x1 << 13,
     };
static size_t initialized = 0;
static const size_t total_count = CHUNK_MAX / CHUNK_DELTA;
static size_t current_count = 0;   // {0, ..., delta_count - 1}

static size_t chunk_max = CHUNK_DELTA;
static union chunk pool[CHUNK_MAX];
static union chunk head = {.node = {{NULL, NULL, 0}, 0}};
static union chunk tail = {.node = {{NULL, NULL, 0}, 0}};

static void init() {
  head.node.info.next = pool;
  union chunk* prev = &head;
  union chunk* curr = pool;
  for (size_t i = 0; i < CHUNK_DELTA; i++) {
    curr->node.info.prev = prev;
    curr->node.info.next = curr + 1;
    curr->node.info.size = 0;
    curr->node.used = 0;
    prev = curr++;
  }
  prev->node.info.next = &tail;
  tail.node.info.prev = prev;
  initialized = 1;
}

static void e_realloc() {
  current_count++;
  if (current_count == total_count)
    exit(9);

  union chunk* prev = tail.node.info.prev;
  union chunk* curr = &pool[CHUNK_DELTA * current_count];
  prev->node.info.next = curr;
  for (size_t i = 0; i < CHUNK_DELTA; i++) {
    curr->node.info.prev = prev;
    curr->node.info.next = curr + 1;
    curr->node.info.size = 0;
    curr->node.used = 0;
    prev = curr++;
  }
  prev->node.info.next = &tail;
  tail.node.info.prev = prev;
  chunk_max += CHUNK_DELTA;
}

static size_t chunk_count(size_t size) {
  size_t chunks = 0;
  size_t chunks_size = 0;
  while (chunks_size < size + sizeof (struct info)) {
    chunks_size += sizeof (union chunk);
    chunks++;
  }
  return chunks;
}

static void* unlink(union chunk* top, size_t count) {
  union chunk* prev = top->node.info.prev;
  union chunk* next = top[count - 1].node.info.next;
  prev->node.info.next = next;
  next->node.info.prev = prev;
  top->node.info.size = count;
  return top->data + sizeof (struct info);
}

static void relink(union chunk* top) {
  if (top < pool || pool + chunk_max - 1 < top) return;
  union chunk* prev = &head;
  while (prev->node.info.next != &tail && prev->node.info.next < top) {
    prev = prev->node.info.next;
  }
  if (prev == top) return; //dual free
  union chunk* next = prev->node.info.next;
  union chunk* curr = top;
  prev->node.info.next = curr;
  size_t count = top->node.info.size;
  for (size_t i = 0; i < count; i++) {
    curr->node.info.prev = prev;
    curr->node.info.next = curr + 1;
    curr->node.info.size = 0;
    curr->node.used = 0;
    prev = curr++;
  }
  prev->node.info.next = next;
  next->node.info.prev = prev;
}

void* e_malloc(size_t size) {
  if (!initialized) init();
  size_t chunks = chunk_count(size);
  size_t keep = 0;
  union chunk* top = head.node.info.next;
  for (union chunk* curr = top; curr != &tail; curr = curr->node.info.next) {
    keep++;
    if (keep == chunks) return unlink(top, chunks);
    if (curr->node.info.next == curr + 1) continue;
    keep = 0;
    top = curr->node.info.next;
  }
  // If all memory is used, exit 9.
  e_realloc();
  return e_malloc(size);
}

void e_free(void* ptr) {
  if (ptr == NULL) return;
  char* bptr =(char *) ptr;
  ptr = bptr - sizeof (struct info);
  relink((union chunk*)ptr);
}

void e_print_info() {
  printf("Static Memory Allocate:\n");
  printf("Total size: %d KB\n", CHUNK_MAX >> 5);
  printf("Delta size: %d KB\n", CHUNK_DELTA >> 5);
  printf("Malloc size: %ld KB\n", chunk_max >> 5);

  size_t free_count = 0;
  union chunk* prev = &head;
  while (prev->node.info.next != &tail) {
    prev = prev->node.info.next;
    free_count ++;
  }
  printf("Free block count: %ld(%ld)\n", free_count, chunk_max);
}

