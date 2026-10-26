#include "types.h"

typedef struct Words15 {
    int w[15];
} Words15;

typedef struct Elem5C {
    char base[0xC];        /* 0x00 */
    unsigned char flag;    /* 0x0C */
    char pad0D[3];
    Words15 data;          /* 0x10 */
    char tail[0x10];       /* 0x4C */
} Elem5C;

extern void cString_opAssign(Elem5C* dst, Elem5C* src);
extern void cArray_StatsRequirement_opAssign(void* dst, void* src);

/* Copies [first, last) to dest element by element; returns the end of dest. */
Elem5C* std_msl_copy_MissionStats_copy(Elem5C* first, Elem5C* last, Elem5C* dest) {
    for (; first < last; first++, dest++) {
        cString_opAssign(dest, first);
        dest->flag = first->flag;
        dest->data = first->data;
        cArray_StatsRequirement_opAssign(dest->tail, first->tail);
    }
    return dest;
}
