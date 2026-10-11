#include "types.h"
typedef struct { char pad[0x3C]; int mode; char pad2[0x16]; unsigned char busy; } Menu27A7;
typedef struct { char pad[0x14C]; unsigned int pressed; char pad2[8]; unsigned int held; } Pad27A7;
extern void func_0027AAA0(Menu27A7* s, int dir);
extern void func_0027A8B0(Menu27A7* s);
extern void func_0027AB60(Menu27A7* s);
void func_0027A740(Menu27A7* s, Pad27A7* p) {
    unsigned int bits;
    if (s->busy) return;
    bits = p->pressed & ~p->held;
    if (bits & 0x1000) func_0027AAA0(s, 0);
    if (bits & 0x4000) func_0027AAA0(s, 1);
    if (bits & 0x40) func_0027A8B0(s);
    if (s->mode == 1 && (bits & 0x10)) {
        s->mode = 0;
        func_0027AB60(s);
    }
}