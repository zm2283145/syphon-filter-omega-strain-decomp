#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct C348A00 { int pad0; int a4; char pad8[0x10]; unsigned char a18; };
class S348A00 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void f5C(int, int);
    char pad[0x48]; unsigned int a4C; int pad50; int a54; char pad2[0x4C]; C348A00* aA4;
};
extern "C" {
extern void func_0041E3B0(S348A00*);
extern void func_00424410(S348A00*, int*, unsigned int*);
extern void func_00424430(S348A00*, int, unsigned int);
extern void LobbyArray_SetDirty(C348A00*, int);
void func_00348A00(S348A00* o);
}
static inline void inl_348A00(S348A00* o)
{
    int a;
    unsigned int b;
    if (o->aA4) o->f5C(4, o->aA4->a4);
    func_00424410(o, &a, &b);
    if (b >= o->a4C && o->a4C != 0) b = o->a4C - 1;
    else if (b >= o->a4C) b = 0;
    o->a54 = 100000;
    func_00424430(o, a, b);
}
void func_00348A00(S348A00* o)
{
    func_0041E3B0(o);
    if (o->aA4 && o->aA4->a18) {
        inl_348A00(o);
        LobbyArray_SetDirty(o->aA4, 0);
    }
}