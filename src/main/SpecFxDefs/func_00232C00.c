#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* g_LocalPlayer;
extern char D_004A6E38[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cPlayer_AtmosphericParticleEffect(void* w, void* o);
void* cSnowEffect_ctor(void* p, signed char type, float a, void* src, float b, float c);
void* cCameraAtmosphericEffect_ctor(void* p, signed char type, float a, float b, float c, float d);
}
static inline void* GAlloc(int sz, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, sz, D_004A6E38, line);
}
extern "C" void SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc(signed char type, void* src, float a, float b, float c, float d)
{
    void* w = g_LocalPlayer;
    cPlayer_AtmosphericParticleEffect(w, 0);
    if (type == 0x16 || type == 0x17 || type == 0x18) {
        void* p = GAlloc(0xD0, 0x4CD);
        if (p) p = cSnowEffect_ctor(p, type, b, src, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    } else {
        void* p = GAlloc(0xC0, 0x4D2);
        if (p) p = cCameraAtmosphericEffect_ctor(p, type, a, b, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    }
}

