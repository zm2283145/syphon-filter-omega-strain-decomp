/*
 * main/GuiGameScreen: 3 files, 00465870-00465A50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00465870 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a[4]; } S465;
typedef struct { char pad[0x14]; unsigned short flags; } W465;
typedef struct { char pad[0x6A8]; unsigned char b6a8; } G465;
typedef struct { char pad[0x1EC]; int f1ec; } X465;
extern int g_Pad0State;
extern X465 D_0055A300;
extern int D_00587B20;
extern int D_00497BE8;
extern int D_004FFC04;
extern G465* g_Hud;
extern char g_Game[];
extern int cGameFrontEnd_FindMessageBox(int, int);
extern char* nGlobalization_GetString_charP(char*);
extern void std_basic_string_char_char_traits_char_ctor_charP(S465*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(S465*);
extern int cGameFrontEnd_PushMessageBox(int, int, char*, char*, int, int);
extern void cGameSystem_PauseGame(char*, int);
extern void String_Dtor(S465*, int);
extern void cGameFrontEnd_PopMessageBox(int, int);
extern void GuiCanvas_NextFrame(W465*, float);
static inline int st465(X465* x) { return x->f1ec; }
void GuiCommonCanvas_NextFrame(W465* w, float t) {
    if (w->flags & 4) {
        X465* x = &D_0055A300;
        int ok = g_Pad0State == 0 || x->f1ec == 3;
        if (ok) D_00587B20++;
        else D_00587B20 = 0;
        if (D_00587B20 >= 3) {
            if (D_00497BE8 == -1 || !cGameFrontEnd_FindMessageBox(D_004FFC04, D_00497BE8)) {
                S465 a;
                S465 b;
                std_basic_string_char_char_traits_char_ctor_charP(&a, nGlobalization_GetString_charP("NoCtrlTitle"));
                std_basic_string_char_char_traits_char_ctor_charP(&b, nGlobalization_GetString_charP("NoCtrlMessage"));
                {
                    char* tb = std_basic_string_char_char_traits_char_c_str(&b);
                    D_00497BE8 = cGameFrontEnd_PushMessageBox(D_004FFC04, 1, std_basic_string_char_char_traits_char_c_str(&a), tb, 0, 0);
                }
                cGameSystem_PauseGame(g_Game, 1);
                String_Dtor(&b, 0);
                String_Dtor(&a, 0);
            }
        } else if (D_00497BE8 != -1) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, D_00497BE8);
            D_00497BE8 = -1;
            if (!g_Hud || !g_Hud->b6a8) cGameSystem_PauseGame(g_Game, 0);
        }
    }
    GuiCanvas_NextFrame(w, t);
}
#pragma pop /* merge_units */
/* merge_units: end func_00465870 */

/* merge_units: begin func_00465A40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */


extern int GuiCanvas_ProcessInputEvent(int, int);

int func_00465A40(int a0, int a1) {
    return GuiCanvas_ProcessInputEvent(a0, a1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00465A40 */

/* merge_units: begin func_00465A50 */
#pragma push /* merge_units */
extern char D_00586610[], D_005867B0[], D_005862D0[], D_00586470[], D_00586950[];
extern int PlayGuiSound(void*, void*);
extern int StopGuiSound(void*, void*);
extern int GuiCanvas_onMessage(void*, void*, unsigned short, int, int);
int GuiCommonCanvas_onMessage(void* self, void* b, unsigned short type, int idx, int e)
{
    if (type == 0x10 || type == 0x11) {
        void* t = 0;
        switch (idx) {
        case 0: t = D_00586610; break;
        case 1: t = D_005867B0; break;
        case 2: t = D_005862D0; break;
        case 3: t = D_00586470; break;
        case 4: t = D_00586950; break;
        }
        if (t) {
            int r;
            if (type == 0x10) r = PlayGuiSound(b, t);
            else r = StopGuiSound(b, t);
            return r;
        }
    }
    return GuiCanvas_onMessage(self, b, type, idx, e);
}
#pragma pop /* merge_units */
/* merge_units: end func_00465A50 */
