/*
 * SFOGame/Source/WaterFx: 3 files, 002B2280-002B24C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B2280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct WObj_2280 { char pad[0xC]; int serial; };
struct WRef_2280 { WObj_2280* obj; int serial; };
struct WMgr_2280 { char pad[0x400]; WRef_2280* refs[20]; };
static inline bool V_2280(WRef_2280* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline WObj_2280* G1_2280(WRef_2280* h) { return V_2280(h) ? h->obj : 0; }
extern "C" int cWaterFx_FindBodyIdx(WMgr_2280* m, WObj_2280* target)
{
    int res = -1;
    int i;
    if (target != 0) {
        for (i = 0; i < 20; i++) {
            WRef_2280* r = m->refs[i];
            if (r != 0 && G1_2280(r) != 0 && G1_2280(r) == target) { res = i; break; }
        }
    }
    return res;
}
static inline void merge_flush_func_002B2280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2280 */

/* merge_units: begin func_002B2330 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x20 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} EffectMsg; /* size 0x1C0 */
struct WObj_2330 { char pad[0xC]; int serial; };
struct WRef_2330 { WObj_2330* obj; int serial; };
struct WMgr_2330 { char pad[0x400]; WRef_2330* refs[20]; char pad450[4]; int count; };
extern "C" {
extern char D_004ABFB0[];
extern char g_Game[];
extern char D_004DAE30[];
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, char* name, WObj_2330* a, int b);
void EffectMsg_WrapRequest(EffectMsg* msg, SoundRequest* req);
void QueueMessage_cMessageR_cSystemP_int(EffectMsg* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(EffectMsg* msg, int flags);
void cWaterFx_RemoveBody(WMgr_2330* m, WObj_2330* target);
}
static inline bool V_2330(WRef_2330* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline WObj_2330* G1_2330(WRef_2330* h) { return V_2330(h) ? h->obj : 0; }
static inline int Find_2330(WMgr_2330* m, WObj_2330* target)
{
    int res = -1;
    int i;
    if (target != 0) {
        for (i = 0; i < 20; i++) {
            WRef_2330* r = m->refs[i];
            if (r != 0 && G1_2330(r) != 0 && G1_2330(r) == target) { res = i; break; }
        }
    }
    return res;
}
static inline const int& IdOf_2330(WObj_2330* p) { if (p) return p->serial; int m = -1; return m; }
static inline void SetH_2330(WRef_2330* h, WObj_2330* o) { h->obj = o; h->serial = IdOf_2330(o); }
void cWaterFx_RemoveBody(WMgr_2330* m, WObj_2330* target)
{
    int i = Find_2330(m, target);
    if (i >= 0) {
        SoundRequest req;
        EffectMsg msg;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, D_004ABFB0, target, 0);
        EffectMsg_WrapRequest(&msg, &req);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
        SetH_2330(m->refs[i], 0);
        m->count--;
        msg.vtbl = D_004DAE30;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
    }
}
static inline void merge_flush_func_002B2330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2330 */

/* merge_units: begin func_002B24C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off

struct cVector;
static inline void SubV(cVector* r, const cVector* a, const cVector* b);
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    cVector& operator=(const cVector& o) { __int128 t; cVector* pd = this; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    cVector operator-(const cVector& b) const {
        cVector r; SubV(&r, this, &b); return r;
    }
    float Length() const {
        float r = 0.0f; const cVector* p = this; int t;
        asm { lqc2 vf1, 0x0(p); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni t, vf4; mtc1 t, r }
        return r;
    }
} __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}

struct cMatrix { cVector r[4]; const cVector& GetTrans() const { return r[3]; } };
struct cBox { cVector min; cVector max; };

struct cXform {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void Update();
    char pad04[0xC];
    cMatrix mMatrix;
    unsigned char mDirty;
    const cMatrix& GetMatrix() { if (mDirty) Update(); return mMatrix; }
};

struct cGOBJ {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual cBox* GetBBox();
    char pad04[0x8];
    int mSerial;
    char pad10[0x39];
    unsigned char mClassID;
    char pad4a[0x6];
    cXform* mXform;
};

struct cSafePtr {
    cGOBJ* mPtr;
    int mSerial;
    cSafePtr(cGOBJ* p) { int n = -1; mPtr = p; mSerial = n; mSerial = SerialOf(p, n); }
    static const int& SerialOf(cGOBJ* p, int n = -1) { if (p) return p->mSerial; int m = n; return m; }
    bool SerialOK() const { return mPtr->mSerial == mSerial; } bool IsValid() const { return !(bool)mPtr || SerialOK(); }
    cGOBJ* Get() const { return IsValid() ? mPtr : 0; }
    void operator=(cGOBJ* p) { mPtr = p; mSerial = SerialOf(p); }
};

struct cSplash { char pad[0x30]; };
struct cWake { char pad[0x10]; float a; float b; float z; char pad2[0x8]; void Init(float s, float z0) { a = 0.6f * s; b = 3.8f * s - 0.6f * s; z = z0; } };

struct tBody {
    cSafePtr gobj;
    float size;
    char pad0c[4];
    cVector position;
    cVector velocity;
    float waterZ;
    char pad34[0xC];
    cSplash splash;
    cWake wake;
};

struct cFileMan { char b[0x9C]; };
struct cSndFx {
    char pad[0x48];
    cFileMan mSndFile;
    cFileMan mLipFile;
    char pad2[0x190 - 0x180];
};
struct cMessage {
    void* vtbl;
    char pad04[0x1C];
    unsigned char mLocal;
    char pad21[0xF];
    char snd[0x48];
    cFileMan mSndFile;
    cFileMan mLipFile;
    char pad2[0x1C0 - 0x1B0];
};

struct cWaterFx {
    char pad[0x400];
    tBody* bodies[20];
    int numBodies;
    int numGobjBodies;
    int FindBodyIdx(cGOBJ* g);
    void AddBody(cGOBJ* gobj, float waterZ);
};

extern "C" {
extern char D_004ABFF0[];
#if 0 /* merge_units */
int cWaterFx_FindBodyIdx(cWaterFx* self, cGOBJ* g);
#endif /* merge_units */
#define cWaterFx_FindBodyIdx(a0, a1) (cWaterFx_FindBodyIdx((WMgr_2280 *)(a0), (WObj_2280 *)(a1))) /* merge_units */

void* opNew_uint_int_charP_int(unsigned int size, int pool, char* file, int line);
tBody* cWaterFx_tBody_ctor(void* p);
void WaterFx_InitSplash(cSplash* s, float size, float z);
void cSndFx_ctor_int_charP_cVectorR_int(cSndFx* s, int bank, char* name, cVector* pos, int pri);
#if 0 /* merge_units */
void EffectMsg_WrapRequest(cMessage* m, cSndFx* s);
#endif /* merge_units */
#define EffectMsg_WrapRequest(a0, a1) (EffectMsg_WrapRequest((EffectMsg *)(a0), (SoundRequest *)(a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(cMessage* m, void* sys, int f);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((EffectMsg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(cFileMan* f, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(cMessage* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((EffectMsg *)(a0), (a1))) /* merge_units */

}

static inline bool IsSwimmer(const cSafePtr& p)
{
    if (!p.Get()) return false;
    bool r = false;
    bool ok = false;
    if (p.Get()->mXform && p.Get()->GetBBox()) ok = true;
    if (ok && p.Get()->mClassID == 2) r = true;
    return r;
}

extern "C" void cWaterFx_AddBody_cGOBJP_float(cWaterFx* self, cGOBJ* gobj, float waterZ)
{
    float bz = 0.2f + waterZ;
    if (self->numBodies < 20 && self->numGobjBodies < 8) {
        cSafePtr sp(gobj);
        if (IsSwimmer(sp)) {
            int idx = cWaterFx_FindBodyIdx(self, gobj);
            tBody* found = idx >= 0 ? self->bodies[idx] : 0;
            if (!found) {
                int bidx = -1;
                for (int i = 0; i < 20; i++) {
                    if (!self->bodies[i]) {
                        bidx = i;
                        tBody* m = (tBody*)opNew_uint_int_charP_int(0xA0, 0, D_004ABFF0, 0x1AA);
                        if (m) m = cWaterFx_tBody_ctor(m);
                        self->bodies[bidx] = m;
                        self->numBodies++;
                        break;
                    }
                }
                cBox* bbox = gobj->GetBBox();
                cVector xyMin(bbox->min.x, bbox->min.y, 0.0f, 0.0f);
                cVector xyMax(bbox->max.x, bbox->max.y, 0.0f, 0.0f);
                tBody& body = *self->bodies[bidx];
                body.gobj = gobj;
                body.size = 0.5f * (xyMax - xyMin).Length();
                body.position = gobj->mXform->GetMatrix().GetTrans();
                body.velocity = cVector(0.0f, 0.0f, 0.0f, 0.0f);
                body.waterZ = bz;
                if (body.position.z > 1.5f + waterZ)
                    WaterFx_InitSplash(&body.splash, body.size, body.waterZ);
                float s = body.size;
                float z0 = body.waterZ;
                float h = 3.8f;
                float k = 0.6f;
                body.wake.a = k * s;
                body.wake.b = h * s - k * s;
                body.wake.z = z0;
                cSndFx sndFx;
                cSndFx_ctor_int_charP_cVectorR_int(&sndFx, 0, D_004ABFB0, &body.position, 0);
                cMessage msg;
                EffectMsg_WrapRequest(&msg, &sndFx);
                msg.mLocal = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                self->numGobjBodies++;
                msg.vtbl = D_004DAE30;
                cFileMan_dtor(&msg.mLipFile, -1);
                cFileMan_dtor(&msg.mSndFile, -1);
                cMessage_dtor(&msg, 0);
                cFileMan_dtor(&sndFx.mLipFile, -1);
                cFileMan_dtor(&sndFx.mSndFile, -1);
            }
        }
    }
}
#undef cWaterFx_FindBodyIdx /* merge_units */
#undef EffectMsg_WrapRequest /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002B24C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B24C0 */
