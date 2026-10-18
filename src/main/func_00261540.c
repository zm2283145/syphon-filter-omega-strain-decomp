#include "types.h"
typedef struct { char pad[0x30]; float f30; } O_1540;
typedef struct { int pad0; float cur; } M_1540;
typedef struct { O_1540* obj; int pad4; M_1540* a; M_1540* b; } S_1540;
extern float Game_GetDangerMag(O_1540* o);
extern void IeElement_PlayRange(M_1540* m, float lo, float hi, unsigned char fl);
extern void IeElement_Fade(M_1540* m, float v);
extern int D_0048B0B0;
extern int D_0048B0B8;
extern int D_004F8260;

static inline float fmin_(float a, float b)
{
    float r;
    /* EE minimum has no equivalent CodeWarrior C intrinsic. */
    asm { min.s r, a, b }
    return r;
}

void HudRadar_SetMeter(S_1540* s, int sel, float scale)
{
    M_1540* m;
    float f;
    if (sel) {
        m = s->b;
    } else {
        m = s->a;
    }
    f = scale * Game_GetDangerMag(s->obj);
    f = fmin_(f, 1.0f);
    if (!sel) {
        s->obj->f30 = 1.0f;
    }
    if (m) {
        if (f > 0.98f) {
            IeElement_PlayRange(m, (float)D_0048B0B0, (float)D_0048B0B8, 1);
            if (!sel) {
                s->obj->f30 = ((float)D_0048B0B8 - *(volatile float*)&m->cur) / (float)(D_0048B0B8 - D_0048B0B0);
            }
        } else {
            float delta = (float)(D_0048B0B0 - D_004F8260);
            delta *= f;
            IeElement_Fade(m, (float)(int)((float)D_004F8260 + delta));
        }
    }
}
