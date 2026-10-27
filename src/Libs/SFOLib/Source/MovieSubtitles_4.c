/*
 * Libs/SFOLib/Source/MovieSubtitles: 5 files, 00411500-004117A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00411500 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4 cMatrix_opMul_cVectorR(void* m, V4* vp) {
    V4 v;
    V4* p; V4* d;
    d = &v; VCopyF(d, vp);
    p = &v;
    asm {
        lqc2 vf8, 0x0(p)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(p)
    }
    return *p;
}
#pragma pop
static inline void merge_flush_func_00411500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00411500 */

/* merge_units: begin func_00411550 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "MovieSubtitles_types.h"

extern void cXViewport_Validate(SubtitleEntry* entry);
extern float XLib_UpdateCompMat(SubtitleOwner* owner);

char* XLib_GetCompMat(SubtitleOwner* owner) {
    XLib_UpdateCompMat(owner);
    return owner->unkEC0;
}

/* Updates the current entry and returns its block at +0xA0. */
char* XLib_GetVPOffset(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    cXViewport_Validate(entry);
    return entry->unk0A0;
}

/* Updates the current entry and returns its block at +0x90. */
char* XLib_GetVPScale(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    cXViewport_Validate(entry);
    return entry->unk090;
}
static inline void merge_flush_func_00411550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00411550 */

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

void cSubtitleFont_GetBounds(Font411600* f, const char* s, const char* end, float* w, float* h)
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

/* merge_units: begin func_004117A0 */
#pragma push /* merge_units */
typedef struct DmaBuf {
    int unk00;
    unsigned long long* packet; /* 0x04 */
    int unk08;
} DmaBuf; /* size 0x0C */

typedef struct DblBuf {
    DmaBuf bufs[2];        /* 0x00, packet ptrs at 0x04 / 0x10 */
    int current;           /* 0x18 */
    unsigned int tag;      /* 0x1C */
    unsigned int cur;      /* 0x20 */
    int a;                 /* 0x24 */
    int b;                 /* 0x28 */
    int c;                 /* 0x2C */
    int d;                 /* 0x30 */
    unsigned char ready;   /* 0x34 */
} DblBuf;

extern void DIntr(void);
extern void EIntr(void);

/* Initializes a double-buffered DMA packet chain when all four parameters are set. */
void cMovieSubtitles_GraftDma(DblBuf* db, int a, int b, int c, int d) {
    if (a && b && c && d) {
        db->a = a;
        db->b = b;
        db->c = c;
        db->d = d;
        db->bufs[0].packet[0] = 0x70000000;
        db->bufs[0].packet[1] = 0;
        db->bufs[1].packet[0] = 0x70000000;
        db->bufs[1].packet[1] = 0;
        db->current = 1;
        DIntr();
        db->current ^= 1;
        db->cur = (unsigned int)db->bufs[db->current].packet;
        db->tag = db->cur | 0x20000000;
        EIntr();
        db->ready = 1;
    }
}
static inline void merge_flush_func_004117A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004117A0 */
