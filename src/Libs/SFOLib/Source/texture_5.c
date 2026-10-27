/*
 * Libs/SFOLib/Source/texture: 2 files, 003BB620-003BB6B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BB620 */
#pragma push /* merge_units */
/* Set the 1-bit field at bit 5 and the 3-bit field at bits 6..8 of the 64-bit
 * register word at +0x58 from flag bits 2/3 of g_DrawMode. */
typedef struct {
    char pad[0x58];
    unsigned long reg;              /* 0x58 */
} Obj003BB620;

extern int g_DrawMode;

unsigned long* cTexture_GetTEX1_1(Obj003BB620* self)
{
    unsigned int enable;
    unsigned int mode;
    unsigned char bit4;
    unsigned char bit8;
    int flags;
    enable = 0;
    mode = 0;
    flags = g_DrawMode;
    bit4 = (flags & 4) != 0;
    bit8 = (flags & 8) != 0;
    if (flags & 0xC) {
        enable = 1;
        if (bit4) mode = 4;
        else if (bit8) mode = 5;
    }
    self->reg &= ~(unsigned long)0x1E0;
    self->reg |= ((unsigned long)enable << 5) | ((unsigned long)mode << 6);
    return &self->reg;
}
static inline void merge_flush_func_003BB620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB620 */

/* merge_units: begin func_003BB6B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Attach an info header to a texture entry and mark it. */
void cTexture_SetReallocData(TexEntry* self, TexInfo* info) {
    self->info = info;
    self->flags = self->flags | 0x1000;
    self->unk60 = 0;
    self->unk61 = 0;
}
static inline void merge_flush_func_003BB6B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB6B0 */
