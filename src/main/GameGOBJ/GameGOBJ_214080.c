/*
 * main/GameGOBJ: range (2 files, 00214080-00214160)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00214080 */
#pragma push /* merge_units */
typedef struct { char pad0[0x68]; int state; char pad1[0x98-0x6C]; int count; char pad2[0xD0-0x9C]; int* cur; char pad3[0xDC-0xD4]; unsigned char active; } Obj4080;
typedef struct { char pad0[0x4C]; int kind; } Ent4080;
typedef struct { char pad0[0x70]; int num; char vec[8]; Obj4080** objs; } Lift4080;
extern Ent4080** std_vector_cGOBJPtr_opIndex(void* vec, int i);
extern int g_GameGobjClassWord;
#pragma opt_strength_reduction off
unsigned char cElevatorGOBJ_InsideDoorsAreOpen(Lift4080* p) {
    unsigned char ok = 1;
    int i;
    Obj4080* o;
    for (i = 0; i < p->num; i++) {
        Ent4080** e = std_vector_cGOBJPtr_opIndex(p->vec, i);
        if ((*e)->kind == g_GameGobjClassWord) {
            o = p->objs[i];
            if (o->state == 2) {
                int c = o->count - 1;
                if (!o->active || c != *o->cur) { ok = 0; break; }
            }
        }
    }
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214080 */

/* merge_units: begin func_00214160 */
#pragma push /* merge_units */
extern int cElevatorGOBJ_OutsideDoorsAreClosed(int);
extern int cElevatorGOBJ_InsideDoorsAreClosed(int);

int cElevatorGOBJ_DoorsAreClosed(int a0) {
    int s0, v0;
    int cond;

    s0 = a0;
    v0 = cElevatorGOBJ_InsideDoorsAreClosed(a0);
    v0 = v0 & 255;
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00214190;
    v0 = cElevatorGOBJ_OutsideDoorsAreClosed(a0);
    v0 = v0 & 255;
L00214190:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214160 */
