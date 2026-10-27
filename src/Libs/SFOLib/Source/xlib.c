/*
 * Libs/SFOLib/Source/xlib: 3 files, 003780D0-00378170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003780D0 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* D_0053924C;
extern void cAnimTexMan_SetTextureFrame(void* manager, int object, int texture);

/* Script native: sets texture args[1] on object args[0]; returns 0. */
int Script_SetTexture(ScriptArg* args)
{
    int object[1];
    int texture[1];
    texture[0] = args[1].i;
    object[0] = args[0].i;
    cAnimTexMan_SetTextureFrame(D_0053924C, *(int*)object, *(int*)texture);
    return 0;
}
static inline void merge_flush_func_003780D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003780D0 */

/* merge_units: begin func_00378110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script natives forwarding a texture id to the global texture manager.
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern int D_0053924C;          /* texture manager instance */
#endif /* merge_units */
#define D_0053924C (*(int*)&D_0053924C) /* merge_units */

extern void cAnimTexMan_DecTextureFrame(int mgr, int id);
extern void cAnimTexMan_IncTextureFrame(int mgr, int id);

int Script_DecTexture(int* args) {
    int part[1];

    part[0] = args[0];
    cAnimTexMan_DecTextureFrame(D_0053924C, *(int*)part);
    return 0;
}

int Script_IncTexture(int* args) {
    int part[1];

    part[0] = args[0];
    cAnimTexMan_IncTextureFrame(D_0053924C, *(int*)part);
    return 0;
}
#undef D_0053924C /* merge_units */
static inline void merge_flush_func_00378110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00378110 */

/* merge_units: begin func_00378170 */
#pragma push /* merge_units */
extern void XLib_DrawLensFlares(void* a, void* b, void* c, int* d, int* zero, float* one, int flag, int e, int f);
/* Calls XLib_DrawLensFlares with default zero / 1.0 parameters and the flag set. */
void XLib_DrawLensFlare(void* a, void* b, void* c, int d, int e, int f)
{
    int dv = d;
    float one = 1.0f;
    int zero = 0;
    XLib_DrawLensFlares(a, b, c, &dv, &zero, &one, 1, e, f);
}
static inline void merge_flush_func_00378170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00378170 */
