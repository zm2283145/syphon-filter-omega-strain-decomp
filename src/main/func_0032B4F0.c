#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Stk { public: VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Push(void* o, int pri); };
struct Dlg { char p0[0x48]; void* title; void* body; int f50; int f54; int f58; char p5c[0xE0 - 0x5C]; unsigned char fE0; };
extern "C" {
extern char D_004B8CF0[];
void func_0041BEB0(void* w, char* s, int a);
void func_0041A100(void* w, int a);
Stk* Gui_GetScreenStack(void);
}
extern "C" void func_0032B4F0(Dlg* d, char* title, char* body, int a, int b, int c, unsigned char e)
{
    if (d->title) func_0041BEB0(d->title, title ? title : D_004B8CF0, 0);
    if (d->body) {
        func_0041BEB0(d->body, body ? body : D_004B8CF0, 0);
        func_0041A100(d->body, -1);
    }
    d->f54 = a;
    d->f58 = c;
    d->f50 = b;
    d->fE0 = e;
    Gui_GetScreenStack()->Push(d, 100);
}

