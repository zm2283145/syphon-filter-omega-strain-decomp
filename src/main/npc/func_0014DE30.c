#include "types.h"
typedef struct { int time; unsigned char active; char pad[0x14 - 5]; } E_DE30;
typedef struct { char pad[0x178]; E_DE30 e[3]; } S_DE30;
void cNPC_v4D(S_DE30* self, int t)
{
    int i = 0;
    S_DE30* p = self;
    do {
        if (p->e[0].active && p->e[0].time == t) {
            unsigned char k = i;
            E_DE30* e = &self->e[k]; S_DE30* q = (S_DE30*)((char*)self + k * 0x14); if (t >= q->e[0].time) { q->e[0].active = 0; e->time = 0;
            }
        }
        i++;
        p = (S_DE30*)((char*)p + 0x14);
    } while (i < 3);
}