/*
 * main/gameSound: range (2 files, 001C7460-001C7500)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Event001C7500* ev, void* desc);
extern void nGameSound_StopAllQuips(int a);
extern void cMessage_dtor(Event001C7500* ev, int flags);
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
#pragma pop /* merge_units */
/* merge_units: end func_001C7500 */
