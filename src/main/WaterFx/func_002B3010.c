#include "types.h"
typedef struct WaterFx WaterFx;
extern void WaterFx_Clear(WaterFx* w);
extern void operator_delete(void* p);
WaterFx* WaterFx_Destroy(WaterFx* self, short flag) {
    if (self) {
        WaterFx_Clear(self);
        if (flag > 0) {
            operator_delete(self);
        }
    }
    return self;
}