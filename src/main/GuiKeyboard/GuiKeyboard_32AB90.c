/*
 * main/GuiKeyboard: 2 files, 0032AB90-0032AC20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032AB90 */
#pragma push /* merge_units */
typedef struct { char d[0x2C]; } E2AB90;
typedef struct { int first; int count; E2AB90* buf; } V2AB90;
extern void func_003282A0(E2AB90* e, int flag);
void func_0032AB90(V2AB90* v)
{
    E2AB90* b = v->buf;
    E2AB90* e = b + v->count;
    while (b < e) {
        --e;
        func_003282A0(e, -1);
    }
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032AB90 */

/* merge_units: begin func_0032AC20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

extern "C" { char D_004B8880[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_0032AC20, 0x220, D_004B8880, func_00328660)
#pragma pop /* merge_units */
/* merge_units: end func_0032AC20 */
