/*
 * main/GuiGameOptions: range (2 files, 002996D0-00299780)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002996D0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int GuiGameOptions_Refresh(int, int);                                 
int FrontEnd_ResumeGui(int);                               
int FrontEnd_SuspendGui(int, int);                            
int FrontEnd_ClosePopup(int, int);                          
int GameOptions_Apply(int , int);                         
extern float D_004C1FC8;
extern int D_004FFC04;
extern int D_005383C0;

void func_002996D0(int arg0, int arg1) {
    F_(arg0, 0x78, int) = 0;
    F_(arg0, 0xD8, int) = 0;
    GuiGameOptions_Refresh(arg0, 0x800);
    FrontEnd_SuspendGui(D_004FFC04, 1);
    GameOptions_Apply(arg0 + 0xB8, 0x800);
    FrontEnd_ResumeGui(D_004FFC04);
    D_005383C0 = (int) (F_(arg0, 0xD4, float) * D_004C1FC8) & 0xFF;
    if (arg1 != 0) {
        FrontEnd_ClosePopup(D_004FFC04, F_(arg0, 0x48, int));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002996D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002996D0 */

/* merge_units: begin func_00299780 */
#pragma push /* merge_units */
int Gui_GetScreenList();                                
int Gui_GetScreenStack();                                
int GuiStack_SwapScreens(int, int , int);                  
int GuiManager_FindOrLoad(int, int *, int *);                   
int GuiStartMenu_ReturnToMenu();                                  

void GuiGameOptions_Leave(int arg0) {
    int temp_s0;

    if (F_(arg0, 0x400, unsigned char) != 0) {
        GuiStartMenu_ReturnToMenu();
        return;
    }
    temp_s0 = GuiManager_FindOrLoad(Gui_GetScreenList(), ((int*)"GuiTitleScreen"), ((int*)"TITLESCR"));
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg0, temp_s0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00299780(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00299780 */
