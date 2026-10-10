/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Menu: only the slots used here are named (vtable offset in comments). */
struct Menu {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
};

extern char D_004C1AA0[];
extern "C" void func_004262D0(Menu* self);
extern "C" void func_004248C0(Menu* self, int column, int width);
extern "C" void func_00425E20(Menu* self, const char* name);
extern "C" void func_00425E00(Menu* self, int value);
extern "C" void func_00455840(Menu* self, int index);

/* Menu setup: base init, virtual +0x5C(2, 4), two column widths, the D_004C1AA0 name, then func_00455840(-1). */
extern "C" void func_00455B60(Menu* self)
{
    func_004262D0(self);
    self->Method5C(2, 4);
    func_004248C0(self, 0, 0x73);
    func_004248C0(self, 1, 10);
    func_00425E20(self, D_004C1AA0);
    func_00425E00(self, 0);
    func_00455840(self, -1);
}
