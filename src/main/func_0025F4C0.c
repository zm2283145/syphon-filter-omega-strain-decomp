#pragma cplusplus on
#include "types.h"

struct LightBase_F4C0 { int x0; };
struct Light_F4C0 : LightBase_F4C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual float SizeFactor();
    virtual unsigned char Flag();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual float Range();
    char pad8[0x1D - 0x8];
    unsigned char aux;
    char pad1E[0x20 - 0x1E];
    float color[4];
    float pos[4];
};

typedef struct { Light_F4C0* light; int pad; } LightEnt_F4C0;
typedef struct { char pad[0x2000]; LightEnt_F4C0 e[1]; } LightTab_F4C0;
typedef struct { int mode; char pad4[0x194 - 4]; Light_F4C0* skip; char pad198[0x1D4 - 0x198]; int tex[9]; } VisionFx_F4C0;

extern "C" {
extern char g_LightMgr[];
extern int D_00535D70;
extern LightTab_F4C0* D_00535D74;
extern float D_004A7DE0[9][4];
extern char g_Video[];
extern int D_004A7E70[];
extern float D_004A7EA0[];
void cLightMan_AquireSourcesByProperty(void* m, int a, int b, int c);
void XLib_DrawLensFlares(void* a, float* pos, float (*col)[4], int* tex, int* t0, float* t1, int n, float size, int flag, int vflag);
}

extern "C" void cVisionFxMan_DrawLensFlares(VisionFx_F4C0* fx) {
    float cols[9][4];
    int b = 0;
    int a = 0;
    int c = 0;
    float alpha = 1.0f;
    int i;
    float* col;
    int n;
    int vflag;
    int j;
    float size;
    Light_F4C0* l;
    int flag;
    float* pos;
    switch (fx->mode) {
    case 0:
        c = 1;
        a = 0x54;
        b = 0x18;
        break;
    case 1:
    case 2:
        a = 0x44;
        b = 0xFF;
        c = 1;
        alpha = 0.7f;
        break;
    }
    cLightMan_AquireSourcesByProperty(g_LightMgr, a, b, c);
    for (i = 0; i < D_00535D70; i++) {
        l = D_00535D74->e[i].light;
        if (l != fx->skip) {
            pos = l->pos;
            col = l->color;
            size = 0.5f * l->Range();
            if ((l->aux & 8) > 0) n = 9;
            else n = 1;
            for (j = 0; j < n; j++) {
                cols[j][0] = col[0] * D_004A7DE0[j][0];
                cols[j][1] = col[1] * D_004A7DE0[j][1];
                cols[j][2] = col[2] * D_004A7DE0[j][2];
                cols[j][3] = alpha * D_004A7DE0[j][3];
            }
            flag = (l->aux & 0x10) > 0;
            vflag = l->Flag();
            if (flag) size *= l->SizeFactor();
            XLib_DrawLensFlares(g_Video, pos, cols, fx->tex, D_004A7E70, D_004A7EA0, n, size, flag, vflag);
        }
    }
}
