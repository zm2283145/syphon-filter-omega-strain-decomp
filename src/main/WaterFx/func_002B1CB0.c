#include "types.h"
typedef struct { char pad[0x40]; char splash[0x30]; char ripples[0x10]; } WaterFx;
typedef struct { char pad[0x400]; WaterFx* fx[20]; } WaterFxMgr;
extern void cSplash_Render(void*);
extern void cWake_Render(void*);
void cWaterFx_Render(WaterFxMgr* m)
{
    int i;
    WaterFxMgr* q = m;
    for (i = 0; i < 20; i++, q = (WaterFxMgr*)((char*)q + 4)) {
        WaterFx* p = q->fx[0];
        if (p) {
            cSplash_Render(p->splash);
            cWake_Render(p->ripples);
        }
    }
}