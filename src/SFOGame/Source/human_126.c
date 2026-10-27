/*
 * SFOGame/Source/human: 18 files, 001B79C0-001B9030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B79C0 */
#pragma push /* merge_units */
#include "types.h"
#include "human_types.h"

#if 0 /* merge_units */
Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel* r); /* gsynth: defined below */
#endif /* merge_units */
Rel * std_vector_cTargetZRotationStackSlot_ctor(); /* merge_units */

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel*);
#endif /* merge_units */
Rel * std_vector_cTargetZRotationStackSlot_ctor(); /* merge_units */



void cSplinedMotion_float_SetTargetVal(char* self, float* value) {
    *(float*)(self + 16) = *value;
}

/* back(): address of the last 8-byte element. */
char* cArray_cTargetZRotationStackSlot_Back(PtrVec* v) {
    return (char*)v->data + (v->count << 3) - 8;
}

/* Clear the three words and set the byte at +0x0C. */
Rel* cHumanMotionParams_cTargetZRotationStack_ctor(Rel* r) {
    std_vector_cTargetZRotationStackSlot_ctor(r);
    *((char*)r + 12) = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B79C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B79C0 */

/* merge_units: begin func_001B7A20 */
#pragma push /* merge_units */
extern int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(void* binding, CurveSegment* segment);
extern int cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(CurveSegment*, int, int, float);
static const float dat_0048A1B8[2] = { 0.0f, 0.0f };
static const float dat_0048A1C0[2] = { 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA7D0[];   /* AngleCurve vtable */

Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Scalar angle curve constructor (actor member +0x3050). */
CurveChannel* cSplinedMotion_Angle_ctor(CurveChannel* self) {
    self->vtable = D_004DA380;
    self->previous = (*(float*)dat_0048A1B8);
    self->current = (*(float*)dat_0048A1B8);
    self->target = (*(float*)dat_0048A1C0);
    self->rate = (*(float*)dat_0048A1B8);
    self->damping = 0.0f;
    cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(&self->segment, (int)&(*(float*)dat_0048A1B8), (int)&(*(float*)dat_0048A1C0), 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(self->binding, &self->segment);
    self->vtable = D_004DA7D0;
    return self;
}

Rel* cStatesWithHistory_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B7A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B7A20 */

/* merge_units: begin func_001B7B00 */
#pragma push /* merge_units */
/* cHuman_ctor_cMatrix_int_charP_int_etc / cHuman_ctor_cMatrix_int_charP_int_etc_2: the two NPC constructors of this unit. They share one
   member-initialisation body; the first allocates its object id (category 69), the second takes it. */
#pragma cplusplus on
#pragma always_inline on

template <int O, class T> struct At_1B7B00 { char pad[O]; T v; };
#define W_(p, o) (((At_1B7B00<o, int>*)(p))->v)
#define F_(p, o) (((At_1B7B00<o, float>*)(p))->v)
#define B_(p, o) (((At_1B7B00<o, unsigned char>*)(p))->v)

typedef struct V4_1B7B00 { float x, y, z, w; } __attribute__((aligned(16))) V4_1B7B00;
typedef struct Pair_1B7B00 { V4_1B7B00 a, b; } Pair_1B7B00;
typedef struct Blk_1B7B00 { __int128 q[68]; } Blk_1B7B00;
typedef struct Sub60_1B7B00 { char pad[64]; Blk_1B7B00 blk; } Sub60_1B7B00;

extern "C" {
extern char g_HumanActorClassKey[];
extern char D_0049D8D0[];
extern char D_004DA690[];
extern char D_004DA2F0[];
extern char D_004DA7B8[];
extern char D_004DA7A8[];
extern int g_NoneWord;
extern int g_ActorSerialCounter;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void nGobjManager_GetNextId(int* id, int cat);
void cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(void* self, int* id, char* name);
#if 0 /* merge_units */
void cStatesWithHistory_1_ctor(void* p);
#endif /* merge_units */
#define cStatesWithHistory_1_ctor(a0) ((void)cStatesWithHistory_1_ctor((Rel *)(a0))) /* merge_units */

V4_1B7B00* cVector_GetZero(void);
void cVector_ctor_cVectorR(void* d, V4_1B7B00* s);
#if 0 /* merge_units */
void cSplinedMotion_Angle_ctor(void* p);
#endif /* merge_units */
#define cSplinedMotion_Angle_ctor(a0) ((void)cSplinedMotion_Angle_ctor((CurveChannel *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cHumanMotionParams_cTargetZRotationStack_ctor(void* p);
#endif /* merge_units */
#define cHumanMotionParams_cTargetZRotationStack_ctor(a0) ((void)cHumanMotionParams_cTargetZRotationStack_ctor((Rel *)(a0))) /* merge_units */

void cSplinedMotion_Vector_ctor(void* p);
int cHumanMotionParams_PushTargetZRotationOnStack(void* p, float a, float b);
void cSplinedMotion_float_SetDamp(void* p, float d);
void cSplinedMotion_cVector_SetDamp(void* p, float d);
void cBitArray_8_ctor(void* p, int v);
void func_001B75B0(void* p, int v);
void func_001B7580(void* p, int v);
void cCollisionModelList_ctor(void* p, int* a, int* b);
void cActivationTracker_ctor(void* p);
void cCheckpoint_ctor(void* p);
void cQuatVec_GetUnit(Pair_1B7B00* p);
void cQuatVec_ctor_cQuatVecR(void* d, Pair_1B7B00* s);
void cVector_Get0001(V4_1B7B00* v);
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void* cWeapon_ctor(void* p, void* owner, int local);
void NetGetMyClientIndex(int* slot, int session);
int cHuman_InitHuman(void* a, void* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label);
void* cHuman_ctor_cMatrix_int_charP_int_etc(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int flag, int tag);
void* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int* idp, int flag, int tag, Blk_1B7B00* src);
}

struct Obj_1B7B00 { char pad[12]; int id; };
struct Hd_1B7B00 { Obj_1B7B00* p; int id; };
static inline void Set_1B7B00(Hd_1B7B00* h, Obj_1B7B00* o)
{
    int d;
    h->p = o;
    h->id = *(o ? &o->id : (d = -1, &d));
}
struct V4q_1B7B00 {
    float x, y, z, w;
    V4q_1B7B00() {}
    V4q_1B7B00(const V4q_1B7B00& o) { V4q_1B7B00* pd = this; const V4q_1B7B00* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V4q_1B7B00& operator=(const V4q_1B7B00& o) { V4q_1B7B00* pd = this; const V4q_1B7B00* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
static inline float Dot_1B7B00(const V4q_1B7B00* a, const V4q_1B7B00* b)
{
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline void Tag_1B7B00(char* t, int tag) { *(int*)t = tag; F_(t, 4) = -1.0f; F_(t, 8) = 36.69f; B_(t, 12) = 0; }
/* the original copies the block with this inline-asm quadword loop */
static inline void QCopyN_1B7B00(void* dd, void* ss, int nn)
{
    void* d = dd; int n = nn; void* s = ss; __int128 q;
    asm {
        .set noreorder
    lp:
        lq q, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq q, -0x10(d)
        .set reorder
    }
}
static inline void Body_1B7B00(void* self, int x, unsigned char type, int flag, int tag, int line)
{
    V4q_1B7B00 o;
    V4q_1B7B00 n;
    V4q_1B7B00 z;
    {
        char* a = (char*)self + 12336;
        cStatesWithHistory_1_ctor(a);
        B_(a, 12) = 1;
        cVector_ctor_cVectorR(a + 16, cVector_GetZero());
        cSplinedMotion_Angle_ctor(a + 32);
        cHumanMotionParams_cTargetZRotationStack_ctor(a + 88);
        W_(a, 108) = 0;
        W_(a, 112) = 0;
        W_(a, 116) = 0xFF7FFFFF;
        W_(a, 120) = 0;
        B_(a, 124) = 0;
        B_(a, 125) = 0;
        cVector_ctor_cVectorR(a + 128, cVector_GetZero());
        W_(a, 144) = 0;
        cVector_ctor_cVectorR(a + 160, cVector_GetZero());
        W_(a, 176) = 0;
        cSplinedMotion_Vector_ctor(a + 192);
        B_(a, 384) = 0;
        B_(a, 385) = 0;
        B_(a, 386) = 0;
        B_(a, 387) = 0;
        B_(a, 388) = 0;
        B_(a, 389) = 0;
        B_(a, 390) = 0;
        B_(a, 391) = 0;
        cVector_ctor_cVectorR(a + 400, cVector_GetZero());
        W_(a, 416) = 0;
        W_(a, 420) = 0;
        W_(a, 424) = 0;
        B_(a, 428) = 1;
        B_(a, 429) = 0;
        W_(a, 432) = 0;
        W_(a, 104) = cHumanMotionParams_PushTargetZRotationOnStack(a, 0.0f, -1.0f);
        cSplinedMotion_float_SetDamp(a + 32, 15.0f);
        cSplinedMotion_cVector_SetDamp(a + 192, 10.0f);
    }
    *(char**)self = D_004DA690;
    Tag_1B7B00((char*)self + 12784, tag);
    {
        char* b = (char*)self + 12800;
        cBitArray_8_ctor(b, 0);
        cBitArray_8_ctor(b + 4, 0);
        cBitArray_8_ctor(b + 8, 0);
    }
    {
        char* c = (char*)self + 12812;
        func_001B75B0(c, 0);
        func_001B75B0(c + 20, 0);
        func_001B75B0(c + 40, 0);
        func_001B7580(c + 60, 0);
        func_001B7580(c + 68, 0);
        func_001B7580(c + 76, 0);
    }
    B_(self, 12896) = 0;
    B_(self, 12904) = 0;
    B_(self, 12905) = 0;
    B_(self, 12906) = 0;
    {
        char* d = (char*)self + 12960;
        int t1;
        int t2;
        t2 = 0;
        t1 = 0;
        cCollisionModelList_ctor(d, &t1, &t2);
        *(char**)d = D_004DA2F0;
        W_(d, 32) = 0;
        cVector_ctor_cVectorR(d + 48, cVector_GetZero());
        cActivationTracker_ctor(d + 64);
        W_(d, 96) = 0;
    }
    W_(self, 13072) = 0;
    W_(self, 13076) = 0;
    W_(self, 13216) = 0;
    B_(self, 13220) = 0;
    B_(self, 13221) = 0;
    W_(self, 13224) = 0;
    W_(self, 13228) = 0;
    W_(self, 13232) = 0;
    W_(self, 13236) = 0;
    W_(self, 13260) = g_NoneWord;
    W_(self, 13264) = 0;
    W_(self, 13268) = 0;
    W_(self, 13272) = 0;
    W_(self, 13276) = 0;
    W_(self, 13280) = 0;
    B_(self, 13284) = 0;
    B_(self, 13285) = 0;
    B_(self, 13286) = 0;
    B_(self, 13288) = 0;
    cCheckpoint_ctor((char*)self + 13296);
    { int x; int* px = &x; (void)px; } /* dead address-taken local: reserves the retail stack slot between t2 and the handle temporary */
    W_(self, 13412) = 0;
    B_(self, 13416) = 0;
    W_(self, 13428) = 0;
    ((Hd_1B7B00*)((char*)self + 13432))->id = -1;
    Set_1B7B00((Hd_1B7B00*)((char*)self + 13432), 0);
    W_(self, 13444) = -2;
    W_(self, 13440) = 0;
    B_(self, 13456) = 0;
    {
        Pair_1B7B00 pr;
        cQuatVec_GetUnit(&pr);
        cQuatVec_ctor_cQuatVecR((char*)self + 13472, &pr);
    }
    {
        V4_1B7B00 org;
        cVector_Get0001(&org);
        cVector_ctor_cVectorR((char*)self + 13504, &org);
    }
    cVector_ctor_cVectorR((char*)self + 13520, cVector_GetZero());
    W_(self, 13588) = -1;
    *(signed char*)((char*)self + 13592) = -1;
    W_(self, 13596) = 0;
    W_(self, 13600) = 0;
    W_(self, 13616) = (int)D_004DA7B8;
    W_(self, 13616) = (int)D_004DA7A8;
    W_(self, 13620) = 0;
    B_(self, 13625) = 0;
    B_(self, 13626) = 0;
    W_(self, 13628) = 0;
    F_(self, 13632) = 1.0f;
    W_(self, 13636) = 0;
    W_(self, 13640) = x;
    {
        int* h = (int*)((char*)self + 13644);
        do {
            h[1] = -2;
            h[0] = 0;
            h += 2;
        } while (h != (int*)((char*)self + 13668));
    }
    n.x = 0.0f;
    n.z = 1.0f;
    n.y = 0.0f;
    n.w = 0.0f;
    {
        V4q_1B7B00* pz = &z;
        asm { sqc2 vf0, 0x0(pz) }
    }
    o = z;
    {
        float d = Dot_1B7B00(&n, &o);
        { float x, y, z2, w; z2 = n.z; y = n.y; x = n.x; w = -d; F_(self, 13680) = x; F_(self, 13684) = y; F_(self, 13688) = z2; F_(self, 13692) = w; }
    }
    W_(self, 13696) = 0;
    W_(self, 13700) = 0;
    W_(self, 13716) = 0;
    B_(self, 13720) = flag ? true : false;
    {
        void* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, 248, D_0049D8D0, line);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (p) { int l = type == 1; if (!l) l = type == 3; p = cWeapon_ctor(p, self, l); }
        W_(self, 13604) = (int)p;
        W_(self, 13620) = W_(self, 13604);
    }
}

void* cHuman_ctor_cMatrix_int_charP_int_etc(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int flag, int tag)
{
    int id;
    nGobjManager_GetNextId(&id, 69);
    cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(self, &id, g_HumanActorClassKey);
    Body_1B7B00(self, x, type, flag, tag, 540);
    if (flag) {
        int s = D_005721A8;
        int id = 0;
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, s);
            id = D_00494178;
        } else {
            asm { .set reorder } /* scheduling barrier: keeps the empty else block (b + nop) */
        }
        W_(self, 12) |= (id + 1) << 24;
    }
    if (((At_1B7B00<12784, unsigned int>*)self)->v == (unsigned int)-1) {
        if (type == 2 || type == 4) {
            ((At_1B7B00<12784, unsigned int>*)self)->v = g_ActorSerialCounter;
            g_ActorSerialCounter = g_ActorSerialCounter + 1;
        }
    }
    cHuman_InitHuman(self, mtx, name, health, 0, weap, flag, type, label);
    W_(self, 48) = 1;
    return self;
}

void* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* self, void* mtx, int x, char* name, int health, int* weap, unsigned char type, char* label, int* idp, int flag, int tag, Blk_1B7B00* src)
{
    cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(self, idp, g_HumanActorClassKey);
    Body_1B7B00(self, x, type, flag, tag, 448);
    if (src) {
        { Sub60_1B7B00* sb = (Sub60_1B7B00*)((char*)self + 96); QCopyN_1B7B00(&sb->blk, src, 68); }
        name = 0;
    }
    if (type == 3 || type == 4)
        B_(self, 20) = 0;
    if (((At_1B7B00<12784, unsigned int>*)self)->v == (unsigned int)-1) {
        if (type == 2 || type == 4) {
            ((At_1B7B00<12784, unsigned int>*)self)->v = g_ActorSerialCounter;
            g_ActorSerialCounter = g_ActorSerialCounter + 1;
        }
    }
    cHuman_InitHuman(self, mtx, name, health, 0, weap, flag, type, label);
    W_(self, 48) = 1;
    return self;
}
#undef cStatesWithHistory_1_ctor /* merge_units */
#undef cSplinedMotion_Angle_ctor /* merge_units */
#undef cHumanMotionParams_cTargetZRotationStack_ctor /* merge_units */
static inline void merge_flush_func_001B7B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B7B00 */

/* merge_units: begin func_001B8740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */



unsigned char cHuman_IsInvulnerable(Actor* actor) {
    return actor->unk33A4;
}

/* Set unk33A4 and mirror it to the linked object when the global gate is on. */
void cHuman_SetInvulnerable(Actor* actor, int value) {
    ActorLink3584* link;

    actor->unk33A4 = value;
    if (g_IsMultiplayer != 0 && actor->unk14 != 0) {
        link = actor->unk3584;
        if (link != 0) {
            link->unk34 = value;
        }
    }
}
static inline void merge_flush_func_001B8740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8740 */

/* merge_units: begin func_001B8790 */
#pragma push /* merge_units */
extern int cWeapon_DrawWeapon_eWpnSlot(int, int);
extern void cWeapon_StoreWeapon_void(int);

void cHuman_cDrawAndHolsterWeaponCallback_Trigger(int a0, int a1, int a2) {
    int v0;
    int cond;

    a0 = *(int*)((char*)a0 + 4);
    cond = a0 == 0;
    if (cond) goto L001B87C8;
    cond = a1 == 0;
    if (cond) goto L001B87C0;
    cWeapon_StoreWeapon_void(a0);
    goto L001B87C8;
L001B87C0:;
    a1 = a2;
    v0 = cWeapon_DrawWeapon_eWpnSlot(a0, a1);
L001B87C8:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B8790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B8790 */

/* merge_units: begin func_001B87E0 */
#pragma push /* merge_units */
void cSplinedMotion_Angle_TeleportByDelta(float* p, float* ang) {
    float a = *ang;
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    p[1] += a;
    p[2] += a;
    p[4] += a;
    p[6] += a;
    p[8] += a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B87E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B87E0 */

/* merge_units: begin func_001B88A0 */
#pragma push /* merge_units */
float cSplinedMotion_Angle_InitPos(void) {
    return 0.0f;
}

float cSplinedMotion_Angle_ZeroVel(void) {
    return 0.0f;
}
static inline void merge_flush_func_001B88A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B88A0 */

/* merge_units: begin func_001B88C0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; float f10; } Tgt;
typedef struct {
    char pad0[8];
    float f8;
    float fC;
    float f10;
    char pad14[4];
    char a18[8];
    float f20;
    float f24;
    float f28;
    char pad2C[4];
    Tgt* p30;
    float f34;
} AC;
extern "C" {
extern float D_0048A1B0;
extern char D_0048A1A8;
extern void func_0017CA90(void*, int);
extern void* opNew_uint_voidP(int, void*);
extern void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void*, float*, float*, float*, void*, float);
}
static inline bool Gt(float a, float b) { return a > b; }
static inline bool Eq(float a, float b) { return a == b; }
static inline void Set2(float* q, float a, float b) { q[0] = a; q[1] = b; }
static inline float WrapPi(float a)
{
    for (;;) {
        if (Gt(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}

extern "C" void cSplinedMotion_Angle_UpdateSplinePoints(AC* c)
{
    bool go = 0;
    if (c->f34 == c->p30->f10 && c->f28 > 0.0f) go = 1;
    if (go) {
        void* v;
        c->f10 = c->f8 + WrapPi(c->f10 - c->f8);
        func_0017CA90(c->a18, -1);
        v = opNew_uint_voidP(0x18, c->a18);
        if (v) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(v, &c->f8, &c->fC, &c->f10, &D_0048A1A8, c->f28);
    } else {
        bool ne = !Eq(0.0f, c->f34);
        if (ne) {
            float* q = &c->f20;
            float base = c->f20;
            float d = WrapPi(c->f10 - base);
            c->f10 = base + d;
            Set2(q, c->f10, D_0048A1B0 * c->f28);
        }
    }
}
static inline void merge_flush_func_001B88C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B88C0 */

/* merge_units: begin func_001B8AC0 */
#pragma push /* merge_units */
typedef struct { int a, b; float ang; } S1B8;
static inline int Gt1B8(float a, float b) { return a > b; }
void cSplinedMotion_Angle_FixUpResultOfSplineEvaluation(S1B8* s) {
    float a = s->ang;
    for (;;) {
        if (Gt1B8(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
}
static inline void merge_flush_func_001B8AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8AC0 */

/* merge_units: begin func_001B8B40 */
#pragma push /* merge_units */
typedef struct { int pad0; float a; float b; float rate; int pad10; float damp; } AC_t;
static inline float AC_Max(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
void cSplinedMotion_Angle_UpdateVelocity(AC_t* p, float dt, float k) {
    float d = p->b - p->a;
    while (1) {
        if (d > 3.1415927f) d += -6.2831855f;
        else if (d < -3.1415927f) d += 6.2831855f;
        else break;
    }
    p->rate = k * d;
    p->rate *= AC_Max(0.0f, 1.0f - p->damp * dt);
}
static inline void merge_flush_func_001B8B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8B40 */

/* merge_units: begin func_001B8C00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4 operator*(float s) const {
        V4 r; int t; V4* q = &r; const V4* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        return *q;
    }
    V4& operator-=(const V4& a) {
        V4* d = this; const V4* p = &a;
        asm {
            lqc2 vf1, 0x0(d)
            lqc2 vf2, 0x0(p)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
} __attribute__((aligned(16)));
static inline float Dot3(const V4* a, const V4* b) {
    int t;
    float r;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
struct Phys { char p0[0x10]; V4 axis; };
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
extern "C" void cHumanCollision_DeltaPosModificationFunction_Floor_Execute(Phys* p, V4* v) {
    float w = v->w; float d; V4* axis = &p->axis;
    d = Dot3(v, axis); *v -= *axis * d;
    v->w = w;
}
static inline void merge_flush_func_001B8C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8C00 */

/* merge_units: begin func_001B8C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cHumanCollision_DeltaPosModificationFunction_Floor_dtor, D_004DA800, D_004DA810)
static inline void merge_flush_func_001B8C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8C80 */

/* merge_units: begin func_001B8CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cSkaAnimAnchor_cDeltaPosModificationFunction_dtor, D_004DA810)
static inline void merge_flush_func_001B8CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8CE0 */

/* merge_units: begin func_001B8D30 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Phys_001B8D30 { char pad[0x10]; V axis; };
static inline float Dot3_001B8D30(V* a, V* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void Scale3(V* v, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0x0(v)
        .set reorder
    }
}
extern "C" void cHumanCollision_DeltaPosModificationFunction_Ledge_Execute(Phys_001B8D30* p, V* b);
void cHumanCollision_DeltaPosModificationFunction_Ledge_Execute(Phys_001B8D30* p, V* b)
{
    p = (Phys_001B8D30*)&p->axis; V* ax = (V*)p;
    float d = Dot3_001B8D30(b, ax);
    float w = b->w;
    { __int128 q; asm volatile { lq q, 0(ax); sq q, 0(b) } }
    __int128 tt = 0; /* dead: retail's paddub zero */
    b->w = w;
    Scale3(b, d);
}
static inline void merge_flush_func_001B8D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8D30 */

/* merge_units: begin func_001B8D90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cHumanCollision_DeltaPosModificationFunction_Ledge_dtor, D_004DA820, D_004DA810)
static inline void merge_flush_func_001B8D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8D90 */

/* merge_units: begin func_001B8DF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cIkRoutine_dtor_void, D_004DA830)
static inline void merge_flush_func_001B8DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8DF0 */

/* merge_units: begin func_001B8E40 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma opt_propagation off
extern float Libc_Fmodf(float, float);
static inline float clamp_(float a, float lo, float hi) { asm { max.s lo, a, lo
 min.s lo, lo, hi } return lo; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    char pad24[4];
    float f28;
    char pad2C[0x38 - 0x2C];
    unsigned char b38;
} Ch;
extern char D_0048A190;

static inline float Clamp(Ch* c, float x)
{
    float v;
    if (!c->b38) {
        v = clamp_(x, 0.0f, 1.0f);
    } else {
        v = Libc_Fmodf(x, 1.0f);
        if (v < 0.0f) v += 1.0f;
    }
    return v;
}
static inline float Wrap(Ch* p, float d)
{
    float r;
    float h;
    if (!p->b38) {
        return d;
    }
    r = Libc_Fmodf(d, 1.0f);
    h = 0.5f;
    if (r < h) {
        r += 1.0f;
    } else if (r > h) {
        r -= 1.0f;
    }
    return r;
}

void cSplinedMotion_Scalar0To1_TeleportByDelta(Ch* c, float* dt)
{
    void* v;
    c->f4 += *dt;
    c->f8 += *dt;
    c->f10 += *dt;
    c->f18 += *dt;
    c->f20 += *dt;
    c->f4 = Clamp(c, c->f4);
    c->f8 = Clamp(c, c->f8);
    c->f10 = c->f8 + Wrap(c, c->f10 - c->f8);
    func_0017CA90(&c->f18, -1);
    v = opNew_uint_voidP(0x18, &c->f18);
    if (v) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(v, &c->f8, &c->fC, &c->f10, &D_0048A190, c->f28);
}
static inline void merge_flush_func_001B8E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B8E40 */

/* merge_units: begin func_001B9030 */
#pragma push /* merge_units */
float cSplinedMotion_Scalar0To1_InitPos(void) {
    return 0.0f;
}

float cSplinedMotion_Scalar0To1_ZeroVel(void) {
    return 0.0f;
}
static inline void merge_flush_func_001B9030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9030 */
