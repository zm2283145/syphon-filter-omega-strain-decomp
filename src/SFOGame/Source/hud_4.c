/*
 * SFOGame/Source/hud: 4 files, 002426A0-002426E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002426A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern int D_004F7DB8;
extern void cRADAR_GOBJ_SetRelative(int* p);

Word* cLListIterator_tCalloutPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tCalloutPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tCalloutPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Stores *p into the global at 0x004F7DB8, then forwards p. */
void cHud_SetOwner(int* p) {
    D_004F7DB8 = *p;
    cRADAR_GOBJ_SetRelative(p);
}
static inline void merge_flush_func_002426A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002426A0 */

/* merge_units: begin func_002426E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } Obj2426;
extern void GuiGameScreen_ActivateQuickChat(void* p, int on);
extern void cJoystick_Debounce(void* p);
extern char D_0055A300[];void cHud_DeactivateQuickChat(Obj2426* s) {
    if (!s->b6AA || !s->snd) return;
    GuiGameScreen_ActivateQuickChat(s->snd, 0);
    cJoystick_Debounce(D_0055A300);
    s->b6AA = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002426E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002426E0 */

/* merge_units: begin func_00242740 */
#pragma push /* merge_units */
void cHud_ActivateQuickChat(Obj2426* s) {
    if (s->b6AA || !s->snd) return;
    cJoystick_Debounce(D_0055A300);
    GuiGameScreen_ActivateQuickChat(s->snd, 1);
    s->b6AA = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242740 */

/* merge_units: begin func_002427A0 */
#pragma push /* merge_units */
extern int D_0055A6C0;
extern void cHud_DeactivateMap(Obj2426* s);
extern void cHud_ActivateMap(Obj2426* s);
void cHud_ToggleMap(Obj2426* s) {
    D_0055A6C0 = -0x41;
    if (s->b6A9) cHud_DeactivateMap(s);
    else cHud_ActivateMap(s);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002427A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002427A0 */
