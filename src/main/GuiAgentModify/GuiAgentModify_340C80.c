/*
 * main/GuiAgentModify: range (3 files, 00340C80-00341060)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "child_list_iter.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_00340C80 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W_340C80;
typedef struct { char pad[4]; char s4[4]; } Snd_340C80;
typedef struct {
    char pad[0x88]; W_340C80* f88; char pad8C[0xEC - 0x8C]; int fEC; int fF0; char padF4[4]; int fF8;
    char padFC[0x144 - 0xFC]; int f144; int f148; int f14C; int f150;
} O_340C80;
char D_004B9F50[] = "head"; extern char D_004B9F58[]; extern char D_004B9F60[]; extern char D_004B9F68[];
extern char g_AgentPartCache[]; extern char D_004B9ED0[]; extern char D_004B9EE8[];
char* String_CStr(void* s);
void GuiAgentModify_SelectCategory(O_340C80* o, char* s);
void GuiAgentModify_GroupHide(O_340C80* o, int v);
void GuiAgentModify_GroupShow(O_340C80* o, Snd_340C80* s);
void GuiAgentModify_ShowPatch(O_340C80* o);
void GuiAgentModify_UpdateAvailability(O_340C80* o);
void AgentPartCache_Unlock(void* p);
void World_ClearPendingIfLoaded(void);
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
void* GuiManager_FindOrLoad(void* mgr, char* a, char* b);
void GuiStack_SwapScreens(void* mgr, void* o, void* w);
int GuiSaveAgentWidget_OnEvent(O_340C80* o, Snd_340C80* s, unsigned short msg, int param, int extra);

int GuiAgentModify_HandleEvent(O_340C80* o, Snd_340C80* snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x10 && param == 1) return 1;
    if (msg == 0) {
        char* s;
        o->fF0 = 0;
        s = String_CStr(snd->s4);
        GuiAgentModify_SelectCategory(o, s);
        if (!strcmp(s, D_004B9F50)) {
            GuiAgentModify_GroupHide(o, o->f144);
            GuiAgentModify_GroupHide(o, o->f14C);
            GuiAgentModify_GroupHide(o, o->f150);
            GuiAgentModify_GroupShow(o, snd);
            if (o->fF8 == 0 && o->f88) o->f88->flags &= ~2;
            o->fEC = 3;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F58)) {
            GuiAgentModify_GroupHide(o, o->f148);
            GuiAgentModify_GroupHide(o, o->f14C);
            GuiAgentModify_GroupHide(o, o->f150);
            GuiAgentModify_GroupShow(o, snd);
            o->fEC = 2;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F60)) {
            GuiAgentModify_GroupHide(o, o->f148);
            GuiAgentModify_GroupHide(o, o->f144);
            GuiAgentModify_GroupHide(o, o->f150);
            GuiAgentModify_GroupShow(o, snd);
            o->fEC = 0;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F68)) {
            GuiAgentModify_GroupHide(o, o->f148);
            GuiAgentModify_GroupHide(o, o->f144);
            GuiAgentModify_GroupHide(o, o->f14C);
            GuiAgentModify_GroupShow(o, snd);
            o->fEC = 1;
            o->fF0 = 1;
        }
        if (o->fF0 == 0 && o->fEC == 1) GuiAgentModify_ShowPatch(o);
        GuiAgentModify_UpdateAvailability(o);
    }
    if (msg == 0x1A && param == 0xC) {
        void* w;
        AgentPartCache_Unlock(g_AgentPartCache);
        World_ClearPendingIfLoaded();
        w = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004B9ED0, D_004B9EE8);
        GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
        return 1;
    }
    return GuiSaveAgentWidget_OnEvent(o, snd, msg, param, extra);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00340C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00340C80 */

/* merge_units: begin func_00340F60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Clear flag 0x80 on every other child of the given type. */
extern "C" {
extern char D_004A9870[];
void GuiAgentModify_GroupUnlock(void* self, ChildWidget* o);
}
static inline ChildWidget* cast340F60(ChildWidget* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void GuiAgentModify_GroupUnlock(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (cast340F60(c)) n->obj->flags &= ~0x80;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00340F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00340F60 */

/* merge_units: begin func_00341060 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Set flags 4 and 0x80 on every other child of the given type. */
extern "C" {
void GuiAgentModify_GroupLock(void* self, ChildWidget* o);
}
static inline ChildWidget* cast341060(ChildWidget* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void GuiAgentModify_GroupLock(void* self, ChildWidget* o)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (cast341060(c)) {
                n->obj->flags |= 4;
                n->obj->flags |= 0x80;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341060 */
