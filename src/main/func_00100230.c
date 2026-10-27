/*
 * Matched functions (byte-identical with the retail executable).
 * Soft-float double comparison wrappers around SoftFloat_UnpackAndCompare
 * (result < 0, 0 or > 0).
 */

#include "types.h"

extern int SoftFloat_UnpackAndCompare(int a, int b);

/* a >= b */
int _dpfge(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return ((cmp < 0) ^ 1);
}

/* a > b */
int _dpfgt(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return (0 < cmp);
}

/* a <= b */
int _dpfle(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return ((0 < cmp) ^ 1);
}

/* a != b */
int _dpfne(int a, int b) {
    int cmp;

    cmp = SoftFloat_UnpackAndCompare(a, b);
    return cmp != 0;
}
