/*
 * main/path: range (2 files, 0015FDD0-0015FE80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"

/* merge_units: begin func_0015FDD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E8Mtx { float m[12]; float px, py, pz, pw; E8Mtx() {} float* Pos() { return &px; } float Z() { return pz; } };
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct E8Obj {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34)
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual E8Mtx GetMatrix(); /* 0xF4 */
};
struct E8Nav {
    char pad00[8];
    float y08;          /* 0x08 */
    char pad0C[0x28 - 0x0C];
    float y28;          /* 0x28 */
    char pad2C[0x54 - 0x2C];
    int node;           /* 0x54 */
    char pad58[4];
    int target;         /* 0x5C */
    char pad60[0x70 - 0x60];
    E8Obj* obj;         /* 0x70 */
};
extern "C" void NpcPath_HoldNode(E8Nav* self, int n);
extern "C" int NpcRoute_NearestGroupNode(int n, float* pos, int flags, int ex);
extern "C" void NpcPath_GetDestination(E8Nav* self, int n)
{
    NpcPath_HoldNode(self, -1);
    if (n >= 0 && n != self->target) {
        self->target = n;
        int r = NpcRoute_NearestGroupNode(n, self->obj->GetMatrix().Pos(), 0x80, -1);
        if (r >= 0) self->node = r;
    }
    float z = self->obj->GetMatrix().Z();
    self->y08 = z;
    self->y28 = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015FDD0 */

/* merge_units: begin func_0015FE80 */
#pragma push /* merge_units */
#pragma cplusplus on
/* NpcPath route-to-node: queue node, set destination to its translation, notify the actor's owner */
struct SnV4 { __int128 q; };
struct SnActor { char pad[0x58]; SnActor* owner; };
struct SnRoute { SnV4 dest; int target; char pad14[0xC]; int* nodes; int cap; int count; };
struct SnPath { char pad[0x70]; SnActor* actor; SnRoute* route; };
struct SnMsg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
void* NpcPath_GetNode(int id);
void Node_GetTranslation(SnV4* out, void* node);
void Event_Construct(SnMsg* m, void* type);
void Event_Send(SnMsg* m, SnActor* to, int flags);
void cMessage_dtor(SnMsg* m, int flags);
}
static inline void Push(SnRoute* r, int v) { r->nodes[r->count] = v; r->count++; }
static inline void Construct(SnMsg* m) { Event_Construct(m, D_004ED9B8); m->vt = D_004D9760; m->kind = 2; m->id = -1; }
static inline void Destroy(SnMsg* loc) { loc->vt = D_004D9760; cMessage_dtor(loc, 0); }
#pragma opt_propagation off
extern "C" bool func_0015FE80(SnPath* self, int node)
{
    bool r = false;
    SnRoute* rt = self->route;
    if (rt->nodes) {
    rt->count = 0;
    Push(self->route, node);
    {
        SnV4 t;
        Node_GetTranslation(&t, NpcPath_GetNode(node));
        VCopyF(&self->route->dest, &t);
        self->route->target = node;
    }
    {
        SnMsg msg;
        SnMsg* m = &msg;
        Construct(m);
        SnActor* a = self->actor;
        SnActor* o = a->owner; SnActor* to = a; if (!o) { asm { .set reorder } /* scheduling barrier: keeps retail's empty then-arm (b + nop) */ } else to = o; Event_Send(&msg, to, 1);
        Destroy(&msg);
    }
    r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015FE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015FE80 */
