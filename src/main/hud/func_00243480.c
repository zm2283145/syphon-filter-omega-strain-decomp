/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern char D_004E0240[];
extern void* func_003E99B0(void* self, int a1, int a2);

void func_00243480(HudElement* self, char value) {
    self->unk10 = value;
}

void func_00243490(HudElement* self, char value) {
    self->unk5B = value;
}

int func_002434A0(HudElement* self) {
    return self->unk74;
}

/* Constructor: base constructor func_003E99B0, then vtable 0x004E0240. */
void* func_002434B0(void* self, int a1, int a2) {
    func_003E99B0(self, a1, a2);
    *(void**)self = D_004E0240;
    return self;
}
