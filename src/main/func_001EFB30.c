#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x38]; float v; } EFT_Tri;
extern "C" bool Edge_FilterTriangle(void* a, void* b, EFT_Tri* t) {
    bool r = true;
    if (t->v < 0.5f) r = false;
    return r;
}