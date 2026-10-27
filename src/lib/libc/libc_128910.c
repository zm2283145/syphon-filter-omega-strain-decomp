/*
 * lib/libc: 6 files, 00128910-001289F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00128910 */
#include "types.h"

extern char D_00489738[];
extern int Newlib_RaiseR(int, int);

int Libc_Raise(int a0) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_RaiseR(tmp0, a0);
}
/* merge_units: end func_00128910 */

/* merge_units: begin func_00128930 */
extern int Newlib_SignalR(int, int, int);

int Libc_Signal(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_SignalR(tmp0, a0, a1);
}
/* merge_units: end func_00128930 */

/* merge_units: begin func_00128958 */
extern int Newlib_InitSignalR(int);

int Newlib_InitSignal(void) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_InitSignalR(tmp0);
}
/* merge_units: end func_00128958 */

/* merge_units: begin func_00128978 */
extern int Newlib_SigtrampR(int, int);

int Newlib_Sigtramp(int a0) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_SigtrampR(tmp0, a0);
}
/* merge_units: end func_00128978 */

/* merge_units: begin func_00128998 */
extern char D_0058805C[];
extern int Libc_Kill(int, int);

int Newlib_KillR(int a0, int a1, int a2) {
    int s0, s1, v0, v1;

    s0 = a0;
    s1 = (int)D_0058805C;
    a0 = a1;
    a1 = a2;
    *(int*)(char*)s1 = 0;
    v0 = Libc_Kill(a0, a1);
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
extern int Libc_Getpid(void);

int Newlib_GetpidR(void) {
    return Libc_Getpid();
}
/* merge_units: end func_001289F8 */
