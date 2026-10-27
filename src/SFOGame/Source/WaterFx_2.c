/*
 * SFOGame/Source/WaterFx: 4 files, 002B20E0-002B21E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B20E0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cWake_dtor(void* p, int n);
void cSplash_dtor(void* p, int n);
}
static inline void WF_Destroy(char* rec, int pool, int full, char* file, int line)
{
    AllocGuard g;
    if (full && rec) {
        cWake_dtor(rec + 0x70, -1);
        cSplash_dtor(rec + 0x40, -1);
    }
    cMemMan_Deallocate(pool, rec, file, line);
}
/* Frees a water effect record, optionally destroying its sub-lists first. */
extern "C" void opDelete_tBodyP_int_bool_charP_etc(char* rec, int pool, int full, char* file, int line)
{
    WF_Destroy(rec, pool, full, file, line);
}
static inline void merge_flush_func_002B20E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B20E0 */

/* merge_units: begin func_002B21D0 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; } Obj4;
/* Returns whether the field at +4 is zero. */
int cWake_Expired(Obj4* o) { return o->unk4 == 0; }
static inline void merge_flush_func_002B21D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B21D0 */

/* merge_units: begin func_002B21E0 */
#pragma push /* merge_units */
int cSplash_Expired(float* p) { return *p == 0.0f; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B21E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B21E0 */

/* merge_units: begin func_002B2210 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; float h0; char pad2[0x54]; float h1; } WaterFxObj;
typedef struct { char pad[0x400]; WaterFxObj* objs[1]; } WaterFxMgr;
extern int cWaterFx_FindBodyIdx(WaterFxMgr* w, int id);
void cWaterFx_ChangeWaterHeight(WaterFxMgr* w, int id, float h) {
    float y = 0.2f + h;
    if (id) {
        int i = cWaterFx_FindBodyIdx(w, id);
        WaterFxObj* o = (i >= 0) ? w->objs[i] : 0;
        if (o) {
            o->h0 = y;
            o->h1 = y;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B2210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B2210 */
