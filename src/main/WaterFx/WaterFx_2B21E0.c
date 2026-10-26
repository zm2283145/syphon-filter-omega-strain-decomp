/*
 * main/WaterFx: range (2 files, 002B21E0-002B2210)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
extern int WaterFx_Find(WaterFxMgr* w, int id);
void WaterFx_UpdateHeight(WaterFxMgr* w, int id, float h) {
    float y = 0.2f + h;
    if (id) {
        int i = WaterFx_Find(w, id);
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
