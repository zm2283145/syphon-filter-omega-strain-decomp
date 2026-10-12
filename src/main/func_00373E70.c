#include "types.h"
typedef struct { char pad[8]; int id; char padC[0x34]; } LmA;
typedef struct { char pad[8]; int id; char padC[0x44]; } LmB;
typedef struct { char pad[8]; int id; char padC[0x34]; } LmC;
typedef struct { char pad[8]; int id; char padC[0xD4]; } LmD;
typedef struct { char pad[8]; int id; } LmAny;
typedef struct {
    LmA* a;
    LmB* b;
    LmC* c;
    LmD* d;
    int na;
    int nb;
    int nc;
    int nd;
} LightMgr;
LmAny* LightMgr_AllocPoint(LightMgr* m, unsigned char kind)
{
    LmAny* l = 0;
    int i;
    switch (kind) {
    case 1:
        for (i = 0; i < m->na && !l; i++) {
            if (m->a[i].id == -1)
                l = (LmAny*)&m->a[i];
        }
        break;
    case 2:
        for (i = 0; i < m->nb && !l; i++) {
            if (m->b[i].id == -1)
                l = (LmAny*)&m->b[i];
        }
        break;
    case 4:
        for (i = 0; i < m->nc && !l; i++) {
            if (m->c[i].id == -1)
                l = (LmAny*)&m->c[i];
        }
        break;
    case 0x10:
        for (i = 0; i < m->nd && !l; i++) {
            if (m->d[i].id == -1)
                l = (LmAny*)&m->d[i];
        }
        break;
    }
    if (l)
        l->id = i;
    return l;
}
