/*
 * main/GuiNetJoinMission: 3 files, 002A9660-002A96A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A9660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AB8F0[] = "GuiOnlineOptions";   /* "GuiOnlineOptions" */

/* Class name getter: "GuiOnlineOptions". */
char* GuiOnlineOptions_GetClassName(void) {
    return D_004AB8F0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A9660 */

/* merge_units: begin func_002A9670 */
#pragma push /* merge_units */
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int GuiOnlineOptions_IsType(void* a0, const char* s) { return strcmp("GuiOnlineOptions", s) == 0; }
#pragma pop /* merge_units */
/* merge_units: end func_002A9670 */

/* merge_units: begin func_002A96A0 */
#pragma push /* merge_units */
typedef struct { char d[0x10]; } Str;
typedef struct { char pad[0x268]; int f268; } Ui;
typedef struct { char pad[0x98]; int f98; } S;
extern Ui* D_004FFC04;
extern char D_004AB808[];
extern int GuiScreen_GetLobbyString(S* self, int a, int b, int c, int d, int e);
extern void FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S* d, int e);
extern void String_CtorCStr_13B480(Str* s, int c);
extern int String_CStr(Str* s);
extern void String_Dtor(Str* s, int flags);
extern int GuiScreen_Navigate(S* self, int v);
void func_002A96A0(S* self, int flag)
{
    if (flag && self->f98 == -1) {
        Str a;
        Str b;
        int t;
        String_CtorCStr_13B480(&a, GuiScreen_GetLobbyString(self, 0x73, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, GuiScreen_GetLobbyString(self, 0x74, 0, 0, 0, 0));
        t = String_CStr(&b);
        FrontEnd_OpenPopup(D_004FFC04, 2, (char*)String_CStr(&a), t, 0, 0);
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    } else if (!GuiScreen_Navigate(self, D_004FFC04->f268)) {
        Ui* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 2, D_004AB808, GuiScreen_GetLobbyString(self, 0x71, 0, 0, 0, 0), 0, 0);
        D_004FFC04->f268 = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002A96A0 */
