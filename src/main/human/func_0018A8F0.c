/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Array constructor helper: (array, ctor, dtor, element size, count). */
extern void* func_001004B0(void*, void*, void*, int, int);
extern int func_0018A210(int, int);
extern int* func_0018A870(int*);

Rel* func_0018A8F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an array of seven 8-byte pairs. */
void* func_0018A910(void* array) {
    func_001004B0(array, func_0018A870, func_0018A210, 8, 7);
    return array;
}
