/*
 * main/hud: range (3 files, 002426E0-002427A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002426E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } Obj2426;
extern void func_0045DD90(void* p, int on);
extern void Pad_ResetHeldMask(void* p);
extern char D_0055A300[];void func_002426E0(Obj2426* s) {
    if (!s->b6AA || !s->snd) return;
    func_0045DD90(s->snd, 0);
    Pad_ResetHeldMask(D_0055A300);
    s->b6AA = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002426E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002426E0 */

/* merge_units: begin func_00242740 */
#pragma push /* merge_units */
void func_00242740(Obj2426* s) {
    if (s->b6AA || !s->snd) return;
    Pad_ResetHeldMask(D_0055A300);
    func_0045DD90(s->snd, 1);
    s->b6AA = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242740 */

/* merge_units: begin func_002427A0 */
#pragma push /* merge_units */
extern int D_0055A6C0;
extern void func_002427F0(Obj2426* s);
extern void func_00242870(Obj2426* s);
void Hud_ToggleMap(Obj2426* s) {
    D_0055A6C0 = -0x41;
    if (s->b6A9) func_002427F0(s);
    else func_00242870(s);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002427A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002427A0 */
