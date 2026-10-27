#include "types.h"
/* cLightMan_AddLightScoreBox: bounding-sphere test of a light entry, appends (light, key) to the gather list */
typedef struct Pt1TbVec { float x, y, z, w; } __attribute__((aligned(16))) Pt1TbVec;
typedef struct Pt1TbEntry {
    unsigned char flags;
    char pad1[3];
    void* light;
    float range;
    float weight;
    Pt1TbVec pos;
} Pt1TbEntry;
typedef struct Pt1TbCand { void* light; float key; } Pt1TbCand;
typedef struct Pt1TbList { char pad[0x2000]; Pt1TbCand cand[1]; } Pt1TbList;
typedef struct Pt1TbGather {
    char pad0[0x50];
    int count;
    Pt1TbList* list;
} Pt1TbGather;

void cLightMan_AddLightScoreBox(Pt1TbGather* g, Pt1TbVec* pos, Pt1TbEntry* e, float radius)
{
    float key;
    unsigned char ok;
    if (e->flags == 2) {
        key = 0.0f;
        ok = 1;
    } else {
        int r;
        int st;
        int k;
        asm {
            lqc2 vf1, 0x0(pos)
            lqc2 vf2, 0x10(e)
            vsub.xyzw vf3, vf2, vf1
            mfc1 r, radius
            qmtc2 r, vf5
            lqc2 vf6, 0x0(e)
            vaddz.x vf7, vf5, vf6z
            vmul.xyz vf4, vf3, vf3
            vaddw.x vf9, vf0, vf0w
            vmul.x vf8, vf7, vf7
            vmulax.x ACC, vf9, vf4x
            vmadday.x ACC, vf9, vf4y
            vmaddz.x vf10, vf9, vf4z
            vsub.x vf11, vf10, vf8
            vnop
            vnop
            vnop
            vmulw.x vf8, vf10, vf6w
            cfc2 st, vi16
            qmfc2 k, vf8
        }
        {
            /* S flag (bit 1) of dist^2 - (radius + range)^2: inside the light's reach */
            unsigned s = (st >> 1) << 31;
            unsigned zero = 0;
            ok = !(s <= zero);
        }
        asm { mtc1 k, key } /* key bits from VU0 into an FPR */
    }
    if (ok) {
        g->list->cand[g->count].key = key;
        g->list->cand[g->count].light = e->light;
        g->count++;
    }
}
