#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* cWaterFx::CreateWaterBaseCVs: fills the 4x4 water base grid - positions over [-0.5,0.5]
   (y from top), texture coordinates over [0,1] and a random colour per control vertex. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { Q16(this, &o); }
    cVector& operator=(const cVector& o) { cVector* d = this; Q16(d, &o); return *this; }
} __attribute__((aligned(16)));
struct tUV { float u, v, q, p; tUV() {} tUV(float a, float b, float c, float d) { u = a; v = b; q = c; p = d; } };
struct tRGBA { float r, g, b, a; tRGBA() {} tRGBA(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
struct cWaterFx { cVector waterBaseCVs[16]; tUV waterBaseUVs[16]; tRGBA waterBaseCols[16]; };
extern "C" {
int Libc_Rand(void);
void cWaterFx_CreateWaterBaseCVs(cWaterFx* self);
}
static inline float RandRange(float lo, float hi) { float range = hi - lo; float t = range * ((float)Libc_Rand() / 2147483648.0f); return t + lo; }
void cWaterFx_CreateWaterBaseCVs(cWaterFx* self)
{
    int idx = 0;
    float cy = 0.5f;
    float cv = 0.0f;
    int y;
    for (y = 0; y < 4; y++) {
        float cx = -0.5f;
        float cu = 0.0f;
        int x;
        for (x = 0; x < 4; x++) {
            self->waterBaseCVs[idx] = cVector(cx, cy, 0.0f, 1.0f);
            self->waterBaseUVs[idx] = tUV(cu, cv, 1.0f, 0.0f);
            self->waterBaseCols[idx] = tRGBA(RandRange(0.0f, 1.0f), RandRange(0.0f, 1.0f), RandRange(0.0f, 1.0f), 1.0f);
            idx++;
            cx += 1.0f / 3.0f;
            cu += 1.0f / 3.0f;
        }
        cy -= 1.0f / 3.0f;
        cv += 1.0f / 3.0f;
    }
}
