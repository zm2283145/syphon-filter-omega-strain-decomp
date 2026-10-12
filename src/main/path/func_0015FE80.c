#pragma cplusplus on
/* NpcPath route-to-node: queue node, set destination to its translation, notify the actor's owner */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
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