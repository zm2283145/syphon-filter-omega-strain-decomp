/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};

extern int D_00494140;
extern int D_00494148;
extern char D_004AAE00[];
extern "C" void func_0041F150(void* self);
extern "C" Widget* func_0041DC70(void* self, int id);
typedef struct Screen { char pad[0x88]; Widget* unk88; /* +0x88 */ Widget* unk8C; /* +0x8C */ } Screen;

/* func_0041F150, then caches the D_00494140 child at +0x8C if it is of type D_004AAE00 (virtual +0x58), else 0, and the D_00494148 child at +0x88. */
extern "C" void func_00424BC0(Screen* self)
{
    Widget* child;
    func_0041F150(self);
    child = func_0041DC70(self, D_00494140);
    if (!child || !child->IsA(D_004AAE00))
    child = 0;
    self->unk8C = child;
    self->unk88 = func_0041DC70(self, D_00494148);
}
