/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Returns the address 8 bytes into the object pointed to by the second word. */
char* func_003D3600(char** self) {
    return self[1] + 8;
}

void func_003D3610(Unk3D3670* self, float value) {
    self->unkF94 = value;
}

/* Fills an entry: position, a tag byte, and marks it in use. */
void func_003D3620(L4Entry110* entry, Vec4* pos, int tag) {
    entry->unk00.x = pos->x;
    entry->unk00.y = pos->y;
    entry->unk00.z = pos->z;
    entry->unk00.w = pos->w;
    entry->unk105 = tag;
    entry->unk106 = 1;
}

Vec4* func_003D3650(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Returns the current entry. */
L4Entry110* func_003D3670(Unk3D3670* self) {
    return &self->entries[self->cur];
}

/* Advances to the next entry and marks it in use. */
void func_003D3690(int a0) {
    int tmp0;
    int tmp1;

    /* entries[++cur].unk106 = 1; the struct form swaps an addu operand order */
    tmp0 = *(int*)((char*)a0 + 2672);
    *(int*)((char*)a0 + 2672) = (tmp0 + 1);
    tmp1 = *(int*)((char*)a0 + 2672);
    *(char*)((char*)(a0 + (tmp1 * 272)) + 758) = 1;
}

/* Assumed to act on the same object as its neighbours. */
void func_003D36C0(Unk3D3670* self, int unused, int value) {
    self->unkF4 = value & 255;
}

unsigned char func_003D36D0(Unk3D36D0* self) {
    return self->unk10;
}

int func_003D36E0(Unk3D36D0* self) {
    return self->unk0C;
}

int func_003D36F0(Unk3D36D0* self) {
    return self->unk08;
}
