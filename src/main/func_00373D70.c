#include "types.h"
typedef struct { int pad0; void* light; char pad8[24]; } Pt2_LEnt;
typedef struct { char pad0[0x4C]; int count; char pad50[0x10]; Pt2_LEnt ents[1]; } Pt2_LMgr;
typedef struct { char pad0[8]; int x8; char padC[0x12]; unsigned char type; } Pt2_Light;
typedef struct { char pad[0x60]; Pt2_LEnt e; } Pt2_Row;
extern void SyncDCache(Pt2_LEnt*, Pt2_LEnt*);
static inline void Pt2_QMove(void* d, void* s, int n) {
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void LightMgr_RemoveFromTable(Pt2_LMgr* m, Pt2_Light* l) {
    int i;
    switch (l->type) {
    case 1:
        break;
    case 2:
        break;
    case 4:
        l->x8 = -1;
        break;
    case 0x10:
        break;
    }
    for (i = 0; i < m->count; i++) {
        Pt2_Row* r = (Pt2_Row*)((i << 5) + (int)m);
        if (r->e.light == l) {
            m->count = m->count - 1;
            Pt2_QMove(&r->e, &m->ents[i + 1], (m->count - i) * 2);
            SyncDCache(m->ents, &m->ents[m->count]);
            return;
        }
    }
}
#pragma pop
