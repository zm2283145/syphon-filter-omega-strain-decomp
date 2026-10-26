/*
 * main/hud_netlobby: 2 files, 0027AA80-0027AAA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027AA80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* std_list_GameInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Address 8 bytes past the node stored at +8. */
char* std_list_GameInfoPtr_front(PtrVec* self) {
    return (char*)self->data + 8;
}
#pragma pop /* merge_units */
/* merge_units: end func_0027AA80 */

/* merge_units: begin func_0027AAA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; int count; char pad2[8]; int sel; int mode; } Menu27AA;
extern unsigned char D_00504040;
extern void cHudNetLobby_SetActive(Menu27AA* s);
void cHudNetLobby_NextButton(Menu27AA* s, int dir) {
    int n = 0;
    if (s->mode == 0) {
        if (D_00504040 || !s->count) return;
        n = 2;
    } else if (s->mode == 1) {
        n = s->count;
    }
    if (n) {
        if (dir) {
            s->sel++;
            if (s->sel >= n) s->sel = 0;
        } else {
            s->sel--;
            if (s->sel < 0) s->sel = n - 1;
        }
    }
    cHudNetLobby_SetActive(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_0027AAA0 */
