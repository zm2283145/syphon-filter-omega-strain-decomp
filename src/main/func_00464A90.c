/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Child {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void Method30(); /* +0x30 */
};

typedef struct Holder {
    char pad[0x14];
    unsigned short flags; /* +0x14 */
    char pad16[0x44 - 0x16];
    Child* child;         /* +0x44 */
} Holder;

typedef struct Widget {
    char pad[0x48];
    Holder* holder; /* +0x48 */
    void* unk4C;    /* +0x4C */
} Widget;

extern "C" void func_0026CA70(void* p);
extern "C" void func_0041E470(Widget* self);

/* Sets flag 0x2 on the +0x48 object while notifying its +0x44 child (virtual +0x30), then func_0026CA70(+0x4C) and func_0041E470(self). */
extern "C" void func_00464A90(Widget* self)
{
    self->holder->flags |= 2;
    self->holder->child->Method30();
    self->holder->flags &= ~2;
    func_0026CA70(self->unk4C);
    func_0041E470(self);
}
