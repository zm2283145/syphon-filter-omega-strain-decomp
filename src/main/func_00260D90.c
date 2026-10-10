#include "types.h"
typedef struct { float t, r, g, b; } F260D90_Key;
extern unsigned char D_004F8258;
extern unsigned char D_004F8230;
extern F260D90_Key D_004F8190[];
extern F260D90_Key D_004F80F0[];
extern float D_0048B0A8;
extern float D_0048B0A0;
void func_00260D90(float* out, float x) {
    int i;
    unsigned char alt = D_004F8258 && D_004F8230;
    F260D90_Key* tab = alt ? D_004F8190 : D_004F80F0;
    for (i = 0; i < 9; i++) {
        float t1 = tab[i + 1].t;
        if (x < t1) {
            F260D90_Key* k = &tab[i];
            float f = (x - k[0].t) / (t1 - k[0].t);
            float r = ((1.0f - f) * k[0].r + f * k[1].r) / 255.0f;
            float g = ((1.0f - f) * k[0].g + f * k[1].g) / 255.0f;
            float b = ((1.0f - f) * k[0].b + f * k[1].b) / 255.0f;
            float a = alt ? D_0048B0A8 : D_0048B0A0;
            out[0] = r;
            out[1] = g;
            out[2] = b;
            out[3] = a;
            return;
        }
    }
}