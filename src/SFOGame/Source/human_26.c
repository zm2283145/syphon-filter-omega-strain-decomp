/*
 * SFOGame/Source/human: 6 files, 0018A0B0-0018A410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0018A0B0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

typedef struct { int top; int cur[2]; int dirty[2]; } Bits_18A0B0;
static inline unsigned char Get_18A0B0(int* a, int bit) { return ((a[bit/32] >> (bit&31)) & 1) != 0; }
static inline void Set_18A0B0(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
void ActionPriority_Reset(Bits_18A0B0* b, int bit)
{
    int old[2];
    int i;
    unsigned int j;
    old[0] = b->cur[0];
    old[1] = b->cur[1];
    b->cur[0] = 0;
    b->cur[1] = 0;
    Set_18A0B0(b->cur, bit);
    for (i = 31; i >= 0 && !Get_18A0B0(b->cur, i); i--) {
    }
    if (!Get_18A0B0(b->cur, i)) b->top = -1; else b->top = i;
    for (j = 0; j < 32; j++) {
        if (Get_18A0B0(b->cur, j) != Get_18A0B0(old, j)) Set_18A0B0(b->dirty, j);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A0B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A0B0 */

/* merge_units: begin func_0018A210 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_0018A210)
static inline void merge_flush_func_0018A210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A210 */

/* merge_units: begin func_0018A260 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cSkaAnimEndedMessage_Clone();
extern void * const D_004DA930[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cSkaAnimEndedMessage_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA930);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA930[8] = { (void*)0x0, (void*)0x0, (void*)cSkaAnimEndedMessage_dtor, (void*)cSkaAnimEndedMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A260 */

/* merge_units: begin func_0018A2C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

#if 0 /* merge_units */
extern char D_004DA930[];   /* AnimEvent vtable */
#endif /* merge_units */
#define D_004DA930 ((char*)&D_004DA930) /* merge_units */

extern char D_00542B60[];   /* AnimEvent message type */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

float func_0018A2C0(char* self) {
    return *(float*)(self + 156);
}

float cSkaRequestStream_AnimationPacket_GetDuration(char* self) {
    return *(float*)(self + 152);
}

void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(char* self) {
    return self + 76;
}

signed char cSkaRequestStream_AnimationPacket_GetInstruction(signed char* self) {
    return self[72];
}

AnimEvent* cSkaAnimEndedMessage_ctor_void(AnimEvent* self) {
    cMessage_ctor_cMessageNameR(&self->base, D_00542B60);
    self->base.vtable = D_004DA930;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0.0f;
    return self;
}

Vec4* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
#undef D_004DA930 /* merge_units */
static inline void merge_flush_func_0018A2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A2C0 */

/* merge_units: begin func_0018A380 */
#pragma push /* merge_units */
typedef struct { float a, b, c, d; } AnimRate;
static inline float b4inv(float r) { return (r != 0.0f) ? 1.0f / r : 3.4028235e38f; }
AnimRate* cSkaCrossFadeDuration_ctor_float(AnimRate* p, float r) {
    p->a = r;
    p->b = r;
    p->c = b4inv(r);
    p->d = b4inv(r);
    return p;
}
static inline void merge_flush_func_0018A380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A380 */

/* merge_units: begin func_0018A410 */
#pragma push /* merge_units */
float cSkaAnimationSet_DefaultCrossFadeDuration(char* self) {
    return *(float*)(self + 0);
}
static inline void merge_flush_func_0018A410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A410 */
