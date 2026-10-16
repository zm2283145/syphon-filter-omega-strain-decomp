/*
 * main/hud_loading: 3 files, 00272170-00272200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00272170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

/* Clears all 14 slots (handle at 0x00 is left untouched). */
void LoadingScreen_Reset(SlotTable14* self) {
    self->slots[0] = 0;
    self->slots[1] = 0;
    self->slots[2] = 0;
    self->slots[3] = 0;
    self->slots[4] = 0;
    self->slots[5] = 0;
    self->slots[6] = 0;
    self->slots[7] = 0;
    self->slots[8] = 0;
    self->slots[9] = 0;
    self->slots[10] = 0;
    self->slots[11] = 0;
    self->slots[12] = 0;
    self->slots[13] = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00272170 */

/* merge_units: begin func_002721B0 */
#pragma push /* merge_units */
typedef struct { int* model; } Obj002721B0;
extern int* LoadingScreen_BuildIeScreen(int name);
extern void IeNode_SetShown(int a, int b, int c);
#if 0 /* merge_units */
extern void LoadingScreen_Reset(Obj002721B0* obj);
#endif /* merge_units */
#define LoadingScreen_Reset(a0) (LoadingScreen_Reset((SlotTable14 *)(a0))) /* merge_units */

/* Construct: look up the model by name, activate it and finish setup. */
Obj002721B0* LoadingScreen_ctor(Obj002721B0* obj, int unused, int name)
{
    obj->model = LoadingScreen_BuildIeScreen(name);
    IeNode_SetShown(*obj->model, 0, 1);
    LoadingScreen_Reset(obj);
    return obj;
}
#undef LoadingScreen_Reset /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002721B0 */

/* merge_units: begin func_00272200 */
#pragma push /* merge_units */
typedef struct { char p[0x20]; int f20; } H272200;
typedef struct { char p[0x19]; unsigned char b19; char p1A[0x5A]; H272200* h; } O272200;
typedef struct { char p[0x280]; int f280; } G272200;
extern O272200* Hud_FindOrCreateElement(int a, int b);
extern void IeElement_SetText(O272200* o, void* x);
extern void TextObj_SetColour(H272200* h, void* c);
extern G272200* App_GetInstance(void);
extern char D_004A8DA0[];
O272200* LoadingScreen_SetText(int a, int b, void* x)
{
    O272200* o = Hud_FindOrCreateElement(a, b);
    if (o && x && o->h) {
        IeElement_SetText(o, x);
        o->b19 = 0;
        TextObj_SetColour(o->h, D_004A8DA0);
        o->h->f20 = App_GetInstance()->f280;
    }
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_00272200 */
