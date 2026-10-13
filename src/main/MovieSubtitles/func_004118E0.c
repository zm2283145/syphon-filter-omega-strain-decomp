#pragma cplusplus on
#include "types.h"

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
extern TexMgr_18E0* D_00539248;
extern char D_004BEF10[];
extern char D_004BEF20[];
extern u64_18E0* func_003BB620(TexEnt_18E0* e);
extern void func_00411600(Font_18E0* f, const char* s, const char* end, float* w, float* h);
extern u64_18E0* func_00410E50(Font_18E0* f, u64_18E0* pkt, float x, const char* s, float y, Vec_18E0* color, void* p, const char* end);
extern float Math_FMod(float a, float b);
extern int sprintf(char* buf, const char* fmt, ...);
extern void FlushCache(int mode);
extern void func_001161A0(void);
extern void func_001161F8(void);
}

#pragma opt_dead_assignments off
static inline bool CanDraw(Sub_18E0* s) { return s->font != 0 && s->active != 0; }
extern "C" void func_004118E0(Sub_18E0* self)
{
    if (self->ready) {
        self->pkt++;
        self->pkt++;
        self->pkt++;
        self->pkt++;
        *self->pkt++ = D_00539248->ents[self->font->tex]->tex0;
        *self->pkt++ = 6;
        *self->pkt++ = *func_003BB620(D_00539248->ents[self->font->tex]);
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
                func_00411600(self->font, self->text[j], self->cur[j], &tw, &th);
                ys[j] += (4.0f + th) * (float)(n - j);
                if (self->flags & 4) {
                    float d = self->w - tw;
                    xs[j] += 0.5f * ((0.0f > d) ? 0.0f : d);
                }
            }
            for (k = 0; k < n; k++) {
                self->pkt = func_00410E50(self->font, self->pkt, xs[k], self->text[k], ys[k], &self->color, self->f40, self->cur[k]);
            }
        }
        if (self->showTime) {
            Vec_18E0 c;
            float t = self->time;
            float m = t / 60.0f;
            float s = Math_FMod(t, 60.0f);
            float f = Math_FMod(10.0f * s, 10.0f);
            sprintf(D_004BEF20, D_004BEF10, (int)m, (int)s, (int)f);
            c.w = 0.5f;
            c.x = 1.0f;
            c.y = 1.0f;
            c.z = 1.0f;
            self->pkt = func_00410E50(self->font, self->pkt, 200.0f, D_004BEF20, 218.0f, &c, self->f40, 0);
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
        func_001161A0();
        self->current ^= 1;
        self->base = self->bufs[self->current].packet;
        self->pkt = (u64_18E0*)((unsigned int)self->base | 0x20000000);
        func_001161F8();
    }
}
