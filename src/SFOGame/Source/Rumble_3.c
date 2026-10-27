/*
 * SFOGame/Source/Rumble: 2 files, 0026BDE0-0026BE70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026BDE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned char type; int a; float f; int b; int c; int id; unsigned char used; } C4Slot26B;
extern C4Slot26B D_004FEED0[][6];
static unsigned int dat_0048B270[2] = { 0x1, 0x0 };
int nRumbleManager_Start(int idx, unsigned char type, int a, int b, float f) {
    int i;
    for (i = 0; i < 6; i++) {
        C4Slot26B* s = &D_004FEED0[idx][i];
        if (!s->used) {
            int id;
            s->used = 1;
            s->type = type;
            s->a = a;
            s->f = f;
            s->b = b;
            s->c = 0;
            id = (*(int*)dat_0048B270)++;
            s->id = id;
            return s->id;
        }
    }
    return 0;
}
static inline void merge_flush_func_0026BDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BDE0 */

/* merge_units: begin func_0026BE70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_004FF028;

void nRumbleManager_SetEnabled(int value) {
    D_004FF028 = value;
}
static inline void merge_flush_func_0026BE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BE70 */
