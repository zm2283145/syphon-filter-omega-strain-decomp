/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003809B0(TexHdr* t) {
    return t->h36 + t->h34;
}

int func_003809C0(TexHdr* t) {
    return t->h34 + (t->pal ? 0x400 : 0);
}
