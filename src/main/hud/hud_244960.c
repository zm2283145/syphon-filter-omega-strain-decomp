/*
 * main/hud: range (3 files, 00244960-002449D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00244960 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; void* obj; } O4960;
extern void func_00260D90(void* tmp);
extern void func_003E7EE0(void* obj, void* tmp);
void func_00244960(O4960* self) {
    if (self->obj) {
        char tmp[16];
        func_00260D90(tmp);
        func_003E7EE0(self->obj, tmp);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244960 */

/* merge_units: begin func_002449A0 */
#pragma push /* merge_units */
extern void func_003E8DE0(int, int);

void func_002449A0(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L002449C0;
    func_003E8DE0(a0, a1);
L002449C0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449A0 */

/* merge_units: begin func_002449D0 */
#pragma push /* merge_units */
void func_002449D0(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0 + 1;
    if (cond) goto L002449F0;
    func_003E8DE0(a0, a1);
L002449F0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449D0 */
