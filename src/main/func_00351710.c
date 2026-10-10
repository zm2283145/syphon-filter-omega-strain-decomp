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

extern void func_00329930(Elem5C* dst, Elem5C* src);
extern void func_003517B0(void* dst, void* src);

/* Copies [first, last) to dest element by element; returns the end of dest. */
Elem5C* func_00351710(Elem5C* first, Elem5C* last, Elem5C* dest) {
    for (; first < last; first++, dest++) {
        func_00329930(dest, first);
        dest->flag = first->flag;
        dest->data = first->data;
        func_003517B0(dest->tail, first->tail);
    }
    return dest;
}
