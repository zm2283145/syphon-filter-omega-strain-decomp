/*
 * main/hud: range (2 files, 00246510-00246540)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "hud_types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_00246510 */
#pragma push /* merge_units */
char D_004A7530[] = "GuiWidget"; /* "GuiWidget" */

/* GuiWidget::IsA: returns 1 if the given class name is "GuiWidget". */
int GuiWidget_IsType(void* self, const char* name)
{
    return strcmp(D_004A7530, name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00246510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00246510 */

/* merge_units: begin func_00246540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */


extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
ListPos* cLList_cHudTargetsObserverPtr_PushBackActual(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

Rel* std_vector_cInterfaceElementPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_PDAQuip_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00246540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00246540 */
