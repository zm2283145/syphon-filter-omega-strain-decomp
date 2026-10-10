#include "types.h"
typedef struct {
    char pad0[0x2340];
    void* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    int x2c08;
    char pad2c0c[0x2D96 - 0x2C0C];
    short x2d96;
} F38CBF0;
extern void func_0036CA70(void*);
void func_0038CBF0(F38CBF0* p)
{
    int i;
    p->x2c08 = 0;
    p->x2d96 = 0;
    for (i = 0; i < p->count; i++) {
        if (p->items[i]) {
            func_0036CA70(p->items[i]);
            p->items[i] = 0;
        }
    }
}