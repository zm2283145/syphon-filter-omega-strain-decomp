/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x2F - 4];
    unsigned char unk2F; /* +0x2F */
    char pad30[0x60 - 0x30];
    void* owner;         /* +0x60 */
    unsigned char unk64; /* +0x64 */
    int value;           /* +0x68 */
    char pad6C[0x84 - 0x6C];
    unsigned char unk84; /* +0x84 */
};

extern char D_004E05A0[];
extern "C" void IdMgr_Allocate(int* name, int id);
extern "C" void cGOBJ_ctor(Obj* self, int* name, int type, int* extra);
extern "C" void Object_Register(Obj* self);

/* Constructor: base construct (cGOBJ_ctor, type 0xD with name 0xF3), vtable D_004E05A0, stores owner/value fields, then Object_Register and virtual +0x5C(0). */
extern "C" Obj* func_003E99B0(Obj* self, void* owner, int* value)
{
    int extra;
    int name;
    extra = 0;
    IdMgr_Allocate(&name, 0xF3);
    cGOBJ_ctor(self, &name, 0xD, &extra);
    *(void**)self = D_004E05A0;
    self->owner = owner;
    self->unk64 = 1;
    self->value = *value;
    self->unk84 = 0;
    Object_Register(self);
    self->Method5C(0);
    self->unk2F = 1;
    return self;
}
