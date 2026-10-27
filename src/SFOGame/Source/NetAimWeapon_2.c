/*
 * SFOGame/Source/NetAimWeapon: 1 file, 002C4F20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiEquipmentModify_2C4F20 */
#pragma push /* merge_units */
#include "types.h"
static unsigned int dat_0048C0C0[2] = { 0x1, 0x0 };
typedef struct { unsigned short max; unsigned short cur; } Ctr4F20;
unsigned char cAimWeapon_GetFireWeapon(Ctr4F20* c)
{
    unsigned char r;
    if ((*(unsigned char*)dat_0048C0C0)) {
        c->cur = 0;
        (*(unsigned char*)dat_0048C0C0) = 0;
    }
    if (c->cur < c->max) { c->cur++; r = 1; } else { r = 0; } return r;
}
static inline void merge_flush_GuiEquipmentModify_2C4F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiEquipmentModify_2C4F20 */
