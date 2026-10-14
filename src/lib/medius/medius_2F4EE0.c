/*
 * lib/medius: 7 files, 002F4EE0-002F4FB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F4EE0 */
#include "types.h"

extern int func_002D8A28(void);
extern int func_002D8B38(int, int);

int func_002F4EE0(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_002D8A28();
    tmp2 = func_002D8B38(tmp0, a1);
    *(int*)((char*)a0) = tmp0;
    return tmp2;
}
/* merge_units: end func_002F4EE0 */

/* merge_units: begin func_002F4F30 */
extern int func_002D8FB0(int, int, int, int);

int func_002F4F30(int a0, int a1, int a2, int a3) {
    return func_002D8FB0(a0, a1, a2, a3);
}
/* merge_units: end func_002F4F30 */

/* merge_units: begin func_002F4F48 */
extern int func_002D9550(int, int, int, int);

int func_002F4F48(int a0, int a1, int a2, int a3) {
    return func_002D9550(a0, a1, a2, a3);
}
/* merge_units: end func_002F4F48 */

/* merge_units: begin func_002F4F60 */
extern int func_002D90C0(int);

int func_002F4F60(int a0) {
    return func_002D90C0(a0);
}
/* merge_units: end func_002F4F60 */

/* merge_units: begin func_002F4F78 */
extern int func_002DA8E8(int, int);

int func_002F4F78(int a0, int a1) {
    return func_002DA8E8(a0, a1);
}
/* merge_units: end func_002F4F78 */

/* merge_units: begin func_002F4F90 */
extern int func_002DA900(int, int);

int func_002F4F90(int a0, int a1) {
    *(int*)((char*)a1) = (0 | 65535);
    return func_002DA900(a0, a1);
}
/* merge_units: end func_002F4F90 */

/* merge_units: begin func_002F4FB0 */
extern int func_002DA920(int, int, int);

int func_002F4FB0(int a0, int a1, int a2) {
    return func_002DA920(a0, a1, a2);
}
/* merge_units: end func_002F4FB0 */
