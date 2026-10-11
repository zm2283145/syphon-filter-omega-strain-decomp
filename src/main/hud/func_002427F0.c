#pragma cplusplus on
#include "vslot_pad.h"
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y); virtual void s24(void* x);
};
extern "C" {
void* func_00414790(void);
Mgr2427* func_004147A0(void);
void* func_00418980(void* a, void* b);
void* func_00418A80(void* a, void* b, void* c);
extern char D_004A7230[];
extern char D_004A7240[];
}extern "C" void func_002427F0(Obj2426* s) {
    if (s->b6A9) {
        void* x = func_00418980(func_00414790(), D_004A7230);
        if (x) func_004147A0()->s24(x);
        s->b6A9 = 0;
    }
}

