#include "types.h"
typedef struct {
    float x, y, w, h;
    char pad10[0x90 - 0x10];
    float vs[4];
    float vo[4];
    char padB0[0x104 - 0xB0];
    unsigned char ortho;
    unsigned char useView;
    unsigned char dirty;
    char pad107;
    long scissor;
} Vp374;
extern char g_Video[];
extern void cXViewport_BuildPersp(Vp374*);
extern void cXViewport_BuildOrtho(Vp374*);
extern float XLib_GetZBuffMin(char*);
extern float XLib_GetZBuffMax(char*);
extern float XLib_GetGuardBandScaleY(char*);
extern float XLib_GetGuardBandScaleX(char*);
extern float* XLib_GetFullscreenWindow(char*);
extern float XLib_GetDisplayOffY(char*);
extern float XLib_GetFrameBuffOffY(char*);
extern float XLib_GetDisplayOffX(char*);
extern float XLib_GetFrameBuffOffX(char*);
extern float XLib_GetDisplaySclY(char*);
extern float XLib_GetFrameBuffSclY(char*);
extern float XLib_GetDisplaySclX(char*);
extern float XLib_GetFrameBuffSclX(char*);
extern int nSFO_Macros_FTOI(float);

void cXViewport_Validate(Vp374* self) {
    float sx, sy, ox, oy, w, h;
    float a, b, c, half, hw, hh;
    float l, t, r, bt;
    int x0, x1, y0, y1;
    if (self->dirty == 0) return;
    if (self->ortho == 0)
        cXViewport_BuildPersp(self);
    else
        cXViewport_BuildOrtho(self);
    sx = self->useView ? XLib_GetFrameBuffSclX(g_Video) * XLib_GetDisplaySclX(g_Video) : 1.0f;
    sy = self->useView ? XLib_GetFrameBuffSclY(g_Video) * XLib_GetDisplaySclY(g_Video) : 1.0f;
    ox = self->useView ? XLib_GetFrameBuffOffX(g_Video) + XLib_GetDisplayOffX(g_Video) : 0.0f;
    oy = self->useView ? XLib_GetFrameBuffOffY(g_Video) + XLib_GetDisplayOffY(g_Video) : 0.0f;
    w = self->useView ? XLib_GetFullscreenWindow(g_Video)[2] : self->w;
    h = self->useView ? XLib_GetFullscreenWindow(g_Video)[3] : self->h;
    a = XLib_GetGuardBandScaleX(g_Video);
    b = XLib_GetGuardBandScaleY(g_Video);
    c = XLib_GetZBuffMax(g_Video);
    half = 0.5f * (c - XLib_GetZBuffMin(g_Video));
    hw = 0.5f * self->w;
    hh = 0.5f * self->h;
    self->vs[0] = 16.0f * (a * (hw * sx));
    self->vs[1] = 16.0f * (b * (-hh * sy));
    self->vs[2] = 16.0f * -half;
    self->vs[3] = 1.0f;
    self->vo[0] = 16.0f * (2048.0f + (((0.5f * w - hw) - self->x) - ox));
    self->vo[1] = 16.0f * (2048.0f + (((0.5f * h - hh) - self->y) - oy));
    self->vo[2] = 16.0f * (half + XLib_GetZBuffMin(g_Video));
    self->vo[3] = 0.0f;
    sx = XLib_GetFrameBuffSclX(g_Video);
    sy = XLib_GetFrameBuffSclY(g_Video);
    ox = XLib_GetFrameBuffOffX(g_Video);
    oy = XLib_GetFrameBuffOffY(g_Video);
    l = ox + self->x * sx;
    t = oy + self->y * sy;
    r = ox + (l + self->w * sx);
    bt = oy + (t + self->h * sy);
    x0 = nSFO_Macros_FTOI(l);
    x1 = nSFO_Macros_FTOI(r) - 1;
    y0 = nSFO_Macros_FTOI(t);
    y1 = nSFO_Macros_FTOI(bt) - 1;
    self->scissor = ((long)y1 << 48) | (((long)y0 << 32) | ((long)x0 | ((long)x1 << 16)));
    self->dirty = 0;
}

