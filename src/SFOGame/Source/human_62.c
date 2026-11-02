/*
 * SFOGame/Source/human: 6 files, 001A0890-001A0B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A0890 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(char* self) {
    return *(int*)(self + 8);
}
static inline void merge_flush_func_001A0890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0890 */

/* merge_units: begin func_001A08D0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { char pad[0x10]; int set; } E_1A08D0;
typedef struct { E_1A08D0*** p; } It_1A08D0;
typedef struct { int n; } SIt_1A08D0;
typedef struct { char pad[0x108]; int vec; } O_1A08D0;
#if 0 /* merge_units */
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(int* v);
#endif /* merge_units */
#define std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(a0) ((E_1A08D0 * * *)std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void((char *)(a0))) /* merge_units */



#if 0 /* merge_units */
extern E_1A08D0*** std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(int* v);
#endif /* merge_units */
#define std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(a0) ((E_1A08D0 * * *)std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void((PtrVec *)(a0))) /* merge_units */



#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(It_1A08D0* out, int* v, E_1A08D0**** p);
#endif /* merge_units */
#define std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(a0, a1, a2) (std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */



#if 0 /* merge_units */
extern void* cSkaParams_GetAnimAnchorList(int* s);
#endif /* merge_units */
void * cSkaParams_GetAnimAnchorList(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_Begin(SIt_1A08D0* out, void* s);
#endif /* merge_units */
void cArray_cSkaAnimAnchorListEntry_Begin(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_End(SIt_1A08D0* out, void* s);
#endif /* merge_units */
void cArray_cSkaAnimAnchorListEntry_End(); /* merge_units */


#if 0 /* merge_units */
extern int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(SIt_1A08D0* a, SIt_1A08D0* b);
#endif /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(); /* merge_units */


#if 0 /* merge_units */
extern void* cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(SIt_1A08D0* a);
#endif /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(); /* merge_units */


#if 0 /* merge_units */
extern void* cSkaAnimAnchorListEntry_Anchor(void* p);
#endif /* merge_units */
void * cSkaAnimAnchorListEntry_Anchor(); /* merge_units */


#if 0 /* merge_units */
extern void cSkaAnimAnchor_DetachParent(void* p);
#endif /* merge_units */
void cSkaAnimAnchor_DetachParent(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cSkaAnimAnchorListEntry_Iterator_opInc(SIt_1A08D0* a);
#endif /* merge_units */
Iter16 * cArray_cSkaAnimAnchorListEntry_Iterator_opInc(); /* merge_units */


static inline int Eq_1A08D0(E_1A08D0*** a, E_1A08D0*** b) { return a == b; }
void cSkaSystem_DetachChildrenAnchors_All(O_1A08D0* self)
{
    It_1A08D0 b;
    It_1A08D0 e;
    E_1A08D0*** t0;
    E_1A08D0*** t1;
    SIt_1A08D0 i;
    SIt_1A08D0 ie;
    int* v = &self->vec;
    E_1A08D0*** it;
    E_1A08D0*** end;
    t0 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&b, v, &t0);
    it = b.p;
    t1 = std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void(v);
    std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR(&e, v, &t1);
    end = e.p;
    while (Eq_1A08D0(it, end) ^ 1) {
        void* s = cSkaParams_GetAnimAnchorList(&(**it)->set);
        cArray_cSkaAnimAnchorListEntry_Begin(&i, s);
        cArray_cSkaAnimAnchorListEntry_End(&ie, s);
        while (cArray_cSkaAnimAnchorListEntry_Iterator_opNe(&i, &ie)) {
            cSkaAnimAnchor_DetachParent(cSkaAnimAnchorListEntry_Anchor(cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(&i)));
            cArray_cSkaAnimAnchorListEntry_Iterator_opInc(&i);
        }
        it++;
    }
}
#undef std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_begin_void /* merge_units */
#undef std_vector_imp_cTreeNode_cSkaSystemPtrPtr_1_end_void /* merge_units */
#undef std_vector_cTreeNode_cSkaSystemPtrPtr_pointer2iterator_cTreeNodePPR /* merge_units */
static inline void merge_flush_func_001A08D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A08D0 */

/* merge_units: begin func_001A09F0 */
#pragma push /* merge_units */
int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 384-byte elements. */
Iter16* cArray_cSkaAnimAnchorListEntry_Iterator_opInc(Iter16* it) {
    it->p = it->p + 384;
    return it;
}
static inline void merge_flush_func_001A09F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A09F0 */

/* merge_units: begin func_001A0A30 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } VP_1A0A30;
typedef struct { Q a; } V4_1A0A30;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* self);
extern V4_1A0A30* cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(void* self);
extern VP_1A0A30* cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(void* self);
extern void cQuatVec_ctor_cQuatVecR(VP_1A0A30* d, VP_1A0A30* s);
extern void cVector_ctor_cVectorR(V4_1A0A30* d, V4_1A0A30* s);
extern void cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(void* self);
extern void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(void* self, VP_1A0A30* p);
extern void cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(void* self, V4_1A0A30* m);
extern void cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(void* self, VP_1A0A30* p);
void cSkaAnimAnchor_DetachParent(void* self)
{
    VP_1A0A30 place;
    V4_1A0A30 motion;
    VP_1A0A30 other;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void_2(self)) {
        cQuatVec_ctor_cQuatVecR(&place, cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self));
        cVector_ctor_cVectorR(&motion, cSkaAnimAnchor_TreeNode_GetDeltaPos_WorldSpace(self));
        cQuatVec_ctor_cQuatVecR(&other, cSkaAnimAnchor_TreeNode_GetSkeletonTarget_WorldSpace(self));
        cTreeNode_cSkaAnimAnchor_TreeNodeData_DetachParent(self);
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(self, &place);
        cSkaAnimAnchor_TreeNode_SetDeltaPos_WorldSpace(self, &motion);
        cSkaAnimAnchor_TreeNode_SetSkeletonTarget_WorldSpace(self, &other);
    }
}
static inline void merge_flush_func_001A0A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0A30 */

/* merge_units: begin func_001A0AD0 */
#pragma push /* merge_units */
void* cSkaAnimAnchorListEntry_Anchor(char* self) {
    return self + 16;
}

int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 384-byte elements. */
void cArray_cSkaAnimAnchorListEntry_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 384;
}

void cArray_cSkaAnimAnchorListEntry_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cSkaParams_GetAnimAnchorList(char* self) {
    return self + 160;
}
static inline void merge_flush_func_001A0AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0AD0 */

/* merge_units: begin func_001A0B30 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(12)
#include "alloc_guard.h"

struct cVector { float x, y, z, w; } __attribute__((aligned(16)));
struct cVectorC { float x, y, z, w; cVectorC(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } void Init(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
struct cString16N {
    char charArray[32];
    cString16N(const char* s)
    {
        unsigned char ended = 0;
        int i;
        for (i = 0; i < 31; i++) {
            char c;
            if (s[i] == 0)
                ended = 1;
            if (ended)
                c = 0;
            else
                c = s[i];
            charArray[i] = c;
        }
        charArray[i] = 0;
    }
    void Init(const char* s)
    {
        unsigned char ended = 0;
        int i;
        for (i = 0; i < 31; i++) {
            char c;
            if (s[i] == 0)
                ended = 1;
            if (ended)
                c = 0;
            else
                c = s[i];
            charArray[i] = c;
        }
        charArray[i] = 0;
    }
} __attribute__((aligned(16)));
struct cMsg { void* vtable; char pad4[0x20]; int f24; unsigned char b28; char pad29[3]; int f2C; unsigned char b30; char pad31[3]; int f34; char pad38[8]; };
struct tEvPair { int id; void* obj; };
extern "C" void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
extern "C" void cArray_cTimedEvent_ctor_void(void* p);
struct cAnimCheckpoints { unsigned char kind; char pad[3]; tEvPair pairs[7]; char tail[0x10];
    cAnimCheckpoints() { cAnimCheckpoints* t = this; t->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(t->pairs); cArray_cTimedEvent_ctor_void(t->tail); }
    void Add(int i, int id, void* o) { tEvPair* p = &pairs[i]; p->id = id; p->obj = o; kind = 1; }
};
struct cCrossFade { float a, b, c, d; };
struct cPhysicsX { char pad[0x11]; unsigned char b11; char pad12[0x9C0 - 0x12]; unsigned char b9C0; };
struct cTimeCb { int duration; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; struct cHuman* human; unsigned char type; };
struct cHuman {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char GetHealthState();
    char pad4[0x2EC0 - 4];
    char* animSet; char pad2EC4[0x30A0 - 0x2EC4];
    float f30A0; char pad30A4[0x3210 - 0x30A4];
    int f3210; char pad3214[0x3248 - 0x3214];
    int f3248; char pad324C[0x326C - 0x324C];
    int* blend326C; char pad3270[0x3310 - 0x3270];
    cPhysicsX* physics;
};

extern "C" {
extern char D_00542B60[];
extern char D_004DA930[];
extern char D_004D9DE0[];
extern char D_004DA870[];
extern char D_0049D8D0[];
extern float g_DefaultMotionTransition;
extern char D_0049E148[];
extern char D_0049E160[];
extern cString16N D_0049D100, D_0049D120, D_0049D140, D_0049D160;
extern signed char D_004EEE20, D_004EEE28, D_004EEE30, D_004EEE38;
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(void* it, void* arr, cString16N* key);
int** cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(void* it);
void cMessage_ctor_cMessageNameR(cMsg* m, void* name);
void cMessage_dtor(cMsg* m, int f);
void cSkaRequestStream_AddRequest(void* s, int n, int mode, cCrossFade* cf, void* pg, const cMsg& m1, const cMsg& m2, cAnimCheckpoints* x, float f0, float f1);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
void cSkaAnimCheckpoints_ctor_void(void* p);
void cSkaAnimCheckpoints_dtor(void* p, int f);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
void* cSkaCrossFadeDuration_ctor_float(void* p, float f);
void cSkaSystem_PlayAnimation(void* sys, int* blend, int instr, void* cfd, void* cp);
void cHuman_HandleFootstepEvent(cHuman* h, int foot, int force);
int Libc_Rand(void);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nCallback_SetCallback(void* p);
}
static inline void MsgInit(cMsg* m0)
{
    cMsg* m = m0;
    cMessage_ctor_cMessageNameR(m, D_00542B60);
    m->vtable = D_004DA930;
    m->f24 = 0; m->b28 = 0; m->f2C = 0; m->b30 = 0; m->f34 = 0;
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct cMsgT : cMsg { cMsgT() { MsgInit(this); } __declspec(weak) __declspec(DROPDTOR) ~cMsgT() { vtable = D_004DA930; cMessage_dtor(this, 0); } };
static inline void AddR(void* s, int* b, int mode, cCrossFade* cf, const cMsg& m1, const cMsg& m2, cAnimCheckpoints* x, float f0, float f1) { void* pg = b + 1; cSkaRequestStream_AddRequest(s, b[0], mode, cf, pg, m1, m2, x, f0, f1); }
static inline float Inv(float t) { return t != 0.0f ? 1.0f / t : 3.4028235e38f; }

/* cvt.w.s+mfc1: a C (int) cast compiles to trunc.w.s */
static inline int F2I(float f) { int r; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline int RandN(int n) { int r = Libc_Rand(); return F2I((float)n * ((float)r / 2147483648.0f)); }
static inline int RandRange(int lo, int hi) { int n = hi - lo + 1; return lo + RandN(n); }
struct cCp3 { char d[0x50]; cCp3() { cSkaAnimCheckpoints_ctor_void(this); } __declspec(weak) __declspec(DROPDTOR) ~cCp3() { cSkaAnimCheckpoints_dtor(this, -1); } };
struct cCfd { float a, b, c, d; cCfd() {} void* Ctor(float f) { return cSkaCrossFadeDuration_ctor_float(this, f); } };

static inline unsigned char IsDeadOrDying(cHuman* h)
{
    unsigned char r;
    unsigned char s = h->GetHealthState();
    r = 1;
    if (s != 3 && s != 2) r = 0;
    return r;
}

extern "C" void cHuman_Land(cHuman* self, unsigned char playLandAnimation)
{
    char* animationName;
    float transitionTime;
    int callbackWaitDuration;
    cTimeCb* callback;
    if (IsDeadOrDying(self))
        return;
    if (playLandAnimation) {
        if (!((self->f3210 >> 11) & 1)) {
            if (!D_004EEE20) { D_0049D100.Init(D_0049E148); D_004EEE20 = 1; }
            if (!D_004EEE28) { D_0049D120.Init(D_0049E148); D_004EEE28 = 1; }
            if (!D_004EEE30) { D_0049D140.Init(D_0049E148); D_004EEE30 = 1; }
            if (!D_004EEE38) { D_0049D160.Init(D_0049E160); D_004EEE38 = 1; }
            int instr;
            unsigned char inWater = self->f30A0 == 0.0f;
            float t2 = g_DefaultMotionTransition;
            if (inWater) {
                animationName = D_0049D160.charArray;
                transitionTime = 0.35f;
                instr = 0;
                t2 = transitionTime;
            } else if ((self->f3248 >> 11) & 1) {
                animationName = D_0049D100.charArray;
                transitionTime = 0.2f;
                instr = 0;
            } else if ((self->f3248 >> 13) & 1) {
                animationName = D_0049D120.charArray;
                transitionTime = 0.2f;
                instr = 0;
            } else {
                animationName = D_0049D140.charArray;
                transitionTime = 0.2f;
                instr = 0;
            }
            /* The retail frame keeps the slots of a third request block (cf/cp/iterator at 0x330..0x398 and
               two message temporaries at 0x1F0..0x270) that no code references: the original had a block that
               MW removed after laying out the frame. A dead block reproduces the slots. The volatile asm inside
               it emits nothing; it only selects MW's less-optimised mode that the retail code shows (no strength
               reduction of the cString16N::Init loops, the checkpoint 'this' kept in s2/s3, RandRange's n kept
               as an int across Libc_Rand). Any volatile asm in the function does this; a live one would add an
               instruction or block retail's scheduling around the cvt.w.s. */
            if (0) {
                asm volatile { nop }
                cCrossFade cf;
                cAnimCheckpoints cp;
                cf.a = t2; cf.b = t2; cf.c = Inv(t2); cf.d = Inv(t2);
                int it;
                cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(&it, self->animSet + 0x44, (cString16N*)animationName);
                int* blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(&it);
                char* ac = (char*)&self->animSet;
                AddR(ac + 0x34, blend, 1, &cf, cMsgT(), cMsgT(), &cp, -1.0f, 0.0f);
                func_001BE5A0(cp.tail, 0);
                __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
            }
            {
                cCrossFade cf;
                cAnimCheckpoints cp;
                char* ac;
                int* blend;
                cp.Add(0, 0x25, self);
                cAnimCheckpoints* pcp = &cp;
                pcp->Add(3, 0x26, self);
                pcp->Add(5, 0x27, self);
                pcp->Add(6, 0x28, self);
                cf.a = transitionTime;
                cf.b = transitionTime;
                cf.c = Inv(transitionTime);
                cf.d = Inv(transitionTime);
                int it;
                cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(&it, self->animSet + 0x44, (cString16N*)animationName);
                blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(&it);
                ac = (char*)&self->animSet;
                AddR(ac + 0x34, blend, 1, &cf, cMsgT(), cMsgT(), pcp, -1.0f, 0.0f);
                func_001BE5A0(cp.tail, 0);
                __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
            }
            {
                cCrossFade cf;
                cAnimCheckpoints cp;
                cf.a = t2;
                cf.b = t2;
                cf.c = Inv(t2);
                cf.d = Inv(t2);
                char* ac = (char*)&self->animSet;
                int* blend = self->blend326C;
                AddR(ac + 0x34, blend, instr, &cf, cMsgT(), cMsgT(), &cp, -1.0f, 0.0f);
                func_001BE5A0(cp.tail, 0);
                __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
            }
        }
    } else {
        char** as = &self->animSet;
        int* blend = self->blend326C;
        cSkaSystem_PlayAnimation(as, blend, 3, cCfd().Ctor(cSkaAnimationSet_DefaultCrossFadeDuration(*as)), &cCp3());
        if (self->physics)
            self->physics->b9C0 = 0;
        if (self->physics)
            self->physics->b11 = 1;
    }
    cHuman_HandleFootstepEvent(self, 2, 1);
    callbackWaitDuration = RandRange(70, 100);
    {
        AllocGuard guard;
        callback = (cTimeCb*)cMemMan_Allocate(0, 0x14, D_0049D8D0, 0x2433);
    }
    if (callback) {
        callback->vt = D_004D9DE0;
        callback->b4 = 1;
        callback->duration = callbackWaitDuration;
        callback->b5 = 0;
        callback->vt = D_004DA870;
        callback->human = self;
        callback->type = 0;
    }
    nCallback_SetCallback(callback);
}
static inline void merge_flush_func_001A0B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A0B30 */
