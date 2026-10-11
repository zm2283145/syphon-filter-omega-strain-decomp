
#include "types.h"
/* Model_FoldMaterialFlags */
typedef struct { char pad0[4]; int flags; char pad8[0x40]; int tex[4]; int nTex; char pad5C[0]; } Pt2_Mat;
typedef struct { char pad0[4]; int flags; char pad8[0x10]; int nMat; char pad1C[0x34]; char* mats; } Pt2_Geo;
typedef struct { char pad0[4]; Pt2_Geo* geo; char pad8[0x1C]; int flags; } Pt2_Model;

void Model_FoldMaterialFlags(Pt2_Model* m) {
    int i;
    for (i = 0; i < m->geo->nMat; i++) {
        Pt2_Mat* mt = (Pt2_Mat*)(m->geo->mats + i * 0x5C);
        int j;
        if (mt->flags & 0x10) m->flags |= 0x20;
        if (mt->flags & 0x20) m->flags |= 0x40;
        for (j = 0; j < mt->nTex; j++) {
            switch (mt->tex[j]) {
            case 2:
                break;
            case 0xB:
                m->flags |= 0x400;
                break;
            case 0xA:
                m->flags |= 0x800;
                break;
            case 0xE:
                m->flags |= 0x1000;
                break;
            }
        }
    }
    if (m->geo->flags & 0x10) {
        m->flags &= ~0x60;
        m->flags |= 0x20000;
    }
}