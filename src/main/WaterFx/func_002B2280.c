#pragma cplusplus on
#include "types.h"
struct WObj_2280 { char pad[0xC]; int serial; };
struct WRef_2280 { WObj_2280* obj; int serial; };
struct WMgr_2280 { char pad[0x400]; WRef_2280* refs[20]; };
static inline bool V_2280(WRef_2280* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline WObj_2280* G1_2280(WRef_2280* h) { return V_2280(h) ? h->obj : 0; }
extern "C" int WaterFx_Find(WMgr_2280* m, WObj_2280* target)
{
    int res = -1;
    int i;
    if (target != 0) {
        for (i = 0; i < 20; i++) {
            WRef_2280* r = m->refs[i];
            if (r != 0 && G1_2280(r) != 0 && G1_2280(r) == target) { res = i; break; }
        }
    }
    return res;
}
