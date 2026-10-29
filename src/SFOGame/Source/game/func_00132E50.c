#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V4 { float x, y, z, w; V4() {} V4(const V4& o, int) { x = o.x; y = o.y; z = o.z; w = o.w; } V4(const V4& o) { float ty, tz, tw, tx; tw = o.w; tz = o.z; ty = o.y; tx = o.x; w = tw; z = tz; y = ty; x = tx; } };
struct Mq { __int128 q[4]; Mq() {} };
struct Slot { char pad[0x1F0]; V4 col; char pad200[0x2E4 - 0x200]; float f2E4; int pad2E8; float f2EC; float f2F0; char f2F4; char f2F5; char f2F6; };
struct Rs { char pad[0xA80]; Mq mtx[1]; };
struct Fog { char pad0[0x64]; float x64; char pad68[0x14]; unsigned char b7C; };
struct Env { char pad0[0xC]; Fog* fog; unsigned char b10; char pad11[0xB]; float t; char pad20[0x18]; float a; float b; };
struct Cam { char pad0[0x60]; float x60; };
struct CamHolder { char pad0[8]; Cam* cam; };
struct World {
    char pad0[0x84];
    Env* env;
    char pad88[0xCC - 0x88];
    CamHolder* ch;
    char padD0[0xD9 - 0xD0];
    unsigned char bD9;
    char padDA[2];
    int xDC;
    char padE0[8];
    int xE8;
};

extern "C" {
extern char g_Video[];
extern int g_DrawMode;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int D_00543790;
extern int D_00543794;
extern long D_005392D8;
extern long D_004BC1B0;
void* cGOBJ_GetXform_void(void* o);
Mq cXform_GetInverseMatrix(void* xf);
int GetSceneManager(void);
void cSceneManager_UpdateActivation(int z);
void cSceneManager_Render(int z);
void cBulletManager_Render(void);
void func_0025C650(void);
void cAirTaser_RenderAll(void);
void cHud_Render(int x);
void cScreenFader_Render(int x, int y);
void cGameSystem_Render(World* self);
}

#define RS ((Rs*)g_Video)
#define SLOT(i) ((Slot*)(g_Video + (i) * 0x110))

static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void SetTop(const Mq& m) { const Mq* xx = &m; QR(&RS->mtx[D_00538C64], (void*)&m); }

static inline float FogDensity(World* self)
{
    Env* e = self->env;
    if (e->b10) return e->a + e->t * (e->b - e->a);
    return e->fog->x64 + 0;
}

static inline Cam* SetView(V4 c, World* self)
{
    V4* p = &c;
    Slot* s = SLOT(D_00538C60);
    Cam* cam = self->ch->cam;
    s->col.x = p->x;
    s->col.y = p->y;
    s->col.z = p->z;
    s->col.w = p->w;
    s->f2F5 = 1;
    s->f2F6 = 1;
    Fog* fg = self->env->fog;
    float fa = cam->x60;
    float fx = fg->x64;
    s->f2F0 = fa;
    s->f2E4 = 2.0f;
    s->f2EC = 12.0f + fx;
    s->f2F6 = 1;
    s->f2F4 = 0;
    return cam;
}
void cGameSystem_Render(World* self)
{
    int mode = 0x75;
    Cam* cam;
    float f;
    {
        Env* e = self->env;
        if (e->b10) f = e->a + e->t * (e->b - e->a);
        else f = *(float*)((char*)e->fog + 0x6C);
    }
    if (!(f <= 0.0f)) {
        if (self->env->fog->b7C) mode |= 0x100;
        else mode |= 0x80;
    }
    g_DrawMode = mode;
    D_005392D8 = D_004BC1B0;
    D_00543790 = 2;
    D_00543794 = 4;
    {
        V4 c(SLOT(*(volatile int*)&D_00538C60)->col, 0);
        D_00538C60++;
        SLOT(D_00538C60)->f2F6 = 1;
        cam = SetView(c, self);
    }
    QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
    D_00538C64++;
    SetTop(cXform_GetInverseMatrix(cGOBJ_GetXform_void(cam)));
    D_00538C68 = 1;
    cSceneManager_UpdateActivation(GetSceneManager());
    if (!self->bD9) {
        cSceneManager_Render(GetSceneManager());
        cBulletManager_Render();
        func_0025C650();
        cAirTaser_RenderAll();
    }
    cHud_Render(self->xDC);
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    SLOT(D_00538C60)->f2F6 = 1;
    cScreenFader_Render(self->xE8, 1);
}
