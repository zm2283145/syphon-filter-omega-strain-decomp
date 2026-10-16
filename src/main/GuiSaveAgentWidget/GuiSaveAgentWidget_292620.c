/*
 * main/GuiSaveAgentWidget: 3 files, 00292620-002926B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00292620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Vector clear (count = 0). */
void func_00292620(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00292620 */

/* merge_units: begin func_00292630 */
#pragma push /* merge_units */
typedef struct { char b[0x3C]; } G1E;
typedef struct { int cap; int count; G1E* data; } G1Arr;
extern void func_001AEF70(G1E* e, int a);
void func_00292630(G1Arr* a)
{
    G1E* b = a->data;
    G1E* e = b + a->count;
    while (b < e) {
        e--;
        func_001AEF70(e, -1);
    }
    a->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00292630 */

/* merge_units: begin func_002926B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004A9B70[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiAgentCreate_Create, 0x100, D_004A9B70, GuiAgentCreate_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_002926B0 */
