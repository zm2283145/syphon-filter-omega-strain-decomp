/*
 * SFOGame/Source/SpecFxDefs: 4 files, 00230920-00230C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00230920 */
#pragma push /* merge_units */
#include "types.h"

typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_004F7C00[];
extern char D_004DBAC0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(EventMsg* msg, void* type);
#if 0 /* merge_units */
extern void cNetSpawnLightMsg_UnpackAndProcess(EventMsg* msg, void* target);
#endif /* merge_units */
void cNetSpawnLightMsg_UnpackAndProcess(); /* merge_units */

extern void cMessage_dtor(EventMsg* msg, int flags);

/* Builds a stack event message and dispatches it to target. */
void cNetSpawnLightMsg_NetReceive(void* target) {
    EventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7C00);
    msg.vtbl = D_004DBAC0;
    cNetSpawnLightMsg_UnpackAndProcess(&msg, target);
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
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

extern char D_004F7BE8[];
extern char D_004DBB40[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((EventMsg *)(a0), (a1))) /* merge_units */

extern void cNetSpawnParticleMsg_UnpackAndProcess(Visitor* v, void* target);
#if 0 /* merge_units */
extern void cMessage_dtor(Visitor* v, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((EventMsg *)(a0), (a1))) /* merge_units */


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
