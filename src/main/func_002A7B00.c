#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
class M2A7B00 { public: VPAD16(a) VPAD8(b) virtual void Remove(void* o); };
struct O2A7B00 { char p0[0x10]; int sel; char p14[0x34]; int mode; int cur; int f50; };
extern "C" {
extern void* D_004FFC04;
int func_002A8800(int v);
void func_0041E0F0(O2A7B00* o, int a, int b, int c, int d);
int func_002CAC80(void* g, int sel);
M2A7B00* func_004147A0(void);
}
/* Input handler: on the confirm button event, refreshes the current item and closes when unchanged. */
extern "C" int func_002A7B00(O2A7B00* o, char* ev)
{
    int v;
    v = F_(ev, 0x0, unsigned short) == 1;
    if (v != 0) {
        v = F_(ev, 0x2, unsigned short) == 0;
    }
    v = v ? F_(ev, 0x8, unsigned short) == 0x10 : v;
    if (v != 0) {
        v = F_(ev, 0x6, unsigned short) == 0;
    }
    if (v != 0) {
        if (o->mode != 0 && o->mode != 1) {
            int old;
            o->cur = func_002A8800(o->cur);
            old = o->sel;
            func_0041E0F0(o, o->cur, o->mode == 2 ? 0x1A : 0x1B, o->f50, 0);
            if (!func_002CAC80(D_004FFC04, old) && old == o->sel) {
                o->sel = -1;
                func_004147A0()->Remove(o);
            }
        }
        return 1;
    }
    return 0;
}
