#include "types.h"
extern void operator_delete(void* p);
typedef struct HumanColPreset HumanColPreset;
HumanColPreset* HumanColPreset_Dtor(HumanColPreset* self, short flag) {
    if (self && flag > 0) {
        operator_delete(self);
    }
    return self;
}