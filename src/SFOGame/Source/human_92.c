/*
 * SFOGame/Source/human: 4 files, 001AD710-001AD8C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AD710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

/* 16-byte member with an inline lq/sq assignment (gcc-style asm keeps the copy unfolded). */
struct QV7 {
    float x, y, z, w;
    QV7& operator=(const QV7& o)
    {
        const QV7* src = &o;
        QV7* dst = this;
        __int128 t;
        __asm__ volatile("lq %0,0(%1)" : "=r"(t) : "r"(src));
        __asm__ volatile("sq %0,0(%1)" : : "r"(t), "r"(dst) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct SA7 { int a; int b; int pad[2]; QV7 c; QV7 e; };

extern "C" SA7* cInteractParams_ctor_cInteractParamsR(SA7* d, const SA7* s)
{
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->e = s->e;
    return d;
}
static inline void merge_flush_func_001AD710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AD710 */

/* merge_units: begin func_001AD750 */
#pragma push /* merge_units */
typedef struct { float a; float b; float ia; float ib; } S1AD750;
static inline float fmin_(float a, float b) { float r; asm { min.s r, a, b } return r; }
S1AD750* cSkaCrossFadeDuration_ctor_float_float(S1AD750* s, float a, float b) {
    s->a = a;
    s->b = fmin_(b, a);
    s->ia = s->a != 0.0f ? 1.0f / s->a : 3.4028235e38f;
    s->ib = s->b != 0.0f ? 1.0f / s->b : 3.4028235e38f;
    return s;
}
static inline void merge_flush_func_001AD750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AD750 */

/* merge_units: begin func_001AD7F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

extern char D_004DCD70[];   /* cAIGOBJMsg vtable */
extern char D_004DFD80[];   /* Message base vtable */
extern char D_004E0840[];   /* ArgMsg vtable */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

/* Copy constructor for a message with an int and a byte argument. */
ArgMsg* cCharActionMsg_ctor_cCharActionMsgR(ArgMsg* self, ArgMsg* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004E0840;
    self->arg0 = src->arg0;
    self->arg1 = src->arg1;
    return self;
}

ArgMsg* cAIGOBJMsg_ctor(ArgMsg* self, void* type, int arg) {
    cMessage_ctor_cMessageNameR(&self->base, type);
    self->base.vtable = D_004DCD70;
    self->arg0 = arg;
    self->base.unk20 = 2;
    return self;
}

int cGobjController_Gobj(char* self) {
    return *(int*)(self + 48);
}
static inline void merge_flush_func_001AD7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AD7F0 */

/* merge_units: begin func_001AD8C0 */
#pragma push /* merge_units */
typedef struct { int pad0; int count; int* data; } PtrVec_1AD8C0;
typedef struct { char pad[8]; PtrVec_1AD8C0 list; } Own_1AD8C0;
typedef struct { int pad0; Own_1AD8C0* owner; } Ch_1AD8C0;
extern void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
void cTreeNode_cSkaSystemPtr_AttachChild(Own_1AD8C0* self, Ch_1AD8C0* c)
{
    Ch_1AD8C0* q = c;
    if (q->owner) {
        cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(&q->owner->list, &q);
        q->owner = 0;
    }
    c->owner = self;
    std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(&self->list, &c);
}
static inline void merge_flush_func_001AD8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AD8C0 */
