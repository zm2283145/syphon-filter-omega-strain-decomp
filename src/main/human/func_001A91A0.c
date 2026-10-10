#include "types.h"
typedef struct { char pad[0x10]; float pos[4]; char pad2[0x30]; } PlaceD4;
typedef struct { PlaceD4 world; PlaceD4 base; } RootIdD4;
extern void* Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern RootIdD4* Root_Identity(void* r);
float* Root_GetWorldBasePlacement(void* r)
{
    PlaceD4* p;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        p = &Root_Identity(r)->world;
    } else {
        p = &Root_Identity(r)->base;
    }
    return p->pos;
}