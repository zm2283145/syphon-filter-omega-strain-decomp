/*
 * main/GuiSubTitleDisplay: 2 files, 00456F90-00457040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456F90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V456 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(char*); };
extern "C" {
extern void GuiWidget_onAdd(void*);
extern V456* GuiWidget_FindChild_charP(void*, char*);
extern char D_004A7520[];
extern char D_004C1A38[];
extern char g_Game[];
extern int cGameSystem_GetAgentData(char*, int);
extern char* cAgentData_GetUserName(int);
extern void GuiTextWidget_SetText(V456*, char*, int);
}
extern "C" void GuiStartMenuBackdrop_onAdd(void* w) {
    V456* p;
    GuiWidget_onAdd(w);
    p = GuiWidget_FindChild_charP(w, "value_agentname");
    p = (p && p->v20(D_004A7520)) ? p : 0;
    if (p) {
        char* s = cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game, -1));
        GuiTextWidget_SetText(p, s ? s : D_004C1A38, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00456F90 */

/* merge_units: begin func_00457040 */
#pragma push /* merge_units */
#include "GuiGameScreen_types.h"

extern void* Gui_Manager(void);
extern void* GuiManager_FindOpenGui(void* manager, const char* name);
#if 0 /* merge_units */
extern GuiGameChild* GuiWidget_FindChild_charP(void* parent, const char* name);
#endif /* merge_units */
#define GuiWidget_FindChild_charP(a0, a1) ((GuiGameChild *)GuiWidget_FindChild_charP((a0), (char *)(a1))) /* merge_units */

extern char D_004C1B00[];
extern char D_004C1B28[];
extern char D_004C1B38[];
extern char D_004C1B18[];
extern char D_004C1B20[];

static inline void set_active(GuiGameChild* widget, int active)
{
    if (widget) {
        if (active)
            widget->flags |= 2;
        else
            widget->flags &= ~2;
    }
}

/* Toggle the first pair of named widgets when their parent is available. */
void func_00457040(int active)
{
    void* parent = GuiManager_FindOpenGui(Gui_Manager(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = GuiWidget_FindChild_charP(parent, D_004C1B28);
        GuiGameChild* second = GuiWidget_FindChild_charP(parent, D_004C1B38);
        set_active(first, active);
        set_active(second, active);
    }
}

/* Toggle the second pair of named widgets when their parent is available. */
void func_00457110(int active)
{
    void* parent = GuiManager_FindOpenGui(Gui_Manager(), D_004C1B00);
    if (parent) {
        GuiGameChild* first = GuiWidget_FindChild_charP(parent, D_004C1B18);
        GuiGameChild* second = GuiWidget_FindChild_charP(parent, D_004C1B20);
        set_active(first, active);
        set_active(second, active);
    }
}
#undef GuiWidget_FindChild_charP /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00457040 */
