#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* NpcAi_ModeFlee: flee-mode message handler - start a node search away from the current position,
   retarget on hits, and resume the flee timer. */
struct V4 { __int128 q; V4() {} };
struct Mat { V4 r[4]; Mat() {} };
struct GObj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mat GetMatrix();
};
struct Bits20 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char hi : 5; };
struct Obj_548F0 { char pad0[0xC]; int serial; };
struct Hdl_548F0 { Obj_548F0* obj; int serial; };
struct Target_548F0 { V4 pos; char pad10[0x10]; Bits20 bits20; char pad21[0x40 - 0x21]; Hdl_548F0 h; };
struct Self_548F0 {
    VPAD16(a) VPAD8(b) VPAD2(c) virtual int CanSee(Obj_548F0* o);
    VPAD8(d) VPAD4(e) virtual int Busy();
    VPAD4(f) VPAD1(g) virtual void SetMovement(int a, int b);
    VPAD16(h) VPAD8(i) VPAD2(j) virtual void Attack(Obj_548F0* o, int a, float t);
    char pad4[0x2C];
    GObj* obj;              /* 0x30 */
    char pad34[0xE0 - 0x34];
    int fE0;                /* 0xE0 */
    int fE4;                /* 0xE4 */
    int fE8;                /* 0xE8 */
    char padEC[0x13F - 0xEC];
    unsigned char f13F;     /* 0x13F */
    char pad140[0x1AC - 0x140];
    Target_548F0* target;   /* 0x1AC */
    int f1B0;               /* 0x1B0 */
};
struct Ev_548F0 { char pad[0x24]; signed char kind; char pad25[3]; int f28; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern char g_Game[];
extern char g_NpcRouteMgr[];
int* Event_GetType(Ev_548F0* ev);
void* Service_Lookup(void* a, void* b);
int NpcRoute_IsHeadPending(void* svc, GObj* id);
int NpcRoute_StartRegion(int r);
unsigned char NpcRoute_NodeSearch(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void NpcNodeSearch_SetQuery(float a, float b, void* out, int k);
unsigned char NpcAi_ModeFlee(Self_548F0* self, Ev_548F0* ev);
}

/* quadword copy (lq/sq), the retail V4 copy */
static inline void QC(void* d0, const void* s0) { void* d = d0; __int128 t; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
/* target position, or an explicit override point (always null here: retail keeps the dead
   `bnez zero` arm) */
static inline void CopyOr(V4* d, Self_548F0* self, V4* a) { if (!a) QC(d, &self->target->pos); else QC(d, a); }
static inline bool Reached(Target_548F0* t) { bool r = false; if (t->bits20.b0) { unsigned char b = t->bits20.b2; if (b) r = true; } return r; }
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
static inline Obj_548F0* Get(Target_548F0* t)
{
    unsigned char ok = 1;
    if (!IsNullNV(t->h.obj) && !SameNV(t->h.obj->serial, t->h.serial))
        ok = 0;
    { unsigned char k = ok; return k ? t->h.obj : 0; }
}
static inline void Run(Self_548F0* self, void* svc, char* e0)
{
    V4 pos;
    V4 tgt;
    GObj* o;
    { Mat m = self->obj->GetMatrix(); Mat* pm = &m; QC(&pos, &pm->r[3]); }
    CopyOr(&tgt, self, (V4*)0);
    o = self->obj;
    NpcRoute_NodeSearch(10000.0f, svc, o, e0, &pos, &tgt, NpcRoute_StartRegion(self->f1B0), 6, 2, -1);
}
static inline void Search(Self_548F0* self, void* svc)
{
    char e0[0x10];
    NpcNodeSearch_SetQuery(0.0f, -10000.0f, e0, 0);
    Run(self, svc, e0);
    self->f13F = 2;
}

unsigned char NpcAi_ModeFlee(Self_548F0* self, Ev_548F0* ev)
{
    unsigned char handled = 0;
    int t = *Event_GetType(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 3) {
            if (!(unsigned char)self->Busy() && Reached(self->target)) {
                void* svc = Service_Lookup(g_Game, g_NpcRouteMgr);
                if (!NpcRoute_IsHeadPending(svc, self->obj))
                    Search(self, svc);
            }
            self->fE8 = 60;
        } else if ((unsigned char)ev->kind == 0) {
            void* svc;
            self->fE8 = 60;
            self->SetMovement(0, 20);
            self->fE0 = -1;
            self->fE4 = -1;
            svc = Service_Lookup(g_Game, g_NpcRouteMgr);
            if (!NpcRoute_IsHeadPending(svc, self->obj))
                Search(self, svc);
            handled = 1;
        } else if ((unsigned char)ev->kind == 1) {
            self->SetMovement(1, 20);
        }
    } else {
      int t2 = *Event_GetType(ev);
      if (t2 == D_004ED9B8) {
        if ((unsigned char)ev->kind == 7) {
            if (ev->f28 == 10 && Get(self->target) && self->CanSee(Get(self->target)) && !Reached(self->target))
                self->Attack(Get(self->target), 0, 1.0f);
        } else if ((unsigned char)ev->kind == 6) {
            self->fE8 = 1;
        }
      }
    }
    return handled;
}
