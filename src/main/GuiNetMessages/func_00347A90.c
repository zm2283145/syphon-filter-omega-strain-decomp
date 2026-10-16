#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct C347A90 { int pad0; int a4; };
class S347A90 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void f5C(int, int);
    char pad[0x48]; unsigned int a4C; int pad50; int a54; char pad2[0x4C]; C347A90* aA4;
};
extern "C" {
extern void func_00424410(S347A90*, int*, unsigned int*);
extern void GuiArrayWidget_Select(S347A90*, int, unsigned int);
void func_00347A90(S347A90* o);
}
void func_00347A90(S347A90* o)
{
    int a;
    unsigned int b;
    if (o->aA4) o->f5C(4, o->aA4->a4);
    func_00424410(o, &a, &b);
    if (b >= o->a4C && o->a4C != 0) b = o->a4C - 1;
    else if (b >= o->a4C) b = 0;
    o->a54 = 100000;
    GuiArrayWidget_Select(o, a, b);
}
