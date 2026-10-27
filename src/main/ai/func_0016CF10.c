#pragma cplusplus on
#pragma inline_depth(8)
#include "sfo_ai_types.h"
#include "hotbox_types.h"
#include "vslot_pad.h"
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; const V* s = &o; Q16(d, s); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } };
struct AObj;
struct ObjV { VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V Pos(int); VPAD4(e) virtual int D4(); VPAD4(f) virtual M Mtx(); VPAD2(g) VPAD1(h) virtual int Type(void*); VPAD2(i) VPAD1(j) virtual unsigned char Life(); };
struct CtlV { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); VPAD4(d) VPAD2(e) virtual int Enemy(AObj*); };
struct AObj {
    void** vt; char p04[8]; int id; char p10[0x1C];
    unsigned char enabled, activated, removed; char p2F[0x15];
    int burst; char p48[4]; int team; char p50[8]; void* ctrl;
    char p5C[0x3468 - 0x5C]; unsigned char human; char p3469[7]; unsigned char solo;
    char p3471[0x3524 - 0x3471]; unsigned char* weapon;
};
struct AComp { void** vt; char p04[0x2C]; AObj* owner; };
struct ARec {
    SfWeakHandle h; int id2; char p0C[4]; V lastPos; unsigned char cause; char p21[3];
    float age, since7, visibility, threat, salience; unsigned char inView, lineClear; char p3A[2]; unsigned char sent;
};
union AIt { HotboxListNode* p; };
struct Raw { HotboxListNode* p; };
extern "C" {
AObj* cSafePtr_cGOBJ_opCast_cGOBJPtr(SfWeakHandle*);
void Alloc_Lock(int);
void EnableIntc(int);
AObj* cGobjController_GetTarget(void*);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMemMan_Deallocate(int, void*, void*, int);
void cAITarget_AddAwareness(SfAiPerception*, AObj*, int, float);
void cAITarget_SetTargetPositionLastSeen(SfAiPerception*, AObj*, const V&, int);
AObj* cNetObj_GetPlayer(int);
float cWeapon_GetMaxRange(void*);
void __register_global_object(void*, void*, void*);
void cMessage_dtor(void*, int);
void std_list_deleter_voidPtr_erase_listdeleter(void*, void*, void*);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(void*, void*);
void std_list_cTargetAwarenessPtr_end_void(void*, void*);
void cLListIterator_cTargetAwarenessPtr_ctor(void*, void*);
void std_list_cTargetAwarenessPtr_begin(void*, void*);
void std_list_cTargetAwarenessPtr_generic_iterator_ctor(void*, void*);
void std_list_cTargetAwarenessPtr_generic_iterator_opCast(void*, void*);
void cPlane_dtor(void*, int);
extern char D_0049C650[];
extern int g_HumanActorClassKey;
extern char D_004D9340[], D_004DCC90[], D_004DCD70[], D_004EE550[], D_004EE568[], D_004EE580[];
extern signed char D_004EE560;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char g_ScriptAINewAwarenessMsgKey[];
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB { void* vt;
    MsgB(void* k) { cMessage_ctor_cMessageNameR(this, k); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); } };
struct Msg7 : MsgB { char p04[0x20]; unsigned char kind; char p25[3]; int id; int cause;
    Msg7(int i, int c) : MsgB(D_004EE550) { vt = D_004D9340; kind = 7; id = i; cause = c; }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg7() { vt = D_004D9340; } };
struct MsgNew : MsgB { char p04[0x1C]; unsigned char kind; char p21[3]; AObj* obj; signed char cause; char p29[7];
    MsgNew(AObj* o, signed char c) : MsgB(g_ScriptAINewAwarenessMsgKey) { vt = D_004DCD70; obj = o; kind = 2; vt = D_004DCC90; cause = c; }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgNew() { vt = D_004DCD70; } };
static inline bool Active(AObj* p) { return p->activated && p->enabled && !p->removed; }
static inline bool Player(void* c) { bool yes = false; if (c) if (((CtlV*)c)->IsPlayer()) yes = true; return yes; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
static inline int Valid(SfWeakHandle* h) { unsigned char ok = 1; if (!IsNullNV(h->object) && !SameNV(((AObj*)h->object)->id, h->id)) ok = 0; return ok; }
static inline AObj* WGet(SfWeakHandle* h) { return Valid(h) ? (AObj*)h->object : 0; }
static inline int Ld(int* p) { return *p; }
static inline bool SameObj(AObj* a, AObj* b) { return a->id == b->id; }
static inline const V& T(const M& m) { return m.r[3]; }
static inline bool Human(AObj* o) { bool r = false; bool a = Active(o); if (a && o->human) r = true; return r; }
static inline int Key0() { int* p = &g_HumanActorClassKey; return *p; }
static inline bool Keep(AObj* o) { bool r = false; if (Active(o) && o->team == Key0()) r = Human(o); return r; }
static inline bool Aimed(void* c, AObj* o) { return cGobjController_GetTarget(c) == o; }
static inline float MaxA(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float MinA(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float MinF(float a, float b) { float r; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void Sub(V* d, V* a, V* b) {
    asm { lqc2 vf1, 0x0(a)
          lqc2 vf2, 0x0(b)
          vsub.xyzw vf1, vf1, vf2
          sqc2 vf1, 0x0(d) }
}
static inline int IsZero(V* v) {
    int k, fl; unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline float Len(V* a) {
    int rv0; float ret;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
static inline void FreeRec(ARec* r, int line) {
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    cMemMan_Deallocate(0, r, D_0049C650, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
}
static inline void Er2(void* recs, void* a, Raw* t) { char y[4], x[4]; void* pa = a; std_list_cTargetAwarenessPtr_generic_iterator_opCast(x, pa); std_list_deleter_voidPtr_erase_listdeleter(y, recs, x); std_list_cTargetAwarenessPtr_generic_iterator_ctor(t, y); }
static inline void Er1(void* recs, AIt* it, AIt* r) { Raw t; char a[4]; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(a, it); Er2(recs, a, &t); r->p = t.p; }
static inline void Bg2(void* recs, AIt* b) { void* s; std_list_cTargetAwarenessPtr_begin(&s, recs); cLListIterator_cTargetAwarenessPtr_ctor(b, &s); }
/* Retail reserves two unused depth-1 iterator slots above the erase temps; dead address-taken locals reproduce them. */
static inline void Bg1(void* recs, AIt* b) { AIt u1, u2; void* q1 = &u1; void* q2 = &u2; Bg2(recs, b); }
static inline void En2(void* recs, AIt* e) { void* s; std_list_cTargetAwarenessPtr_end_void(&s, recs); cLListIterator_cTargetAwarenessPtr_ctor(e, &s); }
static inline void En1(void* recs, AIt* e) { En2(recs, e); }
extern "C" void cAITarget_UpdateAwareness(SfAiPerception* p, float dt) {
    SfAiPerception* self = p;
    ARec* rec; AObj* obj;
    int i; int id; int seen; int cause; unsigned char done; AObj* pl; signed char cause2;
    AIt it, b, r1, r2, e;
        AComp* comp;
    V own = ((ObjV*)((AComp*)self->component)->owner)->Pos(-1);
    Bg1(&self->records, &b);
    for (it = b; En1(&self->records, &e), it.p != e.p; it.p = it.p->next) {
        rec = (ARec*)it.p->value;
        obj = WGet(&rec->h);
        if (!obj) {
            FreeRec(rec, 0x255);
            Er1(&self->records, &it, &r1);
            it = r1;
            continue;
        }
        if (((ObjV*)obj)->Life() == 3 && !Keep(obj)) {
            FreeRec(rec, 0x262);
            Er1(&self->records, &it, &r2);
            it = r2;
            continue;
        }
        if (Active(obj)) {
            rec->threat *= 0.8f;
            rec->salience *= 0.9f;
        } else {
            rec->inView = 0;
            rec->lineClear = 0;
            rec->threat = 0.0f;
            rec->salience = 0.0f;
        }
        float age = rec->age;
        if (age <= 0.0f || !rec->lineClear) rec->age += dt;
        if (age <= 0.0f && !(rec->age <= 0.0f)) {
            bool dead; unsigned char life = ((ObjV*)obj)->Life();
            dead = true;
            if (life != 3 && life != 2) dead = false;
            if (!dead) {
                if (!WGet(&self->target)) {
                    if (((CtlV*)self->component)->Enemy(obj)) {

                        cAITarget_SetTargetPositionLastSeen(self, obj, ((ObjV*)obj)->Mtx().T(), 0);
                    }
                } else if (SameObj(obj, cSafePtr_cGOBJ_opCast_cGOBJPtr(&self->target))) {
                    seen = (rec->lineClear & rec->inView) != 0;

                    { const V& t = ((ObjV*)obj)->Mtx().T(); cAITarget_SetTargetPositionLastSeen(self, WGet(&self->target), t, seen); }
                }
                if (!rec->sent || !(rec->since7 <= 1.0f)) {
                    Msg7(obj->id, rec->cause).Send(self->component);
                    rec->since7 = 0.0f;
                    if (!rec->sent) {
                        done = 1;
                        if (D_004EE560 == 0) {
                            __register_global_object(D_004EE580, (void*)&cPlane_dtor, D_004EE568);
                            D_004EE560 = 1;
                        }
                        if (Player(obj->ctrl)) done = (unsigned char)((ObjV*)obj)->Type(D_004EE580);
                        if (!done) {
                            for (i = 0; i < 4; i++) {
                                pl = cNetObj_GetPlayer(i);
                                if (pl && ((ObjV*)pl)->Type(D_004EE580)) cAITarget_AddAwareness(self, pl, 9, 0.0f);
                            }
                        }
                    }
                }
                if (!rec->sent) {
                    if (((CtlV*)self->component)->Enemy(obj) || (Player(obj->ctrl) && (self->flags2 & 1))) {
                        MsgNew(obj, (signed char)rec->cause).Send(((AComp*)self->component)->owner);
                        rec->sent = 1;
                    }
                }
            }
        }
        float vis = 0.0f;
        if (rec->lineClear) {
            if (rec->inView) {

                rec->lastPos = ((ObjV*)obj)->Mtx().T();
            }
            if (((CtlV*)self->component)->Enemy(obj)) {
                float dist;
                float range = MaxF(self->viewRadius, 1.0f);
                V d = ((ObjV*)obj)->Pos(-1);
                { V* pd = &d; V* pa = &d; Sub(pd, pa, &own); }
                if (!IsZero(&d)) dist = Len(&d);
                else dist = 0.1f;
                vis = dist / range;
                if (vis > 1.0f) vis = 1.0f;
                vis = 1.0f - vis;
                int n = obj->burst;
                if (((AComp*)self->component)->owner->solo == 1) n = 0;
                if (n > 0) vis *= (100.0f - (float)(n >> 1)) / 100.0f;
                float thr = self->viewRadius;
                if (obj->team == Key0() && obj->weapon[0x84] != 6) { float w = cWeapon_GetMaxRange(obj->weapon); MinA(thr, MaxA(w, 30.0f)); }
                thr = dist / range;
                if (thr > 1.0f) thr = 1.0f;
                thr = 1.0f - thr;
                if (obj->ctrl) {
                    if (Aimed(obj->ctrl, ((AComp*)self->component)->owner)) thr *= 1.2f;
                    else Player(obj->ctrl);
                    if (((ObjV*)obj)->D4()) thr *= 1.4f;
                }
                rec->threat = thr;
            }
        }
        rec->visibility = vis;
        rec->since7 += dt;
    }
}