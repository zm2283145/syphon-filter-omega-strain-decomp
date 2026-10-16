/*
 * main/lights: 5 files, 00373BA0-00373E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00373BA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float a; float b; } A5_00373BA0;
int LightMgr_CompareOrder(A5_00373BA0* x, A5_00373BA0* y) {
    float b = y->b, a = x->b;
    if (a < b) return -1;
    else if (a > b) return (unsigned char)(a > b);
    return (unsigned char)(a > b);
}
#pragma pop /* merge_units */
/* merge_units: end func_00373BA0 */

/* merge_units: begin func_00373BE0 */
#pragma push /* merge_units */
int LightMgr_FindFirstAmbient(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 16);
    cond = v1 == 0;
    v0 = 0;
    if (cond) goto L00373BF0;
    v0 = *(int*)(char*)a0;
L00373BF0:;
    goto ret;
ret:
    return v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00373BE0 */

/* merge_units: begin func_00373C00 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_00373C00 */

/* merge_units: begin func_00373D70 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_00373D70 */

/* merge_units: begin func_00373E70 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_00373E70 */
