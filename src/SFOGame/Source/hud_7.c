/*
 * SFOGame/Source/hud: 1 file, 00242900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00242900 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00242900 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int cGameSystem_PauseGame(...);                            
int cJoystick_Debounce(...);                               
int Gui_Manager(...);                                
void **Gui_Canvas(...);                             
int GuiManager_FindOpenGui(...);                        
extern char g_Game;
extern unsigned char D_004FFBB7;
extern char D_0055A300;
}
#pragma push
#pragma opt_common_subs off
extern "C" void cHud_DeactivateObjectiveMenu(char * arg0) {
    int temp_v0;
    int temp_v0_3;
    void **temp_v0_2;
    void **temp_v0_4;

    if (F_(arg0, 0x6A8, unsigned char) != 0) {
        temp_v0 = GuiManager_FindOpenGui(Gui_Manager(), "GuiStartMenu");
        if (temp_v0 != 0) {
            temp_v0_2 = Gui_Canvas();
            ((VC00242900 *)(temp_v0_2))->v24(temp_v0);
        }
        temp_v0_3 = GuiManager_FindOpenGui(Gui_Manager(), "GuiStartMenuBackdrop");
        if (temp_v0_3 != 0) {
            temp_v0_4 = Gui_Canvas();
            ((VC00242900 *)(temp_v0_4))->v24(temp_v0_3);
        }
        cJoystick_Debounce(&D_0055A300);
        if (D_004FFBB7 != 0) {
            cGameSystem_PauseGame(&g_Game, 0);
        }
        F_(arg0, 0x6A8, unsigned char) = 0U;
    }
}
#pragma pop
static inline void merge_flush_func_00242900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242900 */
