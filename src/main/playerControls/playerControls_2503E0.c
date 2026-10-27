/*
 * main/playerControls: range (2 files, 002503E0-00250470)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002503E0 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } E7V3;
typedef struct { float x, y; } E7V2;
const float D_0048AE70[2] = { 60.0f, 0.0f };
const float D_0048AE78[2] = { 160.0f, 0.0f };
void PlayerInput_GetLookOffset(E7V3* out, E7V2* in, int invX, int invY) {
    float a, b, x, y, z;
    a = 0.017453292f * (*(float*)D_0048AE78);
    x = in->x;
    b = 0.017453292f * (*(float*)D_0048AE70);
    z = (invX ? -1.0f : 1.0f) * (a * -x);
    y = in->y;
    out->x = (invY ? -1.0f : 1.0f) * (b * -y);
    out->y = 0.0f;
    out->z = z;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002503E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002503E0 */

/* merge_units: begin func_00250470 */
#pragma push /* merge_units */
typedef struct { char pad[0x38]; int state; } Obj250;
typedef struct { char pad[0x320C]; int mode; } Ctx250;
int cPlayerControls_CanChangeWeapon(Obj250* o, Ctx250* c) {
    if (o->state != 6 && c->mode != 0x17 && c->mode != 0x14 && c->mode != 0x15) return 1;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250470 */
