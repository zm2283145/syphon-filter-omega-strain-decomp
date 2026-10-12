#pragma cplusplus on
#include "types.h"

struct Widget_456020 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};
typedef struct Panel_456020 {
    char pad0[0x14];
    unsigned short flags;      /* +0x14 */
    char pad16[0x60 - 0x16];
    int m60;                   /* +0x60 */
    char pad64[0x7C - 0x64];
    Widget_456020* m7C;        /* +0x7C */
} Panel_456020;
typedef struct Screen_456020 {
    char pad[0x48];
    Panel_456020* panel;       /* +0x48 */
} Screen_456020;
extern "C" int D_00497980;
extern "C" int D_00497988;
extern "C" char D_004AAE20[];
extern "C" char D_004AAE00[];
extern "C" void func_0041F150(Screen_456020* self);
extern "C" Widget_456020* func_0041DB80(Screen_456020* self, int id);

extern "C" void func_00456020(Screen_456020* self)
{
    Widget_456020* child;
    func_0041F150(self);
    child = func_0041DB80(self, D_00497980);
    child = (child && child->IsA(D_004AAE20)) ? child : 0;
    self->panel = (Panel_456020*)child;
    if (self->panel) {
        self->panel->m60 = 0;
        child = func_0041DB80(self, D_00497988);
        child = (child && child->IsA(D_004AAE00)) ? child : 0;
        self->panel->m7C = child;
        self->panel->flags |= 0x80;
    }
}