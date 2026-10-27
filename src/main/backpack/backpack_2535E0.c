/*
 * main/backpack: range (3 files, 002535E0-00253670)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002535E0 */
#pragma push /* merge_units */
extern void* cInterfaceModel_GetChild(void* obj);
extern int cInterfaceModel_CreateInstance(void* p);

/* Resolves obj via cInterfaceModel_GetChild and forwards to cInterfaceModel_CreateInstance (0 if none). */
int CreateElement(void* obj) {
    void* p = cInterfaceModel_GetChild(obj);
    if (p) {
        return cInterfaceModel_CreateInstance(p);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002535E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002535E0 */

/* merge_units: begin func_00253620 */
#pragma push /* merge_units */
void Global_SetPickupTextColor(int r, int g, int b, float a); /* gsynth: defined below */
typedef struct ColorArgs {
    int r, g, b;
    int alpha; /* float passed as a raw word */
} ColorArgs;

#if 0 /* merge_units */
extern void Global_SetPickupTextColor(int r, int g, int b, float alpha);
#endif /* merge_units */
#define Global_SetPickupTextColor(a0, a1, a2, a3) (Global_SetPickupTextColor((a0), (a1), (a2), (a3))) /* merge_units */


/* Script native: SetPickupTextColor(r, g, b, alpha). */
int Script_SetPickupTextColor(ColorArgs* args) {
    float alpha;
    int b, g, r;
    volatile int wa, wb, wg, wr;
    wa = args->alpha;
    alpha = *(float*)&wa;
    wb = args->b;
    b = wb;
    wg = args->g;
    g = wg;
    wr = args->r;
    r = wr;
    Global_SetPickupTextColor(r, g, b, alpha);
    return 0;
}
#undef Global_SetPickupTextColor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00253620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00253620 */

/* merge_units: begin func_00253670 */
#pragma push /* merge_units */
extern float g_PickupTextColour;
extern float D_004F7E74;
extern float D_004F7E78;
extern float D_004F7E7C;
extern unsigned char D_004F7E80;

/* Sets the pickup text colour from 0-255 RGB and a float alpha, and marks it overridden. */
void Global_SetPickupTextColor(int r, int g, int b, float a)
{
    g_PickupTextColour = r / 255.0f;
    D_004F7E74 = g / 255.0f;
    D_004F7E78 = b / 255.0f;
    D_004F7E7C = a;
    D_004F7E80 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00253670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00253670 */
