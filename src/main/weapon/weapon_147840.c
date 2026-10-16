/*
 * main/weapon: range (2 files, 00147840-00147880)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00147840 */
#pragma push /* merge_units */
int WeaponDb_Get(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a1 < 0;
    if (cond) goto L00147860;
    v0 = *(int*)((char*)a0 + 4);
    v0 = *(int*)((char*)v0 + 4);
    v0 = a1 < v0;
    cond = v0 != 0;
    if (cond) goto L00147868;
L00147860:;
    a1 = 0;
L00147868:;
    v0 = *(int*)((char*)a0 + 20);
    v1 = a1 << 2;
    v1 = v1 + a1;
    v1 = v1 << 6;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147840 */

/* merge_units: begin func_00147880 */
#pragma push /* merge_units */
typedef struct { int a[4]; } Q_7880;
typedef struct { char pad[0x2C0]; Q_7880 e[16]; short x3C0; char pad2[0x40C - 0x3C2]; unsigned char count; } T_7880;
typedef struct { char pad[0xCC]; T_7880* t; } S_7880;
static const unsigned int dat_00489CE0[8] = { 0xFF0000, 0x1, 0x401FF06, 0xFF020404, 0x2010105, 0x3030202, 0xFFFF0105, 0xFF };
extern int D_0055DE90;
Q_7880* WeaponDb_GetShellRecord(S_7880* self, int id)
{
    signed char k;
    T_7880* t;
    if (id < 0)
        return 0;
    k = ((signed char*)dat_00489CE0)[id];
    if (k < 0)
        return 0;
    t = self->t;
    if (t) {
        if (!(k < t->count))
            return 0;
        D_0055DE90 = t->x3C0;
        return &t->e[k];
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147880 */
