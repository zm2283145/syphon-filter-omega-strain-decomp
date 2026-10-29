#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { const cVector* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    cVector& operator=(const cVector& o) { cVector* pd = this; const cVector* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    cVector operator-(const cVector& b) const {
        cVector r; cVector* pr = &r; const cVector* pa = this; const cVector* pb = &b;
        asm { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
        return r;
    }
    cVector operator+(const cVector& b) const {
        cVector r; cVector* pr = &r; const cVector* pa = this; const cVector* pb = &b;
        asm { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
        return r;
    }
    cVector operator*(float s) const {
        cVector r; cVector* pr = &r; const cVector* pa = this; __int128 t = 0; float k = s;
        asm { .set noreorder; lqc2 vf1, 0x0(pa); mfc1 t, k; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(pr); .set reorder }
        return r;
    }
    float Length() const {
        float r = 0.0f; const cVector* p = this; int t;
        asm { lqc2 vf1, 0x0(p); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni t, vf4; mtc1 t, r }
        return r;
    }
} __attribute__((aligned(16)));

struct cBox {
    cVector min;
    cVector max;
    cBox(const cVector& mn, const cVector& mx) : min(mn), max(mx) {}
    bool IsEmpty() const { return min.x > max.x; }
    void Extend(const cVector& p) {
        cVector* lo = &min; cVector* hi = &max; const cVector* pp = &p;
        asm { lqc2 vf1, 0(lo); lqc2 vf2, 0(hi); lqc2 vf3, 0(pp); vmini.xyz vf1, vf1, vf3; vmax.xyz vf2, vf2, vf3; sqc2 vf1, 0(lo); sqc2 vf2, 0(hi) }
    }
    cBox& operator+=(const cBox& b) { if (b.min.x <= b.max.x) { Extend(b.min); Extend(b.max); } return *this; }
    cVector GetSize() const { return IsEmpty() ? cVector(0.0f, 0.0f, 0.0f, 0.0f) : max - min; }
    cVector GetCenter() const { cVector c = (min + max) * 0.5f; return c; }
};

struct cFileMan { char b[0xA0]; };
struct tHogHeader { int pad; int mNumBlocks; };
struct cHogFile {
    char pad[0x148];
    tHogHeader* mHogHeader;
    unsigned char mHogOpenMode;
};
struct cHogList { char pad[0xC]; };
struct cObjectId { int mId; cObjectId(int i) : mId(i) {} };

struct tVUMLoad {
    cFileMan& vumFile;
    cFileMan& texFile;
    void* refVUM;
    void* refGroupVUM;
    char* groupModelName;
    tVUMLoad(cFileMan& v, cFileMan& t) : vumFile(v), texFile(t), refVUM(0), refGroupVUM(0), groupModelName(0) {}
};

struct cVUM_GOBJ {
    virtual void Destroy(int f);
    virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void SetFlag40(int f);
    virtual void Load(tVUMLoad* l);
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58();
    virtual void SetFlag5C(int f);
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84();
    virtual cBox* GetBBox();
};

struct cInterfaceModel;
struct cInterface { cInterfaceModel* mModel; };

extern "C" void std_vector_cVUM_GOBJPtr_ctor(void* a);
struct cArray { char vec[0xC]; unsigned char mOwns; cArray() { std_vector_cVUM_GOBJPtr_ctor(this); mOwns = 1; } };
struct cHudTargetsObserver { int m0; virtual void Notify(); cHudTargetsObserver() {} };

struct cMap {
    int m0;
    void* vt;
    cInterface* mInterface;
    void* mSelfController;
    cArray mMapParts;
    char pad20[0x40];
    int mCurrentTarget;
    int mPreviousTarget;
};

struct cLevelInfo { char pad[0xC4]; int mLevelID; const int& GetLevelID() const { return mLevelID; } };
struct cGameMan { char pad[0x188]; cLevelInfo mLevel; const cLevelInfo& GetLevel() const { return mLevel; } };

extern "C" {
extern char D_004DC930[];
extern char D_004DCBB0[];
extern char D_004A8808[];
extern char D_004A8810[];
extern char D_004A8830[];
extern char D_004A8850[];
extern char D_004A8870[];
extern char D_004A8890[];
extern char D_0048B2F8[];
extern char g_LevelDirName[];
extern char D_004A88A8[];
extern char D_004FF0C0[];
extern char D_004FF0D0[];
extern cInterfaceModel* D_004FFD70;
extern cInterfaceModel* D_004FFD68;
extern cInterfaceModel* D_004FFD78;
extern cInterfaceModel* D_004FFD80;
extern cGameMan* D_004FFC04;
extern float D_004ACCE0[];
extern unsigned char D_004FF058;
extern float D_0048B278;
extern float D_0048B280;
extern float D_0048B288;
extern float D_004FF084;
extern float D_0048B290;
extern float D_0048B298;
extern float D_0048B2A0;
extern float D_0048B2A8;

cInterface* LoadInterface_charP_cHogListR(const char* name, cHogList& hl);
void cInterfaceModel_Activate(cInterfaceModel* m, int a, int b);
cInterfaceModel* cInterfaceModel_GetChild(cInterfaceModel* m, const char* name);
void func_003EE5E0(cInterfaceModel* m, void* c);
void cInterfaceModel_SetPerspective(cInterfaceModel* m, int on);
int sprintf(char* buf, const char* fmt, ...);
cHogFile* cHogList_Open(cHogList& hl, const char* name, int a, int b);
void cFileMan_ctor_void(cFileMan* f);
char* cHogFile_GetBlockName(cHogFile* h, int i);
char* strrchr(const char* s, int c);
int strcmp(const char* a, const char* b);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(cFileMan* f, char* name, cHogFile* h, int b);
int cFileMan_Open(cFileMan* f);
void cFileMan_Close(cFileMan* f);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
cVUM_GOBJ* cVUM_GOBJ_ctor_cObjectIdR(void* p, const cObjectId& id);
void std_vector_cVUM_GOBJPtr_push_back(cArray* a, cVUM_GOBJ** p);
void cMAP_GOBJ_SetScale(float s);
float Libc_Sinf(float x);
float Libc_Atanf(float x);
void cMap_ResetCamera(cMap* m);
void cFileMan_dtor(cFileMan* f, int flags);
}

/* min.s / max.s have no C form in MW */
static inline void SfoDelete(cVUM_GOBJ* p) { AllocGuard g; p->Destroy(-1); cMemMan_Deallocate(0, p, D_004A8808, 0xFB); }
static inline float AbsF(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void* SfoNew(int sz, char* f, int l) { AllocGuard g; return cMemMan_Allocate(0, sz, f, l); }
static inline float MinF(float a, float b) { float r = 0.0f; r = a; asm { min.s r, r, b } return r; }
static inline float MaxF(float a, float b) { float r = 0.0f; r = b; asm { max.s r, a, r } return r; }
static inline float MinP(float a, float b) { asm { min.s a, a, b } return a; }
static inline float MinR(float a, float b) { float r = 0.0f; r = b; asm { min.s r, r, a } return r; }
static inline float MinQ(float a, float b) { float r = 0.0f; asm { mov.s r, a; min.s r, r, b } return r; }
static inline float MinS(float a, float b) { float r = 0.0f; r = a; asm { min.s r, r, b } return r; }
static inline float ClampR(float x, float lo, float hi) { float r = 0.0f; r = lo; asm { max.s r, x, r; min.s r, r, hi } return r; }
static inline float ClampS(float x, float lo, float hi) { float r = 0.0f; r = lo; asm { max.s r, x, r } asm { min.s r, r, hi } return r; }
static inline float ClampT(float x, float lo, float hi) { float r = 0.0f; r = lo; asm { max.s r, x, r } return MinP(r, hi); }
static inline float MaxR(float a, float b) { float r = 0.0f; r = b; asm { max.s r, a, r } return r; }
static inline float ClampF(float x, float lo, float hi) { asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }

extern "C" cMap* cMap_ctor(cMap* self, cHogList& hogList, const char* mapFname)
{
    self->vt = D_004DC930;
    self->vt = D_004DCBB0;
    cArray* parts = &self->mMapParts;
    std_vector_cVUM_GOBJPtr_ctor(parts);
    parts->mOwns = 1;
    self->mCurrentTarget = -1;
    self->mPreviousTarget = -1;
    self->mInterface = LoadInterface_charP_cHogListR(mapFname, hogList);
    cInterfaceModel_Activate(self->mInterface->mModel, 0, 0);
    D_004FFD70 = cInterfaceModel_GetChild(self->mInterface->mModel, D_004A8810);
    D_004FFD68 = cInterfaceModel_GetChild(self->mInterface->mModel, D_004A8810);
    D_004FFD78 = cInterfaceModel_GetChild(self->mInterface->mModel, D_004A8830);
    D_004FFD80 = cInterfaceModel_GetChild(self->mInterface->mModel, D_004A8850);
    func_003EE5E0(D_004FFD78, D_004FF0C0);
    func_003EE5E0(D_004FFD80, D_004FF0D0);
    cInterfaceModel_SetPerspective(D_004FFD70, 1);
    cInterfaceModel_SetPerspective(D_004FFD68, 1);
    cInterfaceModel_SetPerspective(D_004FFD78, 1);
    cInterfaceModel_SetPerspective(D_004FFD80, 1);

    char texName[128];
    char vumName[128];
    sprintf(texName, D_004A8870, D_0048B2F8, g_LevelDirName);
    sprintf(vumName, D_004A8890, D_0048B2F8, g_LevelDirName);
    cHogFile& texHog = *cHogList_Open(hogList, texName, 0, 0);
    cHogFile& vumHog = *cHogList_Open(hogList, vumName, 0, 0);
    if (!texHog.mHogOpenMode || !vumHog.mHogOpenMode)
        return self;

    cFileMan vumFile;
    cFileMan_ctor_void(&vumFile);
    cFileMan texFile;
    cFileMan_ctor_void(&texFile);
    int numParts = vumHog.mHogHeader->mNumBlocks;
    cBox vumBounds(cVector(-10.0f, -10.0f, -10.0f, 1.0f), cVector(10.0f, 10.0f, 10.0f, 1.0f));
    for (int i = 0; i < numParts; i++) {
        char* blockName = cHogFile_GetBlockName(&vumHog, i);
        char* ext = strrchr(blockName, '.');
        if (!ext) ext = blockName;
        if (strcmp(ext, D_004A88A8) == 0) {
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&vumFile, blockName, &vumHog, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&texFile, blockName, &texHog, 0);
            cFileMan_Open(&texFile);
            if (!(unsigned char)cFileMan_Open(&vumFile)) {
                cVUM_GOBJ* part;
                cVUM_GOBJ* m = (cVUM_GOBJ*)SfoNew(0x1F4, D_004A8808, 0xE1);
                if (m) m = cVUM_GOBJ_ctor_cObjectIdR(m, cObjectId(0));
                part = m;
                tVUMLoad vumLoad(vumFile, texFile);
                part->SetFlag40(0);
                part->Load(&vumLoad);
                part->SetFlag5C(0);
                cFileMan_Close(&vumFile);
                cFileMan_Close(&texFile);
                cBox* box = part->GetBBox();
                if (box) {
                    std_vector_cVUM_GOBJPtr_push_back(&self->mMapParts, &part);
                    vumBounds += *box;
                } else {
                    SfoDelete(part);
                }
            }
        }
    }
    cVector size = vumBounds.GetSize();
    cVector center = vumBounds.GetCenter();
    D_0048B288 = size.Length();
    int levelID = D_004FFC04->GetLevel().GetLevelID();
    if (levelID == -1) {
        D_004FF058 = 0;
        D_0048B278 = 0.25f;
    } else {
        float f = D_004ACCE0[levelID];
        float s;
        if (f <= 0.0f) s = 0.25f;
        else s = 128.0f / f;
        D_0048B278 = s;
        D_004FF058 = 1;
    }
    D_0048B280 = 1.0f / D_0048B278;
    cMAP_GOBJ_SetScale(1.25f);
    D_004FF084 = -(D_0048B288 / Libc_Sinf(0.7853982f));
    D_0048B2A0 = Libc_Atanf((150.0f * D_0048B278) / AbsF(D_004FF084));
    { float pm = D_0048B2A0; D_0048B2A0 = MinF(0.7853982f, pm); }
    D_0048B2A8 = Libc_Atanf((D_0048B288 / 2.0f) / AbsF(D_004FF084));
    {
        /* clamp pitchMax to [pitchMin, PI/4]; volatile reads keep retail's load order */
        float px, m, k;
        m = 0.0f;
        k = 0.7853982f;
        m = *(volatile float*)&D_0048B2A0;
        px = *(volatile float*)&D_0048B2A8;
        asm { max.s m, px, m; min.s m, m, k }
        D_0048B2A8 = m;
    }
    D_0048B290 = 1.0f + (D_0048B288 + AbsF(D_004FF084));
    D_0048B298 = AbsF(D_004FF084) - (1.0f + D_0048B288);
    if (D_0048B298 < 2.0f) D_0048B298 = 2.0f;
    cMap_ResetCamera(self);
    cFileMan_dtor(&texFile, -1);
    cFileMan_dtor(&vumFile, -1);
    return self;
}
