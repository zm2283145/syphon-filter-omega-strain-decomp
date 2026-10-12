#include "types.h"
#pragma cplusplus on
struct Tgt {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3468 - 0x2F];
    unsigned char b3468;
    unsigned char b3469;
    char pad346A[0x3528 - 0x346A];
    int inv;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Ctl { char pad[0x9C]; int mode; };
struct Obj {
    char pad0[0x60];
    unsigned char b60;
    char pad61[0x2FC - 0x61];
    Ctl* ctl;
    Hnd h;
};
extern "C" int ItemInv_Any(int);
static inline bool A(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3468; return v; }
static inline bool B(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3469; return v; }
extern "C" void func_00255F60(Obj* o)
{
    if (o->ctl) {
        int m = 0;
        if (o->b60 == 1) {
            m = 5;
        } else if (o->h.Get()) {
            if (A(o->h.Get()) || B(o->h.Get()) || ItemInv_Any(o->h.Get()->inv))
                m = 0x14;
        }
        o->ctl->mode = m;
    }
}


