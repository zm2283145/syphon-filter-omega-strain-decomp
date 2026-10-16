/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern int D_004F7DB8;
extern void HudRadar_SetPlayerId(int* p);

Word* func_002426A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void CalloutList_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002426C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Stores *p into the global at 0x004F7DB8, then forwards p. */
void Hud_SetPlayerId(int* p) {
    D_004F7DB8 = *p;
    HudRadar_SetPlayerId(p);
}
