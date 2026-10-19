/*
 * main/game: 2 files, 0013BDE0-0013BE20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013BDE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int String_CopyCtor(Unk0013BDE0* self, int a1);

/* Base init through String_CopyCtor, then store the word at +0x0C. */
int func_0013BDE0(Unk0013BDE0* self, int a1, int value) {
    int result;

    result = String_CopyCtor(self, a1);
    self->unk0C = value;
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BDE0 */

/* merge_units: begin func_0013BE20 */
#pragma push /* merge_units */
extern signed char D_004EA0D0;
extern char D_004EA0F0[];
extern char D_004EA0D8[];
extern void func_0013C250(void* obj, void* a, void* b);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void func_0013BF00(void);

/* Returns the lazily constructed static container. */
void* func_0013BE20(void) {
    int tagB;
    int tagA;
    if (!D_004EA0D0) {
        func_0013C250(D_004EA0F0, &tagA, &tagB);
        __register_global_object(D_004EA0F0, func_0013BF00, D_004EA0D8);
        D_004EA0D0 = 1;
    }
    return D_004EA0F0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BE20 */
