#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void QP(void* d, const void* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline void QPW(void* d, const void* s) { QP(d, s); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(&o) : "memory"); return *this; }
    V& SetZ(float nz) { V* p = this; p->z = nz; return *p; }
} __attribute__((aligned(16)));
struct Pl { V q; V p; };
struct Rung { char pad[0x990]; float f990; float f994; float f998; unsigned char block[3]; unsigned char snapped; };
struct Ctrl {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual int v54();
};
struct Msg;
extern "C" {
extern char D_004E00E0[], D_004E0840[];
void cMessage_ctor3(Msg* d, const Msg* s);
void func_001AD710(void* d, const void* s);
void cMessage_dtor(void* msg, int flags);
void Actor_SendCasAction(Msg* m, signed char action, int flag);
void Ledge_ToObjectPlacement(void* d, int obj, Pl* pl, int z);
}
struct Msg {
    void* vt;
    char pad04[0x18];
    int flags;             /* 0x1C */
    unsigned char b20;     /* 0x20 */
    char pad21[0xF];
    char sub[0x30];        /* 0x30 */
    Msg(signed char action, int obj, Pl* pl);
    Msg(const Msg& o);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
struct Lad {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Ctrl* ctrl;            /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    char anim[0x3248 - 0x2EC0];
    int flags;             /* 0x3248 */
    char pad324C[0x3298 - 0x324C];
    void* root;            /* 0x3298 */
    char pad329C[0x3310 - 0x329C];
    Rung* rung;            /* 0x3310 */
    char pad3314[0x3514 - 0x3314];
    int obj;               /* 0x3514 */
    signed char side;      /* 0x3518 */
};
extern float D_004A03C0, D_004A0410, D_004A0418;
extern "C" {
extern char D_004E00E0[], D_004E0840[];
}
struct Msg;
extern "C" {
V Ladder_RungTarget(Lad* l, int i);
void* Root_GetWorldPlacement(void*);
V* Placement_GetPosition(void*);
V* Placement_GetQuat(void*);
float AnimChannel_GetCurrent(char* owner, int i);
void Event_Send(void* msg, void* target, int immediate);
void Ladder_Dismount(Lad* a);
}
static inline float fab(float x) { float r; asm { abs.s r, x } return r; }
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
static inline bool Ctrl_Test(Ctrl* c) { return c && c->v54(); }
static inline bool Flag25(Lad* a) { return (a->flags >> 25) & 1; }
static inline bool Flag26(Lad* a) { return (a->flags >> 26) & 1; }
static inline float AnimCur(Lad* a) { char* an = a->anim; return AnimChannel_GetCurrent(an + 0x10, 0x15); }
inline Msg::Msg(signed char action, int obj, Pl* pl) { Msg* s = this; Actor_SendCasAction(s, action, 0xE); Ledge_ToObjectPlacement(s->sub, obj, pl, 0); s->vt = D_004E00E0; }
inline Msg::Msg(const Msg& o) { Msg* s = this; cMessage_ctor3(s, &o); func_001AD710(s->sub, o.sub); s->vt = D_004E00E0; }
static inline void Send(const Msg& m, Lad* t) { Event_Send((void*)&m, t, 1); }
static inline unsigned char Open(Rung* r, int s) { return r->block[s]; }
static inline V WithZ(const V& p, float z) { V t; QPW(&t, &p); return t.SetZ(z); }

void Ladder_Dismount(Lad* a)
{
    if (a->rung) {
        if (Rung_Valid(a->rung) && Open(a->rung, a->side)) {
            unsigned char atTop = 0;
            unsigned char atBot = 0;
            V* pos = Placement_GetPosition(Root_GetWorldPlacement(a->root));
            Rung* r = a->rung;
            float y = pos->z;
            float bot = r->f990;
            float top = r->f998 + D_004A0410;
            float k = D_004A0418;
            float tol = D_004A03C0 * k;
            if (fab(y - top) <= tol) atTop = 1;
            if (fab(y - bot) <= tol) atBot = 1;
            unsigned char exitTop = a->side == 2 && (atTop || (Flag25(a) && AnimCur(a) < 0.15f));
            unsigned char exitBot = a->side == 4 && (atBot || (Flag26(a) && AnimCur(a) < 0.15f));
            unsigned char go = (a->side != 2 && a->side != 4) || exitTop || exitBot;
            if (go) {
                if (Ctrl_Test(a->ctrl) && !a->b14)
                    return;
                int action = 0x1E;
                V target;
                if (exitTop) {
                    float z = a->rung->f998 + D_004A0410;
                    if ((a->flags >> 25) & 1)
                        z -= 1.0f;
                    target = WithZ(*Placement_GetPosition(Root_GetWorldPlacement(a->root)), z);
                    action = 0x1F;
                } else if (exitBot) {
                    float z = a->rung->f990;
                    target = WithZ(*Placement_GetPosition(Root_GetWorldPlacement(a->root)), z);
                    action = 0x20;
                } else if (a->rung->snapped) {
                    target = Ladder_RungTarget(a, 1);
                } else {
                    target = Ladder_RungTarget(a, 1);
                }
                Pl pl;
                pl.q = *Placement_GetQuat(Root_GetWorldPlacement(a->root));
                pl.p = target;
                Msg m(action, a->obj, &pl);
                if (!Ctrl_Test(a->ctrl))
                    m.b20 = 1;
                m.flags = 0x40;
                Send(Msg(m), a);
            }
        }
    }
}

