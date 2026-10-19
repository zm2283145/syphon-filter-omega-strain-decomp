#pragma cplusplus on
#include "types.h"
struct Tgt { char pad[0xC]; int id; char pad10[0x3464 - 0x10]; int f3464; };
struct Hnd { Tgt* p; int id; };
struct Vec { int cap; int count; void** items; };
struct Msg { void* vt; char pad4[0x1C]; signed char b20; char pad21[3]; signed char b24; char pad25[3]; void* bp; int id; };
struct Bp { char pad0[0x2F3]; unsigned char b2F3; char pad2F4[0x2FC - 0x2F4]; void* fx; Hnd h; int owner; };
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
extern void* g_HotboxTracker;
extern Vec* g_BackpackList;
int NetGame_InitLocalSlot(int*, int);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* src, int f);
void cMessage_dtor(void* m, int flags);
void Hotbox_RemoveObjectBox(void*, void*);
void Object_Unregister(void*);
void Object_DeleteLater(void*, float);
void PtrVector_Resize(Vec* v, int n, int* fill);
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r;int a=D_005721A8;if(g_IsMultiplayer) { if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,a);r=D_00494178; }else { r=0; }return r; }
#pragma pop
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
#pragma opt_strength_reduction off
extern "C" void Backpack_Destroy(Bp* self)
{
    if (HGet(&self->h)) HGet(&self->h)->f3464 = 0;
    if (!self->b2F3 && g_IsMultiplayer) {
        if (self->owner == LocalId()) {
            Msg m;
            Event_Construct(&m, D_005061B0);
            m.vt = D_004DCEF0;
            m.bp = self;
            m.b24 = 1;
            m.id = -1;
            m.b20 = 4;
            Event_Send(&m, self, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
    if (self->fx) {
        Hotbox_RemoveObjectBox(g_HotboxTracker, self->fx);
        Object_Unregister(self->fx);
        Object_DeleteLater(self->fx, 0.1f);
        self->fx = 0;
    }
    Object_Unregister(self);
    {
        Vec* v = g_BackpackList;
        int i;
        int last = v->count - 1;
        int fill;
        for (i = 0; last >= i; i++) {
            void** e = &v->items[i];
            if (*e == self) {
                *e = v->items[last];
                last--;
            }
        }
        fill = 0;
        PtrVector_Resize(v, last + 1, &fill);
    }
    Object_DeleteLater(self, 0.1f);
}
