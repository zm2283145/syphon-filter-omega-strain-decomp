/*
 * main/GuiGameScreen: range (4 files, 0045ECA0-0045ED80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiGameScreen_types.h"

/* merge_units: begin func_0045ECA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* hud; } Game0045ECA0;
extern Game0045ECA0* g_Hud;
extern int nGlobalization_GetString_charP(int id);
extern void GuiGameScreen_ShowInteract(void* hud, int text, int b, int c);
/* Show a localized message on the HUD if one exists. */
void DisplayInteractLabel(int id, int b)
{
    void* hud;
    if (g_Hud && (hud = g_Hud->hud) != 0) {
        GuiGameScreen_ShowInteract(hud, nGlobalization_GetString_charP(id), b, 1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045ECA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045ECA0 */

/* merge_units: begin func_0045ED00 */
#pragma push /* merge_units */
typedef struct InteractOwner {
    char pad000[0x6A4];
    void* display; /* 0x6A4 */
} InteractOwner;

#if 0 /* merge_units */
extern InteractOwner* g_Hud;
#endif /* merge_units */
#define g_Hud (*(InteractOwner **)&g_Hud) /* merge_units */

#if 0 /* merge_units */
extern void GuiGameScreen_ShowInteract(void* display, int a, int b, int show);
#endif /* merge_units */
#define GuiGameScreen_ShowInteract(a0, a1, a2, a3) (GuiGameScreen_ShowInteract((a0), (a1), (a2), (a3))) /* merge_units */


/* Shows the interact prompt on the current display, if any. */
void DisplayInteract_charP_eJoystickButton(int a, int b) {
    if (g_Hud && g_Hud->display) {
        GuiGameScreen_ShowInteract(g_Hud->display, a, b, 1);
    }
}
#undef g_Hud /* merge_units */
#undef GuiGameScreen_ShowInteract /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045ED00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045ED00 */

/* merge_units: begin func_0045ED40 */
#pragma push /* merge_units */
extern void Global_PlayXA(int a, int b);
/* Script: PlayXA(a, b). */
int Script_PlayXA_2(int* args)
{
    volatile int b = args[1]; /* staged through the stack */
    volatile int a = args[0];
    Global_PlayXA(a, b);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045ED40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045ED40 */

/* merge_units: begin func_0045ED80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern void Global_PlayXA(int track, int a1);
#endif /* merge_units */
#define Global_PlayXA(a0, a1) (Global_PlayXA((a0), (a1))) /* merge_units */


/* Script native: PlayXA(track). */
int Script_PlayXA(ScriptArg* args) {
    int track[1];

    track[0] = args[0].i;
    Global_PlayXA(STACK_COPY(track), 0);
    return 0;
}
#undef Global_PlayXA /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045ED80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045ED80 */
