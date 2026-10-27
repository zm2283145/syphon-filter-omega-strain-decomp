/*
 * SFOGame/Source/GameGOBJ: 3 files, 00213FE0-00214080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00213FE0 */
#pragma push /* merge_units */
typedef struct { int floor; } St_00213FE0;
typedef struct { char pad0[0x68]; int x68; char pad6C[0x98 - 0x6C]; int x98; char pad9C[0xD0 - 0x9C]; int* xD0; char padD4[0xDC - 0xD4]; unsigned char xDC; } Door_00213FE0;
typedef struct { char pad0[0xEC]; int nDoors; Door_00213FE0** doors; char padF4[0x128 - 0xF4]; St_00213FE0* st; } Lift_00213FE0;
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
unsigned char cElevatorGOBJ_OutsideDoorsAreOpen(Lift_00213FE0* l)
{
    int i;
    int floor = l->st->floor;
    unsigned char r = 1;
    if (floor < 0)
        return 0;
    floor = floor * 2;
    i = floor;
    floor++;
    for (; i < l->nDoors && i <= floor; i++) {
        Door_00213FE0* d = l->doors[i];
        if (d->x68 == 2) {
            int f = d->x98 - 1;
            if (!d->xDC || f != *d->xD0) {
                r = 0; break; }
        }
    }
    return r;
}
static inline void merge_flush_func_00213FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213FE0 */

/* merge_units: begin func_00214080 */
#pragma push /* merge_units */
#include "types.h"

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
