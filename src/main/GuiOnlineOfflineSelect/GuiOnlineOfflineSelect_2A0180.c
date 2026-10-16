/*
 * main/GuiOnlineOfflineSelect: 3 files, 002A0180-002A01C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AAF50[] = "GuiOnlineOfflineSelect";   /* "GuiOnlineOfflineSelect" */

/* Class name getter: "GuiOnlineOfflineSelect". */
char* func_002A0180(void) {
    return D_004AAF50;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0180 */

/* merge_units: begin func_002A0190 */
#pragma push /* merge_units */
extern int strcmp(const char* a, const char* b); /* strcmp */
char D_004AAF70[] = "GuiOnlineOfflineSelect"; /* "GuiOnlineOfflineSelect" */

/* GuiOnlineOfflineSelect type check: true when name equals the class name "GuiOnlineOfflineSelect". */
int GuiOnlineOfflineSelect_IsType(void* self, const char* name) {
    return strcmp(D_004AAF70, name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0190 */

/* merge_units: begin func_002A01C0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char* D_0048BA28;
extern char* D_0048BA30;
extern char* D_0048BA38;
extern char D_004AAE80[];
extern char D_004AAE98[];
extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern char D_00532FE8;
struct Ctl_2A01C0 { char pad[0x32]; unsigned char b32; };
extern Ctl_2A01C0* D_004FFC04;
struct Pg_2A01C0 { char pad[0x10]; int f10; };
struct W_2A01C0 { int unk0; char name[4]; };
int String_AssignCStr_1C43A0(void* a, char* b);
void FrontEnd_SetOnlineMode(Ctl_2A01C0* c, int on);
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
Pg_2A01C0* GuiManager_FindOrLoad(void* a, char* b, char* c);
void GuiStack_SwapScreens(void* ui, void* self, void* pg);
int GuiWidget_OnEvent(void* self, W_2A01C0* w, int msg, int sub, char* text);
}

extern "C" int GuiOnlineOfflineSelect_HandleEvent(void* self, W_2A01C0* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 2) {
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA28)) {
            void* pg;
            D_00532FE8 = 0;
            FrontEnd_SetOnlineMode(D_004FFC04, 1);
            D_004FFC04->b32 = 0;
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAE80, D_004AAE98);
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA30)) {
            Pg_2A01C0* pg;
            FrontEnd_SetOnlineMode(D_004FFC04, 0);
            D_004FFC04->b32 = 0;
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
            pg->f10 = 1;
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
        if (!String_AssignCStr_1C43A0(w->name, D_0048BA38)) {
            Pg_2A01C0* pg;
            pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
            pg->f10 = 1;
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
            return 1;
        }
    }
    return GuiWidget_OnEvent(self, w, msg, sub, text);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A01C0 */
