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
extern char D_005381F0[];
extern void Renderer_LevelCameraProjection(Vp374*);
extern void Renderer_OrthoCameraProjection(Vp374*);
extern float func_003751A0(char*);
extern float func_003751B0(char*);
extern float func_003751C0(char*);
extern float func_003751E0(char*);
extern float* func_00375200(char*);
extern float func_00375210(char*);
extern float func_00375240(char*);
extern float func_00375270(char*);
extern float func_003752A0(char*);
extern float func_003752D0(char*);
extern float func_00375300(char*);
extern float func_00375330(char*);
extern float func_00375360(char*);
extern int Math_TruncFloatSat(float);

void Renderer_RefreshCamera(Vp374* self) {
    float sx, sy, ox, oy, w, h;
    float a, b, c, half, hw, hh;
    float l, t, r, bt;
    int x0, x1, y0, y1;
    if (self->dirty == 0) return;
    if (self->ortho == 0)
        Renderer_LevelCameraProjection(self);
    else
        Renderer_OrthoCameraProjection(self);
    sx = self->useView ? func_00375360(D_005381F0) * func_00375330(D_005381F0) : 1.0f;
    sy = self->useView ? func_00375300(D_005381F0) * func_003752D0(D_005381F0) : 1.0f;
    ox = self->useView ? func_003752A0(D_005381F0) + func_00375270(D_005381F0) : 0.0f;
    oy = self->useView ? func_00375240(D_005381F0) + func_00375210(D_005381F0) : 0.0f;
    w = self->useView ? func_00375200(D_005381F0)[2] : self->w;
    h = self->useView ? func_00375200(D_005381F0)[3] : self->h;
    a = func_003751E0(D_005381F0);
    b = func_003751C0(D_005381F0);
    c = func_003751B0(D_005381F0);
    half = 0.5f * (c - func_003751A0(D_005381F0));
    hw = 0.5f * self->w;
    hh = 0.5f * self->h;
    self->vs[0] = 16.0f * (a * (hw * sx));
    self->vs[1] = 16.0f * (b * (-hh * sy));
    self->vs[2] = 16.0f * -half;
    self->vs[3] = 1.0f;
    self->vo[0] = 16.0f * (2048.0f + (((0.5f * w - hw) - self->x) - ox));
    self->vo[1] = 16.0f * (2048.0f + (((0.5f * h - hh) - self->y) - oy));
    self->vo[2] = 16.0f * (half + func_003751A0(D_005381F0));
    self->vo[3] = 0.0f;
    sx = func_00375360(D_005381F0);
    sy = func_00375300(D_005381F0);
    ox = func_003752A0(D_005381F0);
    oy = func_00375240(D_005381F0);
    l = ox + self->x * sx;
    t = oy + self->y * sy;
    r = ox + (l + self->w * sx);
    bt = oy + (t + self->h * sy);
    x0 = Math_TruncFloatSat(l);
    x1 = Math_TruncFloatSat(r) - 1;
    y0 = Math_TruncFloatSat(t);
    y1 = Math_TruncFloatSat(bt) - 1;
    self->scissor = ((long)y1 << 48) | (((long)y0 << 32) | ((long)x0 | ((long)x1 << 16)));
    self->dirty = 0;
}

