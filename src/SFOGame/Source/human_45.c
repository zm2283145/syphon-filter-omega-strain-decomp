/*
 * SFOGame/Source/human: 10 files, 00195900-001960C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00195900 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cCharActionMsg_InteractParams_dtor, D_004E00E0, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_00195900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00195900 */

/* merge_units: begin func_00195970 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cBitArray_19_dtor)
static inline void merge_flush_func_00195970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00195970 */

/* merge_units: begin func_001959C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Plc4 { V4 rot, pos; };
struct Mtx { V4 r0, r1, r2, r3; };
struct Elem { VPAD16(a) VPAD4(b) virtual void Sync(); char pad04[0xC]; Mtx m; unsigned char b50; };
struct Obj_959C0 { char pad0[0xC]; int id; char pad10[0x50 - 0x10]; Elem* elem; };
struct Ref_959C0 { int kind; int id; char pad08[8]; Plc4 p; };

extern "C" {
void cMatrix_Copy_InvertRotTrans(Mtx* d, Mtx* s);
Plc4* cQuatVec_ctor_cQuatVecR(Plc4* d, const Plc4* s);
Plc4* cQuatVec_Transform(Plc4* a, Plc4* b);
}

static inline Plc4* MtxToPlc(Mtx* m, Plc4* out) {
    Mtx* mm = m;
    Plc4* o = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mm)
        lqc2 vf2, 0x10(mm)
        lqc2 vf3, 0x20(mm)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(o)
        .set reorder
    }
    Q16(&out->pos, &m->r3);
    return out;
}


static inline void Q16b(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" Ref_959C0* cInteractParams_ctor_int_cQuatVecR_cGOBJP(Ref_959C0* out, int kind, Plc4* in, Obj_959C0* obj)
{
    Elem* e;
    Plc4* src;
    out->kind = kind;
    out->id = -1;
    {
        int tmp;
        int* r;
        if (obj) r = &obj->id; else { tmp = -1; r = &tmp; }
        out->id = *r;
    }
    e = obj ? obj->elem : 0;
    if (e) {
        Mtx inv;
        Plc4 pl;
        Plc4 res;
        Plc4 t;
        if (e->b50) {
            e->Sync();
        }
        cMatrix_Copy_InvertRotTrans(&inv, &e->m);
        MtxToPlc(&inv, &pl);
        cQuatVec_ctor_cQuatVecR(&res, cQuatVec_Transform(cQuatVec_ctor_cQuatVecR(&t, in), &pl));
        src = &res;
    } else {
        src = in;
    }
    Q16b(&out->p.rot, &src->rot);
    Q16(&out->p.pos, &src->pos);
    return out;
}
static inline void merge_flush_func_001959C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001959C0 */

/* merge_units: begin func_00195C80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

extern char D_004E0840[];   /* ArgMsg vtable */
extern char g_ActorActionMsgClass[];   /* CAS action message type */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

ArgMsg* cCharActionMsg_ctor_int_eParamType(ArgMsg* self, int action, int flag) {
    cMessage_ctor_cMessageNameR(&self->base, g_ActorActionMsgClass);
    self->base.vtable = D_004E0840;
    self->arg0 = action;
    self->arg1 = flag;
    return self;
}
static inline void merge_flush_func_00195C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00195C80 */

/* merge_units: begin func_00195CE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int mode; int bits[1]; } E7Phys;
static inline unsigned char E7PTest(E7Phys* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void cModeSwitch_WithHistory_12_ActivateMode_uint_2(E7Phys* p, int bit)
{
    int i;
    p->bits[bit / 32] |= 1 << (bit & 31);
    for (i = 12; i >= 0 && !E7PTest(p, i); i--) {
    }
    if (!E7PTest(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}
static inline void merge_flush_func_00195CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00195CE0 */

/* merge_units: begin func_00195DB0 */
#pragma push /* merge_units */
char* func_00195DB0(char* base, int i) {
    return base + i;
}

char* cArray_FixedSize_cQuatVec_3_opIndex(char* base, int i) {
    return base + (i << 5);
}

int* cArray_FixedSize_cGOBJPtr_3_opIndex(int* base, int i) {
    return base + i;
}
static inline void merge_flush_func_00195DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00195DB0 */

/* merge_units: begin func_00195DE0 */
#pragma push /* merge_units */
typedef struct { V4 rot; V4 pos; } Plc;
static inline V4 QMul_5DE0(V4* a, V4* b) {
    V4 r; V4* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
static inline void QRot_5DE0(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3_5DE0(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void Q_5DE0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cQuatVec_Copy_Transform(Plc* o, Plc* l, Plc* b) {
    Plc t;
    Plc* a;
    V4* v;
    { void* xx = &t; /* dead on purpose: retail keeps this addiu */ }
    { Plc* d = &t; Q_5DE0(&d->rot, &l->rot); }
    Q_5DE0(&t.pos, &l->pos);
    a = &t;
    { V4 r; V4* tp; r = QMul_5DE0(&a->rot, &b->rot); tp = &r; a->rot = *tp; }
    v = &a->pos;
    QRot_5DE0(v, &b->rot);
    VAdd3_5DE0(&b->pos, &a->pos);
    Q_5DE0(&o->rot, &a->rot);
    Q_5DE0(&o->pos, &a->pos);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00195DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00195DE0 */

/* merge_units: begin func_00195EE0 */
#pragma push /* merge_units */
typedef struct { V4 r0; V4 r1; V4 r2; V4 r3; } Mtx_00195EE0;
#pragma peephole off
Plc* cQuatVec_ctor_cMatrixR(Plc* out, Mtx_00195EE0* m) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
    out->pos = m->r3;
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00195EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00195EE0 */

/* merge_units: begin func_001960A0 */
#pragma push /* merge_units */
int opNe_cObjectIdR_cObjectIdR(Iter* a, Iter* b) {
    return a->p != b->p;
}
static inline void merge_flush_func_001960A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001960A0 */

/* merge_units: begin func_001960C0 */
#pragma push /* merge_units */
/* cHuman_ShootWeapon: act on a fire request: throw a grenade or star, start a
 * melee attack, or discharge the held weapon at the requested target. */
#pragma cplusplus on
#pragma inline_depth(10)
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct Req { int id; int f4; unsigned char b8; char p9[7]; V pos; float f20; };
struct Sec { char p0[0x310]; unsigned char a, b; };
struct SecState { char p0[0x4C]; unsigned char ok; char p4D[3]; };
struct Act {
    VPAD32(a) VPAD32(b) virtual unsigned char Life();
    char p04[0x3210 - 4]; int f3210; char p3214[0x3248 - 0x3214]; int f3248;
    char p324C[0x3314 - 0x324C]; Sec* sec; char p3318[0x33E4 - 0x3318];
    unsigned char b33E4; char p33E5[3]; unsigned char b33E8; char p33E9[0x3524 - 0x33E9]; void* inv;
};
extern "C" {
extern int g_NoneWord;
extern char g_Game[];
extern SecState SecondaryStateTable[];
void* nGobjManager_LookupGOBJ_cObjectIdR(Req* r);
int cWeapon_GetEquipmentType(void* inv);
void cWeapon_ReloadIfOutOfAmmo(void* inv);
int cWeapon_Ready(void* inv);
void cHuman_ThrowGrenade(Act* a, Req* r, V* p, float f);
void cHuman_ThrowStar(Act* a, Req* r, V* p);
void* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_HasSpecialBonus(void* a, int k);
void* cWeapon_GetStabTarget(void* inv, unsigned char* out);
void Melee_StartAttack(Act* a, void* t, unsigned char f);
void cWeapon_FireIfReady(void* inv, void* t, int a, unsigned char b, int c);
void cHuman_ShootWeapon(Act* self, Req* req);
}
typedef unsigned char u8;
static inline u8 Bit2(Act* a) { return ((a->f3210 >> 2) & 1) != 0; }
static inline u8 Bit4(Act* a) { return ((a->f3210 >> 4) & 1) != 0; }
static inline u8 Bit5(Act* a) { return ((a->f3210 >> 5) & 1) != 0; }
static inline u8 Bit7(Act* a) { return ((a->f3210 >> 7) & 1) != 0; }
static inline u8 Bit8(Act* a) { return ((a->f3210 >> 8) & 1) != 0; }
static inline u8 Bit20(Act* a) { return ((a->f3210 >> 20) & 1) != 0; }
static inline u8 BBit3(Act* a) { return ((a->f3248 >> 3) & 1) != 0; }
static inline u8 NBBit3(Act* a) { return !BBit3(a); }
static inline u8 D0(Act* a) { u8 r = 0; if (Bit2(a)) { if (NBBit3(a)) r = 1; } return r; }
static inline u8 C0(Act* a) { u8 r = 1; if (!Bit4(a)) { if (!Bit5(a)) r = 0; } return r; }
static inline u8 C1(Act* a) { u8 r = 1; if (!C0(a)) { if (!Bit7(a)) r = 0; } return r; }
static inline u8 C2(Act* a) { u8 r = 1; if (!C1(a)) { if (!Bit8(a)) r = 0; } return r; }
static inline u8 C3(Act* a) { u8 r = 1; if (!C2(a)) { if (!Bit20(a)) r = 0; } return r; }
static inline u8 C4(Act* a) { u8 r = 1; if (!C3(a)) { if (!D0(a)) r = 0; } return r; }
static inline u8 IsHand(unsigned char c) { unsigned char b = 0; if ((unsigned int)(c - 3) < 8 && ((1 << (c - 3)) & 0x83)) b = 1; return b; }
static inline bool IsNone(Req* r) { return r->id == g_NoneWord; }
static inline SecState* St(int i) { return &SecondaryStateTable[i]; }
static inline int Ready(Sec* s) { unsigned char r = 0; if (St(s->a)->ok && St(s->b)->ok) r = 1; return r; }

void cHuman_ShootWeapon(Act* self, Req* req)
{
    bool dead; unsigned char life = self->Life();
    dead = true;
    if (life != 3 && life != 2) dead = false;
    if (dead) return;
    void* tgt = IsNone(req) ? 0 : nGobjManager_LookupGOBJ_cObjectIdR(req);
    int cls = cWeapon_GetEquipmentType(self->inv);
    u8 melee = (unsigned char)cls == 11;
    u8 hand = IsHand(cls);
    cWeapon_ReloadIfOutOfAmmo(self->inv);
    if (!melee && !cWeapon_Ready(self->inv)) return;
    u8 busy = C4(self);
    if ((unsigned char)cls == 1) {
        if (!busy && !self->b33E4) {
            V p = req->pos;
            cHuman_ThrowGrenade(self, req, &p, req->f20);
        }
    } else if ((unsigned char)cls == 7) {
        if (!busy && !self->b33E4) {
            V p = req->pos;
            cHuman_ThrowStar(self, req, &p);
        }
    } else if (hand || melee) {
        if (!busy) {
            if (melee && !cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 0)) return;
            if (!self->b33E8) {
                u8 f;
                void* t = cWeapon_GetStabTarget(self->inv, &f);
                Melee_StartAttack(self, t, f);
            }
        }
    } else {
        if (!self->sec) return;
        if (!Ready(self->sec)) return;
        { unsigned char b8 = req->b8; cWeapon_FireIfReady(self->inv, tgt, req->f4, b8, 0); }
    }
}
static inline void merge_flush_func_001960C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001960C0 */
