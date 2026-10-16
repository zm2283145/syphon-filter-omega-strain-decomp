#include "types.h"

typedef struct { char pad[4]; unsigned short w; unsigned short h; } VfxTexInfo;
typedef struct { char pad[0x44]; VfxTexInfo* info; } VfxTexEntry;
typedef struct { int unk00; int unk04; VfxTexEntry** entries; } VfxTexReg;
typedef struct { signed char id; char pad[3]; } VfxFlareId;

typedef struct {
    char pad0[0x19C];
    int tex;
    float w;
    float h;
    char pad1A8[4];
    int x1AC;
    char pad1B0[0x1D4 - 0x1B0];
    int flares[9];
    int x1F8;
} VisionFx;

extern VfxFlareId D_004A7DB0[];
extern VfxTexReg* D_00539248;
extern int* SpecFx_GetEffectDef(int id);

static inline int VfxTexW(int h) { return D_00539248->entries[h]->info->w; }
static inline int VfxTexH(int h) { return D_00539248->entries[h]->info->h; }

void VisionFx_LoadFlareTextures(VisionFx* self)
{
    int i;
    for (i = 0; i < 9; i++) {
        self->flares[i] = *SpecFx_GetEffectDef(D_004A7DB0[i].id);
    }
    self->x1F8 = *SpecFx_GetEffectDef(0x21);
    {
        int t = self->x1F8;
        self->tex = t;
        self->x1AC = 0;
        self->w = VfxTexW(t);
        self->h = VfxTexH(t);
    }
}


