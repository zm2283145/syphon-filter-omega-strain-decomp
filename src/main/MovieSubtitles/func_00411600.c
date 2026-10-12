#include "types.h"

typedef struct { float u0; float u1; float v0; float v1; } Glyph411600;
typedef struct {
    int tex;                     /* 0x000 */
    char pad004[0x8C];
    unsigned char h90;           /* 0x090 */
    char pad091[3];
    float space;                 /* 0x094 */
    char pad098;
    unsigned char h99;           /* 0x099 */
    char pad09A[2];
    int stride;                  /* 0x09C */
    Glyph411600 glyphs[180];     /* 0x0A0 */
    unsigned char hasKern;       /* 0xBE0 */
    signed char kern[1];         /* 0xBE1 */
} Font411600;
typedef struct { char pad[4]; unsigned short h; } Tex411600;
typedef struct { char pad[0x44]; Tex411600* tex; } TexEnt411600;
typedef struct { char pad[8]; TexEnt411600** ents; } TexMgr411600;
extern TexMgr411600* D_00539248;

void func_00411600(Font411600* f, const char* s, const char* end, float* w, float* h)
{
    float th, scale, tw, adv;
    int c;
    if (*s == 0) {
        *w = 0;
        *h = 0;
        return;
    }
    tw = 0.0f;
    th = f->h99 * f->h90;
    scale = (int)D_00539248->ents[f->tex]->tex->h;
    while ((c = *(unsigned char*)s) != 0 && s != end) {
        adv = 2.0f;
        if (c != ' ') {
            int idx = c - 0x21;
            tw += f->glyphs[idx].u1 * scale - f->glyphs[idx].u0 * scale;
            if (f->hasKern) {
                unsigned char n = s[1];
                int k = (signed char)(n - 0x21);
                if (k != 0 && n != ' ') {
                    adv = 2.0f - f->kern[(signed char)k + f->stride * idx];
                }
            }
        } else {
            adv = f->space;
        }
        s++;
        tw += adv;
    }
    *w = tw;
    *h = th;
}




