/*
 * SFOGame/Source/activation: 10 files, 00224180-00224A80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00224180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* eClassID is a one-byte enum; comparing through an eClassID local gives retail's
   register choice (byte in a0, pointer kept in v1). */
#pragma enumsalwaysint off
enum eClassID { CID_0, CID_GROUP = 0x10, CID_MAX = 0x7F };
#include "vslot_pad.h"

struct FileMan_4180 { int flags; char name[0x90]; unsigned char b94; };
struct Model_4180 { char p0[0x28]; int refs; };
struct GOBJ_4180 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int);
    virtual void Deactivate(int);
    unsigned int mMagic;
    char p8[0x2D - 8];
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char p2F[0x49 - 0x2F];
    eClassID mClassID;
    char p4A[0x4C - 0x4A];
    int mSubclassId;
    char p50[0x64 - 0x50];
    char mParentName[48];
};
struct VUM_4180 { char p0[0x64]; VUM_4180* mRefGroupGobj; Model_4180* mModel; char p6C[0x1E0 - 0x6C]; FileMan_4180* mVUMFile; };
struct Man_4180 { int list[3]; };
struct EqualTo_4180 { };
struct Binder_4180 {
    EqualTo_4180 op;
    GOBJ_4180* const* value;
    Binder_4180(const EqualTo_4180& x, GOBJ_4180* const& y) : op(x), value(&y) {}
};
static inline Binder_4180 Bind2nd_4180(const EqualTo_4180& op, GOBJ_4180* const& x) { return Binder_4180(op, x); }

extern "C" {
void std_list_imp_voidPtr_remove_if(Man_4180* l, Binder_4180 pred);
#if 0 /* merge_units */
VUM_4180* IsVUM(GOBJ_4180* g);
#endif /* merge_units */
int IsVUM(int a0); /* merge_units */
#define IsVUM(a0) ((VUM_4180 *)IsVUM((int)(a0))) /* merge_units */

extern char g_Game[];
extern int D_004F56B0;
#if 0 /* merge_units */
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void* game, const char* name, VUM_4180** out);
#endif /* merge_units */
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void*, const char*, void*); /* merge_units */
#define cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(a0, a1, a2) (cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP((a0), (a1), (void *)(a2))) /* merge_units */

void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(void* fsm, FileMan_4180* f, void* cb, void* data, int mode);
void cGOBJActivationMan_StreamCB(void);
void cGenerator_DeactivateImmediate(GOBJ_4180* g);
}


extern "C" void cGOBJActivationMan_Deactivate(Man_4180* self, GOBJ_4180* gobj, unsigned char actMode) {
    unsigned char deactivateFlag = 1;
    VUM_4180* vum;
    VUM_4180* loadedVUM;
    unsigned char foundFlag;
    EqualTo_4180 eq;
    std_list_imp_voidPtr_remove_if(self, Bind2nd_4180(eq, gobj));
    vum = IsVUM(gobj);
    if (vum && (vum->mVUMFile->flags & 4)) {
        FileMan_4180* file = vum->mVUMFile;
        loadedVUM = 0;
        eClassID c = gobj->mClassID;
        if (c == CID_GROUP) {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, gobj->mParentName, &loadedVUM);
        } else {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, file->name, &loadedVUM);
        }
        deactivateFlag = 0;
        if (foundFlag) {
            int& refs = vum->mModel->refs;
            if (refs > 0) {
                refs--;
            }
        }
        if (vum->mModel->refs == 0) {
            if (vum->mRefGroupGobj == 0) {
                cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(GetFileStreamMan(), file, (void*)cGOBJActivationMan_StreamCB, gobj, 0);
            }
        } else {
            deactivateFlag = 1;
        }
    }
    if (actMode == 1 && gobj->mSubclassId == D_004F56B0) {
        cGenerator_DeactivateImmediate(gobj);
    }
    if (gobj->mMagic == 0xBEBAAFDE && deactivateFlag) {
        gobj->Deactivate(0);
    }
    gobj->mActiveFlag = 0;
}
#undef IsVUM /* merge_units */
#undef cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP /* merge_units */
static inline void merge_flush_func_00224180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224180 */

/* merge_units: begin func_00224330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma enumsalwaysint off

struct FileMan_4330 { int flags; char name[0x90]; unsigned char b94; };
struct Model_4330 { char p0[0x28]; int refs; };
struct GOBJ_4330 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int);
    char p4[0x2D - 4];
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char p2F[0x49 - 0x2F];
    eClassID mClassID;
    char p4A[0x64 - 0x4A];
    char mParentName[48];
};
struct VUM_4330 { char p0[0x68]; Model_4330* mModel; char p6C[0x1E0 - 0x6C]; FileMan_4330* mVUMFile; };
struct Man_4330 { int list[3]; };

extern "C" {
void std_list_cGOBJPtr_push_back(Man_4330* l, GOBJ_4330** p);
#if 0 /* merge_units */
VUM_4330* IsVUM(GOBJ_4330* g);
#endif /* merge_units */
#define IsVUM(a0) ((VUM_4330 *)IsVUM((int)(a0))) /* merge_units */


#if 0 /* merge_units */
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void* game, const char* name, VUM_4330** out);
#endif /* merge_units */
#define cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(a0, a1, a2) (cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP((a0), (a1), (void *)(a2))) /* merge_units */


unsigned char cNIEventBase_AreVUMsActive(GOBJ_4330* self, int n);
void cFileStreamMan_StreamRequest(void* fsm, FileMan_4330* f, void* cb, void* data, int mode, unsigned char a, unsigned char b);
}


extern "C" void cGOBJActivationMan_Activate(Man_4330* self, GOBJ_4330* gobj, int mode) {
    unsigned char activateFlag = 1;
    unsigned char groupVUMFlag = 0;
    VUM_4330* vum;
    gobj->mStreamingFlag = 0;
    std_list_cGOBJPtr_push_back(self, &gobj);
    vum = IsVUM(gobj);
    if (vum && (vum->mVUMFile->flags & 4)) {
        FileMan_4330* file = vum->mVUMFile;
        VUM_4330* loadedVUM = 0;
        unsigned char foundFlag;
        eClassID c = gobj->mClassID;
        if (c == CID_GROUP) {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, gobj->mParentName, &loadedVUM);
        } else {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, file->name, &loadedVUM);
        }
        activateFlag = 0;
        if (foundFlag) {
            if (vum->mModel->refs == 0) {
                if (gobj->mClassID == 0x10) {
                    activateFlag = cNIEventBase_AreVUMsActive(gobj, 0);
                    groupVUMFlag = 1;
                    if (activateFlag && !file->b94) {
                        activateFlag = 0;
                    }
                }
            } else if (file->b94) {
                activateFlag = 1;
            }
            vum->mModel->refs++;
        }
        if (!activateFlag) {
            gobj->mStreamingFlag = 1;
            cFileStreamMan_StreamRequest(GetFileStreamMan(), file, (void*)cGOBJActivationMan_StreamCB, gobj, 0, 0, !groupVUMFlag);
        }
    }
    if (activateFlag) {
        gobj->Activate(0);
    }
    gobj->mActiveFlag = 1;

}
#undef IsVUM /* merge_units */
#undef cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP /* merge_units */
static inline void merge_flush_func_00224330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224330 */

/* merge_units: begin func_002244D0 */
#pragma push /* merge_units */
extern int cNIEventBase_GetVUMInTree(int);

int IsVUM(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = 0 + 1;
    a1 = *(unsigned char*)((char*)a0 + 73);
    cond = a1 != v1;
    v0 = 0;
    if (cond) goto L002244F0;
    v0 = a0;
    goto L00224520;
L002244F0:;
    v1 = 0 + 15;
    cond = a1 != v1;
    if (cond) goto L00224508;
    v0 = *(int*)((char*)a0 + 100);
    goto L00224520;
L00224508:;
    v1 = 0 + 16;
    cond = a1 != v1;
    if (cond) goto L00224520;
    v0 = cNIEventBase_GetVUMInTree(a0);
L00224520:;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_002244D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002244D0 */

/* merge_units: begin func_00224530 */
#pragma push /* merge_units */
extern signed char D_004F7530;
extern char D_004F7548[];
extern char D_004F7538[];
extern void std_list_deleter_voidPtr_ctor_void(void* obj);
extern void __register_global_object(void* obj, void* dtor, void* link);
#if 0 /* merge_units */
extern void cGOBJActivationMan_dtor(void);
#endif /* merge_units */
void* cGOBJActivationMan_dtor(void* self, short deleteFlag); /* merge_units */


/* Returns the lazily constructed static collection. */
void* GetGOBJActivationMan(void) {
    if (!D_004F7530) {
        std_list_deleter_voidPtr_ctor_void(D_004F7548);
        __register_global_object(D_004F7548, cGOBJActivationMan_dtor, D_004F7538);
        D_004F7530 = 1;
    }
    return D_004F7548;
}
static inline void merge_flush_func_00224530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224530 */

/* merge_units: begin func_00224590 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(cGOBJActivationMan_dtor, std_list_cGOBJPtr_dtor)
static inline void merge_flush_func_00224590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224590 */

/* merge_units: begin func_002245F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma always_inline on
#pragma inline_depth(8)
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Box { V mn; V mx; };
static inline int InBox(const V* p, const Box* b) {
    const V* hi = &b->mx;
    int r;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(b)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
extern "C" void std_vector_cGOBJPtr_ctor_void(void*);
extern "C" void cArray_cGOBJPtr_dtor(void*);
struct cArray { int a, b, c; unsigned char mCanExpand; };
static inline void cArray_Construct(cArray* t) { std_vector_cGOBJPtr_ctor_void(t); t->mCanExpand = 1; }
struct cHandle { int v; cHandle(int x) : v(x) {} };
struct cTerrain {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box* GetBounds();
    char pad04[8];
    cHandle mHandle;
    char pad10[0x1E4];
    cArray mActivationList;
};
struct cSafePtr {
    cTerrain* volatile mPtr;
    cHandle mHandle;
    bool IsNull() const { return !mPtr; }
    bool Matches() const { return mPtr->mHandle.v == mHandle.v; }
    bool Matches(cTerrain* p) const { return p->mHandle.v == mHandle.v; }
    bool IsValid() const { cTerrain* p = mPtr; return !p || Matches(p); }
    cTerrain* Raw() const { return mPtr; }
    cTerrain* Get() const { bool v = IsValid(); if (v) return Raw(); return 0; }
    void Set(cTerrain* p) { mPtr = p; mHandle = p ? p->mHandle : cHandle(-1); }
};
struct cActivationTracker { V position; cSafePtr terrainPiece; };
static inline bool InTerrain(cActivationTracker* t) { return t->terrainPiece.Get() ? (unsigned char)InBox(&t->position, t->terrainPiece.Get()->GetBounds()) : 0; }
extern "C" {
extern signed char D_004F7518;
extern cArray D_004A5B00;
extern char D_004F7520[];
void std_vector_cGOBJPtr_ctor_void(void*);
void __register_global_object(void* obj, void* dtor, void* link);
#if 0 /* merge_units */
cTerrain* nActivation_FindBestSectorInActivation(const V* p, cTerrain* t);
#endif /* merge_units */
struct GObj; /* merge_units */
struct V_00224AC0; /* merge_units */
struct Self; /* merge_units */
GObj* nActivation_FindBestSectorInActivation(const V_00224AC0* p, Self* self); /* merge_units */
#define nActivation_FindBestSectorInActivation(a0, a1) ((cTerrain *)nActivation_FindBestSectorInActivation((const V_00224AC0 *)(a0), (Self *)(a1))) /* merge_units */

#if 0 /* merge_units */
cTerrain* nActivation_GetClosestTerrainPiece(const V* p);
#endif /* merge_units */
struct LosRegion; /* merge_units */
struct V_002248A0; /* merge_units */
LosRegion* nActivation_GetClosestTerrainPiece(const V_002248A0* p); /* merge_units */
#define nActivation_GetClosestTerrainPiece(a0) ((cTerrain *)nActivation_GetClosestTerrainPiece((const V_002248A0 *)(a0))) /* merge_units */

cArray* nActivation_GetActivationFor(cActivationTracker* t);
}
cArray* nActivation_GetActivationFor(cActivationTracker* t)
{
    cTerrain* terrainPiece;
    if (!D_004F7518) {
        cArray* o = &D_004A5B00;
        cArray_Construct(o);
        __register_global_object(o, (void*)cArray_cGOBJPtr_dtor, D_004F7520);
        D_004F7518 = 1;
    }
    if (InTerrain(t)) {
        terrainPiece = t->terrainPiece.Get();
    } else {
        terrainPiece = nActivation_FindBestSectorInActivation(&t->position, t->terrainPiece.Get());
        if (!terrainPiece)
            terrainPiece = nActivation_GetClosestTerrainPiece(&t->position);
        t->terrainPiece.Set(terrainPiece);
    }
    return terrainPiece ? &terrainPiece->mActivationList : &D_004A5B00;
}
#undef nActivation_FindBestSectorInActivation /* merge_units */
#undef nActivation_GetClosestTerrainPiece /* merge_units */
static inline void merge_flush_func_002245F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002245F0 */

/* merge_units: begin func_002248A0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* nActivation_GetClosestTerrainPiece: nearest LOS region (by squared box distance) to a point.
   Iterator wraps its pointer in a nested struct so `it = b` is a block copy (lwc1/swc1);
   `it` declared first gets the top slot; dead `xx = &d` gives the duplicate addiu. */
#pragma always_inline on
#pragma inline_depth(8)
struct V_002248A0 {
    float x, y, z, w;
    V_002248A0() {}
    V_002248A0(const V_002248A0& o) { V_002248A0* d = this; const V_002248A0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box_002248A0 { V_002248A0 mn; V_002248A0 mx; };
/* per-axis distance from p to the box (0 inside), via VU0 sign flags */
static inline V_002248A0 BoxDelta(const V_002248A0* p, const Box_002248A0* b)
{
    V_002248A0 r;
    int f1, f2, t;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%4); lqc2 $vf2, 0x0(%5); lqc2 $vf3, 0x0(%6); vsub.xyz $vf4, $vf2, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; vsub.xyz $vf5, $vf1, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %1, $vi17; vmulx.xyzw $vf6, $vf0, $vf0x; andi %2, %0, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf4, $vf0x; andi %2, %1, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf5, $vf0x; 1: andi %2, %0, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf4, $vf0x; andi %2, %1, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf5, $vf0x; 2: andi %2, %0, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf4, $vf0x; andi %2, %1, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf5, $vf0x; 3: sqc2 $vf6, 0x0(%3); .set reorder"
        : "=r"(f1), "=r"(f2), "=r"(t) : "r"(&r), "r"(p), "r"(&b->mn), "r"(&b->mx) : "memory");
    return r;
}
struct LosRegion {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box_002248A0* GetBounds();
};
struct ItP { LosRegion** p; };
struct It {
    ItP q;
    bool operator==(const It& o) const { LosRegion** b = o.q.p; return q.p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
    It& operator++() { ++q.p; return *this; }
};
extern "C" {
extern void* D_004FFD48;
#if 0 /* merge_units */
void* cObjList_cTerrainPtr_GetList(void* list);
#endif /* merge_units */
void* cObjList_cTerrainPtr_GetList(char* self); /* merge_units */
#define cObjList_cTerrainPtr_GetList(a0) (cObjList_cTerrainPtr_GetList((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_cTerrainPtr_Begin(It* it, void* node);
#endif /* merge_units */
void cArray_cTerrainPtr_Begin(Iter* out, PtrVec* v); /* merge_units */
#define cArray_cTerrainPtr_Begin(a0, a1) (cArray_cTerrainPtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cTerrainPtr_End(It* it, void* node);
#endif /* merge_units */
void cArray_cTerrainPtr_End(Iter* out, PtrVec* v); /* merge_units */
#define cArray_cTerrainPtr_End(a0, a1) (cArray_cTerrainPtr_End((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

}
extern "C" LosRegion* nActivation_GetClosestTerrainPiece(const V_002248A0* p)
{
    void* list = D_004FFD48;
    float best = 3.4028235e38f;
    LosRegion* found = 0;
    It it;
    It e;
    cArray_cTerrainPtr_End(&e, cObjList_cTerrainPtr_GetList(list));
    It b;
    cArray_cTerrainPtr_Begin(&b, cObjList_cTerrainPtr_GetList(list));
    for (it = b; it != e; ++it) {
        LosRegion* r = *it.q.p;
        V_002248A0 d = BoxDelta(p, r->GetBounds());
        void* xx = &d;
        float l = d.LenSq();
        if (l < best) {
            found = r;
            best = l;
            if (l == 0.0f)
                break;
        }
    }
    return found;
}
#undef cObjList_cTerrainPtr_GetList /* merge_units */
#undef cArray_cTerrainPtr_Begin /* merge_units */
#undef cArray_cTerrainPtr_End /* merge_units */
static inline void merge_flush_func_002248A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002248A0 */

/* merge_units: begin func_00224A80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cArray_cTerrainPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void cArray_cTerrainPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void* cObjList_cTerrainPtr_GetList(char* self) {
    return self + 4;
}
static inline void merge_flush_func_00224A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224A80 */

/* merge_units: begin func_00224AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_00224AC0;
static inline void SubV(V_00224AC0* r, const V_00224AC0* a, const V_00224AC0* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct V_00224AC0 {
    float x, y, z, w;
    V_00224AC0() {}
    V_00224AC0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00224AC0(const V_00224AC0& o) { V_00224AC0* d = this; const V_00224AC0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V_00224AC0 operator-(const V_00224AC0& o) const {
        V_00224AC0 r;
        SubV(&r, this, &o);
        return r;
    }
    float Dot(const V_00224AC0& o) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 0x6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box_00224AC0 {
    V_00224AC0 mn; V_00224AC0 mx;
    bool IsEmpty() const { return mn.x > mx.x; }
    V_00224AC0 Size() const { return IsEmpty() ? V_00224AC0(0.0f, 0.0f, 0.0f, 0.0f) : mx - mn; }
};
static inline float Dot(const V_00224AC0& a, const V_00224AC0& b) { const V_00224AC0& aa = a; return aa.Dot(b); }
static inline int InBox_00224AC0(const V_00224AC0* p, const Box_00224AC0* b) {
    const V_00224AC0* hi = &b->mx;
    int r;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(b)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
struct GObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box_00224AC0* GetBounds();
    char pad04[0x45];
    unsigned char x49;
    char pad4A[2];
    int x4C;
    bool Own();
};
struct LPVec { int count; int cap; GObj** data; };
struct LItP { GObj** p; };
struct LIt {
    LItP q;
    bool operator==(const LIt& o) const { GObj** b = o.q.p; return q.p == b; }
    bool operator!=(const LIt& o) const { return !(*this == o); }
    GObj*& operator*() const { return *q.p; }
    LIt& operator++() { q.p++; return *this; }
};
struct Self { char pad[0x1F4]; LPVec list; };
extern "C" {
extern GObj** std_vector_imp_cGOBJPtr_1_end_void_2(LPVec* v);
extern LIt std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(LPVec* self, GObj** const& src);
extern LIt std_vector_cGOBJPtr_begin(LPVec* v);
extern LIt cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(const LIt& s);
extern int D_004EE780;
GObj* nActivation_FindBestSectorInActivation(const V_00224AC0* p, Self* self);
}
static inline void EndO(LIt* o, LPVec* v) { o->q.p = std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(v, std_vector_imp_cGOBJPtr_1_end_void_2(v)).q.p; }
static inline LIt FirstI(LPVec* v) { return cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(std_vector_cGOBJPtr_begin(v)); }
inline bool GObj::Own() { int d = D_004EE780; return x4C == d; }
GObj* nActivation_FindBestSectorInActivation(const V_00224AC0* p, Self* self)
{
    GObj* found = 0;
    if (self) {
        float best = 0.0f;
        LPVec* v = &self->list;
        LIt cur;
        LIt last;
        EndO(&last, v);
        for (cur = FirstI(v); cur != last; ++cur) {
            GObj* o = *cur;
            if (o && o->x49 == 1 && o->Own()) {
                const Box_00224AC0* b = o->GetBounds();
                if ((unsigned char)InBox_00224AC0(p, b)) {
                    float d = Dot(b->Size(), b->Size());
                    if (!(d <= best)) {
                        best = d;
                        found = o;
                    }
                }
            }
        }
    }
    return found;
}
static inline void merge_flush_func_00224AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224AC0 */

/* merge_units: begin func_00224D80 */
#pragma push /* merge_units */
#pragma cplusplus on
/* nActivation_GetFirstTerrainPieceOnGobjList: first entry of the global list, or 0 when empty */
struct Pt1FlIt {
    int* p;
    bool operator==(const Pt1FlIt& o) const { return p == o.p; }
    bool operator!=(const Pt1FlIt& o) const { return !(*this == o); }
};
extern "C" {
#if 0 /* merge_units */
void* cObjList_cTerrainPtr_GetList(void* list);
#endif /* merge_units */
#define cObjList_cTerrainPtr_GetList(a0) (cObjList_cTerrainPtr_GetList((char *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cArray_cTerrainPtr_Begin(Pt1FlIt* it, void* node);
#endif /* merge_units */
#define cArray_cTerrainPtr_Begin(a0, a1) (cArray_cTerrainPtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
void cArray_cTerrainPtr_End(Pt1FlIt* it, void* node);
#endif /* merge_units */
#define cArray_cTerrainPtr_End(a0, a1) (cArray_cTerrainPtr_End((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


}
extern "C" int nActivation_GetFirstTerrainPieceOnGobjList(void)
{
    void* list = D_004FFD48;
    Pt1FlIt b;
    Pt1FlIt e;
    int r;
    cArray_cTerrainPtr_Begin(&b, cObjList_cTerrainPtr_GetList(list));
    r = 0;
    cArray_cTerrainPtr_End(&e, cObjList_cTerrainPtr_GetList(list));
    if (b != e)
        r = *b.p;
    return r;
}
#undef cObjList_cTerrainPtr_GetList /* merge_units */
#undef cArray_cTerrainPtr_Begin /* merge_units */
#undef cArray_cTerrainPtr_End /* merge_units */
static inline void merge_flush_func_00224D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224D80 */
