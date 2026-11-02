/*
 * SFOGame/Source/gameSound: 4 files, 001C7340-001C7460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C7340 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x20]; int id; int arg; char pad2c[4]; } Msg_7340;
#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_7340*, void*);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cNetMsg_GetInt(int*);
#endif /* merge_units */
void cNetMsg_GetInt(); /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(Msg_7340*, int);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

void* nGlobalization_GetStringTag(int);
int Voice_PlayQuip(void*, int, int);
extern char D_004DCF10[];
extern char D_004DAC70[];
extern char D_004F2D00[];

/* net message handler: read quip id and argument, play the quip if it resolves */
void cPlayQuipMsg_NetReceive(void)
{
    Msg_7340 m;
    void* p;
    cMessage_ctor_cMessageNameR(&m, D_004F2D00);
    m.vt = D_004DAC70;
    cNetMsg_GetInt(&m.id);
    cNetMsg_GetInt(&m.arg);
    p = (m.id != -1) ? nGlobalization_GetStringTag(m.id) : 0;
    if (p) Voice_PlayQuip(p, m.arg, 1);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_001C7340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C7340 */

/* merge_units: begin func_001C73F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cStopAllQuipsMsg_dtor_2, D_004DAC70, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_001C73F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C73F0 */

/* merge_units: begin func_001C7460 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* stream cursor */

static inline unsigned char ReadU8(void)
{
    return *D_005061D0++;
}

static inline short ReadS16(void)
{
    unsigned char lo = ReadU8();
    unsigned char hi = ReadU8();
    return lo + (hi << 8);
}

/* Reads a little-endian 32-bit value (two 16-bit halves) from the stream into *out. */
void cNetMsg_GetInt(int* out)
{
    unsigned short lo = ReadS16();
    unsigned short hi = ReadS16();
    *out = lo + (hi << 16);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7460 */

/* merge_units: begin func_001C7500 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x2C]; } Event001C7500;
extern char D_004F2CE8[];
extern void cMessage_getSOBJClassId();
extern void cPlayQuipMsg_dtor_2();
extern void cPlayQuipMsg_Clone();
extern void cStopAllQuipsMsg_v04();
extern void cStopAllQuipsMsg_v05();
extern void cNetMsg_Pack();
void * const D_004DAC50[8] = { (void*)0x0, (void*)0x0, (void*)cPlayQuipMsg_dtor_2, (void*)cPlayQuipMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cStopAllQuipsMsg_v04, (void*)cStopAllQuipsMsg_v05 };
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Event001C7500* ev, void* desc);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void nGameSound_StopAllQuips(int a);
#if 0 /* merge_units */
extern void cMessage_dtor(Event001C7500* ev, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

/* Build a temporary event, run nGameSound_StopAllQuips(1) and destroy the event. */
void cStopAllQuipsMsg_NetReceive(void)
{
    Event001C7500 ev;
    cMessage_ctor_cMessageNameR(&ev, D_004F2CE8);
    ev.vtable = ((char*)D_004DAC50);
    nGameSound_StopAllQuips(1);
    ev.vtable = D_004DCF10;
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7500(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C7500 */
