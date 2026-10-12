#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct KeyEv_4153F0 {
    short type;
    short a;
    short b;
    short c;
    short key;
    int flags;
    char ch;
};
struct Kb_4153F0 { char pad[0x94]; int flags; };
struct W_4153F0;
struct W_4153F0 {
    VPAD16(p) VPAD8(q) VPAD1(r)
    virtual void Event(KeyEv_4153F0* ev);
    char pad[0x4E];
    unsigned char b52;
};
extern "C" unsigned char func_003D1580(int c, int flags);
extern "C" unsigned char func_003D1610(Kb_4153F0* k);
extern "C" int func_003D1660(Kb_4153F0* k, int n);

extern "C" void func_004153F0(W_4153F0* w, Kb_4153F0* kb)
{
    while (func_003D1660(kb, 1)) {
        int c = func_003D1610(kb);
        if (c) {
            int f = kb->flags;
            KeyEv_4153F0 ev;
            ev.type = 2;
            ev.a = 0;
            ev.b = 1;
            ev.c = 0;
            ev.key = c;
            ev.flags = f;
            if (w->b52) ev.ch = func_003D1580(c, f);
            else ev.ch = c;
            w->Event(&ev);
        }
    }
}



