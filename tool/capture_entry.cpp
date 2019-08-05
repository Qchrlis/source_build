
#include"capture_handle.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 9;
    }
    std::vector<std::string> args;
    std::string compiler = argv[1];

    for (int32_t i = 1; i < argc; i++) {
        args.push_back(std::string(argv[i]));
    }
}
