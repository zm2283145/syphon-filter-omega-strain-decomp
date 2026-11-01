/*
 * SFOGame/Source/NIEvent: 9 files, 0023E5B0-0023E9B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023E5B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int std_vector_pod_int_size(char* self) {
    return *(int*)(self + 4);
}

int std_vector_imp_cNIEventBasePtr_1_size(char* self) {
    return *(int*)(self + 4);
}
static inline void merge_flush_func_0023E5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E5B0 */

/* merge_units: begin func_0023E5D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "vc_copy.h"
#include "q4r.h"
struct V { __int128 q; V() {} V& operator=(const V& o) { V* d = this; const V* s = &o; VCopyFF(d, s); return *this; } };
struct M { V r[4]; M() {} M& operator=(const M& o) { __int128 qa, qb; Q4COPY_N(this, &o, qa, qb); return *this; } };
struct E64 { float f; char pad[0x3C]; };
struct E8 { float f; int pad; };
struct Ch { virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19(); virtual void c20(); virtual void c21(); virtual void c22(); virtual void c23(); virtual void c24(); virtual void c25(); virtual void c26(); virtual void c27(); virtual void c28(); virtual void c29(); virtual void c30(); virtual void c31(); virtual void c32(); virtual void c33(); virtual void c34(); virtual void c35(); virtual void c36(); virtual void c37(); virtual void c38(); virtual void c39(); virtual void c40(); virtual void c41(); virtual void c42(); virtual void c43(); virtual void c44(); virtual void c45(); virtual void c46(); virtual void c47(); virtual void c48(); virtual void c49(); virtual void c50(); virtual void c51(); virtual void c52(); virtual void c53(); virtual void c54(); virtual void c55(); virtual void c56(); virtual void c57(); virtual void c58(); virtual void c59(); virtual void c60(); virtual void c61(); virtual void c62(); virtual void c63(); virtual void c64(); virtual void c65(); virtual void c66(); virtual void c67(); virtual void c68(); virtual void c69(); virtual void c70(); virtual void c71(); virtual void v72(); };
template <class T> struct Vec { int cap; int n; T* p; T& operator[](int i) { return p[i]; } int size() { return n; } };
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(float); virtual void v74(float);
    char pad04[0x5C];
    int i60;
    char pad64[0x38];
    Vec<Ch*> a;
    char padA8[4];
    Vec<E64> b;
    char padB8[4];
    int iBC;
    float fC0;
    Vec<E8> c;
    char padD0[4];
    int iD4;
    float fD8;
    char padDC[4];
    V vE0;
    M mF0;
    unsigned char b130;
};

/* The asm copies (VCopyFF/Q4COPY_N) leave the loop un-rotated; the goto form plus
   rotateloops/strength_reduction off give retail's b-to-bottom, unscaled-index loop. */
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
extern "C" void cNIEventBase_SetEndState(Obj* o)
{
    o->b130 = 1;
    if (o->iBC == -1) o->v73(o->b[o->b.size() - 1].f - o->fC0);
    if (o->iD4 == -1) o->v74(o->c[o->c.size() - 1].f - o->fD8);
    if (o->i60 != 3) { M m; M* d; M* s; V* t = &m.r[3]; __int128 q = VLoadF(&o->vE0); s = &m; d = &o->mF0; VStoreF(t, q); __int128 qa, qb; Q4COPY_N(d, s, qa, qb); }
    o->v70();
    int i = 0; goto t; l: o->a[i]->v72(); i++; t: if (i < o->a.size()) goto l;
}


#pragma pop
static inline void merge_flush_func_0023E5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E5D0 */

/* merge_units: begin func_0023E720 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad4[0x20]; int type; char pad28[8]; } Msg0023E720;
extern char D_004F7C28[];
extern char D_004DC2F0[];
extern void cMessage_ctor_cMessageNameR(Msg0023E720* ev, void* desc);
extern void QueueMessage_cMessageR_cSystemP_int(Msg0023E720* ev, void* target, int flags);
extern void cMessage_dtor(Msg0023E720* ev, int flags);
/* Send a type-2 message to the target. */
void cNIEventBase_Reset(void* target)
{
    Msg0023E720 ev;
    cMessage_ctor_cMessageNameR(&ev, D_004F7C28);
    ev.vtable = D_004DC2F0;
    ev.type = 2;
    QueueMessage_cMessageR_cSystemP_int(&ev, target, 0);
    ev.vtable = D_004DC2F0;
    cMessage_dtor(&ev, 0);
}
static inline void merge_flush_func_0023E720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E720 */

/* merge_units: begin func_0023E790 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad04[0x1C]; char b20; char pad21[3]; int i24; char pad28[8]; } Msg0023E790;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg0023E790* m, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg0023E720 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg0023E790* m, void* target, int a);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg0023E720 *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Msg0023E790* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg0023E720 *)(a0), (a1))) /* merge_units */


void cNIEventBase_Stop(void* target, int flag)
{
    Msg0023E790 m;
    cMessage_ctor_cMessageNameR(&m, D_004F7C28);
    m.vtable = D_004DC2F0;
    m.i24 = 1;
    if (!flag)
        m.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, target, 0);
    m.vtable = D_004DC2F0;
    cMessage_dtor(&m, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0023E790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E790 */

/* merge_units: begin func_0023E820 */
#pragma push /* merge_units */
typedef struct EventMsg24 {
    void* vtbl;
    char pad04[0x20];
    int unk24;     /* 0x24 */
    char pad28[8];
} EventMsg24;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(EventMsg24* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg0023E720 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg24* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg0023E720 *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg24* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg0023E720 *)(a0), (a1))) /* merge_units */



/* Builds a stack event message and sends it to target. */
void cNIEventBase_Play(void* target) {
    EventMsg24 msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7C28);
    msg.vtbl = D_004DC2F0;
    msg.unk24 = 0;
    QueueMessage_cMessageR_cSystemP_int(&msg, target, 0);
    msg.vtbl = D_004DC2F0;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0023E820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E820 */

/* merge_units: begin func_0023E890 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#pragma inline_depth(10)
typedef unsigned __int128 u_long128;
struct cVector { float x, y, z, w; cVector& operator=(const cVector& source) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0(%1)" : "=r"(reg) : "r"(&source)); __asm__ volatile("sq %1, 0(%0)" : : "r"(&refThis), "r"(reg)); return refThis; } };
struct cMatrix { float m[4][4]; cMatrix& operator=(const cMatrix& source) { cMatrix& refThis = *this; const cMatrix* s = &source; cMatrix* d = &refThis; u_long128 reg0, reg1; __asm__ volatile("lq %0, 0(%1)" : "=r"(reg0) : "r"(s)); __asm__ volatile("lq %0, 16(%1)" : "=r"(reg1) : "r"(s)); __asm__ volatile("sq %0, 0(%1)" : : "r"(reg0), "r"(d)); __asm__ volatile("lq %0, 32(%1)" : "=r"(reg0) : "r"(s)); __asm__ volatile("sq %0, 16(%1)" : : "r"(reg1), "r"(d)); __asm__ volatile("lq %0, 48(%1)" : "=r"(reg1) : "r"(s)); __asm__ volatile("sq %0, 32(%1)" : : "r"(reg0), "r"(d)); __asm__ volatile("sq %0, 48(%1)" : : "r"(reg1), "r"(d)); return *this; } };
struct cMessageName { int id; bool operator==(const cMessageName& o) const { return id == o.id; } };
struct cArray { int cap; int n; void* data; int pad; void* At() { void** p = &data; return *p; } void* Get() { return data; } };
struct PosKey_E890 { float t; char pad4[0xC]; cVector pos; };
struct VisKey_E890 { float t; unsigned char vis; };
struct cMessage;
struct cNIShuttle { void* vtable; char pad4[0x20]; int mAction; };
class cNIEventBase {
public:
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual void UpdateAll(float t);
    char pad4[0x60 - 0x4];
    int mType; char mParentName[48]; cNIEventBase* mParent; int mChildCount;
    cArray mChildren; cArray mPosKeys; int mPosORT; float mPosTime;
    cArray mVisKeys; int mVisORT; float mVisTime; unsigned char mVisible;
    cVector mPos; cMatrix mLocalXform; unsigned char mPlaying; float mSpeedMult;
};
extern "C" {
#if 0 /* merge_units */
extern cMessageName D_004F7C28;
#endif /* merge_units */
#define D_004F7C28 (*(cMessageName*)&D_004F7C28) /* merge_units */

cMessageName* cMessage_Name(const cMessage* m);
unsigned char cGOBJ_HandleMessage(cNIEventBase* self, const cMessage* m);
unsigned char cNIEventBase_HandleMessage(cNIEventBase* self, const cMessage* m);
}

extern "C" unsigned char cNIEventBase_HandleMessage(cNIEventBase* self, const cMessage* m)
{
    if (*cMessage_Name(m) == D_004F7C28) {
        cNIShuttle* msg = (cNIShuttle*)m;
        int action = msg->mAction;
        switch (action) {
        case 0: self->mPlaying = 1; break;
        case 1: self->mPlaying = 0; break;
        case 2: {
            cMatrix mat;
            self->mPosTime = 0.0f;
            self->mVisTime = 0.0f;
            self->mPos = ((PosKey_E890*)self->mPosKeys.data)[0].pos;
            *(cVector*)mat.m[3] = self->mPos;
            self->mLocalXform = mat;
            self->mVisible = ((VisKey_E890*)self->mVisKeys.At())[0].vis;
            self->UpdateAll(0.0f);
            self->mPlaying = 0;
            break;
        }
        }
        return 1;
    }
    return cGOBJ_HandleMessage(self, m);
}
#undef D_004F7C28 /* merge_units */
static inline void merge_flush_func_0023E890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E890 */

/* merge_units: begin func_0023E9B0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "gobj_flag_slot16.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "nievent_v10.h"
#pragma pop

#pragma cplusplus on

/* Call slot 16 unless the object is active. */
DEFINE_GOBJ_FLAG_SLOT16(cNIEventBase_CriticalNextFrame)
static inline void merge_flush_func_0023E9B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E9B0 */

/* merge_units: begin func_0023EA10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Event virtual 10: call slot 66 while inactive. */
DEFINE_NIEVENT_V10(cNIEventBase_NextFrame)
static inline void merge_flush_func_0023EA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023EA10 */

/* merge_units: begin func_0023EA50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg { void* vt; char pad04[0x20]; int i24; char pad28[8]; };
struct Obj_0023EA50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(float);
    char pad04[0x28];
    unsigned char f2C; unsigned char f2D; unsigned char f2E; char pad2F[0x31];
    int i60;
    char pad64[0x78];
    unsigned char bDC;
    char padDD[0x53];
    unsigned char b130;
    char pad131[3];
    float f134;
};
extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg0023E720 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(Msg*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg0023E720 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(Msg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg0023E720 *)(a0), (a1))) /* merge_units */

void cGOBJ_NextFrame(Obj_0023EA50*, float);
}
/* Active flags: the && chain must materialise as a bool (sltu/xori), hence the inline. */
static inline bool Act(Obj_0023EA50* o) { return o->f2D && o->f2C && !o->f2E; }
extern "C" void cNIEventBase_ProcessNextFrame(Obj_0023EA50* o, float dt)
{
    unsigned char b = o->b130;
    if (b || (o->i60 == 3 && o->bDC && Act(o))) {
        float x = dt * o->f134; o->v75(b ? x : 0.0f);
        if (b && !o->b130) {
            Msg m;
            cMessage_ctor_cMessageNameR(&m, D_004F7C30);
            m.vt = D_004DBEB0;
            m.i24 = 0;
            QueueMessage_cMessageR_cSystemP_int(&m, o, 0);
            m.vt = D_004DBEB0;
            cMessage_dtor(&m, 0);
        }
    }
    cGOBJ_NextFrame(o, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023EA50(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023EA50 */
