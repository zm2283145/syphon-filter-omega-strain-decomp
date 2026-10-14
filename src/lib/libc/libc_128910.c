/*
 * lib/libc: 6 files, 00128910-001289F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00128910 */
#include "types.h"

extern char D_00489738[];
extern int func_001287A0(int, int);

int func_00128910(int a0) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_001287A0(tmp0, a0);
}
/* merge_units: end func_00128910 */

/* merge_units: begin func_00128930 */
extern int func_00128720(int, int, int);

int func_00128930(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_00128720(tmp0, a0, a1);
}
/* merge_units: end func_00128930 */

/* merge_units: begin func_00128958 */
extern int func_001286B0(int);

int func_00128958(void) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_001286B0(tmp0);
}
/* merge_units: end func_00128958 */

/* merge_units: begin func_00128978 */
extern int func_00128878(int, int);

int func_00128978(int a0) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return func_00128878(tmp0, a0);
}
/* merge_units: end func_00128978 */

/* merge_units: begin func_00128998 */
extern char D_0058805C[];
extern int func_0010D938(int, int);

int func_00128998(int a0, int a1, int a2) {
    int s0, s1, v0, v1;

    s0 = a0;
    s1 = (int)D_0058805C;
    a0 = a1;
    a1 = a2;
    *(int*)(char*)s1 = 0;
    v0 = func_0010D938(a0, a1);
    v1 = v0;
    a0 = 0 + -1;
    if (v1 != a0) {
    goto L001289E4;
    }
    v1 = *(int*)(char*)s1;
    if (v1 != 0) {
    *(int*)(char*)s0 = v1;
    goto L001289E0;
    }
L001289E0:;
L001289E4:;
    goto ret;
ret:
    return v0;
}
/* merge_units: end func_00128998 */

/* merge_units: begin func_001289F8 */
extern int func_0010D930(void);

int func_001289F8(void) {
    return func_0010D930();
}
/* merge_units: end func_001289F8 */
