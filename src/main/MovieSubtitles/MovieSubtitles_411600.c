/*
 * main/MovieSubtitles: range (2 files, 00411600-00411730)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00411600 */
#pragma push /* merge_units */
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
extern TexMgr411600* g_TextureMgr;

void SubtitleOverlay_MeasureLine(Font411600* f, const char* s, const char* end, float* w, float* h)
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
    scale = (int)g_TextureMgr->ents[f->tex]->tex->h;
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00411600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00411600 */

/* merge_units: begin func_00411730 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern void * const D_004E08B8[];
void cFont_dtor(void* self, int flags);
void operator_delete(void* p);
}
struct V411730 { char pad[0x8A74]; void* vtable; };
extern "C" V411730* cSubtitleFont_dtor(V411730* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E08B8);
        cFont_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E08B8[3] = { (void*)0x0, (void*)0x0, (void*)cSubtitleFont_dtor };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00411730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00411730 */
