/*
 * SFOGame/Source/gameOptions: 1 file, 0045A7A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSubTitleDisplay_45A7A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    int unk0;
    unsigned char b4, b5, b6, b7;
    float unk8;
    float unkC;
    float unk10;
    int unk14;
    unsigned char b18, b19;
    char pad1A[2];
    int unk1C;
    int unk20;
} Settings0045A7A0;
/* Initialise settings with defaults. */
Settings0045A7A0* cGameOptions_ctor(Settings0045A7A0* s)
{
    s->unk0 = 1;
    s->b4 = 0;
    s->b5 = 1;
    s->b6 = 1;
    s->b7 = 0;
    s->unk8 = 0.8f;
    s->unkC = 1.0f;
    s->unk10 = 0.8f;
    s->unk14 = 0;
    s->b18 = 1;
    s->b19 = 1;
    s->unk1C = 0;
    s->unk20 = 0;
    return s;
}
static inline void merge_flush_GuiSubTitleDisplay_45A7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSubTitleDisplay_45A7A0 */
