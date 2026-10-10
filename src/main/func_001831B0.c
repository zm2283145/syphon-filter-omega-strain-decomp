/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of XformNode: only the slots used here are named (vtable offset in comments). */
struct XformNode {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x10 - 4];
    char transform[0x40]; /* +0x10 */
    unsigned char dirty;  /* +0x50 */
};

/* Brings the cached transform up to date (virtual +0x58) if dirty and returns it. */
extern "C" void* Transform_GetUpdated(XformNode* self)
{
    if (self->dirty)
        self->Update();
    return &self->transform;
}
