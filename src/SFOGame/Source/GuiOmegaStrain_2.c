/*
 * main/GuiOmegaStrain: 3 files, 0034E9C0-0034EA00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034E9C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain class-name getter (vtable D_004DEDE0 slot 19).
 */

#include "loose03_types.h"

char D_004BAA30[] = "GuiOmegaStrain";       /* "GuiOmegaStrain" */

/* Returns the class name string "GuiOmegaStrain". */
const char* GuiOmegaStrain_GetClassName(void) {
    return D_004BAA30;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E9C0 */

/* merge_units: begin func_0034E9D0 */
#pragma push /* merge_units */
#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiOmegaStrain" */

/* GuiOmegaStrain type check: true when name equals the class name "GuiOmegaStrain". */
int GuiOmegaStrain_IsClass(void* self, const char* name) {
    return strcmp("GuiOmegaStrain", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034E9D0 */

/* merge_units: begin func_0034EA00 */
#pragma push /* merge_units */
typedef struct { char pad[0x18]; int a18; } E34EA00;
typedef struct { int a0; int count; E34EA00* data; unsigned char aC; } L34EA00;
extern char g_Game[];
extern void func_00296F20(L34EA00* l);
extern void std_vector_deleter_tRequirementInfo_dtor(L34EA00* l, int flags);
extern void* cGameSystem_GetAgentData(void* list, int idx);
extern void cAgentData_GetRequirements(void* ag, int a, int b, L34EA00* l);
extern void GuiPersonnelScreen_SetupPreviewWidgets(void* o, int i, int v);
void GuiOmegaStrain_ItemGainFocus(void* o, int idx)
{
    L34EA00 l;
    func_00296F20(&l);
    l.aC = 1;
    cAgentData_GetRequirements(cGameSystem_GetAgentData(g_Game, -1), 4, 0, &l);
    if (idx >= 0 && idx < l.count) GuiPersonnelScreen_SetupPreviewWidgets(o, idx, ((E34EA00*)((char*)l.data + idx * 28))->a18);
    std_vector_deleter_tRequirementInfo_dtor(&l, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034EA00 */
