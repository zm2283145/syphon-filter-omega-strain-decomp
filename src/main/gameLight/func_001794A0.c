#include "types.h"
typedef struct { int a; int b; } E794;
typedef struct { char pad0[0x1C]; unsigned char flag; char pad1[0x60-0x1D]; E794 e[16]; } S794;
extern unsigned char g_LevelLightsDirty;
void cSceneLight_Init(S794* p) {
    unsigned int i;
    for (i = 0; i < 16; i++) {
        p->e[i].a = 0;
        p->e[i].b = -1;
    }
    if (p->flag == 0) {
        p->flag = 1;
        g_LevelLightsDirty = 1;
    }
}