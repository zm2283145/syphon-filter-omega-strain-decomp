/*
 * SFOGame/Source/GameParticle: 5 files, 001C5710-001C59D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C5710 */
#pragma push /* merge_units */
#include "types.h"
#include "event_toggle_send.h"

/* Post the "on" event and set the state flag. */
DEFINE_EVENT_TOGGLE_SEND(cGameParticle_Enable, g_cEnableMsgClass, D_004E0880, cEnableMsg_SendEnabled, 1)
static inline void merge_flush_func_001C5710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C5710 */

/* merge_units: begin func_001C57A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; int f60; } G1C5;
typedef struct { void* vt; char pad[0x1C]; unsigned char b20; char pad2[0x19F]; } M1C5;
typedef struct { char pad[0x190]; } R1C5;
extern void cPARTICLE_GOBJ_NextFrame(G1C5*);
extern int cPARTICLE_GOBJ_EventHappened(G1C5*);
extern int cPARTICLE_GOBJ_GetEvent(G1C5*, int*);
extern int* nSfxLoader_GetHandle(int);
extern int g_VideoFrameCounter;
extern void cSndFx_ctor_int_charP_cGOBJP_int(R1C5*, int, char*, int, int);
extern void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(M1C5*, R1C5*, int*);
extern void QueueMessage_cMessageR_cSystemP_int(M1C5*, char*, int);
extern char g_Game[];
extern char D_004DAE30[];
#if 0 /* merge_units */
extern void cFileMan_dtor(void*, int);
#endif /* merge_units */
void* cFileMan_dtor(void* entry, int flags); /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(M1C5*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ToggleEventMsg *)(a0), (a1))) /* merge_units */


void cGameParticle_NextFrame(G1C5* g) {
    int x[4];
    R1C5 req;
    M1C5 msg;
    cPARTICLE_GOBJ_NextFrame(g);
    if (!cPARTICLE_GOBJ_EventHappened(g)) return;
    if ((unsigned char)cPARTICLE_GOBJ_GetEvent(g, x) != 1) return;
    if (g->f60 != *nSfxLoader_GetHandle(9)) return;
    if (g_VideoFrameCounter & 7) return;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, "O_GLASS_BREAK_S", 0, 0);
    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, x);
    msg.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    msg.vt = D_004DAE30;
    cFileMan_dtor((char*)&msg + 0x114, -1);
    cFileMan_dtor((char*)&msg + 0x78, -1);
    cMessage_dtor(&msg, 0);
    cFileMan_dtor((char*)&req + 0xE4, -1);
    cFileMan_dtor((char*)&req + 0x48, -1);
}
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_001C57A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C57A0 */

/* merge_units: begin func_001C58A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gobj_flag_dtor.h"
DEFINE_GOBJ_FLAG_DTOR(cPARTICLE_GOBJ_dtor, D_004DF860)
static inline void merge_flush_func_001C58A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C58A0 */

/* merge_units: begin func_001C5950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern char D_004DAA10[]; /* vtable of the derived object */
extern char D_004DF860[]; /* vtable of its intermediate base */
#if 0 /* merge_units */
extern cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3);
#endif /* merge_units */
void* cGOBJ_ctor(void*, int*, int, void*); /* merge_units */
#define cGOBJ_ctor(a0, a1, a2, a3) ((cGOBJ *)cGOBJ_ctor((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */


/* Constructor of a cGOBJ-derived object (two inlined constructor levels). */
UnkGobj001C5950* cGameParticle_ctor_cObjectIdR_int(UnkGobj001C5950* self, int* desc, int value) {
    int zero[1];

    zero[0] = 0;
    cGOBJ_ctor(&self->base, desc, 4, zero);
    self->base.vtable = D_004DF860;
    self->unk60 = value;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk70 = 1.0f;
    self->base.unk2F = 1;
    self->base.vtable = D_004DAA10;
    return self;
}
#undef cGOBJ_ctor /* merge_units */
static inline void merge_flush_func_001C5950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C5950 */

/* merge_units: begin func_001C59D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
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
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
void cGOBJ_ctor(Part_59D0*, int*, int, void*);
#endif /* merge_units */
#define cGOBJ_ctor(a0, a1, a2, a3) ((void)cGOBJ_ctor((void *)(a0), (a1), (a2), (a3))) /* merge_units */

void* cFileMan_ctor_void(void* entry);
void* cFileMan_dtor(void* entry, int flags);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(Mtx* m, const V4& a, const V4& b, const V4& c, const V4& t);
void cMatrix_SetAxes(Mtx* m, V4* a, V4* b, V4* c);
void cMatrix_SetTranslation(Mtx* m, V4* t);
int nGobjManager_LookupGOBJ_int_int(int, int);
void cTerrain_AddActivation(int, Part_59D0*, int, int);
int cNetObj_AddSystem(int, int, Part_59D0*);
int NetGetMyClientIndex(int*, int);
int NetGetPeerToPeerHostClientIndex(int, int*);
}
static inline void FromRows(Mtx* m, const V4& a, const V4& b, const V4& c, const V4& t) { const V4* pa = &a; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, *pa, b, c, t); }
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
static inline unsigned char IsLocal() {unsigned char r;if(g_IsMultiplayer)r=D_005721C0;else {r=1; asm { .set reorder }}return r;}
#pragma inline_depth(10)
static inline int LocalId() { int r=0;int a=D_005721A8;if(*(volatile unsigned char*)&g_IsMultiplayer) { if(D_00494178==-1)NetGetMyClientIndex(&D_00494178,a);r=D_00494178; }else { asm { .set reorder } }return r; }
extern "C" Part_59D0* cGameParticle_ctor_cPopulationR(Part_59D0* self, Reader* r)
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
    cFileMan_ctor_void(&fe);
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
    cMatrix_SetAxes(&x.m, &a, &b, &c);
    cMatrix_SetTranslation(&x.m, &t);
    self->SetXf(&x);
    self->SetName(pn);
    if (s2 != -1 && s1 != -1) {
        int col = nGobjManager_LookupGOBJ_int_int(s2, s1);
        if (col) cTerrain_AddActivation(col, self, 1, col);
    }
    if (g_IsMultiplayer) {
        if (!IsLocal()) self->b14 = 0;
        {
            int h = self->h10.v;
            int nid;
            if (IsLocal()) nid = LocalId(); else { NetGetPeerToPeerHostClientIndex(D_005721A8, &tmp); nid = tmp; }
            cNetObj_AddSystem(h, nid, self);
        }
    }
    cFileMan_dtor(&fe, -1);
    return self;
}
#undef cGOBJ_ctor /* merge_units */
static inline void merge_flush_func_001C59D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C59D0 */
