#include "types.h"
typedef struct { char pad[0xB0]; int coll; } B5aOwner;
typedef struct { char pad[0xC]; B5aOwner* owner; char pad2[0xE4 - 0x10]; float z; } B5aObj;
extern float D_004A0438;
extern int D_004A03C8;
extern void* RootCollection_FindByKey(void* coll, void* key);
extern void* Root_GetWorldPlacement(void* r);
extern float* Placement_GetPosition(void* p);
float func_001E96A0(B5aObj* o) {
    float r;
    if (o->z != D_004A0438) {
        float* p = Placement_GetPosition(Root_GetWorldPlacement(RootCollection_FindByKey(&o->owner->coll, &D_004A03C8)));
        r = o->z - p[2];
    } else {
        r = 0.0f;
    }
    return r;
}