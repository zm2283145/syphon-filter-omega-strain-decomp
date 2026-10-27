/*
 * SFOGame/Source/human: 33 files, 001AD710-001AD920
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
#if 0 /* merge_units */
extern void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
#endif /* merge_units */
void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(); /* merge_units */

#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
#endif /* merge_units */
int std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(); /* merge_units */

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

/* merge_units: begin func_001AD920 */
#pragma push /* merge_units */
extern int std_vector_pod_int_insert(PtrVec*, int*, int, int);

/* push_back: insert one value at end(). */
int std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001AD920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AD920 */

/* merge_units: begin func_001AD940 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct { int pad0; int count; int* data; } PtrVec_1AD940;
extern void std_vector_pod_int_resize(PtrVec_1AD940* v, int n, int* fill);

void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(PtrVec_1AD940* v, int* value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == *value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    std_vector_pod_int_resize(v, last + 1, &fill);
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AD940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AD940 */

/* merge_units: begin func_001AD9C0 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } VP_1AD9C0;
typedef struct { char pad[0x50]; VP_1AD9C0 orient; char pad70[0x30]; unsigned char dirty; } Id_1AD9C0;
typedef struct { char pad[0x160]; int x160; } R_1AD9C0;
extern Id_1AD9C0* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(R_1AD9C0* self);
extern void cQuatVec_opAssign(VP_1AD9C0* d, VP_1AD9C0* s);
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(R_1AD9C0* self);
extern void cQuatVec_ctor_void(VP_1AD9C0* p);
extern VP_1AD9C0* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(R_1AD9C0* self, VP_1AD9C0* tmp);
extern void cQuatVec_Transform(VP_1AD9C0* d, VP_1AD9C0* s);
extern void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(R_1AD9C0* self);
void cSkaAnimAnchor_SetTransform(R_1AD9C0* self, VP_1AD9C0* o)
{
    cQuatVec_opAssign(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, o);
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        VP_1AD9C0 tmp;
        cQuatVec_ctor_void(&tmp);
        cQuatVec_Transform(&cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->orient, cSkaAnimAnchor_TreeNode_GetParentInverseTransform(self, &tmp));
    }
    cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(self)->dirty = 1;
    cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(self);
    self->x160 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AD9C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AD9C0 */

/* merge_units: begin func_001ADA60 */
#pragma push /* merge_units */
/* Copy xyz from src and set w. */
Vec4* cAxisAngle_ctor_cVectorR_float(Vec4* dst, Vec4* src, float w) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = w;
    return dst;
}
static inline void merge_flush_func_001ADA60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADA60 */

/* merge_units: begin func_001ADA90 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Negate(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADA90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADA90 */

/* merge_units: begin func_001ADAB0 */
#pragma push /* merge_units */
void cSafePtr_cHuman_Set(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L001ADAC8;
    v1 = a1 + 12;
    goto L001ADAD8;
L001ADAC8:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001ADAD8:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADAB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADAB0 */

/* merge_units: begin func_001ADAF0 */
#pragma push /* merge_units */
typedef struct Target {
    char pad[0xC];
    int serial;
} Target;

/* Weak reference: object pointer plus the serial it had when stored. */
typedef struct WeakRef {
    Target* obj;
    int serial;
} WeakRef;

/* Returns the referenced object, or 0 if it was replaced (serial mismatch). */
Target* cSafePtr_cHuman_GetPtr(WeakRef* ref) {
    Target* obj = ref->obj;
    unsigned char valid = 1;
    if (!((obj != 0) ^ 1)) {
        if (obj->serial != ref->serial) {
            valid = 0;
        }
    }
    return valid ? obj : 0;
}
static inline void merge_flush_func_001ADAF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADAF0 */

/* merge_units: begin func_001ADB30 */
#pragma push /* merge_units */
typedef struct { unsigned char latched; unsigned char value; } LatchEdge;
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_RequestSearch(LatchEdge* e, int v) {
    if (e->latched) {
        e->value = e->value && v;
    } else {
        e->value = v;
    }
    e->latched = 1;
}
static inline void merge_flush_func_001ADB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADB30 */

/* merge_units: begin func_001ADB70 */
#pragma push /* merge_units */
/* Address of 160-byte element i. */
char* cArray_FixedSize_cFinalLedgeSearchInfo_9_opIndex(char* base, int i) {
    return base + i * 160;
}
static inline void merge_flush_func_001ADB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADB70 */

/* merge_units: begin func_001ADB90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cPointer_cSkaNode_dtor)
static inline void merge_flush_func_001ADB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADB90 */

/* merge_units: begin func_001ADBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */


void cMessage_dtor(void* m, int f);
extern char D_004DA930[];
}
struct M_1ADBE0 { void* vt; };
struct O_1ADBE0 { char pad[0x5C]; M_1ADBE0 msg; };
static inline void MDtor_1ADBE0(M_1ADBE0* m) { if (m) { m->vt = D_004DA930; cMessage_dtor(m, 0); } }
extern "C" void* cSkaSystem_RequestTransition_dtor(O_1ADBE0* self, short deleteFlag)
{
    if (self) {
        MDtor_1ADBE0(&self->msg);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADBE0(void) {}
#undef operator_delete /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADBE0 */

/* merge_units: begin func_001ADC50 */
#pragma push /* merge_units */
void* cSkaSystem_RequestTransition_CrossFadeDuration(char* self) {
    return self + 60;
}

void* cSkaSystem_RequestTransition_CrossFadeOutDuration(char* self) {
    return self + 76;
}

void* cSkaSystem_RequestTransition_EndOfTransitionCallback(char* self) {
    return self + 92;
}
static inline void merge_flush_func_001ADC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADC50 */

/* merge_units: begin func_001ADC80 */
#pragma push /* merge_units */
typedef struct { void* p; int id; } H_1ADC80;
typedef struct { int pad0; unsigned char state; char pad5[0x3B]; int id; } N_1ADC80;
typedef struct { char pad[0x30]; N_1ADC80* node; H_1ADC80 h; } R_1ADC80;
static inline void Make_1ADC80(H_1ADC80* h, N_1ADC80* o)
{
    h->p = (o->id == -1) ? o : 0;
    h->id = o->id;
}
static inline unsigned char Live_1ADC80(N_1ADC80* n)
{
    unsigned char ok = 1;
    if (n->state != 0 && n->state != 1) ok = 0;
    return ok;
}
void cSkaSystem_RequestTransition_GetPlaybackGroupId(H_1ADC80* out, R_1ADC80* r)
{
    H_1ADC80 a;
    H_1ADC80 b;
    H_1ADC80* p;
    int valid = (r->h.p != 0 || r->h.id != -1);
    if (valid) {
        p = &r->h;
    } else {
        unsigned char ok = 0;
        if (r->node && Live_1ADC80(r->node)) ok = 1;
        if (ok) {
            Make_1ADC80(&a, r->node);
            p = &a;
        } else {
            b.p = 0;
            b.id = -1;
            p = &b;
        }
    }
    out->p = p->p;
    out->id = p->id;
}
static inline void merge_flush_func_001ADC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADC80 */

/* merge_units: begin func_001ADD40 */
#pragma push /* merge_units */
void* cSkaSystem_RequestTransition_CrossFadeInDuration(char* self) {
    return self + 60;
}

int cPointer_cSkaNode_opMul(char* self) {
    return *(int*)(self + 0);
}

void* func_001ADD60(char* self) {
    return self + 48;
}

void* func_001ADD70(char* self) {
    return self + 36;
}

int cSkaSystem_RequestTransition_HasAnim(char* self) {
    return *(unsigned int*)(self + 48) != 0;
}
static inline void merge_flush_func_001ADD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADD40 */

/* merge_units: begin func_001ADD90 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
struct Res_1ADD90 { int a; int b; Res_1ADD90() {} };
class Obj_1ADD90 { public: VPAD2(p) virtual Res_1ADD90 Get(); };
typedef struct { int o; } Ref_1ADD90;
typedef struct { char name[0x30]; Ref_1ADD90 ref; int ra; int rb; } __attribute__((aligned(16))) MR_1ADD90;
typedef struct { char pad[0x34]; int reg; } Map_1ADD90;
extern "C" int cSkaAnimationSet_GetNodeId(Map_1ADD90* m, MR_1ADD90* name);
extern "C" Ref_1ADD90* cArray_cSkaNodePtr_opIndex(int* reg, int idx);
static inline void QZero_1ADD90(void* d0) { int n = 3; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
extern "C" void cSkaSystem_RequestTransition_ConvertAnimationNameToAnimationPointer(MR_1ADD90* mr, Map_1ADD90* m)
{
    if (mr->name[0]) {
        volatile int t;
        t = cArray_cSkaNodePtr_opIndex(&m->reg, cSkaAnimationSet_GetNodeId(m, mr))->o;
        mr->ref.o = t;
        Res_1ADD90 r = ((Obj_1ADD90*)mr->ref.o)->Get();
        mr->ra = r.a;
        mr->rb = r.b;
        if (mr->name[0]) QZero_1ADD90(mr);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADD90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADD90 */

/* merge_units: begin func_001ADE40 */
#pragma push /* merge_units */
typedef struct { int w[12]; } __attribute__((aligned(16))) MRHead_c7;
typedef struct {
    MRHead_c7 head;
    int a30, a34, a38;
    float f3C, f40, f44, f48, f4C, f50, f54, f58;
    void* vt5C;
    int b60, b64, b68, b6C, b70, b74, b78;
    signed char c7C;
    int d80;
    signed char c84;
    int d88;
    unsigned char c8C;
    float f90;
} MotionReq_c7;
static inline void QCopy_c7(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
    asm {
        .set noreorder
        nop
    lp:
        lq $a2, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a2, -0x10(d)
        .set reorder
    }
}
MotionReq_c7* cSkaSystem_RequestTransition_ctor(MotionReq_c7* d, MotionReq_c7* s) {
    QCopy_c7(&d->head, &s->head);
    d->a30 = s->a30; d->a34 = s->a34; d->a38 = s->a38;
    d->f3C = s->f3C; d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48;
    d->f4C = s->f4C; d->f50 = s->f50; d->f54 = s->f54; d->f58 = s->f58;
    d->vt5C = D_004DFD80;
    d->b60 = s->b60; d->b64 = s->b64; d->b68 = s->b68; d->b6C = s->b6C;
    d->b70 = s->b70; d->b74 = s->b74; d->b78 = s->b78;
    d->c7C = s->c7C;
    d->vt5C = D_004DA930;
    d->d80 = s->d80; d->c84 = s->c84; d->d88 = s->d88; d->c8C = s->c8C; d->f90 = s->f90;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADE40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADE40 */

/* merge_units: begin func_001ADF50 */
#pragma push /* merge_units */
/* AnimEvent copy constructor. */
AnimEvent* cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(AnimEvent* self, AnimEvent* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004DA930;
    self->unk24 = src->unk24;
    self->unk28 = src->unk28;
    self->unk2C = src->unk2C;
    self->unk30 = src->unk30;
    self->unk34 = src->unk34;
    return self;
}

int* cPointer_cSkaNode_ctor_cSkaNodeP(int* self, int value) {
    *self = value;
    return self;
}

/* Store a Vec4 at +0x08 and set the "valid" byte at +0x05. */
char* cSkaRequestStream_opShl(char* self, Vec4* v) {
    Vec4* dst = (Vec4*)(self + 8);

    dst->x = v->x;
    dst->y = v->y;
    dst->z = v->z;
    dst->w = v->w;
    self[5] = 1;
    return self;
}
static inline void merge_flush_func_001ADF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ADF50 */

/* merge_units: begin func_001AE020 */
#pragma push /* merge_units */
typedef struct { float a; float b; unsigned char c; } S_1AE020;
static inline float clamp_1AE020(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
S_1AE020* cSkaTimeSpan_Normalized_ctor_float_bool(S_1AE020* s, unsigned char c, float x)
{
    float v;
    s->c = c;
    v = clamp_1AE020(x, 0.0f, 1.0f);
    s->b = v;
    s->a = v;
    return s;
}
static inline void merge_flush_func_001AE020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE020 */

/* merge_units: begin func_001AE050 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_001AE050(int a0, int a1, int a2, int a3) {
    int v0, v1;

    v1 = 0 + 1;
    v0 = (signed char)a1;
    v0 = v0 << 3;
    a1 = v0 + a0;
    *(int*)(char*)(a1 + 4) = a2;
    v0 = a0;
    *(int*)(char*)(a1 + 8) = a3;
    *(char*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE050 */

/* merge_units: begin func_001AE080 */
#pragma push /* merge_units */
typedef struct { int unk0; int bits[1]; } BitSet001AE080;
/* Test bit `index` of a bitset that starts at offset 4. */
int cHuman_cStates_CheckState(BitSet001AE080* set, unsigned char index)
{
    unsigned int i = index;
    return ((set->bits[i >> 5] >> (i & 0x1F)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE080 */

/* merge_units: begin func_001AE0B0 */
#pragma push /* merge_units */
unsigned char func_001AE0B0(unsigned char* self, int i) {
    return self[((i & 255) << 1) + 978];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE0B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE0B0 */

/* merge_units: begin func_001AE0D0 */
#pragma push /* merge_units */
typedef struct BitSetOwner {
    char pad0000[0x3204];
    int bits[8]; /* 0x3204 */
} BitSetOwner;

/* Tests bit `index` in the 256-bit set at +0x3204. */
int cHuman_CheckState(BitSetOwner* obj, unsigned char index) {
    return ((obj->bits[(unsigned int)index >> 5] >> (index & 0x1F)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE0D0 */

/* merge_units: begin func_001AE100 */
#pragma push /* merge_units */
void cMan_SetEyeTarget(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 11632) = a1;
    if (cond) goto L001AE118;
    v1 = a1 + 12;
    goto L001AE128;
L001AE118:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L001AE128:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 11636) = v1;
    *(int*)((char*)a0 + 11660) = 0;
    goto ret;
ret:;
}
static inline void merge_flush_func_001AE100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE100 */

/* merge_units: begin func_001AE140 */
#pragma push /* merge_units */
void* func_001AE140(char* self) {
    return self + 96;
}

/* Clear byte +0x3A5 of the 0x70-byte record i. */
void LookCtl_ClearSlot(char* self, int i) {
    i = i & 255;
    self[(((i << 3) - i) << 4) + 933] = 0;
}
static inline void merge_flush_func_001AE140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE140 */

/* merge_units: begin func_001AE170 */
#pragma push /* merge_units */
void MEMCPY16(Q* d, Q* s, int n)
{
    asm {
        .set noreorder
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
static inline void merge_flush_func_001AE170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE170 */

/* merge_units: begin func_001AE190 */
#pragma push /* merge_units */
/* Returns whether the string is empty. */
unsigned char cString16N_3_Empty(char* s)
{
    return s[0] == 0;
}
static inline void merge_flush_func_001AE190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE190 */

/* merge_units: begin func_001AE1A0 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"
#include "vc_copy.h"

#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
char* cString16N_3_ctor_charP(char* d, char* s)
{
    CANONICAL_KEY_INIT(d, s)
    return d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE1A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE1A0 */

/* merge_units: begin func_001AE230 */
#pragma push /* merge_units */
typedef struct { char pad[5]; char flag; char pad6[10]; __int128 q; char pad20[0x50]; } E_E230;
typedef struct { char pad[0x3A0]; E_E230 e[4]; } O_E230;
void cHumanIkRoutine_SetAimAtPoint(O_E230* o, unsigned char i, __int128* src) {
    E_E230* e = (E_E230*)((char*)o->e + i * sizeof(E_E230));
    __int128* d = &e->q;
    VCopyF(d, src);
    e->flag = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE230 */

/* merge_units: begin func_001AE260 */
#pragma push /* merge_units */
void* func_001AE260(char* self) {
    return self + 4;
}

int func_001AE270(char* self) {
    return *(int*)(self + 0);
}
static inline void merge_flush_func_001AE260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE260 */
