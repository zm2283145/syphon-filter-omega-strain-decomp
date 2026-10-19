#pragma cplusplus on
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    /* xx: dead on purpose, retail keeps the duplicate address addiu of the copy target */
    V(const V& o) { void* xx = this; __int128 q; V* pd = this; const V* ps = &o; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
} __attribute__((aligned(16)));
struct Plc { V rot; V pos; };
struct Ident { char pad[0x50]; Plc orient; V pos; Plc pose; unsigned char d160; unsigned char d161; unsigned char d162; };
struct Root { char pad[0xB0]; Root* owner; char children[4]; };

extern "C" {
int Root_GetParent(Root* r);
void Root_RefreshWorldCache(Root* r);
char* Root_Identity(Root* r);
void func_001A76A0(Root* r);
void Root_GetWorldPose(Root* r);
void func_00393600(void* vec, Root** value);
Ident* Root_IdentityAccessor(Root* r);
void Transform_SetOrientation(Plc* d, Plc* s);
int func_001A0280(Root* r);
void func_001A7530(Plc* p);
Plc* Root_GetParentInverse(Root* r, Plc* tmp);
void Placement_Compose(Plc* d, Plc* s);
void Root_PropagateChildren(Root* r);
void Vec4_Copy(V* d, V* s);
void func_00132840(V* q);
V* func_001A73C0(Root* r, V* out);
void Quat_RotateVector(V* a, V* b);
}

static inline Plc* WorldOrient(Root* r)
{
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return (Plc*)Root_Identity(r);
    }
    return (Plc*)(Root_Identity(r) + 0x50);
}
static inline V* WorldPos(Root* r)
{
    if (Root_GetParent(r)) {
        func_001A76A0(r);
        return (V*)(Root_Identity(r) + 0x20);
    }
    return (V*)(Root_Identity(r) + 0x70);
}
static inline Plc* WorldPose(Root* r)
{
    if (Root_GetParent(r)) {
        Root_GetWorldPose(r);
        return (Plc*)(Root_Identity(r) + 0x30);
    }
    return (Plc*)(Root_Identity(r) + 0x80);
}
static inline void Detach(Root* self)
{
    Root* me = self;
    if (me->owner) {
        func_00393600(me->owner->children, &me);
        me->owner = 0;
    }
}
static inline void SetOrient(Root* self, Plc* o)
{
    Transform_SetOrientation(&Root_IdentityAccessor(self)->orient, o);
    if (func_001A0280(self)) {
        Plc tmp;
        func_001A7530(&tmp);
        Placement_Compose(&Root_IdentityAccessor(self)->orient, Root_GetParentInverse(self, &tmp));
    }
    Root_IdentityAccessor(self)->d160 = 1;
    Root_PropagateChildren(self);
}
static inline void SetPos(Root* self, V* p)
{
    Vec4_Copy(&Root_IdentityAccessor(self)->pos, p);
    if (func_001A0280(self)) {
        V q;
        func_00132840(&q);
        Quat_RotateVector(&Root_IdentityAccessor(self)->pos, func_001A73C0(self, &q));
    }
    Root_IdentityAccessor(self)->d161 = 1;
}
static inline void SetPose(Root* self, Plc* o)
{
    Transform_SetOrientation(&Root_IdentityAccessor(self)->pose, o);
    if (func_001A0280(self)) {
        Plc tmp;
        func_001A7530(&tmp);
        Placement_Compose(&Root_IdentityAccessor(self)->pose, Root_GetParentInverse(self, &tmp));
    }
    Root_IdentityAccessor(self)->d162 = 1;
}

extern "C" void func_00393380(Root* self)
{
    if (self->owner) {
        Plc o = *WorldOrient(self);
        V p = *WorldPos(self);
        Plc q = *WorldPose(self);
        Detach(self);
        SetOrient(self, &o);
        SetPos(self, &p);
        SetPose(self, &q);
    }
}
