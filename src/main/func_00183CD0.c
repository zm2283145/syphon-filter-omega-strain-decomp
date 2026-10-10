#include "types.h"

typedef struct Rec70 {
    Q v[4];             /* 0x00 */
    char m40[0x10];     /* 0x40 */
    unsigned char b50;
    unsigned char b51;
    unsigned char b52;
    char pad53[0xD];
    char m60[0x10];     /* 0x60 */
} Rec70;

extern void Vec4_Copy(void*, void*);
extern void func_00139BB0(void*, void*);
extern void func_00139BA0(void*, void*);

/* Copy-constructs [first, last) into dest; returns the end of the destination. */
Rec70* func_00183CD0(Rec70* first, Rec70* last, Rec70* dest) {
    for (; first < last; first++, dest++) {
        Vec4_Copy(&dest->v[0], &first->v[0]);
        Vec4_Copy(&dest->v[1], &first->v[1]);
        Vec4_Copy(&dest->v[2], &first->v[2]);
        Vec4_Copy(&dest->v[3], &first->v[3]);
        dest->b50 = first->b50;
        func_00139BB0(dest->m40, first->m40);
        func_00139BA0(dest->m60, first->m60);
        dest->b51 = first->b51;
        dest->b52 = first->b52;
    }
    return dest;
}
