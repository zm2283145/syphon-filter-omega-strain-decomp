#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"


struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { __int128 t; const cVector* ps = &o; cVector* pd = this; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    cVector& operator=(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } return *this; }
} __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
static inline void AddV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
// .set noreorder: retail has no assembler-inserted nop between mfc1 and qmtc2 (same idiom as func_003E4720.c)
static inline void ScaleV(cVector* r, const cVector* a, float s) {
    __int128 t = 0; const cVector* pa = a; cVector* pr = r;
    asm volatile { .set noreorder; lqc2 vf1, 0x0(pa); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(pr); .set reorder }
}
static inline cVector ScaleR(const cVector& a, float s) { cVector r; cVector* p = &r; const cVector* q = &a; ScaleV(p, q, s); return r; }
static inline cVector operator*(const cVector& a, float s) { return ScaleR(a, s); }
static inline cVector operator+(const cVector& a, const cVector& b) { cVector r; AddV(&r, &a, &b); return r; }
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; SubV(&r, &a, &b); return r; }

struct cObjectId { unsigned int mId; };

struct cPopulation {
    int mVersion;
    int mBufferSize;
    char* mBuffer;
    char* mCurrent;
    unsigned char mOwnBuffer;
};

template <class T> static inline T ReadA(cPopulation& p) { char* c = p.mCurrent; T v = *(T*)c; p.mCurrent = c + sizeof(T); return v; }
template <class T> static inline T ReadB(cPopulation& p) { T v = *(T*)p.mCurrent; p.mCurrent += sizeof(T); return v; }

struct cGOBJ_v {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void SetMatrix(void* m, int f); /* +0x90 */
};

struct cSafeObj { char pad[0xC]; int mId; };

struct cFireObj : cGOBJ_v {
    char pad04[0x8];
    unsigned int mObjId;      /* 0x0C */
    unsigned int mNetId;      /* 0x10 */
    unsigned char mActive;    /* 0x14 */
    char pad15[0x60 - 0x15];
    int mDamagePerSecond;     /* 0x60 */
    char pad64[0xC];
    cVector mCenter;          /* 0x70 */
    cVector mRad;             /* 0x80 */
    cSafeObj* mOwnerPtr;      /* 0x90 */
    int mOwnerId;             /* 0x94 */
};

extern "C" {
extern int D_004F8308[];
extern void* D_004DC970[];
extern int D_0048B0E0;
extern char g_IdentityMatrix[];
extern unsigned char g_IsMultiplayer;
extern bool D_005721C0;
extern int D_005721A8;
extern int D_00494178;
void cGOBJ_ctor(void* p, const cObjectId* id, int cls, int* sub);
void* nGobjManager_LookupGOBJ_int_int(int, int);
void cTerrain_AddActivation(void* t, void* o, int b, void* t2);
int NetGetMyClientIndex(int* p, int a);
void NetGetPeerToPeerHostClientIndex(int a, int* out);
void cNetObj_AddSystem(int id, int owner, void* sys);
}

static inline bool IsHost() { bool r; if (g_IsMultiplayer) r = D_005721C0; else r = true; return r; }
static inline int MyClientIndex(int a)
{
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    } else {
        r = 0;
    }
    return r;
}
static inline int OwnerIndex()
{
    int r;
    if (IsHost()) r = MyClientIndex(D_005721A8);
    else { int t; NetGetPeerToPeerHostClientIndex(D_005721A8, &t); r = t; }
    return r;
}

static inline void SetOwner0(cFireObj* s, cSafeObj* o)
{
    int tmp;
    s->mOwnerPtr = o;
    s->mOwnerId = *(o ? &o->mId : (tmp = -1, &tmp));
}

static inline void SetOwner(cFireObj* s, cSafeObj* o) { SetOwner0(s, o); }
extern "C" cFireObj* cFireObj_ctor_cPopulationR(cFireObj* self, cPopulation& popData)
{
    float tempx;
    float tempy;
    float tempz;
    int levelID;
    int itemID;
    cVector min;
    cVector max;
    int actCount;
    cObjectId oid;
    float intensity;
    int i;

    {
        cObjectId t; t.mId = (unsigned)-1;
        cGOBJ_ctor(self, &t, 0x12, D_004F8308);
    }
    *(void**)self = D_004DC970;
    self->mOwnerId = -2;
    self->mOwnerPtr = 0;
    { int hi = ReadA<int>(popData); int lo = ReadA<int>(popData); oid.mId = lo | (hi << 16); }
    self->mObjId = oid.mId;
    tempx = ReadA<float>(popData);
    tempy = ReadA<float>(popData);
    tempz = ReadA<float>(popData);
    min.x = tempx; min.y = tempy; min.z = tempz;
    tempx = ReadA<float>(popData);
    tempy = ReadA<float>(popData);
    tempz = ReadA<float>(popData);
    max.x = tempx; max.y = tempy; max.z = tempz;
    SetOwner(self, 0);
    self->mCenter = (max + min) * 0.5f;
    self->mRad = (max - min) * 0.5f;
    intensity = ReadB<float>(popData);
    self->mDamagePerSecond = (int)((float)D_0048B0E0 * intensity / 100.0f);
    actCount = ReadB<int>(popData);
    for (i = 0; i < actCount; i++) {
        levelID = ReadA<int>(popData);
        itemID = ReadA<int>(popData);
        if (levelID != -1 && itemID != -1) {
            void* terrObj = nGobjManager_LookupGOBJ_int_int(levelID, itemID);
            if (terrObj) cTerrain_AddActivation(terrObj, self, 1, 0);
        }
    }
    self->SetMatrix(g_IdentityMatrix, 0);
    if (g_IsMultiplayer) {
        self->mNetId = oid.mId;
        if (!IsHost()) self->mActive = 0;
        { int id = self->mNetId; cNetObj_AddSystem(id, OwnerIndex(), self); }
    }
    return self;
}
