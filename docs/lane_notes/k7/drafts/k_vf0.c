#pragma cplusplus on
#include "types.h"

struct tRGBA { float r, g, b, a; };
struct tIRGBA { int r, g, b, a; };
struct V4E { float x, y, z, w;
    void Set(const tRGBA& c) { float a, b, d, e; e = c.a; d = c.b; b = c.g; a = c.r; x = a; y = b; z = d; w = e; }
} __attribute__((aligned(16)));
static inline float LenSq(const V4E* a) { int t; float r = 0.0f; __asm__ ("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
struct cAmbientLight { char pad[0x18]; float invLen2; char pad1C[4]; tRGBA col;
    void SetColor(const tRGBA& c) { V4E d; col.r = c.r; col.g = c.g; col.b = c.b; col.a = c.a; d.Set(c); invLen2 = 1.0f / LenSq(&d); }
};
struct cPointLight { int f0; virtual ~cPointLight(); };
struct tFxParms { char pad[0x30]; float intensity; char pad34[0xC]; };
struct cSyncBar { int x; };
struct cScreenTile { char pad[0x24]; };
struct cVisionFxMan {
    int mode;
    int reqMode;
    int flair;
    char flairTimer[0x18];
    float gamma;
    float overGamma;
    float ramp;
    char rampTimer[0x20];
    tFxParms effectParms[5];
    cAmbientLight* ambientSrc;
    cPointLight* pointSrc;
    cSyncBar syncBar;
    cScreenTile screenNoise;
    tRGBA saveAmbientCol;
    unsigned int saveContext;
};

extern "C" {
extern char g_Video[];
extern unsigned int g_DrawMode;
extern unsigned long long D_00538280;
extern unsigned long long D_00538288;
extern unsigned char D_005382C0;
extern unsigned int D_005382E8;
extern int D_00538314;
extern unsigned char D_00535D63;
void XLib_ClearScreen_tIRGBAR_bool_uint(char* x, tIRGBA* c, int b, unsigned int ctx);
void cScreenTile_Render(cScreenTile* t);
void cSyncBar_Render(cSyncBar* s);
void XLib_ScreenBlur(char* x);
}

static inline void UpdateFrame() { unsigned long long m = (unsigned long long)*(volatile unsigned int*)&D_005382E8 << 32; D_00538280 = (D_00538280 & 0xFFFFFFFF) | m; D_00538288 = (D_00538288 & 0xFFFFFFFF) | m; }

extern "C" void cVisionFxMan_DeactivateFx(cVisionFxMan* self)
{
    tIRGBA igamma;
    if (self->ambientSrc) {
        cAmbientLight* l = self->ambientSrc;
        tRGBA& c = self->saveAmbientCol;
        V4E d;
        l->col.r = c.r; l->col.g = c.g; l->col.b = c.b; l->col.a = c.a;
        d.Set(c);
        l->invLen2 = 1.0f / LenSq(&d);
        self->ambientSrc = 0;
    }
    if (self->pointSrc) {
        delete self->pointSrc;
        self->pointSrc = 0;
    }
    float og = self->overGamma; float g = self->gamma;
    if (g + og > 0.0f) {
        float in = self->effectParms[self->mode].intensity;
        igamma.a = (int)(128.0f * (g + og * (1.0f - g)));
        float v = 255.0f * in;
        igamma.b = (int)v; igamma.g = (int)v; igamma.r = (int)v;
        XLib_ClearScreen_tIRGBAR_bool_uint(g_Video, &igamma, 0, 2);
    }
    g_DrawMode = self->saveContext;
    D_005382E8 = 0xFF000000;
    UpdateFrame();
    D_005382C0 = 1;
    D_00538314 = 1;
    switch (self->mode) {
    case 0:
        break;
    case 1:
        D_00535D63 = 1;
        cScreenTile_Render(&self->screenNoise);
        cSyncBar_Render(&self->syncBar);
        XLib_ScreenBlur(g_Video);
        break;
    case 2:
        D_00535D63 = 1;
        cScreenTile_Render(&self->screenNoise);
        cSyncBar_Render(&self->syncBar);
        XLib_ScreenBlur(g_Video);
        break;
    case 3:
        break;
    case 4:
        break;
    }
}
