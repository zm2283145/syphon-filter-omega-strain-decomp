#include "types.h"
typedef struct { char pad0[8]; int id; char padC[0x34]; } LtA;
typedef struct { char pad0[8]; int id; char padC[0x44]; } LtB;
typedef struct { char pad0[8]; int id; char padC[0xD4]; } LtD;
typedef struct { LtA* amb; LtB* pt; LtA* dir; LtD* spot; int nAmb; int nPt; int nDir; int nSpot; } LtMgr;

void* LightMgr_FindByTypeAndId(LtMgr* m, int type, int id) {
    switch (type) {
    case 1: {
        int i;
        for (i = 0; i < m->nAmb; i++) {
            if (m->amb[i].id == id) return &m->amb[i];
        }
        } break;
    case 2: {
        int i;
        for (i = 0; i < m->nPt; i++) {
            if (m->pt[i].id == id) return &m->pt[i];
        }
        } break;
    case 4: {
        int i;
        for (i = 0; i < m->nDir; i++) {
            if (m->dir[i].id == id) return &m->dir[i];
        }
        } break;
    case 0x10: {
        int i;
        for (i = 0; i < m->nSpot; i++) {
            if (m->spot[i].id == id) return &m->spot[i];
        }
        } break;
    }
    return 0;
}


