/*
 * main/SpecFxDefs: range (2 files, 00230980-00230B00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
