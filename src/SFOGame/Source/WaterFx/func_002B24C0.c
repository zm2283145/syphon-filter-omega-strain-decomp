#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"

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
extern char D_004ABFB0[];
extern char g_Game[];
extern char D_004DAE30[];
int cWaterFx_FindBodyIdx(cWaterFx* self, cGOBJ* g);
void* opNew_uint_int_charP_int(unsigned int size, int pool, char* file, int line);
tBody* cWaterFx_tBody_ctor(void* p);
void WaterFx_InitSplash(cSplash* s, float size, float z);
void cSndFx_ctor_int_charP_cVectorR_int(cSndFx* s, int bank, char* name, cVector* pos, int pri);
void EffectMsg_WrapRequest(cMessage* m, cSndFx* s);
void QueueMessage_cMessageR_cSystemP_int(cMessage* m, void* sys, int f);
void cFileMan_dtor(cFileMan* f, int flags);
void cMessage_dtor(cMessage* m, int flags);
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
