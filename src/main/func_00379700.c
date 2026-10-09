/*
 * Matched functions (byte-identical with the retail executable).
 * Texture registry accessors (code lies between the vu1model.cc and xlib.cc
 * address ranges). Original translation unit not identified yet.
 */

#include "loose03_types.h"

extern int func_003BB620(TexEntry*);

/* Address of the entry's embedded sub-object. */
void* func_00379700(TexEntry* self) {
    return self->body;
}

int func_00379710(TexEntry* self) {
    return self->info->unk0A;
}

int func_00379720(TexEntry* self) {
    return self->info->unk06;
}

int func_00379730(TexEntry* self) {
    return self->info->unk04;
}

TexEntry* func_00379740(TexRegistry* reg, int index) {
    return reg->entries[index];
}

Words4* func_00379760(Words4* self, int a, int b, int c, int d) {
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    return self;
}

void func_00379780(void) {
}

int func_00379790(TexRegistry* reg, int index) {
    return func_003BB620(reg->entries[index]);
}

void* func_003797B0(TexRegistry* reg, int index) {
    return reg->entries[index]->body;
}

int func_003797D0(Manager37F9D0* self) {
    return self->unk1058;
}
