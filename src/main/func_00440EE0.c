#include "types.h"
/* VU0 identity-matrix store (vf0/qmfc2/pexcw): no C equivalent; gcc-style asm as in GuiWeaponDisplay_ctor.c. */
static inline void VU0_UnitMatrix(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

typedef struct Mtx { float m[4][4]; } __attribute__((aligned(16))) Mtx;

typedef struct WeaponDisplay {
    char pad0[0x50];
    float angle;       /* +0x50 */
    char pad54[0xC];
    Mtx mtx;           /* +0x60 */
    char padA0[4];
    unsigned char active; /* +0xA4 */
} WeaponDisplay;

extern float D_004C0390;
extern float D_004C0394;
extern float D_004C0398;

void GuiWidget_Update(void* self, float dt);
float Math_FMod(float a, float b);
void* func_001D3E20(Mtx* m);
void Mtx_MakeAxisRotation(Mtx* m, float x, float y, float z, float a);
void Mtx_Multiply(Mtx* d, Mtx* s);

void GuiWeaponDisplay_Update(WeaponDisplay* self, float dt)
{
    Mtx rot;
    float a;
    const float kPi = 3.1415927f;
    GuiWidget_Update(self, dt);
    if (self->active) {
        self->active = 1;
        VU0_UnitMatrix(&self->mtx);
        self->angle += dt;
        self->angle = Math_FMod(self->angle, 120.0f);
        a = 3.0f * self->angle;
        a = kPi * (a / 180.0f); /* const local for kPi gives retail constant-load order */
        { Mtx* m = &self->mtx; VU0_UnitMatrix(m); }
        func_001D3E20(&rot);
        Mtx_MakeAxisRotation(&rot, D_004C0390, D_004C0394, D_004C0398, a);
        Mtx_Multiply(&self->mtx, &rot);
    }
}





