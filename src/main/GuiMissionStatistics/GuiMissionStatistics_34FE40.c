/*
 * main/GuiMissionStatistics: 3 files, 0034FE40-0034FEC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034FE40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_0034FE40(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FE40 */

/* merge_units: begin func_0034FE60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

DEFINE_DIRECT_BASE_DTOR(func_0034FE60, func_003513B0)
#pragma pop /* merge_units */
/* merge_units: end func_0034FE60 */

/* merge_units: begin func_0034FEC0 */
#pragma push /* merge_units */
typedef struct { char pad0[0xC]; unsigned char en; char p1[3]; unsigned char b10; char p2[0xB];
    unsigned char b1C; char p3[0xB]; unsigned char b28; char p4[0xB]; unsigned char b34; char p5[0xB];
    unsigned char b40; char p6[0x1B]; } E34FEC0;
typedef struct { int a; unsigned int count; E34FEC0* items; } T34FEC0;
typedef struct { char pad[0xC0]; T34FEC0* tab; } S34FEC0;
extern char D_00587BA0[];
extern char D_00587BB0[];
extern char D_00587BC0[];
extern void TextArrayCell_SetColour(S34FEC0*, char*);
extern void GuiTextArrayWidget_DrawCell(S34FEC0*, unsigned int, unsigned int, int);
void GuiMissionStatList_Draw(S34FEC0* self, unsigned int kind, unsigned int idx, int arg) {
    T34FEC0* t = self->tab;
    E34FEC0* e;
    char* s;
    if (!t || kind >= 11 || idx >= t->count) return;
    e = &t->items[idx];
    s = D_00587BB0;
    if (!e->en && kind != 0) return;
    switch (kind) {
    case 0:
        if (e->en) s = D_00587BA0;
        else s = D_00587BC0;
        break;
    case 1: case 2:
        if (e->b10) s = D_00587BA0;
        break;
    case 4: case 5:
        if (e->b1C) s = D_00587BA0;
        break;
    case 7:
        if (e->b28) s = D_00587BA0;
        break;
    case 9:
        if (e->b34) s = D_00587BA0;
        break;
    case 10:
        if (e->b40) s = D_00587BA0;
        break;
    }
    TextArrayCell_SetColour(self, s);
    GuiTextArrayWidget_DrawCell(self, kind, idx, arg);
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FEC0 */
