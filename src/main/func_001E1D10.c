/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Iterator dereference (returns *it). */
extern char* func_00183B10(TableOwner* owner, char** it);

float func_001E1D10(Unk001E1D10* self) {
    return self->unk3C;
}

void func_001E1D20(IntPair* self, int a, int b) {
    self->a = a;
    self->b = b;
}

/* Bit 7 of byte +0x0C. */
int func_001E1D30(unsigned char* flags) {
    return (flags[12] & 128) != 0;
}

/* Bit 7 of byte +0x0B. */
int func_001E1D40(unsigned char* flags) {
    return (flags[11] & 128) != 0;
}

int func_001E1D50(void) {
    return 0;
}

int func_001E1D60(Unk001E1D60** self) {
    return (*self)->unk50;
}

void* func_001E1D70(char* self) {
    return self + 12;
}

/* Address of 16-byte entry index of the owner's table. */
char* func_001E1D80(TableOwnerRef* self, int index) {
    char* it[1];
    TableOwner* owner;

    owner = *self->owner;
    it[0] = owner->table;
    return func_00183B10(owner, it) + (index << 4);
}
