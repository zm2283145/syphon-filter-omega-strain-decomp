#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

typedef struct PackedWord {
    unsigned int flag : 1;
    unsigned int value : 31;
} PackedWord;

extern PackedWord* func_002071B0(void* obj);

/* Returns the 31-bit value field of func_002071B0's result. */
unsigned int func_0020A020(void* obj) {
    return func_002071B0(obj)->value;
}

#pragma pop
