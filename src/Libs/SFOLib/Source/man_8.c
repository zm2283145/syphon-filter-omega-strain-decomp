/*
 * Libs/SFOLib/Source/man: 3 files, 0038A620-0038A800
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
