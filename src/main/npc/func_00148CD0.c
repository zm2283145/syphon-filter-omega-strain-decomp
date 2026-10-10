/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef struct GObj {
    char pad[0x2C];
    unsigned char enabled; /* +0x2C */
    unsigned char active;  /* +0x2D */
    unsigned char paused;  /* +0x2E */
} GObj;

/* Virtual-call view of cNPCCtl: only the slots used here are named (vtable offset in comments). */
struct cNPCCtl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Method48(); /* +0x48 */
    char pad04[0x30 - 4];
    GObj* owner; /* +0x30 */
    char pad34[0x5C - 0x34];
    unsigned char live; /* +0x5C */
};

extern "C" void func_001489D0(void* arg, cNPCCtl* self);

static inline bool IsLive(GObj* o)
{
    return o->active && o->enabled && !o->paused;
}

/* Runs func_001489D0, then virtual +0x48 with the +0x5C flag set to whether the owner is live. */
extern "C" void func_00148CD0(cNPCCtl* self, void* arg)
{
    func_001489D0(arg, self);
    self->live = IsLive(self->owner);
    self->Method48();
    self->live = 0;
}
