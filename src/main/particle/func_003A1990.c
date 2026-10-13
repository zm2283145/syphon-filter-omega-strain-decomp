#include "types.h"

extern char D_004DFAD8[];
extern char D_004DFB50[];
extern struct { int n; float v[0x103]; } D_0053B6A0;

typedef struct {
    char pad0[0xC];
    int xC;
    float x10;
    char pad14[0x180 - 0x14];
    int x180;
} Info3A1990;

typedef struct {
    void* vt;
    char pad4[8];
    unsigned char xC;
    char padD[0x60 - 0xD];
    int x60;
    float x64;
    float x68;
    int x6C;
    int x70;
    int x74;
    unsigned char x78[8];
    int x80;
    unsigned char x84;
} Self3A1990;

Self3A1990* func_003A1990(Self3A1990* self, int a, Info3A1990* info, float f)
{
    int i;
    self->vt = D_004DFAD8;
    self->vt = D_004DFB50;
    self->xC = 0;
    self->x60 = 0;
    self->x64 = f;
    self->x80 = 0;
    self->x84 = 0;
    self->x74 = a;
    for (i = 0; i < info->x180; i++) {
        self->x78[i] = 0;
    }
    self->x70 = ++D_0053B6A0.n;
    self->x6C = info->xC + (int)(0.5f + info->x10 * ((float*)&D_0053B6A0)[(unsigned char)self->x70 + 4]);
    self->x68 = f - 0.25f - 1.0f;
    return self;
}

