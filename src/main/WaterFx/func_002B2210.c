#include "types.h"
typedef struct { char pad[0x30]; float h0; char pad2[0x54]; float h1; } WaterFxObj;
typedef struct { char pad[0x400]; WaterFxObj* objs[1]; } WaterFxMgr;
extern int WaterFx_Find(WaterFxMgr* w, int id);
void WaterFx_UpdateHeight(WaterFxMgr* w, int id, float h) {
    float y = 0.2f + h;
    if (id) {
        int i = WaterFx_Find(w, id);
        WaterFxObj* o = (i >= 0) ? w->objs[i] : 0;
        if (o) {
            o->h0 = y;
            o->h1 = y;
        }
    }
}