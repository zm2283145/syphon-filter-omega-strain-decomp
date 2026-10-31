#pragma bool off
#pragma cplusplus on
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { void* xx = this; G1(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4];
    M() {}
    const V& GetTrans() const { return r[3]; }
    M(const M& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
struct tRGBA { float r, g, b, a; };
struct tIRGBA { int r, g, b, a; };
struct tFogEnv { float min, max, fnear, ffar; tIRGBA color; tRGBA colorf; char pad[0x50]; };
struct cUserFrameEnv { char pad[0x14]; };
struct XLib {
    char pad0[0x150];
    tFogEnv fog;
    char pad1[0xA74 - 0x1D0];
    int viewNum;
    char pad2[0xA80 - 0xA78];
    M viewStack[16];
    char pad3[0xFA0 - 0xE80];
    V lookatVec;
    char pad4[0x1068 - 0xFB0];
    cUserFrameEnv userFrameEnvs[6];
};
struct cBox;
struct cXform;
struct cGOBJ;
struct cVUM_GOBJ;
#define VV4(a,b,c,d) virtual void a(); virtual void b(); virtual void c(); virtual void d();
#define VV16(p) VV4(p##0,p##1,p##2,p##3) VV4(p##4,p##5,p##6,p##7) VV4(p##8,p##9,p##a,p##b) VV4(p##c,p##d,p##e,p##f)
class cXform {
public:
    VV16(x0) VV4(y0,y1,y2,y3)
    virtual void Update();
    char pad[0xC]; M localToWorld; unsigned char needsUpdate;
    M* GetLocalToWorld() { if (needsUpdate) Update(); return &localToWorld; }
};
class cGOBJ {
public:
    VV16(a0) VV16(a1)
    virtual cBox* GetBBox();
    VV16(b0) VV16(b1) VV4(c0,c1,c2,c3) virtual void c4(); virtual void c5();
    virtual cVUM_GOBJ* GetVUM();
    char pad[0x28];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    unsigned char mIsRenderable;
    int mMotionUpdatePriority;
    int mRefCount;
    unsigned int mDrawCode;
    float mSortKey;
    float mHitpoints;
    int mDarkness;
    unsigned char mWasXformCreated;
    signed char mClassID;
    int mSubclassId;
    cXform* mXform;
    void* mMovement;
    void* mController;
    cGOBJ* m_AllAboard;
};struct tVUMHeader { int a; unsigned int flags; };
struct cVU1Model { char* memHead; tVUMHeader* vumFile; char pad[0x1C]; unsigned int ctxtFlags; };
struct cVUM_GOBJ : cGOBJ { cVUM_GOBJ* mRefGobj; cVUM_GOBJ* mRefGroupGobj; cVU1Model* mModel; };
struct cLight_GOBJ : cGOBJ { char pad2[8]; int type; };
struct cSKM_GOBJ : cGOBJ { char pad[0x2C4C - 0x60]; short h; };
struct cVisionFxMan { int mode; };
struct FC { unsigned int size; cGOBJ* array[1024]; };
struct It { cGOBJ** p; It& operator++() { p++; return *this; } };
struct cVector;

extern "C" {
void* nGobjManager_GetGOBJList(void);
void cBBoxMan_InitSingleVisibilityTest(void*);
void* cObjList_cGOBJPtr_GetList(void*);
void cArray_cGOBJPtr_Begin(It*, void*);
void cArray_cGOBJPtr_End(It*, void*);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It*, It*);
void cBBoxMan_SingleVisibilityTest(void*, cBox*, M*, unsigned int*, float*);
int cNIEventOBJ_GetPAR(cGOBJ*);
M cMatrix_Copy_InvertRotTrans(const M*);
void cVisionFxMan_ActivateFx(cVisionFxMan*);
void cLightMan_BuildVisibleLightSubset(void*);
void cShadowMan_ClearCasters(void*);
void cShadowMan_ClearReceivers(void*);
void ProcessShadows(FC*);
void cShadowMan_ProcessShadows(void*);
void cDecalMan_PreRender(void*);
void BatchDraw(FC*, int);
void qsort(void*, unsigned int, unsigned int, int (*)(const void*, const void*));
int CompareVUMs(const void*, const void*);
void cWaterFx_Render(void*);
void XLib_FrameBuffToUserEnv(XLib*, int);
void cDecalMan_Render(void*);
void nDynamicSfxList_Render(void);
void cVisionFxMan_DrawLightSfx(cVisionFxMan*, FC*);
void cVisionFxMan_DrawLightGlows(cVisionFxMan*, FC*, int);
void cUserFrameEnv_ReleaseVram(cUserFrameEnv*);
void cVisionFxMan_DrawLensFlares(cVisionFxMan*);
void cVisionFxMan_DeactivateFx(cVisionFxMan*);
void XLib_UpdateFogParms(XLib*);
void XLib_ClearZBuffer(XLib*);
extern XLib g_Video;
extern char g_LightMgr[];
extern cVisionFxMan* g_VisionFxMan;
extern void* D_004FFC34;
extern void* g_DecalMgr;
extern char D_00542DC0[];
extern char D_00543790[];
}

static inline It BeginIt(void* l) { It t; It r; cArray_cGOBJPtr_Begin(&t, cObjList_cGOBJPtr_GetList(l)); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&r, &t); return r; }
static inline It EndIt(void* l) { It t; It r; cArray_cGOBJPtr_End(&t, cObjList_cGOBJPtr_GetList(l)); cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&r, &t); return r; }
#pragma bool on
static inline bool Eq(const It& a, const It& b) { cGOBJ** q = b.p; return a.p == q; }
static inline bool Ne(const It& a, const It& b) { return !Eq(a, b); }
static inline void Add(FC& l, cGOBJ* g) { if (l.size < 1024) { l.array[l.size] = g; l.size++; } }
static inline bool IsActive(cGOBJ* g) { bool a = false; if (g->mActiveFlag && g->mEnabled) a = true; return a; }
static inline int IsStreaming(cGOBJ* g) { return g->mStreamingFlag; }
static inline bool IsNotStreaming(cGOBJ* g) { return !(bool)g->mStreamingFlag; }
static inline bool IsActiveAndLoaded(cGOBJ* g) { bool r = false; if (IsActive(g) && IsNotStreaming(g)) r = true; return r; }
static inline unsigned char IsRenderable(cGOBJ* g) { if (!IsActiveAndLoaded(g)) return false; return g->mIsRenderable; }
#pragma bool off
static inline unsigned char ClassOf(cGOBJ* g) { return *(unsigned char*)&g->mClassID; }
static inline unsigned char ClassS(cGOBJ* g) { return (unsigned char)g->mClassID; }
static inline int CI(cGOBJ* g) { return g->mClassID & 0xFF; }
static inline int IsVUM(cGOBJ* g) { return CI(g) == 1 || CI(g) == 15 || (CI(g) == 16 && g->GetVUM()); }
static inline cVUM_GOBJ* GetVUM(cGOBJ* g) {
    if (CI(g) == 1) return (cVUM_GOBJ*)g;
    if (CI(g) == 16) return g->GetVUM();
    return ((cVUM_GOBJ*)g)->mRefGroupGobj;
}
static inline int IsLoaded(cVU1Model* m) { return m->memHead ? 1 : 0; }
static inline void SetFogRange(XLib* x, float n, float f) { x->fog.fnear = n; x->fog.ffar = f; }
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline void SetFogColor(XLib* x, float r, float g, float b) {
    r *= 256.0f;
    g *= 256.0f;
    b *= 256.0f;
    x->fog.colorf.r = r;
    x->fog.colorf.g = g;
    x->fog.colorf.b = b;
    x->fog.colorf.a = 256.0f;
    x->fog.color.r = F2I(r);
    x->fog.color.g = F2I(g);
    x->fog.color.b = F2I(b);
    x->fog.color.a = 128;
}

extern "C" void cScene_Render(void* self)
{
    void* gobjList = nGobjManager_GetGOBJList();
    FC skyboxDrawList;
    FC opvumDrawList;
    FC skmDrawList;
    FC ftvumDrawList;
    FC stvumDrawList;
    FC dtvumDrawList;
    FC glowStatDrawList;
    FC glowDynoDrawList;
    FC fgroundDrawList;
    FC interfaceList;
    It gobjItr;
    cGOBJ* gobj;
    cBox* box;
    cXform* xform;
    M* mat;
    unsigned int dcode;
    float zval;
    It end;
    It tb;
    It te;
    cBBoxMan_InitSingleVisibilityTest(D_00542DC0);
    skyboxDrawList.size = 0;
    opvumDrawList.size = 0;
    skmDrawList.size = 0;
    ftvumDrawList.size = 0;
    stvumDrawList.size = 0;
    dtvumDrawList.size = 0;
    glowStatDrawList.size = 0;
    glowDynoDrawList.size = 0;
    fgroundDrawList.size = 0;
    interfaceList.size = 0;
    cArray_cGOBJPtr_Begin(&tb, cObjList_cGOBJPtr_GetList(gobjList));
    cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&gobjItr, &tb);
    goto test;
    loop: {
        cGOBJ** pp = gobjItr.p;
        gobj = *pp;
        gobj->mDrawCode = 0x80;
        if (IsRenderable(gobj)) {
            gobj->mDrawCode = 2;
            box = gobj->GetBBox();
            if (box) {
                xform = gobj->mXform;
                mat = 0;
                if (xform) {
                    mat = xform->GetLocalToWorld();
                }
                cBBoxMan_SingleVisibilityTest(D_00542DC0, box, mat, &dcode, &zval);
                gobj->mDrawCode = dcode;
                gobj->mSortKey = zval;
            }
        }
        if (gobj->mDrawCode != 0x80) {
            if (ClassOf(gobj) == 15 && ((cLight_GOBJ*)gobj)->type == 4) {
                Add(glowDynoDrawList, gobj);
            } else if (ClassOf(gobj) == 15 && ((cLight_GOBJ*)gobj)->type == 6) {
                Add(glowStatDrawList, gobj);
            } else if (CI(gobj) == 1 || CI(gobj) == 15 || (CI(gobj) == 16 && gobj->GetVUM())) {
                cVUM_GOBJ* vum = GetVUM(gobj);
                if (IsLoaded(vum->mModel)) {
                    if (vum->mModel->vumFile->flags & 8) {
                        Add(dtvumDrawList, gobj);
                    } else if (vum->mModel->ctxtFlags & 0x800000) {
                        Add(ftvumDrawList, gobj);
                    } else if (vum->mModel->ctxtFlags & 0x400000) {
                        Add(stvumDrawList, gobj);
                    } else {
                        Add(opvumDrawList, gobj);
                    }
                }
            } else {
                if (CI(gobj) == 13) {
                    Add(interfaceList, gobj);
                } else if (CI(gobj) == 2) {
                    cSKM_GOBJ* skm = (cSKM_GOBJ*)gobj;
                    int fg = skm->h != 0x80;
                    if (!fg) {
                        Add(skmDrawList, gobj);
                    } else {
                        Add(fgroundDrawList, gobj);
                    }
                } else if (CI(gobj) == 3) {
                    Add(opvumDrawList, gobj);
                } else if (CI(gobj) == 4 || (CI(gobj) == 16 && cNIEventOBJ_GetPAR(gobj))) {
                    Add(stvumDrawList, gobj);
                } else if (ClassOf(gobj) == 5) {
                    Add(skyboxDrawList, gobj);
                }
            }
        }
        gobjItr.p++;
    }
    test:
    cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(gobjList));
    cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te);
    if (Ne(gobjItr, end)) goto loop;
    {
        g_Video.lookatVec = cMatrix_Copy_InvertRotTrans(&g_Video.viewStack[g_Video.viewNum]).GetTrans();
    }
    cVisionFxMan_ActivateFx(g_VisionFxMan);
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    cShadowMan_ClearCasters(D_00543790);
    cShadowMan_ClearReceivers(D_00543790);
    ProcessShadows(&opvumDrawList);
    ProcessShadows(&skmDrawList);
    ProcessShadows(&stvumDrawList);
    ProcessShadows(&dtvumDrawList);
    ProcessShadows(&fgroundDrawList);
    cShadowMan_ProcessShadows(D_00543790);
    cDecalMan_PreRender(g_DecalMgr);
    BatchDraw(&skyboxDrawList, 0);
    if (opvumDrawList.size)
        qsort(opvumDrawList.array, opvumDrawList.size - 1, 4, CompareVUMs);
    BatchDraw(&opvumDrawList, 0);
    if (g_VisionFxMan->mode != 2)
        BatchDraw(&skmDrawList, 1);
    if (ftvumDrawList.size)
        qsort(ftvumDrawList.array, ftvumDrawList.size - 1, 4, CompareVUMs);
    BatchDraw(&ftvumDrawList, 0);
    XLib_FrameBuffToUserEnv(&g_Video, 0);
    BatchDraw(&dtvumDrawList, 0);
    BatchDraw(&stvumDrawList, 1);
    cWaterFx_Render(D_004FFC34);
    cDecalMan_Render(g_DecalMgr);
    nDynamicSfxList_Render();
    BatchDraw(&glowStatDrawList, 0);
    cVisionFxMan_DrawLightSfx(g_VisionFxMan, &glowStatDrawList);
    cVisionFxMan_DrawLightGlows(g_VisionFxMan, &glowDynoDrawList, 0);
    if (g_VisionFxMan->mode != 2)
        BatchDraw(&fgroundDrawList, 0);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[0]);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[1]);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[2]);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[3]);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[4]);
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[5]);
    cVisionFxMan_DrawLensFlares(g_VisionFxMan);
    cVisionFxMan_DeactivateFx(g_VisionFxMan);
    if (g_VisionFxMan->mode == 2) {
        float kFogColScl = 1.0f / 255.0f;
        tRGBA resColF;
        float fnear;
        float ffar;
        const float thermalFogNear = 0.95f;
        resColF = g_Video.fog.colorf;
        resColF.a = 0.0f;
        resColF.r *= kFogColScl;
        resColF.g *= kFogColScl;
        resColF.b *= kFogColScl;
        fnear = g_Video.fog.fnear;
        ffar = g_Video.fog.ffar;
        SetFogRange(&g_Video, thermalFogNear * ffar, ffar);
        SetFogColor(&g_Video, 0.0f, 0.0f, 1.0f);
        XLib_UpdateFogParms(&g_Video);
        XLib_ClearZBuffer(&g_Video);
        BatchDraw(&skmDrawList, 1);
        BatchDraw(&fgroundDrawList, 0);
        SetFogRange(&g_Video, fnear, ffar);
        SetFogColor(&g_Video, resColF.r, resColF.g, resColF.b);
        XLib_UpdateFogParms(&g_Video);
    }
    cUserFrameEnv_ReleaseVram(&g_Video.userFrameEnvs[5]);
    BatchDraw(&interfaceList, 0);
}



