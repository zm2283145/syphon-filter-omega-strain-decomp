/*
 * main/path: range (2 files, 00161FA0-00162010)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00161FA0 */
#pragma push /* merge_units */
typedef struct N_1FA0 { struct N_1FA0* prev; struct N_1FA0* next; int pad8; int padC; int a; int b; int fa; int fb; } N_1FA0;
typedef struct { char pad[0x64]; int flags; } Obj_1FA0;
typedef struct { int pad[2]; Obj_1FA0** items; } Reg_1FA0;
typedef struct { char pad[0x18]; N_1FA0* first; int pad1c; N_1FA0 end; } S_1FA0;
extern Reg_1FA0* D_004FFBE0;
void cNodeRequest_SetCompanionNodeLOSResultForRestOfList(S_1FA0* self, int id, unsigned char v)
{
    N_1FA0* n = self->first;
    Obj_1FA0* o = D_004FFBE0->items[id];
    N_1FA0* e = &self->end;
    for (; n != e; n = n->next) {
        if (n->b == id)
            n->fb = v;
        if (n->a == id && !(o->flags & 4))
            n->fa = v;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161FA0 */

/* merge_units: begin func_00162010 */
#pragma push /* merge_units */
void cNodeRequest_SetNodeLOSResultForRestOfList(S_1FA0* self, int id, unsigned char v)
{
    N_1FA0* n = self->first;
    Obj_1FA0* o = D_004FFBE0->items[id];
    N_1FA0* e = &self->end;
    for (; n != e; n = n->next) {
        if (n->a == id)
            n->fa = v;
        if (n->b == id && !(o->flags & 4))
            n->fb = v;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00162010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00162010 */
