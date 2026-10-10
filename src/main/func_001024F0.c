#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma opt_common_subs off

extern char D_004E1B00[];

typedef struct Range10 {
    char pad00[0xC];
    char* start; /* 0x0C */
    char* cur;   /* 0x10 */
} Range10;

/* Points both cursor fields at the shared default buffer. */
int func_001024F0(Range10* obj) {
    obj->start = D_004E1B00;
    obj->cur = D_004E1B00;
    return 1;
}

#pragma pop
