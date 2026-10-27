/*
 * Matched functions (byte-identical with the retail executable).
 * Texture registry accessors (code lies between the vu1model.cc and xlib.cc
 * address ranges). Original translation unit not identified yet.
 */

#include "loose03_types.h"

extern int cTexture_GetTEX1_1(TexEntry*);

/* Address of the entry's embedded sub-object. */
void* cTexture_GetTEX0_1(TexEntry* self) {
    return self->body;
}

int cTexture_GetPSM(TexEntry* self) {
    return self->info->unk0A;
}

int cTexture_GetHeight(TexEntry* self) {
    return self->info->unk06;
}

int cTexture_GetWidth(TexEntry* self) {
    return self->info->unk04;
}

TexEntry* cTexMan_GetTexture(TexRegistry* reg, int index) {
    return reg->entries[index];
}

Words4* tIRGBA_ctor(Words4* self, int a, int b, int c, int d) {
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    return self;
}

void cDmaMan_EndChain_int(void) {
}

int cTexMan_GetTEX1_1(TexRegistry* reg, int index) {
    return cTexture_GetTEX1_1(reg->entries[index]);
}

void* cTexMan_GetTEX0_1(TexRegistry* reg, int index) {
    return reg->entries[index]->body;
}

int XLib_GetTexMan(Manager37F9D0* self) {
    return self->unk1058;
}
