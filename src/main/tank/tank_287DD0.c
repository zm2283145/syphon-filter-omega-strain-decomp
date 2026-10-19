/*
 * main/tank: 2 files, 00287DD0-00287E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00287DD0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiTitleScreen". */
int func_00287DD0(void* self, const char* name)
{
    return strcmp("GuiTitleScreen", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00287DD0 */

/* merge_units: begin func_00287E00 */
#pragma push /* merge_units */
typedef struct { char pad[0x260]; int f260; } Ui287E00;
typedef struct { char pad[0x4C]; float t; int h; } Obj287E00;
typedef struct { int m0; char str[4]; } Msg287E00;
extern int Loc_LookupText(char*);
extern int String_AssignCStr_1C43A0(void*, char*);
extern float SoftFloat_U64ToFloat(int);
extern void GuiTitleScreen_CheckMemCard(Obj287E00*, int);
extern void FrontEnd_StopSplashThread(Ui287E00*);
extern void FrontEnd_StartSplashThread(Ui287E00*);
extern void FrontEnd_ClosePopup(Ui287E00*, int);
extern int FrontEnd_OpenPopup(Ui287E00*, int, char*, int, int, int);
extern int Time_GetMilliseconds(void);
extern int Gui_GetScreenList(void);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, Obj287E00*, int);
extern int GuiManager_FindOrLoad(int, char*, char*);
extern int GuiWidget_OnEvent(Obj287E00*, Msg287E00*, unsigned short, int, int);
extern char* D_0048B3E8;
extern char* D_0048B3F0;
extern char* D_0048B3F8;
extern char D_004A9578[];
extern char D_004A9580[];
extern char D_004A9590[];
extern char D_004A95A0[];
extern char D_004A95B0[];
extern char D_004A95C0[];
extern char D_004A95D0[];
extern char D_004A95E0[];
extern char D_004FFBB8;
extern Ui287E00* D_004FFC04;

int GuiTitleScreen_HandleEvent(Obj287E00* self, Msg287E00* msg, unsigned short id, int a3, int a4)
{
    self->t = SoftFloat_U64ToFloat(Time_GetMilliseconds()) / 1000.0f;
    if (id == 0x1A) {
        if (a3 == 1) {
            D_004FFBB8 = 0;
            return 1;
        }
    } else if (id == 0x1B) {
        if (a3 == 1) {
            FrontEnd_ClosePopup(D_004FFC04, self->h);
            GuiTitleScreen_CheckMemCard(self, 1);
            return 1;
        }
    }
    if (id == 2) {
        int r = 0;
        if (String_AssignCStr_1C43A0(msg->str, D_0048B3E8) == 0) {
            unsigned char open = !D_004FFC04->f260;
            int tok = -2;
            if (open) {
                Ui287E00* ui;
                FrontEnd_StartSplashThread(D_004FFC04);
                ui = D_004FFC04;
                tok = FrontEnd_OpenPopup(ui, 0, D_004A9578, Loc_LookupText(D_004A9580), 0, 0);
            }
            r = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9590, D_004A95A0);
            if (open) {
                FrontEnd_ClosePopup(D_004FFC04, tok);
                FrontEnd_StopSplashThread(D_004FFC04);
            }
        } else if (String_AssignCStr_1C43A0(msg->str, D_0048B3F0) == 0) {
            r = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A95B0, D_004A95C0);
        } else if (String_AssignCStr_1C43A0(msg->str, D_0048B3F8) == 0) {
            r = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A95D0, D_004A95E0);
        }
        if (r)
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, r);
        return 1;
    }
    return GuiWidget_OnEvent(self, msg, id, a3, a4);
}
#pragma pop /* merge_units */
/* merge_units: end func_00287E00 */
