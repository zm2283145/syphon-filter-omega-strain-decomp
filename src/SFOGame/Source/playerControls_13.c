/*
 * SFOGame/Source/playerControls: 26 files, 0024FB50-002503E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0024FB50 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cCharActionMsg_ObjectId_Int_dtor, D_004E0120, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_0024FB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024FB50 */

/* merge_units: begin func_0024FBC0 */
#pragma push /* merge_units */
typedef struct { unsigned char active; unsigned char passive; char pad[0x9E]; } D6EdgeReq;
typedef struct { char pad[0x3E0]; D6EdgeReq req[1]; } D6EdgeOwner;
void cHumanCollisionRoutine_RequestSearchForLedge(D6EdgeOwner* o, signed char idx, unsigned char passive)
{
    D6EdgeReq* e = (D6EdgeReq*)((char*)o + 0x3E0) + idx;
    if (e->active) {
        e->passive = e->passive && passive;
    } else {
        e->passive = passive;
    }
    e->active = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FBC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FBC0 */

/* merge_units: begin func_0024FC20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "playerControls_types.h"

void cGameCamera_SetDesiredFOV(PlayerCamera* self, float value) {
    self->fovTarget = value;
}
static inline void merge_flush_func_0024FC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024FC20 */

/* merge_units: begin func_0024FC30 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"

typedef struct { int a; int b; char c; char pad[7]; __int128 q; float f; } XFC30;
#pragma opt_propagation off
XFC30* cTargetInfo_ctor_cObjectIdR_int_bool_cVectorR_etc(XFC30* d, int* pa, int b, char c, __int128* q, float f) {
    d->a = *pa;
    d->b = b;
    d->c = c;
    { typedef char uf_chk_[sizeof(d->q) == 16 ? 1 : -1]; VCopyF(&(d->q), &(*q)); }
    d->f = f;
    return d;
}
#pragma opt_propagation reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC30 */

/* merge_units: begin func_0024FC60 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0PostMultiply(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC60 */

/* merge_units: begin func_0024FC90 */
#pragma push /* merge_units */
void cSafePtr_cGOBJ_Set(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L0024FCA8;
    v1 = a1 + 12;
    goto L0024FCB8;
L0024FCA8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L0024FCB8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FC90 */

/* merge_units: begin func_0024FCD0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern char SecondaryStateTable;

int cHumanIkRoutine_IsWeaponAimed(char * arg0) {
    int var_v0;

    var_v0 = F_((&SecondaryStateTable + (F_(arg0, 0x310, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    if (var_v0 != 0) {
        var_v0 = F_((&SecondaryStateTable + (F_(arg0, 0x311, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    }
    return var_v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FCD0 */

/* merge_units: begin func_0024FD20 */
#pragma push /* merge_units */
void cVector_VU0PostRotate(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FD20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FD20 */

/* merge_units: begin func_0024FD50 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; int bits[1]; } F24FD50;
int func_0024FD50(F24FD50* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FD50 */

/* merge_units: begin func_0024FD80 */
#pragma push /* merge_units */
/* Iterator equality against a raw value. */
int func_0024FD80(Word* it, int value) {
    return it->value == value;
}

void* func_0024FD90(void* self) {
    return self;
}
static inline void merge_flush_func_0024FD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024FD80 */

/* merge_units: begin func_0024FDA0 */
#pragma push /* merge_units */
typedef struct { __int128 v; float a; float b; signed char f; } MM24;
#pragma push
#pragma optimization_level 3
MM24 *cMotionParams_ctor(MM24 *m, __int128 *v, float a, float b, int flag) {
    signed char c;
    m->v = *v;
    m->a = a;
    m->b = b;
    /* barrier: empty asm keeps the branchy bool (b + delay slot) shape */
    if (flag) { c = 1; asm { .set reorder } } else c = 0;
    m->f = c;
    return m;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FDA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FDA0 */

/* merge_units: begin func_0024FDE0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec3;
static inline float WrapPi(float a)
{
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}
void nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_cEulerAngleTR(Vec3* out, Vec3* in)
{
    float x = WrapPi(in->x);
    float y = WrapPi(in->y);
    float z = WrapPi(in->z);
    out->x = x;
    out->y = y;
    out->z = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FDE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FDE0 */

/* merge_units: begin func_0024FF60 */
#pragma push /* merge_units */
typedef struct { float m[16]; } Mtx16;

/* Builds a 4x4 matrix from 16 floats; returns it. */
Mtx16* cMatrix_Set_float_float_float_float_etc(Mtx16* out, float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7,
                     float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
{
    out->m[0] = m0;
    out->m[1] = m1;
    out->m[2] = m2;
    out->m[3] = m3;
    out->m[4] = m4;
    out->m[5] = m5;
    out->m[6] = m6;
    out->m[7] = m7;
    out->m[8] = m8;
    out->m[9] = m9;
    out->m[10] = m10;
    out->m[11] = m11;
    out->m[12] = m12;
    out->m[13] = m13;
    out->m[14] = m14;
    out->m[15] = m15;
    return out;
}
static inline void merge_flush_func_0024FF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024FF60 */

/* merge_units: begin func_0024FFD0 */
#pragma push /* merge_units */
float Math_MinF(float a, float b) {
    float r;
    asm { min.s r, a, b }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FFD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FFD0 */

/* merge_units: begin func_0024FFE0 */
#pragma push /* merge_units */
typedef struct { int top; int bits[1]; } PrioSet_e8;
static inline unsigned char PrioSet_e8_Test(PrioSet_e8* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void cModeSwitch_12_DeactivateMode(PrioSet_e8* p, int bit)
{
    int i;
    p->bits[bit / 32] &= ~(1 << (bit & 31));
    for (i = 11; i >= 0 && !PrioSet_e8_Test(p, i); i--) {
    }
    if (!PrioSet_e8_Test(p, i)) {
        p->top = -1;
    } else {
        p->top = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FFE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FFE0 */

/* merge_units: begin func_002500C0 */
#pragma push /* merge_units */
void cModeSwitch_12_ActivateMode(PrioSet_e8* p, int bit)
{
    int i;
    p->bits[bit / 32] |= 1 << (bit & 31);
    for (i = 11; i >= 0 && !PrioSet_e8_Test(p, i); i--) {
    }
    if (!PrioSet_e8_Test(p, i)) {
        p->top = -1;
    } else {
        p->top = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002500C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002500C0 */

/* merge_units: begin func_00250190 */
#pragma push /* merge_units */
Vec3f* func_00250190(Vec3f* self, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
    return self;
}
static inline void merge_flush_func_00250190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00250190 */

/* merge_units: begin func_002501B0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Node2501;
typedef struct { Node2501* node; int key; } Ref2501;
Node2501* cSafePtr_cHuman_opCast_cHumanPtr(Ref2501* r) {
    Node2501* n = r->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != r->key) ok = 0;
    return ok ? n : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002501B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002501B0 */

/* merge_units: begin func_002501F0 */
#pragma push /* merge_units */
typedef struct { int head; int bits[1]; } SelectorT;
#pragma optimization_level 3
SelectorT* cModeSwitch_2_opAssign(SelectorT* d, const SelectorT* s)
{
    int i;
    d->head = s->head;
    for (i = 0; i < 2; i++) {
        int w = i / 32;
        int b = i & 31;
        if ((s->bits[w] >> b) & 1)
            d->bits[w] |= 1 << b;
        else
            d->bits[w] &= ~(1 << b);
    }
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002501F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002501F0 */

/* merge_units: begin func_00250280 */
#pragma push /* merge_units */
typedef struct { int head; int bits[1]; } E7PS;
E7PS* cModeSwitch_12_opAssign(E7PS* dst, E7PS* src) {
    int i;
    dst->head = src->head;
    for (i = 0; i < 12; i++) {
        if ((*(int*)((char*)src + (i / 32) * 4 + 4) >> (i & 31)) & 1) {
            *(int*)((char*)dst + (i / 32) * 4 + 4) |= 1 << (i & 31);
        } else {
            *(int*)((char*)dst + (i / 32) * 4 + 4) &= ~(1 << (i & 31));
        }
    }
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250280 */

/* merge_units: begin func_00250310 */
#pragma push /* merge_units */
extern char D_004F7E10[];
extern char D_004F7E20[];
extern char D_004F7E24[];
extern char D_004F7E28[];

int func_00250310(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004F7E10;
    cond = v0 != 0;
    if (cond) goto L00250340;
    v0 = 0 + 1;
    *(int*)(char*)D_004F7E20 = 0;
    *(char*)(char*)D_004F7E10 = v0;
    *(int*)(char*)D_004F7E24 = 0;
    *(int*)(char*)D_004F7E28 = 0;
L00250340:;
    v0 = (int)D_004F7E20;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250310 */

/* merge_units: begin func_00250350 */
#pragma push /* merge_units */
typedef struct { int unk0; int words[1]; } PrioritySet;

/* Returns 1 if bit n is set in the priority set. */
int cModeSwitch_12_IsModeActivated(PrioritySet* set, int n)
{
    return ((set->words[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250350 */

/* merge_units: begin func_00250380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */


float cGameCamera_GetFollowDistance(ControlsUnk934* self) {
    return -self->unk934;
}

Vec2f* cJoyXYVector_ctor_cJoyXYVectorR(Vec2f* dst, Vec2f* src) {
    dst->x = src->x;
    dst->y = src->y;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250380 */

/* merge_units: begin func_002503B0 */
#pragma push /* merge_units */
/* Initializes a float pair from two ints. */
Vec2f* cJoyXYVector_ctor_int_int(Vec2f* v, int x, int y) {
    v->x = (float)x;
    v->y = (float)y;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002503B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002503B0 */

/* merge_units: begin func_002503E0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } E7V3;
typedef struct { float x, y; } E7V2;
const float D_0048AE70[2] = { 60.0f, 0.0f };
const float D_0048AE78[2] = { 160.0f, 0.0f };
void PlayerInput_GetLookOffset(E7V3* out, E7V2* in, int invX, int invY) {
    float a, b, x, y, z;
    a = 0.017453292f * (*(float*)D_0048AE78);
    x = in->x;
    b = 0.017453292f * (*(float*)D_0048AE70);
    z = (invX ? -1.0f : 1.0f) * (a * -x);
    y = in->y;
    out->x = (invY ? -1.0f : 1.0f) * (b * -y);
    out->y = 0.0f;
    out->z = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002503E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002503E0 */

/* merge_units: begin func_00250470 */
#pragma push /* merge_units */
typedef struct { char pad[0x38]; int state; } Obj250;
typedef struct { char pad[0x320C]; int mode; } Ctx250;
int cPlayerControls_CanChangeWeapon(Obj250* o, Ctx250* c) {
    if (o->state != 6 && c->mode != 0x17 && c->mode != 0x14 && c->mode != 0x15) return 1;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250470 */
