#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct V34FBA0 { int cap; int count; int data; };
class W34FBA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    virtual void f5C(int, int);
    char pad[0x84]; void* a88; char pad8C[0x34]; V34FBA0* aC0; int aC4[11];
};
struct S34FBA0 { char pad[0x6C]; W34FBA0* a6C; V34FBA0 v70; char pad7C[4]; int a80; };
extern "C" {
extern "C" char D_004BAA78[];
extern "C" char D_004BAA90[];
static void * const dat_00492BD0[2] = { (void*)D_004BAA78, (void*)0x0 };
static void * const dat_00492BD8[2] = { (void*)D_004BAA90, (void*)0x0 };
extern char D_004BAD80[];
void func_00356CD0(S34FBA0* o);
void func_0034F670(S34FBA0* o);
W34FBA0* GuiWidget_FindChildByName(void* self, char* name);
void func_00424430(void* w, int a, int b);
void func_004248C0(void* w, int i, int v);
void func_0034FBA0(S34FBA0* o);
}
static inline W34FBA0* cast34FBA0(W34FBA0* w)
{
    return (w && w->IsA(D_004BAD80)) ? w : 0;
}
void func_0034FBA0(S34FBA0* o)
{
    func_00356CD0(o);
    o->a80 = 0;
    func_0034F670(o);
    o->a6C = cast34FBA0(GuiWidget_FindChildByName(o, (*(char**)dat_00492BD0)));
    if (o->a6C) {
        W34FBA0* w;
        int i;
        o->a6C->a88 = GuiWidget_FindChildByName(o, (*(char**)dat_00492BD8));

        w = o->a6C;
        w->aC0 = &o->v70;
        w->f5C(0xB, &o->v70 ? o->v70.count : 0);
        func_00424430(w, 0, 0);
        for (i = 0; i < 11; i++) func_004248C0(w, i, w->aC4[i]);
    }
}


