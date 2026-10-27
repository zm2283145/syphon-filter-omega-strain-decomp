/*
 * SFOGame/Source/hud_weapon: 1 file, 00259420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin backpack_259420 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Obj68 {
    void* vtable;
    char pad[0x2B];
    unsigned char unk2F;
    char pad2[8];
    int unk38;
    char pad3[0x24];
    int unk60;
    unsigned char unk64;
} Obj68;

extern int D_004DC4A0;
extern void nGobjManager_GetNextId(int*, int);
extern void cGOBJ_ctor(Obj68*, int*, int, int*);

/* Constructor: base init with resource 0xF5, then sets the vtable and defaults. */
Obj68* cHudWeapon_ctor(Obj68* o) {
    int extra = 0;
    int res;
    nGobjManager_GetNextId(&res, 0xF5);
    cGOBJ_ctor(o, &res, 3, &extra);
    o->vtable = &D_004DC4A0;
    o->unk60 = 0;
    o->unk64 = 7;
    o->unk2F = 1;
    o->unk38 = 2;
    return o;
}
static inline void merge_flush_backpack_259420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end backpack_259420 */
