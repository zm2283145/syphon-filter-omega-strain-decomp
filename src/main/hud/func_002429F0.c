#pragma cplusplus on
#include "vslot_pad.h"
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y);
};
extern "C" {
void* func_00414790(void);
Mgr2427* func_004147A0(void);
void* func_00418A80(void* a, void* b, void* c);
void func_00131470(void* p, int v);
void func_002427F0(Obj2426* s);
int func_00241AC0(Obj2426* s);
void func_0036A240(void* p);
void func_0045CA20(void* p, int v);
void func_00437950(int v);
extern char D_004FFB50[];
extern char D_0055A300[];
extern char D_004A7260[]; extern char D_004A7278[]; extern char D_004A7248[]; extern char D_004A7288[];
}
extern "C" void func_002429F0(Obj2426* s) {
    if (s->b6A8) return;
    func_00131470(D_004FFB50, 1);
    if (s->b6A9) func_002427F0(s);
    if (!func_00241AC0(s)) func_0036A240(D_0055A300);
    {
        void* x = func_00418A80(func_00414790(), D_004A7260, D_004A7278);
        func_004147A0()->s23(x, -1);
    }
    {
        void* x = func_00418A80(func_00414790(), D_004A7248, D_004A7288);
        func_004147A0()->s23(x, 0);
    }
    func_0045CA20(s->snd, 0);
    func_00437950(0);
    s->b6A8 = 1;
}
