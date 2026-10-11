#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } E2A8390;
typedef struct { E2A8390* e; char pad[0x10]; } Ent2A8390;
typedef struct { char pad[0x54]; int sel; Ent2A8390 ent[3]; } S2A8390;
void func_002A8390(S2A8390* s, int sel)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (s->ent[i].e) {
            if (sel == i)
                s->ent[i].e->flags |= 2;
            else
                s->ent[i].e->flags &= ~2;
            {
                E2A8390* e = s->ent[i].e;
                if (sel == i)
                    e->flags |= 4;
                else
                    e->flags &= ~4;
            }
        }
    }
    s->sel = sel;
}