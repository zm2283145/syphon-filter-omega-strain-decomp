#pragma cplusplus on
#pragma exceptions off
#include "types.h"
#include "vslot_pad.h"
struct V4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct V4c : V4 { V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
struct Mtx { V4 r[4]; };
struct Xf { V4 pos; Mtx m; };
struct H_59D0 { int v; };
struct Reader { int version; int a, b; char* cur; };
struct FEnt { char d[0x9C]; };
class Part_59D0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetXf(Xf*); virtual void SetName(char**);
    char p4[8]; H_59D0 hC; H_59D0 h10; unsigned char b14; char p15[0x2F - 0x15]; unsigned char b2F;
    char p30[0x60 - 0x30];
    int f60; int f64; short f68; char p6A[6]; float f70;
};
extern "C" {
extern char D_004DF860[];
extern char D_004DAA10[];
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
void cGOBJ_ctor(Part_59D0*, int*, int, void*);
void* Resource_Construct(void* entry);
void* FileMan_Release(void* entry, int flags);
void Mtx_FromRowsAndTranslation(Mtx* m, const V4& a, const V4& b, const V4& c, const V4& t);
void Mtx_SetBasis(Mtx* m, V4* a, V4* b, V4* c);
void Mtx_SetTranslation(Mtx* m, V4* t);
int IdMgr_FindCollision(int, int);
void ZoneMgr_Associate(int, Part_59D0*, int, int);
int NetMap_BindReceiver(int, int, Part_59D0*);
int NetGame_InitLocalSlot(int*, int);
int func_002EBBA0(int, int*);
}
static inline void FromRows(Mtx* m, const V4& a, const V4& b, const V4& c, const V4& t) { const V4* pa = &a; Mtx_FromRowsAndTranslation(m, *pa, b, c, t); }
static inline void XfSet(Xf* d, const V4* p, const Mtx* m) { d->pos = *p; d->m = *m; }
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void Q4(void* d, const void* s) { __int128 qb, qa; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline int Read(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(Reader* r, int* out) { *out = *(int*)r->cur; *(char* volatile*)&r->cur += 4; }
static inline float ReadF(Reader* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void Align(Reader* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}
static inline void ReadV(Reader* r, V4* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x; v->y = y; v->z = z; v->w = w;
}
static inline unsigned char IsLocal() {unsigned char r;if(D_005721C8)r=D_005721C0;else {r=1; asm { .set reorder }}return r;}
#pragma inline_depth(10)
static inline int LocalId() { int r=0;int a=D_005721A8;if(*(volatile unsigned char*)&D_005721C8) { if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,a);r=D_00494178; }else { asm { .set reorder } }return r; }
extern "C" Part_59D0* Loader_ReadParticleRecord(Part_59D0* self, Reader* r)
{
    FEnt fe;
    Xf x;
    V4 a, b, c, t;
    char* name;
    volatile int id;
    int gid;
    int z;
    int tmp;
    char** pn;
    int s2, s1;
    gid = -1;
    z = 0;
    cGOBJ_ctor(self, &gid, 4, &z);
    *(void**)self = D_004DF860;
    self->f60 = -1;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 1.0f;
    self->b2F = 1;
    *(void**)self = D_004DAA10;
    Resource_Construct(&fe);
    {
        V4 zz;
        Mtx m;
        FromRows(&m, V4c(1.0f, 0.0f, 0.0f, 1.0f), V4c(0.0f, 1.0f, 0.0f, 1.0f), V4c(0.0f, 0.0f, 1.0f, 1.0f), V4c(0.0f, 0.0f, 0.0f, 1.0f));
        {
            zz.x = 0.0f; zz.y = 0.0f; zz.z = 0.0f; zz.w = 0.0f;
            { V4* dd = &x.pos; const V4* ss = &zz; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t), "+r"(dd) : "r"(ss) : "memory"); }
            { Mtx* dd; __int128 a; __int128 b; const Mtx* ss = &m; dd = &x.m; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b), "+r"(dd) : "r"(ss) : "memory"); }
        }
    }
    {
        int hi, lo;
        ReadInt(r, &hi);
        ReadInt(r, &lo);
        id = lo | (hi << 16);
    }
    self->hC.v = id;
    self->h10.v = id;
    ReadInt(r, &s2);
    ReadInt(r, &s1);
    {
        char* nm = r->cur;
        while (*r->cur++)
            ;
        Align(r);
        name = nm;
    }
    pn = &name;
    __asm__ volatile("" : "+r"(pn));
    ReadV(r, &x.pos, 1.0f);
    ReadV(r, &a, 0.0f);
    ReadV(r, &b, 0.0f);
    ReadV(r, &c, 0.0f);
    t.x = 0.0f; t.y = 0.0f; t.z = 0.0f; t.w = 1.0f;
    Mtx_SetBasis(&x.m, &a, &b, &c);
    Mtx_SetTranslation(&x.m, &t);
    self->SetXf(&x);
    self->SetName(pn);
    if (s2 != -1 && s1 != -1) {
        int col = IdMgr_FindCollision(s2, s1);
        if (col) ZoneMgr_Associate(col, self, 1, col);
    }
    if (D_005721C8) {
        if (!IsLocal()) self->b14 = 0;
        {
            int h = self->h10.v;
            int nid;
            if (IsLocal()) nid = LocalId(); else { func_002EBBA0(D_005721A8, &tmp); nid = tmp; }
            NetMap_BindReceiver(h, nid, self);
        }
    }
    FileMan_Release(&fe, -1);
    return self;
}


