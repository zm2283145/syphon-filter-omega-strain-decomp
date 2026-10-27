#include "types.h"
extern void operator_delete(void* p);
typedef struct HumanColPreset HumanColPreset;
HumanColPreset* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_dtor(HumanColPreset* self, short flag) {
    if (self && flag > 0) {
        operator_delete(self);
    }
    return self;
}