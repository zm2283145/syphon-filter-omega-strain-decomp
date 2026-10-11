#include "types.h"
typedef struct N_1FA0 { struct N_1FA0* prev; struct N_1FA0* next; int pad8; int padC; int a; int b; int fa; int fb; } N_1FA0;
typedef struct { char pad[0x64]; int flags; } Obj_1FA0;
typedef struct { int pad[2]; Obj_1FA0** items; } Reg_1FA0;
typedef struct { char pad[0x18]; N_1FA0* first; int pad1c; N_1FA0 end; } S_1FA0;
extern Reg_1FA0* D_004FFBE0;
void func_00161FA0(S_1FA0* self, int id, unsigned char v)
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