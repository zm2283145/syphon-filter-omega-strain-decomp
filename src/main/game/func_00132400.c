#include "types.h"
typedef struct { Vec4 q; Vec4 pos; } F8Plc;
typedef struct { F8Plc world; char pad20[0x30]; F8Plc local; } F8RootW;
typedef struct F8Root { char pad0[0xA0]; unsigned char dirty; char padA1[0xF]; struct F8Root* parent; } F8Root;
extern F8RootW* Root_Identity(void* self);
extern int Root_GetParent(F8Root* r);
extern void Root_RefreshWorldCache(F8Root* r);
extern Vec4* func_001325F0(Vec4* d, Vec4* s);
extern Vec4* Vec4_Copy(Vec4* d, Vec4* s);
extern void* Placement_GetQuat(F8Plc* p);
extern void* Placement_GetPosition(F8Plc* p);
extern void func_00132530(F8RootW* w, void* q);
extern void func_00132510(F8RootW* w, void* pos);
static inline void F8PlcCopy(F8Plc* d, F8Plc* s)
{
    func_001325F0(&d->q, &s->q);
    Vec4_Copy(&d->pos, &s->pos);
}
F8RootW* Root_GetWorldPlacement(F8Root* r)
{
    F8Root* p = r->parent;
    if (p != 0) {
        if (p && r->dirty) {
            F8Plc* pp;
            F8Plc* local;
            F8RootW* world;
            F8RootW* w;
            if (Root_GetParent(p)) {
                Root_RefreshWorldCache(p);
                pp = &Root_Identity(p)->world;
            } else {
                pp = &Root_Identity(p)->local;
            }
            F8PlcCopy(&Root_Identity(r)->world, &Root_Identity(r)->local);
            w = Root_Identity(r);
            func_00132530(w, Placement_GetQuat(pp));
            func_00132510(w, Placement_GetPosition(pp));
            r->dirty = 0;
        }
        return (F8RootW*)r;
    }
    return (F8RootW*)&((F8RootW*)r)->local;
}
