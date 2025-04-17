#ifndef CUSTOM_WARNING_H
#define CUSTOM_WARNING_H

#include <cstdio>

#include "colorPrint.h"

#ifndef NDEBUG
    #define customWarning(expression, returnMessage) do {                            \
        if (!(expression)) {                                                         \
            customPrint(yellow, bold, bgDefault, "[WARNING]: %s ", #returnMessage);  \
            customPrint(white,  bold, bgDefault, "// %s:%d (%s)\n", __FILE__,          \
                                                    __LINE__, __FUNCTION__);         \
            return returnMessage;                                                    \
        }                                                                            \
    } while (0)

    #define customAssert(expression, returnMessage) do {                                  \
        if (!(expression)) {                                                              \
            customPrint(red, bold, bgDefault, "[ASSERTION ERROR]: %s ", #returnMessage);  \
            customPrint(white,  bold, bgDefault, "// %s:%d (%s) => ", __FILE__,           \
                                                        __LINE__, __FUNCTION__);          \
            customPrint(red, bold, bgDefault, "EXIT...\n");                               \
            exit(returnMessage);                                                          \
        }                                                                                 \
    } while (0)
#else
    #define customWarning
    #define customAssert
#endif

#endif // CUSTOM_WARNING_H_
