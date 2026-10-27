#include "types.h"
typedef struct { int x0; unsigned char x4; } FxEnt232120;
extern FxEnt232120 SpecFxTable[];
extern int SfxParticleEffect_int_cMatrixR(int);
static inline FxEnt232120* GetFx232120(int id) {
    if (!SpecFxTable[id].x4) return 0;
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
int SfxParticleEffect_eEffectName_cMatrixR(signed char id) {
    return SfxParticleEffect_int_cMatrixR(GetFx232120(id)->x0);
}