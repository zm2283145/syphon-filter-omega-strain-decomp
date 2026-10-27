/*
 * main/GuiScoresEquip: range (2 files, 0035F910-0035F990)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "guarded_new.h"
#pragma pop

/* merge_units: begin func_0035F910 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; } G7E35;
typedef struct { int pad; int count; G7E35* data; } G7V35;
extern void cSkaSliderValue_dtor(void* p, int x);
void func_0035F910(G7V35* v)
{
    G7E35* b = v->data;
    G7E35* e = b + v->count;
    while (b < e) {
        e--;
        cSkaSliderValue_dtor(e, -1);
    }
    v->count = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035F910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035F910 */

/* merge_units: begin func_0035F990 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004BB6F0[] = "guiWidget.hh";
}
DEFINE_GUARDED_NEW_CTOR(GuiScoresEquip_Create, 0x250, D_004BB6F0, GuiScoresEquip_ctor)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035F990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035F990 */
