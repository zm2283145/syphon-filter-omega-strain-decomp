#include "types.h"
typedef struct { float x, y, z, w; } V4_558A0;
typedef struct { V4_558A0 a; V4_558A0 b; int id; int ref; } Ent_558A0;
typedef struct { unsigned char type; char pad[3]; Ent_558A0 ents[5]; int count; unsigned char flag; char pad2[3]; } Slot_558A0;
typedef struct { char pad[0x64]; Slot_558A0 slots[3]; } Pack_558A0;
extern int func_00143D20(int key);
static inline void Cp_558A0(Ent_558A0* d, Ent_558A0* s) { d->a = s->a; d->b = s->b; d->id = s->id; d->ref = s->ref; }
#pragma opt_rotateloops off
int func_002558A0(Pack_558A0* s, int id, int keep)
{
    Slot_558A0* p; int i;
    int t;
    t = func_00143D20(id); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) {
            Ent_558A0* e = p->ents;
            int j = 0;
            if (j < p->count) {
                do {
                    if ((void*)e->id == (void*)id) {
                        if (!keep) {
                            if (--e->ref == 0) {
                                int n = --p->count;
                                Cp_558A0(e, (Ent_558A0*)((char*)p + n * 40 + 4));
                            }
                        }
                        return 1;
                    }
                    j++;
                    e++;
                } while (j < p->count);
            }
        }
    }
    return 0;
}
#pragma opt_rotateloops reset