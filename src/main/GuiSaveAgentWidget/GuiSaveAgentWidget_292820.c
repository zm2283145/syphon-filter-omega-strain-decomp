/*
 * main/GuiSaveAgentWidget: 3 files, 00292820-00292980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00292820 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004A9C80[] = "GuiAgentCreate"; }
extern "C" { char D_004A9C90[] = "AGENTNEW"; }
DEFINE_EVENT_SOUND_CHECK(func_00292820, D_004A9C80, D_004A9C90)
#pragma pop /* merge_units */
/* merge_units: end func_00292820 */

/* merge_units: begin func_002928E0 */
#pragma push /* merge_units */
typedef struct Settings2E {
    char pad00[0x2E];
    unsigned char altMode; /* 0x2E */
} Settings2E;

extern Settings2E* D_004FFC04;
extern void* Gui_GetScreenList(void);
#if 0 /* merge_units */
extern void* GuiManager_FindOrLoad(void* lib, const char* a, const char* b);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) ((void *)GuiManager_FindOrLoad((a0), (char *)(a1), (char *)(a2))) /* merge_units */

extern void* Gui_GetScreenStack(void);
#if 0 /* merge_units */
extern void GuiStack_SwapScreens(void* mgr, int arg, void* res);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((a0), (void *)(a1), (int)(a2))) /* merge_units */


/* Looks up the mode-dependent resource and hands it to the manager. */
void func_002928E0(int arg) {
    void* res;
    if (D_004FFC04->altMode) {
        res = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiCommandCenter", "CMDCENTR");
    } else {
        res = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "onoffsel");
    }
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, res);
}
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002928E0 */

/* merge_units: begin func_00292980 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00292980 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int atoi(...);                             
int String_CStr(...);                          
int GuiSaveAgentWidget_HandleEvent(...);                            
int GuiSaveAgentWidget_OnEvent(...);                                
extern char D_004A9870;
}
extern "C" int func_00292980(char * arg0, void **arg1, int arg2) {
    void **var_s0;

    var_s0 = arg1;
    if ((arg2 & 0xFFFF) == 2) {
        var_s0 = ((var_s0 != NULL) && (((VC00292980 *)(var_s0))->v20(&D_004A9870) != 0)) ? var_s0 : NULL;
        if (var_s0 != NULL) {
            F_(arg0, 0x50, int) = atoi(String_CStr((char *)var_s0 + 4));
            F_(arg0, 0x4C, signed char) = 0;
            GuiSaveAgentWidget_HandleEvent(arg0);
        }
        return 1;
    }
    return GuiSaveAgentWidget_OnEvent();
}
#pragma pop /* merge_units */
/* merge_units: end func_00292980 */
