/*
 * SFOGame/Source/weapon: 1 file, 00142E40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00142E40 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[4]; unsigned char visible; char pad2[11]; } Hardpoint;
typedef struct { Hardpoint points[8]; char pad[8]; char* model; } HardpointSet;

extern unsigned char WeaponHolsterAttachPoints[]; /* hardpoint index -> model node index */

/* Sets a hardpoint's visibility and the matching hidden flag in the model (+0x2498 table). */
void cWeapon_SetHardpointVisibility(HardpointSet* self, unsigned char index, int visible)
{
    ((Hardpoint*)self)[index].visible = visible;
    self->model[WeaponHolsterAttachPoints[index] + 0x2498] = !(unsigned char)visible;
}
static inline void merge_flush_func_00142E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142E40 */
