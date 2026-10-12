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
    unsigned char b3469;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Obj {
    char pad0[0x300];
    Hnd h;
};
extern "C" bool func_00255E50(Obj* o)
{
    bool r = 0;
    if (o->h.Get()) {
        Tgt* t = o->h.Get();
        bool v = t->b2D && t->b2C && !t->b2E && t->b3469;
        if (v)
            r = 1;
    }
    return r;
}




