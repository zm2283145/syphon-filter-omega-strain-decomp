/*
 * main/GuiEquipmentSetup: range (2 files, 002A6F40-002A6FC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "guarded_new.h"
#pragma pop

/* merge_units: begin func_002A6F40 */
#pragma push /* merge_units */
typedef struct { char d[0x3C]; } g2E3C;
typedef struct { int pad0; int size; g2E3C* data; } g2Vec3C;
extern void func_001AEF70(g2E3C* e, int flag);
void func_002A6F40(g2Vec3C* v) {
    g2E3C* b = v->data;
    g2E3C* e = b + v->size;
    while (b < e) {
        --e;
        func_001AEF70(e, -1);
    }
    v->size = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A6F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A6F40 */

/* merge_units: begin func_002A6FC0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Factory: allocate and construct. */
extern "C" {
char D_004AB358[] = "guiWidget.hh";
}
DEFINE_GUARDED_NEW_CTOR(func_002A6FC0, 0xE0, D_004AB358, GuiEquipmentSetup_Create)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A6FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A6FC0 */
