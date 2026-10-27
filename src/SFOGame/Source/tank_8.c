/*
 * SFOGame/Source/tank: 2 files, 00283CA0-00283DA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00283CA0 */
#pragma push /* merge_units */
#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_00283CA0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00283CA0(int v) { W16_00283CA0((unsigned short)v); W16_00283CA0(v >> 16); }
static inline void WF_00283CA0(float f) { W32_00283CA0(*(int*)&f); }
static inline short R16_00283CA0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00283CA0(void) { unsigned short lo = R16_00283CA0(); return lo + ((unsigned short)R16_00283CA0() << 16); }
static inline float RF_00283CA0(void) { int i = R32_00283CA0(); return *(float*)&i; }
typedef struct { char pad[0x24]; unsigned char b; char p25[3]; void* obj; float f; } M_00283CA0;
extern void cNetMsg_PutGOBJ(void* o);
void cNetUpdateTankMsg_Pack(M_00283CA0* m) {
    *D_005061D0++ = m->b;
    cNetMsg_PutGOBJ(m->obj);
    WF_00283CA0(m->f);
}
static inline void merge_flush_func_00283CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00283CA0 */

/* merge_units: begin func_00283DA0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x24]; int value; char pad2[4]; } Msg;
extern char g_NetCreateTankMsgKey[];
extern char cNetCreateTankMsg_vtable[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern void cNetCreateTankMsg_UnpackAndProcess(Msg* m, void* target);
extern void cMessage_dtor(Msg* m, int flags);
/* Builds a temporary message (value -1), sends it to target, then destroys it. */
void cNetCreateTankMsg_NetReceive(void* target)
{
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, g_NetCreateTankMsgKey);
    msg.vtable = cNetCreateTankMsg_vtable;
    msg.value = -1;
    cNetCreateTankMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_00283DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00283DA0 */
