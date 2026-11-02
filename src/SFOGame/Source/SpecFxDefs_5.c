/*
 * SFOGame/Source/SpecFxDefs: 6 files, 002307B0-00230920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002307B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { __int128 r[4]; } M44;
struct V4c { float x, y, z, w; } __attribute__((aligned(16)));
struct Obj { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V4c GetPos(); };
struct Msg;
extern "C" {
extern char D_004F7BE8[];
extern char D_004DBB40[];
extern char D_004DCF10[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg* v, void* arg);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int(Msg* v, Obj* target, int a2);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg* v, int flags);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void SfxParticleEffect_eEffectName_cMatrixR(int id, M44* m);
}
struct Msg { void* vtable; char pad4[0x1C]; unsigned char b20; char pad21[3]; Obj* target; unsigned char id; char pad29[7];
    Msg(Obj* o, int i) { Msg* s = this; cMessage_ctor_cMessageNameR(s, D_004F7BE8); s->vtable = D_004DCF10; s->vtable = D_004DBB40; s->target = o; s->id = i; s->b20 = 4; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vtable = D_004DCF10; cMessage_dtor(this, 0); }
    void Send(Obj* o) { QueueMessage_cMessageR_cSystemP_int(this, o, 0); }
};
extern "C" {
}
static inline void UnitMtx(void* m0) { void* m = m0; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CpC(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }

extern "C" void Global_SpawnParticle(int id, Obj* o, int notify)
{
    M44 m;
    UnitMtx(&m);
    CpC(&m.r[3], &o->GetPos());
    SfxParticleEffect_eEffectName_cMatrixR(id, &m);
    if (notify) {
        Msg(o, id).Send(o);
    }
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002307B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002307B0 */

/* merge_units: begin func_002308B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

DEFINE_VTABLE2_BASE_DTOR(cNetSpawnParticleMsg_dtor, D_004DBB40, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_002308B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002308B0 */

/* merge_units: begin func_00230920 */
#pragma push /* merge_units */
typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_004F7C00[];
extern char D_004DBAC0[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(EventMsg* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNetSpawnLightMsg_UnpackAndProcess(EventMsg* msg, void* target);
#endif /* merge_units */
void cNetSpawnLightMsg_UnpackAndProcess(); /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


/* Builds a stack event message and dispatches it to target. */
void cNetSpawnLightMsg_NetReceive(void* target) {
    EventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7C00);
    msg.vtbl = D_004DBAC0;
    cNetSpawnLightMsg_UnpackAndProcess(&msg, target);
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00230920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00230920 */

/* merge_units: begin func_00230980 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline short R16_00230980(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00230980(void) { unsigned short lo = R16_00230980(); return lo + ((unsigned short)R16_00230980() << 16); }
static inline float RF_00230980(void) { int i = R32_00230980(); return *(float*)&i; }
static inline char R8_00230980(void) { return *D_005061D0++; }
typedef struct { char pad[0x24]; void* obj; float a; float b; } M_00230980;
extern void cNetMsg_GetGOBJ(void* out);
extern void Global_SpawnLight(void* obj, int z, float a, float b);
void cNetSpawnLightMsg_UnpackAndProcess(M_00230980* m) {
    cNetMsg_GetGOBJ(&m->obj);
    m->a = RF_00230980();
    m->b = RF_00230980();
    Global_SpawnLight(m->obj, 0, m->a, m->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00230980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00230980 */

/* merge_units: begin func_00230B00 */
#pragma push /* merge_units */
static inline void W16_00230B00(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00230B00(int v) { W16_00230B00((unsigned short)v); W16_00230B00(v >> 16); }
static inline void WF_00230B00(float f) { W32_00230B00(*(int*)&f); }
typedef struct { char pad[0x24]; void* obj; float a; float b; } M_00230B00;
extern void cNetMsg_PutGOBJ(void* o);
void cNetSpawnLightMsg_Pack(M_00230B00* m) {
    cNetMsg_PutGOBJ(m->obj);
    WF_00230B00(m->a);
    WF_00230B00(m->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00230B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00230B00 */

/* merge_units: begin func_00230C80 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


extern void cNetSpawnParticleMsg_UnpackAndProcess(Visitor* v, void* target);
#if 0 /* merge_units */
extern void cMessage_dtor(Visitor* v, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */



/* Constructs a temporary visitor on the stack, applies it to self and destroys it. */
void cNetSpawnParticleMsg_NetReceive(void* self)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_004F7BE8);
    v.vtable = D_004DBB40;
    cNetSpawnParticleMsg_UnpackAndProcess(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00230C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00230C80 */
