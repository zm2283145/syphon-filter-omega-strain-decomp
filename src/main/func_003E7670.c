#include "types.h"
/* cInterface_Render: draws the in-engine screen tree under an orthographic
 * scale (D_00493950/D_00493958) with the depth range forced to 0..1000,
 * restoring the slot state afterwards. Render-state helpers as in
 * GuiCanvas_Render (GuiCanvas_415B20.c). */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct M4 { float m[16]; } __attribute__((aligned(16))) M4;
typedef struct Slot { float color[4]; char pad10[0xF0 - 0x10]; float fF0; float fF4; float fF8; float fFC; char pad100[4]; unsigned char b104; unsigned char b105; unsigned char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;


extern "C" {
extern char g_Video[];
extern int D_00538318;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
extern unsigned char D_00493948;
extern float D_00493950;
extern float D_00493958;
extern float D_00539170[4];
void cInterfaceModel_Render(void* n);
}

#define SlotAt(i) ((Slot*)(g_Video + 0x1F0 + (i) * 0x110))
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

static inline void SetM(M4* d, float sx, float sy, float sz) { d->m[0] = sx; d->m[1] = 0.0f; d->m[2] = 0.0f; d->m[3] = 0.0f; d->m[4] = 0.0f; d->m[5] = 0.0f; d->m[6] = sy; d->m[7] = 0.0f; d->m[8] = 0.0f; d->m[9] = 1.0f; d->m[10] = 0.0f; d->m[11] = 0.0f; d->m[12] = 0.0f; d->m[13] = 0.0f; d->m[14] = sz; d->m[15] = 1.0f; }
struct IeScreen { void* root; };
extern "C" int cInterface_Render(IeScreen* self)
{
    if (D_00493948) {
        M4 m;
        int save;
        float f0, f8;
        D_00538318 = 0;
        { long long t = D_004BC1B0; int i = D_00538C64; D_005392D8 = t; GQR(MtxAt(i + 1), MtxAt(i)); }
        D_00538C64++;
        UM(MtxAt(D_00538C64));
        D_00538C68 = 1;
        save = g_DrawMode;
        {
            Slot* s;
            float* v;
            int i;
            v = D_00539170;
            i = D_00538C60;
            s = SlotAt(i);
            s->color[0] = v[0];
            s->color[1] = v[1];
            s->color[2] = v[2];
            s->color[3] = v[3];
            s->b105 = 1;
            s->b106 = 1;
            f0 = s->b104 ? s->fF0 : s->fF4;
            f8 = s->b104 ? s->fF8 : s->fFC;
            s->fF0 = 0.0f;
            s->fF8 = 1000.0f;
            s->b106 = 1;
            s->b104 = 1;
            SetM(&m, D_00493950, D_00493950, D_00493958);
            { Mtx* c = MtxAt(D_00538C64); MM(c, c, &m); }
            D_00538C68 = 1;
            cInterfaceModel_Render(self->root);
            s->fF0 = f0;
            s->fF8 = f8;
            s->b106 = 1;
            s->b104 = 1;
        }
        g_DrawMode = save;
        D_00538C68 = 1;
        D_00538C64--;
    }
    return 1;
}
