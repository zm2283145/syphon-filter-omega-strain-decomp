/*
 * main/guiTextListWidget: 2 files, 00423610-00423660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00423610 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; char pad2[0x3E]; int id; } Ent;
unsigned int D_004BF6D0[1] = { 0x0 };
extern void func_00424F60(void* t, char* name, int z);
/* Notifies the target if the entity is flagged and has the given id. */
void func_00423610(Ent* e, int id, void* target) { if ((e->flags & 0x100) && id == e->id) func_00424F60(target, ((char*)D_004BF6D0), 0); }
#pragma pop /* merge_units */
/* merge_units: end func_00423610 */

/* merge_units: begin func_00423660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_00423660(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00423660 */
