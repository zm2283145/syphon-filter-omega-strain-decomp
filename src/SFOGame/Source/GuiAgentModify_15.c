/*
 * main/GuiNetMessages: 3 files, 00346B80-00346C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346B80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00346B80(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00346B80 */

/* merge_units: begin func_00346B90 */
#pragma push /* merge_units */
typedef struct { char b[0x3C]; } E346;
typedef struct { int a; int count; E346* data; } H346;
extern void cSkaSliderValue_dtor(E346* e, int flags);
void func_00346B90(H346* h)
{
    E346* begin = h->data;
    E346* e = begin + h->count;
    while (begin < e) {
        e--;
        cSkaSliderValue_dtor(e, -1);
    }
    h->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00346B90 */

/* merge_units: begin func_00346C10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

extern "C" { char D_004BA130[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(ConcreteWidgetClassRep_GuiAgentModify_Create, 0x160, D_004BA130, GuiAgentModify_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00346C10 */
