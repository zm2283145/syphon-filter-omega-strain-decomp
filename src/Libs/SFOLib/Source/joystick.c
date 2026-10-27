/*
 * Libs/SFOLib/Source/joystick: 1 file, 00369980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00369980 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y; } Vec2;
typedef struct { char pad[0x12C]; char left[8]; char right[8]; } Pad;
extern void cJoyPad_ApplyDeadZone(Vec2* out, Pad* pad, void* stick, int deadzone);

/* Reads both analog sticks of the pad into *left and *right. */
void cJoyPad_GetStickPosition(Pad* self, Vec2* left, Vec2* right, int deadzone)
{
    Vec2 r;
    Vec2 l;
    cJoyPad_ApplyDeadZone(&l, self, self->left, deadzone);
    left->x = l.x;
    left->y = l.y;
    cJoyPad_ApplyDeadZone(&r, self, self->right, deadzone);
    right->x = r.x;
    right->y = r.y;
}
static inline void merge_flush_func_00369980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00369980 */
