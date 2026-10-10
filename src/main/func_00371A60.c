#include "types.h"
typedef struct { void* obj; int arg; } E2Slot;
typedef struct {
    char pad0[0x1C];
    unsigned char dirty;
    char pad1[0x58 - 0x1D];
    unsigned char active;
    char pad2[3];
    int count;
    E2Slot slots[16];
} E2Group;
extern void func_003767E0(void*, int, int);
extern unsigned char D_00535D62;
void func_00371A60(E2Group* g) {
    int i;
    if (g->active && g->count) {
        for (i = 0; i < 16; i++) {
            E2Slot* s = &g->slots[i];
            if (s->obj) func_003767E0(s->obj, s->arg, 0);
        }
        g->active = 0;
    }
    if (g->dirty) {
        g->dirty = 0;
        D_00535D62 = 1;
    }
}