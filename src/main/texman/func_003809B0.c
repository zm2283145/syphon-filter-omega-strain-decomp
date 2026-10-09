/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int TexHeader_PaletteOffset(TexHdr* t) {
    return t->h36 + t->h34;
}

int TexHeader_PixelOffset(TexHdr* t) {
    return t->h34 + (t->pal ? 0x400 : 0);
}
