/*
 * Matched functions (byte-identical with the retail executable).
 * Texture header data offset helpers.
 */

#include "types.h"

int TexHeader_PaletteOffset(TexHdr* t) {
    return t->h36 + t->h34;
}

int TexHeader_PixelOffset(TexHdr* t) {
    return t->h34 + (t->pal ? 0x400 : 0);
}
