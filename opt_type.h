#ifndef OPT_TYPE_H
#define OPT_TYPE_H

enum OptType{
    // Just only support '-'
    OPT_ONE_PREFIX = 0,
    // Just only support '--'
    OPT_TWO_PREFIX,
    // Support '-' and '--'
    OPT_MULTI_PREFIX,
    // Support '-xx', '-/--xx' or '--xx', '-/--xx'
    OPT_PREFIX_PREFIX,
    // SUpport multi parameter, -x, param1, param2, ...
    OPT_MULTI_PARAM,
    // inputs
    OPT_INPUT_SOURCE,
    // output
    OPT_OUTPUT_SOURCE,

    OPT_UNKNOWN_TYPE,
};


enum OptMatch {
    // Like -c, -E ...
    OPT_MATCH_SIMPLE = 0,
    // Like -x=mmm,
    OPT_MATCH_EQUAL,
    // Like -o output,
    OPT_MATCH_SPACE,
    // Like -lxxx,
    OPT_MATCH_JOIN,
};

enum OptStatus {
    // Recognize the option and it's necessary.
    OPT_ST_KEEP = 0,
    // The option has been recognized, but not necessary.
    OPT_ST_IGNORE,
    // Can not recognize, just keep it.
    OPT_ST_UNKNOWN,
    // The option is not supported, replace it.
    OPT_ST_REPLACE,
    // The option has been removed for this time.
    OPT_ST_DELETE,
};

enum OptCategory {
    OPT_CATEGORY_GCC,
    OPT_CATEGORY_CLANG,
    OPT_CATEGORY_LINK,
    OPT_CATEGORY_ARCHIVE,
    OPT_CATEGORY_RANLIB,
    OPT_CATEGORY_STRIP,
    OPT_CATEGORY_OBJ,
    OPT_CATEGORY_JAVAC,
};


#endif // OPT_TYPE_H
