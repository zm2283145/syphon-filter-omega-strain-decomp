#pragma cplusplus on
#include "vslot_pad.h"

typedef struct { int pad0; void* light; char pad8[24]; } LE18B0;
typedef struct { char pad0[0x4C]; int count; char pad50[0x10]; LE18B0 ents[1]; } LM18B0;
typedef struct { char pad[0x60]; LE18B0 e; } LR18B0;

struct L18B0 {
    char pad0[4];
    void* vt;
    int x8;
    char padC[0x12];
    unsigned char type;
};

extern "C" {
extern char D_004DF700[];
extern char D_004D9240[];
extern char D_004D9280[];
extern unsigned char g_LevelLightsDirty;
extern LM18B0 g_LightMgr;
void SyncDCache(LE18B0*, LE18B0*);
}

static inline void QMove18B0(void* d, void* s, int n) {
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

struct VB18B0 { char k; char f; };
struct VI18B0 : VB18B0 { VPAD8(a) VPAD2(b) virtual void Disable(); };

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
static inline void Remove18B0(LM18B0* m, L18B0* l) {
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
        if (*(L18B0**)((int)&m->ents[0].light + (i << 5)) == l) {
            m->count = m->count - 1;
            QMove18B0(&((LR18B0*)((int)m + (i << 5)))->e, &m->ents[i + 1], (m->count - i) * 2);
            SyncDCache(m->ents, &m->ents[m->count]);
            return;
        }
    }
}

extern "C" L18B0* func_003718B0(L18B0* p, short flag)
{
    if (p) {
        p->vt = D_004DF700;
        if (p) {
            p->vt = D_004D9240;
            p->x8 = -1;
            ((VI18B0*)p)->Disable();
            g_LevelLightsDirty = 1;
            if (p) p->vt = D_004D9280;
        }
        if (flag > 0) Remove18B0(&g_LightMgr, p);
    }
    return p;
}


