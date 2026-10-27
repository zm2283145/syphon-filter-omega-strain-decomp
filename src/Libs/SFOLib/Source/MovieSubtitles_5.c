/*
 * main/MovieSubtitles: range (3 files, 00411860-00411DB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_00411860 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct DmaBuf {
    int unk00;
    unsigned int packet; /* 0x04 */
    int unk08;
} DmaBuf; /* size 0x0C */

typedef struct DblBuf {
    DmaBuf bufs[2];        /* 0x00 */
    int current;           /* 0x18 */
    unsigned int tag;      /* 0x1C */
    unsigned int cur;      /* 0x20 */
    unsigned long long* tags[4]; /* 0x24 */
} DblBuf;

extern "C" void cMovieSubtitles_PatchDma(DblBuf* db, int i, int j) {
    unsigned long long* p = db->tags[j + i * 2];
    bool other;
    *p &= 0x8FFFFFFF;
    *p |= 0x20000000;
    other = !db->current;
    *p |= (unsigned long long)db->bufs[other].packet << 32;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00411860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00411860 */

/* merge_units: begin func_004118E0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef unsigned long long u64_18E0;
typedef struct { float x, y, z, w; } Vec_18E0;
typedef struct { int unk00; u64_18E0* packet; int unk08; } DmaBuf_18E0;
typedef struct { char pad[0x50]; u64_18E0 tex0; } TexEnt_18E0;
typedef struct { char pad[8]; TexEnt_18E0** ents; } TexMgr_18E0;
typedef struct { int tex; } Font_18E0;
typedef struct {
    DmaBuf_18E0 bufs[2];  /* 0x00 */
    int current;          /* 0x18 */
    u64_18E0* pkt;        /* 0x1C */
    u64_18E0* base;       /* 0x20 */
    int a, b, c, d;       /* 0x24 */
    unsigned char ready;  /* 0x34 */
    char pad35[0xB];
    char f40[8];          /* 0x40 */
    float w;              /* 0x48 */
    float h;              /* 0x4C */
    char pad50[4];
    Font_18E0* font;      /* 0x54 */
    char pad58[8];
    char* text[3];        /* 0x60 */
    char* cur[3];         /* 0x6C */
    int count;            /* 0x78 */
    char pad7C[4];
    Vec_18E0 color;       /* 0x80 */
    char pad90[0x14];
    int flags;            /* 0xA4 */
    char padA8[4];
    unsigned char active; /* 0xAC */
    char padAD[3];
    unsigned char showTime; /* 0xB0 */
    char padB1[3];
    float time;           /* 0xB4 */
} Sub_18E0;

extern "C" {
extern TexMgr_18E0* g_TextureMgr;
extern char D_004BEF10[];
extern char D_004BEF20[];
extern u64_18E0* cTexture_GetTEX1_1(TexEnt_18E0* e);
extern void cSubtitleFont_GetBounds(Font_18E0* f, const char* s, const char* end, float* w, float* h);
extern u64_18E0* cSubtitleFont_Display(Font_18E0* f, u64_18E0* pkt, float x, const char* s, float y, Vec_18E0* color, void* p, const char* end);
extern float Libc_Fmodf(float a, float b);
extern void FlushCache(int mode);
extern void DIntr(void);
extern void EIntr(void);
}

#pragma opt_dead_assignments off
static inline bool CanDraw(Sub_18E0* s) { return s->font != 0 && s->active != 0; }
extern "C" void cMovieSubtitles_Render(Sub_18E0* self)
{
    if (self->ready) {
        self->pkt++;
        self->pkt++;
        self->pkt++;
        self->pkt++;
        *self->pkt++ = g_TextureMgr->ents[self->font->tex]->tex0;
        *self->pkt++ = 6;
        *self->pkt++ = *cTexture_GetTEX1_1(g_TextureMgr->ents[self->font->tex]);
        *self->pkt++ = 0x14;
        *self->pkt++ = 0x44;
        *self->pkt++ = 0x42;
        *self->pkt++ = 0x1D6;
        *self->pkt++ = 0;
        if (CanDraw(self)) {
            float tw;
            float th;
            float xs[3];
            float ys[3];
            int n = 0;
            int i;
            int j;
            int k;
            if (self->flags & 8) {
                for (i = 0; i < self->count; i++) {
                    if (self->cur[i]) n++;
                }
            } else {
                n = self->count;
            }
            for (j = 0; j < n; j++) {
                xs[j] = 0.5f * -self->w;
                ys[j] = 0.5f * -self->h;
                cSubtitleFont_GetBounds(self->font, self->text[j], self->cur[j], &tw, &th);
                ys[j] += (4.0f + th) * (float)(n - j);
                if (self->flags & 4) {
                    float d = self->w - tw;
                    xs[j] += 0.5f * ((0.0f > d) ? 0.0f : d);
                }
            }
            for (k = 0; k < n; k++) {
                self->pkt = cSubtitleFont_Display(self->font, self->pkt, xs[k], self->text[k], ys[k], &self->color, self->f40, self->cur[k]);
            }
        }
        if (self->showTime) {
            Vec_18E0 c;
            float t = self->time;
            float m = t / 60.0f;
            float s = Libc_Fmodf(t, 60.0f);
            float f = Libc_Fmodf(10.0f * s, 10.0f);
            sprintf(D_004BEF20, D_004BEF10, (int)m, (int)s, (int)f);
            c.w = 0.5f;
            c.x = 1.0f;
            c.y = 1.0f;
            c.z = 1.0f;
            self->pkt = cSubtitleFont_Display(self->font, self->pkt, 200.0f, D_004BEF20, 218.0f, &c, self->f40, 0);
        }
        {
            int qwc = ((self->pkt - self->base) >> 1) - 1;
            self->base[0] = (unsigned int)(qwc | 0x10000000);
            self->base[1] = 0;
            self->base[2] = (long long)(qwc - 1) | (0x8000 | (0x10000000ULL << 32));
            self->base[3] = 0xE;
        }
        FlushCache(0);
        *self->pkt++ = 0x70000000;
        *self->pkt++ = 0;
        DIntr();
        self->current ^= 1;
        self->base = self->bufs[self->current].packet;
        self->pkt = (u64_18E0*)((unsigned int)self->base | 0x20000000);
        EIntr();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004118E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004118E0 */

/* merge_units: begin func_00411DB0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { float x, y, z, w; } Vec411DB0;
typedef struct {
    char pad00[0x50];
    void* src;           /* 0x50 */
    char pad54[0x8];
    char* textm1;        /* 0x5C */
    char* text[3];       /* 0x60 */
    char* cur[3];        /* 0x6C */
    int count;           /* 0x78 */
    char pad7C[4];
    Vec411DB0 color;     /* 0x80 */
    int len[3];          /* 0x90 */
    float start;         /* 0x9C */
    float stop;          /* 0xA0 */
    int flags;           /* 0xA4 */
    int fA8;             /* 0xA8 */
    unsigned char active;/* 0xAC */
    char padAD[7];
    float time;          /* 0xB4 */
} Sub411DB0;

extern "C" {
extern unsigned int D_0055C5A8;
extern int cSubtitleFeed_ItemPending(void* src);
extern int cSubtitleFeed_GetDisplayFlags(void* src);
extern int cSubtitleFeed_GetNumLines(void* src);
extern char* cSubtitleFeed_GetText(void* src, int i);
extern Vec411DB0* cSubtitleFeed_GetColor(void* src);
extern void tRGBA_opAssign(Vec411DB0* d, Vec411DB0* s);
extern float cSubtitleFeed_GetStartTime(void* src);
extern float cSubtitleFeed_GetEndTime(void* src);
extern int cSubtitleFeed_GetLanguage(void* src);
extern void cSubtitleFeed_NextItem(void* src);
extern void cMovieSubtitles_ResetText(Sub411DB0* s);
}

extern "C" void cMovieSubtitles_NextFrame(Sub411DB0* s)
{
    int j;
    int i;
    if (!(s->time < s->start)) {
        if (s->time < s->stop) {
            s->active = 1;
            if (s->flags & 8) {
                for (i = 0; i < s->count; i++) {
                    if (s->cur[i] == 0) {
                        bool flag = false;
                        if (i == 0) {
                            flag = true;
                        } else if (s->cur[i - 1] == s->text[i - 1] + s->len[i - 1]) {
                            s->start = s->time;
                            flag = true;
                        }
                        if (flag) s->cur[i] = s->text[i];
                    }
                    {
                        char* e;
                        char* c;
                        char* t = s->text[i];
                        int n = s->len[i];
                        e = t + n;
                        if ((c = s->cur[i]) != 0 && c < e) {
                            float q = (s->time - s->start) / (0.1f * n);
                            s->cur[i] = t + (int)(q * n) + 1;
                        }
                    }
                }
            }
        }
        if (!(s->time < s->stop) && s->active) {
            s->active = 0;
            if (cSubtitleFeed_ItemPending(s->src)) {
                s->flags = cSubtitleFeed_GetDisplayFlags(s->src);
                s->count = cSubtitleFeed_GetNumLines(s->src);
                for (j = 0; j < s->count; j++) {
                    s->text[j] = cSubtitleFeed_GetText(s->src, j);
                    s->len[j] = strlen(s->text[j]);
                    s->cur[j] = 0;
                }
                tRGBA_opAssign(&s->color, cSubtitleFeed_GetColor(s->src));
                s->start = cSubtitleFeed_GetStartTime(s->src);
                s->stop = cSubtitleFeed_GetEndTime(s->src);
                s->fA8 = cSubtitleFeed_GetLanguage(s->src);
                cSubtitleFeed_NextItem(s->src);
            } else {
                cMovieSubtitles_ResetText(s);
            }
            if (!(s->time < s->start)) s->active = 1;
        }
    }
    s->time = (float)D_0055C5A8 / 60.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00411DB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00411DB0 */
