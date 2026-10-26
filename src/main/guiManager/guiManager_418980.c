/*
 * main/guiManager: 2 files, 00418980-00418A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418980 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Obj_8980 { VPAD16(a) VPAD2(b) VPAD1(c) virtual char* GetName(); };
struct Raw_8980 { int p; };
extern "C" {
Raw_8980 List_Begin(void*);
Raw_8980 std_list_GuiWidgetPtr_end(void*);
void std_list_GuiWidgetPtr_generic_iterator_ctor(char**, const Raw_8980&);
void cLListIterator_GuiWidgetPtr_ctor_listR(char**, const Raw_8980&);
int String_CompareNoCase(char*, char*);
}
#pragma opt_common_subs off
extern "C" Obj_8980* GuiManager_FindByName(char* self, char* name) {
    char* end;
    char* n;
    char* it;
    if (!name || !*name) return 0;
    std_list_GuiWidgetPtr_generic_iterator_ctor(&it, List_Begin(self + 0x14));
    n = it;
    while ((cLListIterator_GuiWidgetPtr_ctor_listR(&end, std_list_GuiWidgetPtr_end(self + 0x14)), n != end)) {
        if (String_CompareNoCase(F_(n, 0x8, Obj_8980*)->GetName(), name) == 0) return F_(n, 0x8, Obj_8980*);
        n = F_(n, 0x4, char*);
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418980 */

/* merge_units: begin func_00418A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */



int GuiWidget_GetClassName(void) {
    return (int)"GuiWidget";
}
#pragma pop /* merge_units */
/* merge_units: end func_00418A70 */
