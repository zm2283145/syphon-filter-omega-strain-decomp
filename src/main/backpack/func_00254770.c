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
int NetGetMyClientIndex(int*, int);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* src, int f);
void cMessage_dtor(void* m, int flags);
void cHotboxMan_RemoveHotbox(void*, void*);
void nGobjManager_RemoveGOBJ(void*);
void cSystem_ActualScheduleDelete(void*, float);
void std_vector_pod_int_resize(Vec* v, int n, int* fill);
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r;int a=D_005721A8;if(g_IsMultiplayer) { if(D_00494178==-1)NetGetMyClientIndex(&D_00494178,a);r=D_00494178; }else { r=0; }return r; }
#pragma pop
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
#pragma opt_strength_reduction off
extern "C" void cBackpack_Remove(Bp* self)
{
    if (HGet(&self->h)) HGet(&self->h)->f3464 = 0;
    if (!self->b2F3 && g_IsMultiplayer) {
        if (self->owner == LocalId()) {
            Msg m;
            cMessage_ctor_cMessageNameR(&m, D_005061B0);
            m.vt = D_004DCEF0;
            m.bp = self;
            m.b24 = 1;
            m.id = -1;
            m.b20 = 4;
            QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
    if (self->fx) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, self->fx);
        nGobjManager_RemoveGOBJ(self->fx);
        cSystem_ActualScheduleDelete(self->fx, 0.1f);
        self->fx = 0;
    }
    nGobjManager_RemoveGOBJ(self);
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
        std_vector_pod_int_resize(v, last + 1, &fill);
    }
    cSystem_ActualScheduleDelete(self, 0.1f);
}
