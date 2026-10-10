#include "types.h"
typedef struct { char pad[0x5C]; float t; } E279CA0;
typedef struct {
    E279CA0** items; int pad4; int cap; int padC; int count; int pad14;
    unsigned int head; int pad1C; int base;
} R279CA0;
extern void func_0027A570(E279CA0* e, int flags, int a, int b, float x, float y);
void func_00279CA0(R279CA0* r, int a1, int a2, unsigned char a3, int t0, float f)
{
    unsigned int idx;
    unsigned int slot;
    E279CA0* e;
    int fl;
    idx = r->head++;
    slot = (idx + r->base) % r->cap;
    if (r->head == r->cap) {
        r->head = 0;
    }
    if (r->count < r->cap) {
        r->count++;
    } else {
        e = r->items[slot];
        if (e->t != -2.0f) {
            e->t = 0.0f;
        }
    }
    fl = a3 | 1;
    e = r->items[idx];
    if (e) {
        func_0027A570(e, fl, a1, t0, f, (float)a2);
    }
}