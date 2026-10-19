#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* g_LocalPlayer;
extern char D_004A6E38[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void World_SetAtmosphereEffect(void* w, void* o);
void* SnowField_Construct(void* p, signed char type, float a, void* src, float b, float c);
void* SmokeField_Construct(void* p, signed char type, float a, float b, float c, float d);
}
static inline void* GAlloc(int sz, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, sz, D_004A6E38, line);
}
extern "C" void World_StartAtmosphereEffect(signed char type, void* src, float a, float b, float c, float d)
{
    void* w = g_LocalPlayer;
    World_SetAtmosphereEffect(w, 0);
    if (type == 0x16 || type == 0x17 || type == 0x18) {
        void* p = GAlloc(0xD0, 0x4CD);
        if (p) p = SnowField_Construct(p, type, b, src, c, d);
        World_SetAtmosphereEffect(w, p);
    } else {
        void* p = GAlloc(0xC0, 0x4D2);
        if (p) p = SmokeField_Construct(p, type, a, b, c, d);
        World_SetAtmosphereEffect(w, p);
    }
}

