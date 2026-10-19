/*
 * main/texman: 2 files, 003820C0-003820E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003820C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture manager state reset.
 */

#include "types.h"
#include "texman_types.h"

void func_003820C0(TexManager* m) {
    m->unk480 = 0;
    m->unk484 = 0;
    m->unk488 = 0;
    m->unk489 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003820C0 */

/* merge_units: begin func_003820E0 */
#pragma push /* merge_units */
typedef struct TexE {
    char pad0[0x58];
    unsigned long x58;
} TexE;
typedef struct TdxMgr {
    char pad0[8];
    TexE** ents;
} TdxMgr;
extern int g_DrawMode;
extern int D_00539250;

void Renderer_BindTexture(TdxMgr* m, int idx)
{
    TexE* e = m->ents[idx];
    if (g_DrawMode & 4) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x120;
    } else if (g_DrawMode & 8) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x160;
    } else {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x80;
    }
    D_00539250 = idx;
}
#pragma pop /* merge_units */
/* merge_units: end func_003820E0 */
