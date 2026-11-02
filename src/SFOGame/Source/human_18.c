/*
 * SFOGame/Source/human: 7 files, 0019FE90-001A0280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019FE90 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Sets a root's local placement; when it has a parent (ib0 set), the placement
 * is re-expressed relative to the inverse of the parent's world placement. */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    /* The unused xx keeps retail's dead source-address addiu. */
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };

extern "C" {
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
#if 0 /* merge_units */
void cQuatVec_opAssign(Plc*, void*);
#endif /* merge_units */
void cQuatVec_opAssign(void*, void*); /* merge_units */
#define cQuatVec_opAssign(a0, a1) (cQuatVec_opAssign((void *)(a0), (a1))) /* merge_units */

void cQuatVec_InvertAssumingUnitQuat(Plc*);
void cQuaternion_ctor_void(V*);
void cQuaternion_VU0Multiply(V*, V*, V*);
void cQuaternion_ctor_cQuaternionR(V*, V*);
void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(struct S* s, Plc* in);
}

struct S {
    char pad00[0x80];
    Plc p;              /* 0x80 */
    char padA0[2];
    unsigned char ba2;  /* 0xA2 */
    char padA3[0xD];
    int ib0;            /* 0xB0 */
};

static inline void QRot(V* v, V* q) {
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
static inline void VAdd3(V* s, V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(S* s, Plc* in)
{
    {
        Plc* d = &s->p;
        Q16(&d->rot, &in->rot);
        Q16(&d->pos, &in->pos);
    }
    if (s->ib0) {
        Plc inv;
        cQuatVec_opAssign(&inv, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(s)));
        cQuatVec_InvertAssumingUnitQuat(&inv);
        Plc* p;
        Plc* pi = &inv;
        p = &s->p;
        V r;
        V q;
        cQuaternion_ctor_void(&q);
        cQuaternion_VU0Multiply(&q, &pi->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &q);
        p->rot = r;
        QRot(&p->pos, &pi->rot);
        VAdd3(&pi->pos, &p->pos);
    }
    s->ba2 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FE90(void) {}
#undef cQuatVec_opAssign /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019FE90 */

/* merge_units: begin func_0019FFC0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x70]; V4 q; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* parent; } R;
#if 0 /* merge_units */
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(R*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((void *)(a0))) /* merge_units */


extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern V4* cQuatVec_Rotation(void*);
extern V4* cQuaternion_opAssign(V4*, V4*);
extern V4* cQuaternion_InvertUnitQuat(V4*);
static inline void QRot_(V4* q, V4* v) {
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

#pragma peephole off
#pragma opt_propagation off
/* Sets the local orientation quat; when parented, rotates it into the parent's frame. */
void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(R* self, V4* q)
{
    V4 t;
    {V4* d = &self->q; asm { .set reorder } *d = *q;}
    if (self->parent) {
        cQuaternion_opAssign(&t, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self))));
        cQuaternion_InvertUnitQuat(&t);
        QRot_(&t, &self->q);
    }
    self->dirty = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019FFC0(void) {}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019FFC0 */

/* merge_units: begin func_001A0080 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { int pad0; int count; int* data; } PtrVec_1A0080;
typedef struct { char pad[0xB4]; PtrVec_1A0080 list; } Owner_1A0080;
typedef struct { char pad[0xB0]; Owner_1A0080* owner; } O_1A0080;
extern void std_vector_pod_int_resize(PtrVec_1A0080* v, int n, int* fill);
static inline void Remove_1A0080(PtrVec_1A0080* v, int value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    std_vector_pod_int_resize(v, last + 1, &fill);
}
void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(O_1A0080* o)
{
    if (o->owner) {
        Remove_1A0080(&o->owner->list, (int)o);
        o->owner = 0;
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A0080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A0080 */

/* merge_units: begin func_001A0110 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; float rot[0x14]; float wrot[8]; char pad80[0x2]; unsigned char dirty; char padA3[0xD]; void* xform; } RootIdn_f4;
#if 0 /* merge_units */
extern RootIdn_f4* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
#endif /* merge_units */
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*); /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) ((RootIdn_f4 *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */

extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
extern void cQuatVec_opAssign(void*, void*);

extern void cQuatVec_Transform(void*, void*);
void* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(RootIdn_f4* self)
{
    void* pl;
    if (self->xform != 0) {
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty) {
            pl = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self));
            cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->rot, cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->wrot);
            cQuatVec_Transform(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->rot, pl);
            cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty = 0;
        }
        return self->rot;
    }
    return self->wrot;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A0110(void) {}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0110 */

/* merge_units: begin func_001A01C0 */
#pragma push /* merge_units */
typedef struct { float m[4][4]; } Mtx_e1;
typedef struct { char pad[0x20]; float pos[4]; char pad30[0x40]; float wpos[4]; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* motion; } RootIdn_e1;
#if 0 /* merge_units */
extern RootIdn_e1* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) ((RootIdn_e1 *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */


extern void cVector_opAssign(float*, float*);
extern Mtx_e1* cMatrix_ctor_cQuatVecR(Mtx_e1*, void*);
extern void cVector_Rotate_cMatrixR(float*, Mtx_e1*);
float* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(RootIdn_e1* self)
{
    Mtx_e1 m;
    void* pl;
    if (self->motion != 0) {
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty) {
            pl = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(self));
            cVector_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->pos, cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->wpos);
            cVector_Rotate_cMatrixR(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->pos, cMatrix_ctor_cQuatVecR(&m, pl));
            cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(self)->dirty = 0;
        }
        return self->pos;
    }
    return self->wpos;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A01C0(void) {}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A01C0 */

/* merge_units: begin func_001A0280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void* RootCollection_FindByKey(void*, int);

int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(char* self) {
    return *(int*)(self + 176);
}

/* back(): address of the last element. */
int* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Back(PtrVec* v) {
    return v->data + v->count - 1;
}

/* Find in the root collection at +0xB0. */
void* cSkaSystem_GetAnchor(char* self, int key) {
    return RootCollection_FindByKey(self + 176, key);
}
static inline void merge_flush_func_001A0280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0280 */

/* merge_units: begin func_001A02C0 */
#pragma push /* merge_units */
/* Actor_UnlinkAll = cHuman::LetGoOfBodyBeingCarried. opt_propagation off keeps inline ctor 'this' in s0;
 * the empty member dtors on Arr7_L/Tail_L keep X_L's ctor 'this' live while X_L's own dtor (with
 * (char*)this+off forms) avoids the member null checks. Temporaries as args order the X/rate slots;
 * Name_L declared between the two messages orders the slots. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_propagation off
#include "vslot_pad.h"

static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { int id; void* a; } Pair_L;
extern "C" {
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct Arr7_L { Pair_L p[7]; Arr7_L() { cArray_FixedSize_cSkaAnimEvent_7_ctor_void(this); } __declspec(weak) __declspec(MSG_DTOR) ~Arr7_L() {} };
struct Tail_L { char t[0x14]; Tail_L() { cArray_cTimedEvent_ctor_void(this); } __declspec(weak) __declspec(MSG_DTOR) ~Tail_L() {} };
struct X_L { unsigned char kind; Arr7_L pairs; Tail_L tail;
    X_L() : kind(0) {}
    __declspec(weak) __declspec(MSG_DTOR) ~X_L() { func_001BE5A0((char*)this + 0x3C, 0); __destroy_array((char*)this + 4, (void*)func_0018A210, 8, 7); } };
struct Rate_L { float x, y, z, w; Rate_L(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { void* lib; char pad4[0xFC]; char node[0x10]; } Sys_L;

struct Obj_L { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); char pad[0x2C]; int f30; };
struct Act_L;
struct Hdl { Act_L* volatile obj; int serial;
    int IsValid();
    Act_L* Raw() { return obj; } Act_L* Get() { return IsValid() ? Raw() : 0; }
    void Set(Act_L* l);
};
struct Act_L {
    char pad0[0xC]; int serial; char pad10[4]; unsigned char b14; char pad15[0x58 - 0x15];
    Obj_L* o58; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys;
    char pad2FD0[0x3254 - 0x2FD0];
    int f3254; char pad3258[4]; int f325C; char pad3260[0x3478 - 0x3260];
    Hdl carried;
};
inline int Hdl::IsValid() { Act_L* p = obj; unsigned char ok = 1; if (!IsNullNV(p) && !SameNV(p->serial, serial)) ok = 0; return ok; }
inline void Hdl::Set(Act_L* l) { int none; serial = *((obj = l) ? &l->serial : (none = -1, &none)); }

extern "C" {
extern char D_004FF2B0[]; extern char D_004DCD70[]; extern char D_004DCC70[];
extern char D_004EE960[]; extern char D_004DA890[];
void cSkaSystem_DetachChildrenAnchors_All(void* p);
void cTreeNode_cSkaSystemPtr_DetachChildren(void* p);
void cMessage_ctor_cMessageNameR(void* m, char* cls);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Act_L* a, Name_L* n, float* out, int x, int y);
int cSkaAnimationSet_GetNode_cString16NR(void* lib, Name_L* n);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
void* func_0018C6A0(Sys_L* s);
void nSka_GetPlaybackGroupId(Y_L* y, int m);
void cSkaRequestStream_AddRequest(void* ctl, int id, int mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void Actor_UnlinkAll(Act_L* a);
}

struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char prio; char pad21[3]; int who; unsigned char picked; char pad29[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, (char*)t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct GobjMsg : MsgB {
    GobjMsg(int w) : MsgB(D_004FF2B0) { vtable = D_004DCD70; who = w; prio = 2; }
    __declspec(weak) __declspec(MSG_DTOR) ~GobjMsg() { vtable = D_004DCD70; }
};
struct BodyMovedMsg : GobjMsg {
    BodyMovedMsg(int w) : GobjMsg(w) { vtable = D_004DCC70; picked = 0; }
    __declspec(weak) __declspec(MSG_DTOR) ~BodyMovedMsg() { vtable = D_004DCC70; }
};
struct PickupMsg : MsgB {
    PickupMsg() : MsgB(D_004EE960) { vtable = D_004DA890; }
    __declspec(weak) __declspec(MSG_DTOR) ~PickupMsg() { vtable = D_004DA890; }
};

static inline void QZero_L(void* dd) { int n = 3; void* d = dd;
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

static inline unsigned char IsPlayer_L(Act_L* h) { unsigned char r = 0; if (h->o58 && h->o58->IsPlayer()) r = 1; return r; }
static inline void Play_L(Sys_L* sys, Name_L* n, const Rate_L& r, const X_L& x)
{
    int mo = cSkaAnimationSet_GetNode_cString16NR(sys->lib, n);
    if (mo) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        ctl = func_0018C6A0(sys);
        nSka_GetPlaybackGroupId(&y, mo);
        cSkaRequestStream_AddRequest(ctl, mo, 1, (void*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline bool Bit4(int f) { return (f >> 4) & 1; }
static inline bool Skip_L(Act_L* a) { return Bit4(a->f325C) && !Bit4(a->f3254); }

void Actor_UnlinkAll(Act_L* a)
{
    Sys_L* s = &a->sys;
    cSkaSystem_DetachChildrenAnchors_All(s);
    cTreeNode_cSkaSystemPtr_DetachChildren(s->node);
    if (a->carried.Get()) {
        if (IsPlayer_L(a) && a->b14) {
            BodyMovedMsg m(a->o58->f30);
            m.prio = 2;
            QueueMessage_cMessageR_cSystemP_int(&m, a->carried.Get(), 0);
        }
        Name_L n;
        float dur;
        {
            PickupMsg m;
            QueueMessage_cMessageR_cSystemP_int(&m, a->carried.Get(), 0);
        }
        if (!Skip_L(a)) {
            QZero_L(&n);
            cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(a->carried.Get(), &n, &dur, 0, 0);
            Play_L(&a->carried.Get()->sys, &n, Rate_L(0.5f, 0.5f, 2.0f, 2.0f), X_L());
        }
        a->carried.Set(0);
    }
}
static inline void merge_flush_func_001A02C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A02C0 */
