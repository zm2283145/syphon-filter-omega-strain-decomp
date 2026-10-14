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
extern Game0045ECA0* D_004FFC2C;
extern int Loc_LookupText(int id);
extern void func_0045D070(void* hud, int text, int b, int c);
/* Show a localized message on the HUD if one exists. */
void func_0045ECA0(int id, int b)
{
    void* hud;
    if (D_004FFC2C && (hud = D_004FFC2C->hud) != 0) {
        func_0045D070(hud, Loc_LookupText(id), b, 1);
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
extern InteractOwner* D_004FFC2C;
#endif /* merge_units */
#define D_004FFC2C (*(InteractOwner **)&D_004FFC2C) /* merge_units */

#if 0 /* merge_units */
extern void func_0045D070(void* display, int a, int b, int show);
#endif /* merge_units */
#define func_0045D070(a0, a1, a2, a3) (func_0045D070((a0), (a1), (a2), (a3))) /* merge_units */


/* Shows the interact prompt on the current display, if any. */
void Global_DisplayInteract(int a, int b) {
    if (D_004FFC2C && D_004FFC2C->display) {
        func_0045D070(D_004FFC2C->display, a, b, 1);
    }
}
#undef D_004FFC2C /* merge_units */
#undef func_0045D070 /* merge_units */
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
