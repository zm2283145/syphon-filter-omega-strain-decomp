/*
 * main/GuiEquipmentSetup: range (2 files, 002A3B80-002A3BA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiEquipmentSetup_types.h"

/* merge_units: begin func_002A3B80 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char unk32; } Sub002A3B80;
typedef struct { char pad[0x3584]; Sub002A3B80* sub; } Obj002A3B80;
/* Return byte 0x32 of the sub-object, or 0 if none. */
int func_002A3B80(Obj002A3B80* obj)
{
    Sub002A3B80* sub = obj->sub;
    if (sub) {
        return sub->unk32;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A3B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A3B80 */

/* merge_units: begin func_002A3BA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */


extern int GuiWidget_BaseWake(GuiEquipmentSetup* self);

int func_002A3BA0(char* self) {
    return *(int*)(self + 0);
}

/* Calls the base handler, then resets +0xDC and the view angle to pi. */
int GuiEquipmentSetup_Wake(GuiEquipmentSetup* self) {
    int result = GuiWidget_BaseWake(self);

    self->unkDC = 0;
    self->angle = 3.14159265f;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A3BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A3BA0 */
