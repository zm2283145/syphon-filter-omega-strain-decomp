#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
#include "cmessage.h"
#include "alloc_guard.h"
extern "C" char D_004EA370[], D_0055D4E0[], D_004D9360[], D_004D9340[], D_004EE550[];
typedef struct V4 { float x, y, z, w; V4& operator-=(const V4& o); } __attribute__((aligned(16))) V4;
typedef struct M4 { V4 r[4]; V4& T() { return r[3]; } } M4;
struct Obj {
    VPAD16(a) VPAD4(b) VPAD2(c) virtual void f60(int);
    VPAD32(d) VPAD4(e) virtual M4 Mtx();
    VPAD4(f) virtual unsigned char State();
    char p4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char p2F[9]; int x38;
};
struct PNode { char p0[0x60]; Obj* obj; };
struct Path { char p0[0x40]; float f40; char p44[0xC]; int x50; char p54[0xC]; unsigned char pb0 : 1; unsigned char pb1 : 1; unsigned char pb2 : 1; unsigned char hold : 1; };
struct Ref { char p0[8]; int id; signed char c; };
struct Flag { char p0[4]; unsigned char on; };
struct Slot { int a, b, id, c; };
struct Inv { Slot s[8]; char p80[4]; unsigned char cur; };
struct Tgt { char p0[0x3C]; float f3C; float ang; float px, py, pz; };
struct Rdy { char p0[0x2C8]; float f2C8; };
struct Ctl { char p0[0x30E0]; float f30E0; char p30E4[0x320C - 0x30E4]; int x320C; int x3210; char p3214[0x3310 - 0x3214]; Rdy* rdy; char p3314[0x3524 - 0x3314]; Inv* inv; char p3528[0x3584 - 0x3528]; Tgt* tgt; };
struct Self {
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int f44();
    VPAD4(e) VPAD2(f) virtual void f60(Obj*, int, signed char);
    char p4[0x2C]; Obj* obj; char p34[0x84 - 0x34]; float f84; float f88; char p8C[0xF4 - 0x8C]; int xF4;
    char pF8[0x150 - 0xF8]; unsigned short x150; char p152[6]; unsigned char b158; char p159[0x1B0 - 0x159]; Path* path;
    char p1B4[0x1E0 - 0x1B4]; Ref* ref; Flag* flag; PNode* node; char p1EC[2]; unsigned char b1EE; char p1EF[0x200 - 0x1EF];
    float f200; float f204; int x208; char p20C[8]; unsigned char bf0 : 1; unsigned char bf1 : 1; unsigned char bf2 : 1;
};
struct Msg : CMsg { unsigned char b24; char p25[0xB]; char data[0x40]; };
struct CV : V4 { CV(float a, float b, float c) { x = a; y = b; z = c; w = 1.0f; } };
struct FMsg : CMsg { unsigned char b24; char p25[3]; int x28;
    FMsg() { FMsg* f = this; Event_Construct(f, D_004EE550); f->vtable = D_004D9340; f->b24 = 2; f->x28 = -1; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FMsg() { vtable = D_004D9340; cMessage_dtor(this, 0); } };
extern "C" {

Obj* Object_LookupById(int*);
Ctl* AiController_GetActor(Self*);
int Weapon_CanAttack(Inv*);
void func_002D4E70(Self*, Obj*);
float Vec4_GetX(V4*);
float Vec4_GetY(V4*);
float Vec4_GetZ(V4*);
void Mtx_MakeAxisRotation(M4*, float, float, float, float);
V4 Node_GetTranslation(PNode*);
int TeleportMsg_IsMode3(Msg* m);
void* func_00133EC0(void* obj);
void func_0015A400(V4* out, void* v);
void Vec4_CopyAsPoint(V4* out, void* v);
void func_0014B160(void* data, void* obj, V4* v);
void NpcPath_HoldAtRouteNode(Path*, int);
void NpcAi_ModeFollow(Self*, FMsg*);
M4* Mtx_GetIdentity();
int func_001600A0(Path*, int);
PNode* NpcPath_GetNode(int);
void func_0042D790(Obj*);
void NpcThinkList_RemoveActor(Obj*);
void NpcAi_AddToDeadList(void*, Self**);
int Npc_IsDeadRemovalAllowed(Self*);
void NpcAi_RunLocomotion(Self*);
Word* func_0014ABD0(Word* dst, Word* src);
void func_0014ABE0(Iter* out, void* v);
Word* func_0014ABF0(Word* dst, Word* src);
int func_0014AC00(Iter* a, Iter* b);
void func_0014AC20(Iter* out, void* v);
Iter* func_0014AC30(Iter* it);
Self** func_0014AC50(Iter* it);
Iter* func_0014AC60(Iter* dst, Iter* src);
void func_0014AC70(Iter* out, void* v);
Iter* func_0014AC80(Iter* self);
}
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Sub(V4* d, V4* a, V4* b) {
    asm { lqc2 vf1, 0x0(a)
          lqc2 vf2, 0x0(b)
          vsub.xyzw vf1, vf1, vf2
          sqc2 vf1, 0x0(d) }
}
static inline int IsZero(V4* v) {
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
/* the sw stays in the asm: retail stores through a register len pointer (as in Projectile_SolveBallistic.c) */
static inline void Normalize(float* len, V4* v) {
    int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%1); qmfc2.ni %0, $vf4; sw %0, 0(%2)" : "=&r"(t) : "r"(v), "r"(len) : "memory");
}
static inline float Len(V4* a) {
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory");
    return r;
}
static inline const V4* Ad(const V4& v) { return &v; }
static inline const M4* AdM(const M4& v) { return &v; }
static inline void SetT(M4* m, const V4& v) { V4_Copy(&m->r[3], &v); }
static inline void SetTgtPos(Self* s, const V4& v) { Tgt* t2 = AiController_GetActor(s)->tgt; t2->px = v.x; t2->py = v.y; t2->pz = v.z; }
inline V4& V4::operator-=(const V4& o) { V4* d = this; V4* a = this; Sub(d, a, (V4*)&o); return *this; }
static inline bool Idle(Obj* o) { return !(o->b2E != 0); }
static inline bool Active(Obj* o) { bool b = 0; bool a = 0; if (o->b2D && o->b2C) a = 1; if (a && Idle(o)) b = 1; return b; }
static inline bool Dying(Obj* o) { bool d; unsigned char s = o->State(); d = 1; if (s != 3 && s != 2) d = 0; return d; }
static inline int CurId(Inv* i) { return i->cur != 6 ? i->s[i->cur].id : -1; }
static inline bool Ready(Rdy* r) { return r->f2C8 >= 0.5f; }
static inline unsigned char HasReady(Ctl* c) { Rdy* r = c->rdy; if (r) return Ready(r); return 0; }
static inline bool NodeActive(PNode* n) { Obj* o = n->obj; bool r = 0; if (o) { unsigned char a = Active(o); if (a) r = 1; } return r; }



static inline void SetMtx(Msg* m, M4* mtx) { V4 a2; V4 b2; V4* v; if (TeleportMsg_IsMode3(m)) { func_0015A400(&a2, func_00133EC0(mtx)); v = &a2; } else { Vec4_CopyAsPoint(&b2, func_00133EC0(mtx)); v = &b2; } func_0014B160(m->data, mtx, v); }
static inline void SetPt(Msg* m, M4* id, V4* p) { V4 pt; Vec4_CopyAsPoint(&pt, p); func_0014B160(m->data, id, &pt); }
static inline void MakeRot(M4* m, const V4& ax, float a) { Mtx_MakeAxisRotation(m, Vec4_GetX((V4*)&ax), Vec4_GetY((V4*)&ax), Vec4_GetZ((V4*)&ax), a); }
extern "C" void func_002D5160(Self* self, float dt)
{
    float len;
    Word x;
    int id;
    int id2;
    Word w4;
    Word y;
    Word w3;
    Iter it;
    Iter b;
    Iter end;
    Iter end2;
    V4 pos;
    V4 diff;
    M4 mtx;
    Msg msg;
    V4 p2;
    Msg msg2;
    V4 d;
    V4 pos3;
    V4 diff3;
    V4 p4;
    Msg msg4;
    bool done = 0;
    Obj* tgt = 0;
    if (self->ref && self->flag) {
        Obj* o;
        int c;
        id = self->ref->id;
        tgt = Object_LookupById(&id);
        o = tgt;
        if (!self->flag->on || (tgt && !Active(tgt)) || Dying(self->obj)) o = 0;
        c = self->ref->c;
        self->f60(o, CurId(AiController_GetActor(self)->inv), c);
    }
    if (!Dying(self->obj)) {
        if (Weapon_CanAttack(AiController_GetActor(self)->inv)) {
            if (self->f88 > 0.0f) self->f88 -= dt;
            if (self->f84 > 0.0f) self->f84 -= dt;
        }
        func_002D4E70(self, tgt);
        if (AiController_GetActor(self)->tgt) {
            Tgt* t;
            float base;
            Ctl* ctl;
            len = 0.0f;
            t = AiController_GetActor(self)->tgt;
            pos.x = t->px;
            pos.y = t->py;
            pos.z = t->pz;
            V4_Copy(&diff, &pos);
            diff -= self->obj->Mtx().T();
            diff.w = 1.0f;
            if (!IsZero(&diff)) Normalize(&len, &diff);
            if (self->bf2) {
                if (self->node) {
                    float ang = AiController_GetActor(self)->tgt->ang;
                    Msg* m;
                    MakeRot(&mtx, CV(0.0f, 0.0f, 1.0f), ang);
                    SetT(&mtx, Node_GetTranslation(self->node));
                    m = &msg;
                    Event_Construct(m, D_0055D4E0);
                    m->vtable = D_004D9360;
                    m->b24 = 2;
                    SetMtx(m, &mtx);
                    msg.kind = 1;
                    Event_Send(&msg, self->obj, 1);
                    NpcPath_HoldAtRouteNode(self->path, self->x208);
                    SetTgtPos(self, Node_GetTranslation(self->node));
                    self->b1EE = 0;
                    msg.vtable = D_004D9360;
                    cMessage_dtor(&msg, 0);
                }
                self->bf2 = 0;
            } else if (self->bf0) {
                self->b1EE = 1;
                id2 = self->xF4;
                Object_LookupById(&id2);
                NpcAi_ModeFollow(self, (FMsg*)&(const FMsg&)FMsg());
            } else {
                self->b1EE = 0;
                if (len > 4.0f && AiController_GetActor(self)->x320C != 0x10 && (self->obj->x38 == 0x80 || HasReady(AiController_GetActor(self)))) {
                    Msg* m2;
                    Tgt* t3 = AiController_GetActor(self)->tgt;
                    p2.x = t3->px;
                    p2.y = t3->py;
                    p2.z = t3->pz;
                    m2 = &msg2;
                    Event_Construct(m2, D_0055D4E0);
                    m2->vtable = D_004D9360;
                    m2->b24 = 0;
                    SetPt(m2, Mtx_GetIdentity(), &p2);
                    msg2.kind = 1;
                    Event_Send(&msg2, self->obj, 1);
                    NpcPath_HoldAtRouteNode(self->path, self->x208);
                    self->b1EE = 0;
                    msg2.vtable = D_004D9360;
                    cMessage_dtor(&msg2, 0);
                } else if (!self->path->hold) {
                    unsigned char r;
                    if ((r = func_001600A0(self->path, self->x208)) != 0) {
                        if (r == 3) {
                            self->b1EE = 2;
                        } else if (r == 2) {
                            self->b1EE = 1;
                        } else if (self->path->x50 >= 0) {
                            V4_Copy(&d, &pos);
                            d -= Node_GetTranslation(NpcPath_GetNode(self->path->x50));
                            if (Len(&d) > self->path->f40) self->b1EE = 2;
                            else self->b1EE = 1;
                        }
                    }
                }
            }
            ctl = AiController_GetActor(self);
            base = ctl->tgt ? ctl->tgt->f3C : ctl->f30E0;
            if (self->b1EE == 1) {
                if (self->f200 < base) self->f200 = base;
                self->f200 += 0.015f;
                if (self->f200 > 1.0f) self->f200 = 1.0f;
            } else if (self->b1EE == 2) {
                if (!(self->f200 < base)) self->f200 = base;
                self->f200 -= 0.015f;
                if (self->f200 < 0.0f) self->f200 = 0.0f;
            } else {
                self->f200 = base;
            }
            if (self->x150 == 0 && !((AiController_GetActor(self)->x3210 >> 22) & 1)) {
                if (self->b158 == 0 && !(self->node && NodeActive(self->node))) {
                    if (self->f204 > 1.0f) {
                        self->obj->f60(1);
                        done = 1;
                        func_0042D790(self->obj);
                    }
                    self->f204 += dt;
                } else {
                    self->f204 = 0.0f;
                }
            }
        }
    } else {
        if (!self->f44()) {
            func_0014AC80(&it);
            func_0014AC70(&b, D_004EA370);
            func_0014AC60(&it, &b);
            while (func_0014AC20(&end, D_004EA370), func_0014AC00(&it, &end)) {
                if (*func_0014AC50(&it) == self) break;
                func_0014AC30(&it);
            }
            func_0014ABF0(&w4, (Word*)&it);
            x = w4;
            func_0014ABE0(&end2, D_004EA370);
            func_0014ABD0(&w3, (Word*)&end2);
            y = w3;
            if (x.value == y.value) {
                NpcThinkList_RemoveActor(self->obj);
                NpcAi_AddToDeadList(D_004EA370, &self);
            }
        } else if (AiController_GetActor(self) && AiController_GetActor(self)->tgt) {
            Tgt* t4 = AiController_GetActor(self)->tgt;
            pos3.x = t4->px;
            pos3.y = t4->py;
            pos3.z = t4->pz;
            V4_Copy(&diff3, &pos3);
            diff3 -= self->obj->Mtx().T();
            diff3.w = 1.0f;
            if (Len(&diff3) > 4.0f && self->obj->x38 == 0x80 && !((AiController_GetActor(self)->x3210 >> 22) & 1)) {
                Msg* m4;
                Tgt* t5 = AiController_GetActor(self)->tgt;
                p4.x = t5->px;
                p4.y = t5->py;
                p4.z = t5->pz;
                m4 = &msg4;
                Event_Construct(m4, D_0055D4E0);
                m4->vtable = D_004D9360;
                m4->b24 = 0;
                SetPt(m4, Mtx_GetIdentity(), &p4);
                msg4.kind = 1;
                Event_Send(&msg4, self->obj, 1);
                NpcPath_HoldAtRouteNode(self->path, self->x208);
                self->b1EE = 0;
                msg4.vtable = D_004D9360;
                cMessage_dtor(&msg4, 0);
            }
        }
        if (Npc_IsDeadRemovalAllowed(self)) {
            self->obj->f60(1);
            done = 1;
        }
    }
    if (!done) NpcAi_RunLocomotion(self);
}

















