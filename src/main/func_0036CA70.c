/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (code lies between the mem.cc
 * and hog.cc ranges); functions are named by address until real names are known.
 */

#include "loose03_types.h"

extern int D_00533890[256];     /* list storage (ends at the counter) */
extern int D_00533C90;          /* number of entries in D_00533890 */

/* Append a value to the global list. */
void func_0036CA70(int value) {
    D_00533890[D_00533C90] = value;
    D_00533C90 = D_00533C90 + 1;
}

int func_0036CAB0(char* self) {
    return *(int*)(self + 344);
}
