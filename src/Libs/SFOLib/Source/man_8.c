/*
 * Libs/SFOLib/Source/man: 12 files, 0038A620-0038C050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038A620 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
struct Sphere { int w0; unsigned char b4; char pad5[3]; float r; int wC; V c; };
static inline V Sub(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
static inline V Add(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
static inline void Union(Box* bx, const V& p0) {
    V* mx = &bx->mx; const V* p = &p0;
    asm {
        lqc2 vf1, 0x0(bx)
        lqc2 vf2, 0x0(mx)
        lqc2 vf3, 0x0(p)
        vmini.xyz vf1, vf1, vf3
        vmax.xyz vf2, vf2, vf3
        sqc2 vf1, 0x0(bx)
        sqc2 vf2, 0x0(mx)
    }
}
static inline void Xform(V& o, const V& in, M* m) {
    o = in;
    V* out = &o;
    asm {
        lqc2 vf8, 0x0(out)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(out)
    }
}
extern "C" void cSkeletonBBoxContribution_ContributeToBBox(Sphere* s, Box* box, M* m)
{
    V c = s->c;
    if (!s->b4)
        Xform(c, s->c, m);
    else
        c = m->r[3];
    if (s->r > 0.0f) {
        V rv(s->r, s->r, s->r, 0.0f);
        Union(box, Sub(c, rv));
        Union(box, Add(c, rv));
    } else {
        Union(box, c);
    }
}
static inline void merge_flush_func_0038A620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038A620 */

/* merge_units: begin func_0038A7C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of XformNode: only the slots used here are named (vtable offset in comments). */
struct XformNode {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x10 - 4];
    char transform[0x40]; /* +0x10 */
    unsigned char dirty;  /* +0x50 */
};

/* Brings the cached transform up to date (virtual +0x58) if dirty and returns it. */
extern "C" void* cBone_GetMatrix(XformNode* self)
{
    if (self->dirty)
        self->Update();
    return &self->transform;
}
static inline void merge_flush_func_0038A7C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038A7C0 */

/* merge_units: begin func_0038A800 */
#pragma push /* merge_units */
/* Prepare model and equipped-object texture handles in EE scratchpad.
 * Local declaration order preserves CodeWarrior register allocation.
 * Volatile debug-ID reads retain the original per-entry lookup order.
 */
#pragma cplusplus on
typedef struct {
    char pad[0x50];
    long long value;
} TxEntry;
typedef struct {
    int pad[2];
    TxEntry**entries;
    char padc[10];
    unsigned char flag;
    char pad17;
    unsigned count;
    short queue[512];
} TxManager;
typedef struct {
    char pad[0x3c0];
    short cur[8],prev[8];
    char pad3e0[0x40c-0x3e0];
    unsigned char count;
    char pad40d[4];
    signed char special;
    char pad412[5];
    signed char state;
} TxEquip;
typedef struct {
    char pad[0x22c0];
    short cur[32],prev[32];
    char pad2340[0x80];
    unsigned short count;
    char pad23c2[0x2410-0x23c2];
    TxEquip* equips[8];
    char pad2430[8];
    signed char disabled[8];
    char pad2440[0x2bd0-0x2440];
    int special;
    char pad2bd4[0x2c12-0x2bd4];
    signed char extra;
    char pad2c13[0x2dd0-0x2c13];
    signed char selector[32];
} TxModel;
extern "C" {
    extern TxManager* g_TextureMgr;
    extern int g_VisionThermal,D_0055DE90;
    extern short D_0053B360[],D_0053B362,D_0053B364,D_0053B366,D_0053B368;
    void cTexMan_EndBatch(TxManager*);
}
static inline void tx_queue(TxManager* m,int id){
    unsigned n=m->count;
    if(n<512){
        if(n==0||m->queue[n-1]!=id)m->queue[m->count++]=id;
    }
}
extern "C" long long cMan_ManRequestTextures(TxModel* self,int which,int override,unsigned char flag){
    long long result=0;
    int count=self->count;
    TxManager* mgr=g_TextureMgr;
    if(override){
        int n;
        long long*p;
        long long*dst;
        TxEquip*e;
        int i;
        char*base;
        dst=(long long*)0x70000a50;
        while(count>0){
            *dst++=0x20059a019930acc0LL;
            count--;
        }
        *dst=0x20059a019930acc0LL;
        i=0;
        base=(char*)0x70000000;
        for(;i<8;i++,base+=64){
            e=self->equips[i];
            if(e){
                n=e->count;
                p=(long long*)(base+0xb50);
                while(n>0){
                    *p++=0x20059a019930acc0LL;
                    n--;
                }
            }
        }
        return 0x20059a019930acc0LL;
    }
    if(g_VisionThermal){
        mgr->count=0;
        mgr->flag=0;
        tx_queue(mgr,D_0053B360[0]);
        tx_queue(mgr,D_0053B362);
        tx_queue(mgr,D_0053B364);
        tx_queue(mgr,D_0053B366);
        tx_queue(mgr,D_0053B368);
        cTexMan_EndBatch(mgr);
        struct Scratch {
            char pad[0xa50];
            long long values[40];
        };
        int i;
        Scratch* sc=(Scratch*)0x70000000;
        for(i=0;i<count;i++)sc->values[i]=mgr->entries[D_0053B360[self->selector[i]]]->value;
        result=mgr->entries[D_0053B360[self->selector[i]]]->value;
        {
            int special;
            int k;
            Scratch*dp;
            int n;
            int j;
            TxModel*walk;
            char*base;
            TxEquip*e;
            j=0;
            walk=self;
            base=(char*)0x70000000;
            for(;j<8;j++,walk=(TxModel*)((char*)walk+4),base+=64){
                e=walk->equips[0];
                if(e){
                    n=e->count;
                    special=e->special;
                    for(k=0;k<n;k++){
                        dp=(Scratch*)(base+k*8);
                        if(k!=special)dp->values[32]=mgr->entries[*(volatile short*)&D_0053B362]->value;
                        else dp->values[32]=mgr->entries[*(volatile short*)&D_0053B368]->value;
                    }
                }
            }
        }  if(self->extra)*(long long*)0x700024d0=mgr->entries[D_0053B366]->value;
        return result;
    }
    mgr->count=0;
    mgr->flag=0;
    short* ids;
    if(which==0)ids=self->cur;
    else ids=self->prev;
    int n=count;
    while(n>0){
        tx_queue(mgr,*ids++);
        n--;
    }
    if(self->special)tx_queue(mgr,*ids);
    {
        TxEquip*e;
        int i;
        int z;
        int id;
        TxModel*walk;
        short*p;
        i=0;
        walk=self;
        for(;i<8;i++,walk=(TxModel*)((char*)walk+4)){
            e=walk->equips[0];
            if(e&&!self->disabled[i]&&!e->state){
                if(which==0)p=e->cur;
                else p=e->prev;
                z=e->count;
                while(z>0){
                    id=*p++;
                    unsigned qn=mgr->count;
                    if(qn<512){
                        if(qn==0||mgr->queue[qn-1]!=id)mgr->queue[mgr->count++]=id;
                    }z--;
                }
            }
        }
    } if(self->extra)tx_queue(mgr,D_0055DE90);
    cTexMan_EndBatch(mgr);
    if(which==0)ids=self->cur;
    else ids=self->prev;
    long long*dst=(long long*)0x70000a50;
    while(count>0){
        count--;
        *dst++=mgr->entries[*ids++]->value;
    }
    if(self->special)result=mgr->entries[*ids]->value;
    {
        int i;
        int n;
        TxModel*walk;
        char*base;
        TxEquip*e;
        long long*d;
        short*p;
        i=0;
        walk=self;
        base=(char*)0x70000000;
        for(;i<8;i++,walk=(TxModel*)((char*)walk+4),base+=64){
            e=walk->equips[0];
            if(e&&!self->disabled[i]&&!e->state){
                if(which==0)p=e->cur;
                else p=e->prev;
                n=e->count;
                d=(long long*)(base+0xb50);
                while(n>0){
                    n--;
                    *d++=mgr->entries[*p++]->value;
                }
            }
        }
    } if(self->extra)*(long long*)0x700024d0=mgr->entries[D_0055DE90]->value;
    return result;
}
static inline void merge_flush_func_0038A800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038A800 */

/* merge_units: begin func_0038B120 */
#pragma push /* merge_units */
// cMan::GetLocal2ScreenMatrix(cMatrix&, const cMatrix&) @ 0x0038B120 (lane k3)
// scaleNOffsetMatrix = cMatrix(cMatrix(16 floats), cVector) per prototype out-of-line ctors.
#pragma cplusplus on
#pragma inline_depth(8)

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct cMatrix {
    float m[4][4];
    cMatrix() {}
    cMatrix(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }
    cMatrix(const cMatrix& o, const cVector& t) {
        m[0][0] = o.m[0][0]; m[0][1] = o.m[0][1]; m[0][2] = o.m[0][2];
        m[1][0] = o.m[1][0]; m[1][1] = o.m[1][1]; m[1][2] = o.m[1][2];
        m[2][0] = o.m[2][0]; m[2][1] = o.m[2][1]; m[2][2] = o.m[2][2];
        m[0][3] = o.m[0][3]; m[1][3] = o.m[1][3]; m[2][3] = o.m[2][3];
        *(cVector*)m[3] = t;
    }
} __attribute__((aligned(16)));

struct cXViewport;
extern "C" void cXViewport_Validate(const cXViewport* vp);

struct cXViewport {
    char win[16];
    cMatrix orthoMat;
    cMatrix perspMat;
    cVector scale;
    cVector offset;
    char padB0[0x104 - 0xB0];
    unsigned char isOrtho;
    unsigned char isOnScreen;
    unsigned char isDirty;
    unsigned long scissorReg;
    void Validate() const { cXViewport_Validate(this); }
    const cVector& GetScale() const { Validate(); return scale; }
    const cVector& GetOffset() const { Validate(); return offset; }
    const cMatrix& GetProjMatrix() const { Validate(); if (isOrtho) return orthoMat; return perspMat; }
};

struct cXVideo {
    char pad[0x1F0];
    cXViewport viewports[1];
};

extern "C" {
extern cXVideo g_Video;
extern int D_00538C60;
extern float D_00538258[];
extern float D_00538268[];
extern int D_00538278;
extern cMatrix g_IdentityMatrix;
extern cMatrix D_00539070;
}

static inline cXViewport& GetViewport() { return g_Video.viewports[D_00538C60]; }
static inline const cMatrix& GetScreenMatrix() { if (GetViewport().isOrtho) return g_IdentityMatrix; return D_00539070; }

static inline void MatMul(cMatrix& d, const cMatrix& a, const cMatrix& b) { __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf7, 0x30(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(&d), "r"(&b), "r"(&a) : "memory"); }

static inline void MatMul2(cMatrix& d, const cMatrix& b, const cMatrix& a) { MatMul(d, a, b); }
extern "C" void cMan_GetLocal2ScreenMatrix(cMatrix& local2ScreenMatrix, const cMatrix& local2CameraMatrix)
{
    cMatrix camera2ScreenMatrix;
    cXViewport& viewPort = GetViewport();
    cVector scale = viewPort.GetScale();
    cVector offset = viewPort.GetOffset();
    float diagScaleX = 0.0625f / (float)D_00538258[D_00538278];
    float diagScaleY = 0.0625f / D_00538268[D_00538278];
    cMatrix scaleNOffsetMatrix(cMatrix(diagScaleX * scale.x, 0.0f, 0.0f, 0.0f,
                                       0.0f, diagScaleY * scale.y, 0.0f, 0.0f,
                                       0.0f, 0.0f, 0.0625f * scale.z, 0.0f,
                                       0.0f, 0.0f, 0.0f, 1.0f),
                               cVector(0.0625f * offset.x, 0.0625f * offset.y, 0.0625f * offset.z, 1.0f));
    MatMul2(camera2ScreenMatrix, GetScreenMatrix(), viewPort.GetProjMatrix());
    MatMul(camera2ScreenMatrix, scaleNOffsetMatrix, camera2ScreenMatrix);
    MatMul(local2ScreenMatrix, camera2ScreenMatrix, local2CameraMatrix);
}
static inline void merge_flush_func_0038B120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038B120 */

/* merge_units: begin func_0038B530 */
#pragma push /* merge_units */
typedef struct { int t; float v; } KtKey;
#if 0 /* merge_units */
float AnimMix(int t, KtKey* keys); /* gsynth: defined below */
#endif /* merge_units */
float AnimMix(); /* merge_units */


typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;

typedef struct { u8 pad[0x40D]; u8 n; } Grip_38B530;
typedef struct { s8 a[0x18]; s8 b[0x18]; } GripTab_38B530;

typedef struct {
    u8 pad0[0x23D0];
    float w0;
    float w0b;
    int pad23D8;
    int k0;
    float w1;
    float w1b;
    int pad23E8;
    int k1;
    float vals[8];
    Grip_38B530* g0;
    Grip_38B530* g1;
    u8 pad2418[0x2BC1 - 0x2418];
    u8 count;
    u8 ids[8];
    u8 pad2BCA[0x2C0C - 0x2BCA];
    u8 type;
    u8 pad2C0D[0x2D90 - 0x2C0D];
    u8 s0;
    u8 s1;
    u8 s2;
    u8 pad2D93;
    s16 timer;
    s16 pad2D96;
    u16 limit;
} Equip_38B530;

extern GripTab_38B530 D_00571510[];
extern u8 D_0053B340[];
extern u8 D_0053B348[];
extern char g_MorphCurveGrip[], g_MorphCurveActive[], g_MorphCurvePeriodic[];
#if 0 /* merge_units */
extern float AnimMix(int frame, char* track);
#endif /* merge_units */
float AnimMix(); /* merge_units */



extern int Libc_Rand(void);

void cMan_UpdateMorphs(Equip_38B530* e)
{
    u8 s;
    int i;
    float f;
    s = e->s0;
    if (s && e->g0) {
        if (s == 1) {
            i = e->g0->n + 1;
            e->w0b = 0.0f;
            if (i >= 0) {
                e->k0 = D_00571510[e->type].a[i];
                e->w0 = 1.0f;
            } else {
                e->w0 = 0.0f;
            }
        }
        f = AnimMix(e->s0, g_MorphCurveGrip);
        e->w0 = f;
        e->w0b = 1.0f - f;
    }
    s = e->s1;
    if (s && e->g1) {
        if (s == 1) {
            i = e->g1->n + 1;
            e->w1b = 0.0f;
            if (i >= 0) {
                e->k1 = D_00571510[e->type].b[i];
                e->w1 = 1.0f;
            } else {
                e->w1 = 0.0f;
            }
        }
        f = AnimMix(e->s1, g_MorphCurveGrip);
        e->w1 = f;
        e->w1b = 1.0f - f;
    }
    s = e->s2;
    if (s) {
        if (s == 1) {
            e->timer = 300;
            e->limit = 3000;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B340[e->type];
            e->vals[e->count] = AnimMix(e->s2, g_MorphCurveActive);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->s2++;
        if (e->s2 > 72) {
            e->s2 = 0;
        }
    } else if (e->timer >= 0) {
        if (e->timer >= e->limit) {
            e->timer = 0;
            e->limit = (Libc_Rand() & 0x3FF) + 300;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B348[e->type];
            e->vals[e->count] = AnimMix(e->timer, g_MorphCurvePeriodic);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->timer++;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B530 */

/* merge_units: begin func_0038B800 */
#pragma push /* merge_units */
float AnimMix(int t, KtKey* keys)
{
    int i = 0;
    int kt;
    float a, b;
    while (t > (kt = keys[i].t)) i++;
    if (t == kt) return keys[i].v;
    b = keys[i].v;
    a = keys[i - 1].v;
    if (a == b) return b;
    {
        int pt = keys[i - 1].t;
        int span = kt - pt;
        float r;
        t -= pt;
        r = (float)t / (float)span;
        return a - r * (a - b);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B800 */

/* merge_units: begin func_0038B8B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Stores a value in a 256-entry table indexed by a byte.
 */

#include "man_types.h"

extern int WoundEffectTable[256];

void cMan_SetBloodEffect(int index, int value) {
    WoundEffectTable[index & 0xFF] = value;
}
static inline void merge_flush_func_0038B8B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038B8B0 */

/* merge_units: begin func_0038B8D0 */
#pragma push /* merge_units */
typedef struct { unsigned char pad[7]; unsigned char count; unsigned char* data; unsigned char pad2[4]; } Grp_B8D0;
typedef struct {
    unsigned char pad0[0x1EC0];
    Grp_B8D0 groups[0x48];
    unsigned char* bufs[0x20];
    unsigned short numGroups;
} Model_B8D0;
void cMan_Bloodlost(Model_B8D0* m)
{
    unsigned int i;
    unsigned int n;
    unsigned char* d;
    unsigned char* buf;
    unsigned int j;
    unsigned char* p;
    unsigned int c;
    unsigned int k;
    for (i = 0; i < m->numGroups; i++) {
        buf = m->bufs[i];
        if (buf != 0) {
            n = m->groups[i].count;
            d = m->groups[i].data; d += 2;
            for (j = 0; j < n; j++) {
                c = d[1];
                d += 2;
                p = buf;
                buf += 0x20;
                for (k = 0; k < c; k++) {
                    if (*p != 0) *p = 0x5A;
                    p++;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B8D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B8D0 */

/* merge_units: begin func_0038B990 */
#pragma push /* merge_units */
typedef struct { unsigned char a; unsigned char n; } HgPair;
typedef struct { char pad0[2]; HgPair p[1]; } HgDef;
typedef struct {
    char pad0[7];
    unsigned char count;
    HgDef* def;
    char padC[4];
} HgEnt;
typedef struct {
    char pad0[0x1EC0];
    HgEnt ents[32];
    char pad20C0[0x2340 - 0x20C0];
    unsigned char* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    unsigned int age;
} HitGore;

void cMan_BloodUpdate(HitGore* self)
{
    unsigned int i;
    unsigned int cnt;
    HgPair* pr;
    unsigned char* p;
    unsigned int k;
    unsigned char* q;
    unsigned int n;
    unsigned int b;
    unsigned char* buf;
    if (self->age) {
        for (i = 0; i < self->count; i++) {
            p = self->items[i];
            buf = p;
            if (buf) {
                cnt = self->ents[i].count;
                pr = (HgPair*)self->ents[i].def; pr++;
                for (k = 0; k < cnt; k++) {
                    n = pr->n;
                    q = buf;
                    buf += 0x20;
                    pr++;
                    for (b = 0; b < n; b++, q++) {
                        unsigned int v = *q;
                        if (v) {
                            v += self->age;
                            if (v > 0x5A) v = 0x5A;
                            *q = v;
                        }
                    }
                }
            }
        }
        self->age = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B990 */

/* merge_units: begin func_0038BA80 */
#pragma push /* merge_units */
/* cMan::BloodHitVert(bloodHitInfo&) - man.cc (mw38) */
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct { float x, y, z, w; } cVector;
typedef struct { unsigned int x, y, z, w; } hexVect;
typedef struct { unsigned char qwc; unsigned char vertCount; } manRefs;

typedef struct {
    cVector vert;
    cVector normal;
    float closestDist;
    float closestY;
    int closestHitType;
    short closestVert;
    short closestPatch;
    short closestPart;
    short pad;
    float farthestDist;
    float farthestY;
    int farthestHitType;
    char bones[8];
    char boneCount;
    float hitRadius;
} bloodHitInfo;

typedef struct {
    u_long128* data;
    char pad4[4];
    manRefs* refs;
    char padC[4];
} manPart;

typedef struct {
    char pad0[0x1EC0];
    manPart parts[32];
} cMan;

static inline void WaitVif0(void)
{
    int a = 7;
    int b = 7;
    int c;
    while (*(volatile int*)0x10008000 & 0x100) {
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

void cMan_BloodHitVert(cMan* self, bloodHitInfo* hitInfo)
{
    cVector* results1 = (cVector*)0x11004050;
    hexVect* bones = (hexVect*)0x11004670;
    manRefs* refData;
    u_long128* part;
    int qwc;
    unsigned int i;
    int bonesBase;
    unsigned int j;
    int boneNumber;

    refData = self->parts[hitInfo->closestPart].refs;
    part = self->parts[hitInfo->closestPart].data;
    refData++;
    for (i = 0; i < hitInfo->closestPatch; i++) {
        part += refData->qwc;
        refData++;
    }
    qwc = refData->qwc;
    WaitVif0();
    *(volatile int*)0x10008020 = qwc;
    *(volatile int*)0x10008010 = (int)part;
    *(volatile int*)0x10008000 = 0x101;
    __asm__ volatile("sync");
    WaitVif0();
    *(u_long128*)&hitInfo->vert = *(u_long128*)&results1[hitInfo->closestVert << 1];
    hitInfo->boneCount = bones->z & 0xF;
    bones--;
    bonesBase = bones->x;
    for (j = 0; j < hitInfo->boneCount; j++) {
        boneNumber = (bones->z - 133) / 7;
        if (bones->x - bonesBase <= hitInfo->closestVert && bones->x - bonesBase + bones->y >= hitInfo->closestVert) {
            hitInfo->bones[j] = boneNumber;
            if (boneNumber == 2 || boneNumber == 5 || boneNumber == 8 || boneNumber == 10) {
                if (hitInfo->closestHitType != 20) hitInfo->closestHitType = 12;
            }
            if (boneNumber == 9 || boneNumber == 14) {
                if (hitInfo->closestHitType == 8) hitInfo->closestHitType = 4;
            }
        } else {
            hitInfo->bones[j] = -boneNumber;
        }
        bones--;
    }
}
static inline void merge_flush_func_0038BA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038BA80 */

/* merge_units: begin func_0038BD30 */
#pragma push /* merge_units */
/* 0038BD30 cMan::BloodHitPart(bloodHitInfo&, int, int) - SFOLib man.cc */


typedef struct {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
} Parts;

typedef struct {
    Parts bodyParts[64];
    short manTexID[32];
    short manTexID2[32];
    u_long128* bloodData[32];
    unsigned short manAttribsCount;
} ManParts;

typedef struct {
    char pad0[0x1EC0];
    ManParts parts;
} cMan_0038BD30;

/* fabsf: mw38 keeps the dead r = 0 init (mtc1 zero) only when asm writes r. */
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
/* float->int: asm keeps the dead distance = 0 init (daddu zero) like retail. */
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }

static inline void WaitVif0_0038BD30(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        /* dead 7/7 delay div; every C form is DCE'd */
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

void cMan_BloodHitPart(cMan_0038BD30* self, bloodHitInfo* hitInfo, int j, int unused)
{
    cVector* results = (cVector*)0x70000540;
    manRefs* refData;
    u_long128* part;
    unsigned int patchCount;
    int qwc;
    int nextVertCount;
    int vertCount;
    u_long128* blood128;
    unsigned char* bloodChars;
    int partHitType;
    unsigned int i;
    unsigned int k;
    float dist;
    float distCalc;
    int distance;

    partHitType = self->parts.bodyParts[j].type & 0x1C;
    refData = self->parts.bodyParts[j].Refs;
    patchCount = self->parts.bodyParts[j].patchCount;
    blood128 = self->parts.bloodData[j];
    part = self->parts.bodyParts[j].part;
    refData++;
    qwc = refData->qwc;
    nextVertCount = refData->vertCount;
    WaitVif0_0038BD30();
    *(volatile int*)0x10008020 = qwc;
    *(volatile int*)0x10008010 = (int)part;
    *(volatile int*)0x10008000 = 0x101;
    __asm__ volatile("sync");
    part += qwc;
    refData++;
    for (i = 0; i < patchCount; i++) {
        vertCount = nextVertCount;
        WaitVif0_0038BD30();
        {
            u_long128* dst;
            u_long128* src;
            int n;
            n = vertCount;
            src = (u_long128*)0x11004050;
            dst = (u_long128*)results;
            while (n) {
                *dst = *src;
                n--;
                src += 2;
                dst++;
            }
        }
        bloodChars = (unsigned char*)blood128;
        blood128 += 2;
        if (i < patchCount - 1) {
            qwc = refData->qwc;
            nextVertCount = refData->vertCount;
            *(volatile int*)0x10008020 = qwc;
            *(volatile int*)0x10008010 = (int)part;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            part += qwc;
            refData++;
        }
        for (k = 0; k < vertCount; k++) {
            {
                float x;
                float z;
                z = results[k].z;
                x = results[k].x;
                dist = z * z + x * x;
            }
            if (dist < 0.04f) {
                distCalc = 0.25f * results[k].y + AbsZ(dist);
                if (distCalc < hitInfo->closestDist) {
                    hitInfo->closestDist = distCalc;
                    hitInfo->closestY = results[k].y;
                    hitInfo->closestHitType = partHitType;
                    hitInfo->closestVert = k;
                    hitInfo->closestPatch = i;
                    hitInfo->closestPart = j;
                }
                if (distCalc > hitInfo->farthestDist) {
                    hitInfo->farthestDist = distCalc;
                    hitInfo->farthestY = results[k].y;
                    hitInfo->farthestHitType = partHitType;
                }
                dist = 200.0f - dist * 16000.0f;
                distance = F2I(dist);
                if (distance <= 0) distance = 1;
                distance += *bloodChars;
                if (distance > 90) distance = 90;
                *bloodChars = distance;
            }
            bloodChars++;
        }
    }
}
static inline void merge_flush_func_0038BD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038BD30 */

/* merge_units: begin func_0038C050 */
#pragma push /* merge_units */
/* 0038C050 cMan::BloodHit(bloodHitInfo&, int) - SFOLib man.cc */
#pragma cplusplus on
#include "alloc_guard.h"
#include "canonical_key_copy.h"


typedef struct {
    Parts bodyParts[2][32];
    short manTexID[32];
    short manTexID2[32];
    u_long128* bloodData[32];
    unsigned short manAttribsCount;
} ManParts_0038C050;

typedef struct {
    char pad0[0x1EC0];
    ManParts_0038C050 parts;
    char pad23C4[0x2C08 - 0x23C4];
    int bloodSpurt;
} cMan_0038C050;

extern "C" {
extern int D_00542D40;
extern int D_00542D48;
extern unsigned int D_004937C0[];
extern unsigned int D_004937D0[];
extern char D_004BC310[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void cMan_BloodHitPart(cMan_0038C050* self, bloodHitInfo* hitInfo, int j, int bloodyAll);
#endif /* merge_units */
#define cMan_BloodHitPart(a0, a1, a2, a3) (cMan_BloodHitPart((cMan_0038BD30 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void cMan_BloodHitVert(cMan_0038C050* self, bloodHitInfo* hitInfo);
#endif /* merge_units */
#define cMan_BloodHitVert(a0, a1) (cMan_BloodHitVert((cMan *)(a0), (a1))) /* merge_units */

}

static inline void WaitVif0_0038C050(void)
{
    int a, b, c;
    while (*(volatile int*)0x10008000 & 0x100) {
        a = 7;
        b = 7;
        asm { div c, a, b }
    }
    for (c = *(volatile int*)0x10003800; c & 7; c = *(volatile int*)0x10003800) {
        __asm__ volatile("vnop");
        __asm__ volatile("sync");
    }
    __asm__ volatile("vnop");
    __asm__ volatile("sync");
}

/* VU1 output gather; a separate inline gives n/src/dst the a1..a3 coloring retail has */
static inline void CopyVerts(u_long128* dst, u_long128* src, int n)
{
    while (n) {
        *dst = *src;
        n--;
        src += 2;
        dst++;
    }
}

extern "C" unsigned int cMan_BloodHit(cMan_0038C050* self, bloodHitInfo* hitInfo, int bloodyAll)
{
    int bone;
    u_long128* bonesSrc;
    u_long128* boneDest;
    cVector* results;
    manRefs* refData;
    unsigned int patchCount;
    int partHitType;
    unsigned int hit;
    int applyBlood;
    int bloodSpurt;
    float hitRadSquared;
    int j;
    int qwc;
    int vertCount;
    int nextVertCount;
    u_long128* part;
    unsigned int i;
    unsigned int blood;
    unsigned int k;
    float dist;
    float distCalc;
    int bloodQWC;

    boneDest = (u_long128*)0x11004AC0;
    bonesSrc = (u_long128*)0x70000000;
    for (bone = 0; bone < 21; bone++) {
        boneDest[0] = bonesSrc[0];
        boneDest[1] = bonesSrc[1];
        boneDest[2] = bonesSrc[2];
        boneDest[3] = bonesSrc[3];
        bonesSrc += 4;
        boneDest += 4;
    }
    {
        int idx = D_00542D40;
        if (idx != D_00542D48) {
            unsigned int end = D_004937D0[idx];
            unsigned int start = D_004937C0[idx];
            *(volatile int*)0x10008020 = (end - start) >> 4;
            *(volatile int*)0x10008010 = start;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            D_00542D48 = idx;
        }
    }
    results = (cVector*)0x70000540;
    hit = 0;
    bloodSpurt = 0;
    hitInfo->closestDist = 1e7f;
    hitInfo->farthestDist = -1e7f;
    hitRadSquared = hitInfo->hitRadius * hitInfo->hitRadius;
    for (j = self->parts.manAttribsCount - 1; j >= 0; j--) {
        refData = self->parts.bodyParts[1][j].Refs;
        partHitType = self->parts.bodyParts[1][j].type & 0x1C;
        patchCount = self->parts.bodyParts[1][j].patchCount;
        part = self->parts.bodyParts[1][j].part;
        refData++;
        applyBlood = bloodyAll == 2 || (partHitType < 12 && bloodyAll == 1);
        if (self->parts.bodyParts[0][j].type & 0x80) applyBlood = 0;
        if (part && partHitType != 0x1C) {
            qwc = refData->qwc;
            nextVertCount = refData->vertCount;
            WaitVif0_0038C050();
            *(volatile int*)0x10008020 = qwc;
            *(volatile int*)0x10008010 = (int)part;
            *(volatile int*)0x10008000 = 0x101;
            __asm__ volatile("sync");
            part += qwc;
            refData++;
            for (i = 0; i < patchCount; i++) {
                WaitVif0_0038C050();
                vertCount = nextVertCount;
                blood = 0;
                CopyVerts((u_long128*)results, (u_long128*)0x11004050, vertCount);
                if (i < patchCount - 1) {
                    qwc = refData->qwc;
                    nextVertCount = refData->vertCount;
                    *(volatile int*)0x10008020 = qwc;
                    *(volatile int*)0x10008010 = (int)part;
                    *(volatile int*)0x10008000 = 0x101;
                    __asm__ volatile("sync");
                    part += qwc;
                    refData++;
                }
                for (k = 0; k < vertCount; k++) {
                    {
                        float x;
                        float z;
                        z = results[k].z;
                        x = results[k].x;
                        dist = z * z + x * x;
                    }
                    if (dist < hitRadSquared) {
                        hit = 1;
                        blood = 1;
                        distCalc = 0.25f * results[k].y + AbsZ(dist);
                        if (distCalc < hitInfo->closestDist) {
                            hitInfo->closestDist = distCalc;
                            hitInfo->closestY = results[k].y;
                            hitInfo->closestHitType = partHitType;
                            hitInfo->closestVert = k;
                            hitInfo->closestPatch = i;
                            hitInfo->closestPart = j;
                        }
                        if (distCalc > hitInfo->farthestDist) {
                            hitInfo->farthestDist = distCalc;
                            hitInfo->farthestY = results[k].y;
                            hitInfo->farthestHitType = partHitType;
                        }
                        if (applyBlood) break;
                    }
                }
                if (blood && applyBlood) {
                    bloodSpurt = 1;
                    if (!self->parts.bloodData[j]) {
                        bloodQWC = self->parts.bodyParts[0][j].patchCount * 2;
                        {
                            void* p;
                            {
                                AllocGuard guard;
                                p = cMemMan_Allocate(0, bloodQWC * 16, D_004BC310, 0xB24);
                            }
                            self->parts.bloodData[j] = (u_long128*)p;
                        }
                        ckc_qzero(self->parts.bloodData[j], bloodQWC);
                    }
                    cMan_BloodHitPart(self, hitInfo, j, bloodyAll);
                    break;
                }
            }
        }
    }
    if (hit) {
        cMan_BloodHitVert(self, hitInfo);
        if (bloodSpurt) self->bloodSpurt = 1;
        return hitInfo->closestHitType;
    }
    return 0;
}
#undef cMan_BloodHitPart /* merge_units */
#undef cMan_BloodHitVert /* merge_units */
static inline void merge_flush_func_0038C050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038C050 */
