/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0041E040(Unk423540*, int, int, int);

void func_00423540(Unk423540* self, int* out) {
    *out = self->unk84;
}

void func_00423550(Unk423540* self, int value) {
    self->unk84 = value;
}

void func_00423560(Unk423540* self, int* outA, int* outB) {
    *outA = self->unk78;
    *outB = self->unk7C;
}

void func_00423580(Unk423540* self, int a, int b) {
    self->unk78 = a;
    self->unk7C = b;
}

void func_00423590(Unk423540* self, int* outA, int* outB) {
    *outA = self->unk70;
    *outB = self->unk74;
}

void func_004235B0(Unk423540* self, int a, int b) {
    self->unk70 = a;
    self->unk74 = b;
}

int func_004235C0(Unk423540* self, int a, int b) {
    return func_0041E040(self, 21, a, b);
}

int func_004235E0(Unk423540* self, int a, int b) {
    return func_0041E040(self, 20, a, b);
}

void func_00423600(void) {
}
