#include "types.h"
typedef struct { void* a; int b; } E4Slot;
typedef struct {
    char pad0[0x1C];
    unsigned char b1C;
    char pad1D[0x58 - 0x1D];
    unsigned char b58;
    char pad59[3];
    int n5C;
    E4Slot slots[16];
} E4Obj;
extern unsigned char D_00535D62;
extern void func_003767E0(void* a, int b, int c);
void func_00371B00(E4Obj* o)
{
    int i;
    if (!o->b58 && o->n5C) {
        for (i = 0; i < 16; i++) {
            E4Slot* p = &o->slots[i]; if (p->a) func_003767E0(p->a, p->b, 1);
        }
        o->b58 = 1;
    }
    if (!o->b1C) {
        o->b1C = 1;
        D_00535D62 = 1;
    }
}