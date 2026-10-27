#pragma cplusplus on
#include "types.h"
/* cFont_Display_charP_tRGBAR_float_float_etc: draws a string as one textured sprite (two vertices) per glyph. Control
 * characters 16-23 select a colour from the font's table; characters inside the fade band
 * at either clip edge get their alpha ramped, glyphs crossing the left edge are cut (UV
 * shifted), the first glyph past the right edge ends the string; kerning pairs adjust the
 * advance. Render state and vertex emission as in GuiBitmapWidget_onRender (GenInfoObject_43C0C0.c). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
typedef struct Ent { char pad[0x28]; char* pos; char* c2C; char* c30; char* c34; } Ent;
struct TexInfo { int pad0; unsigned short w; unsigned short h; };
struct Tex { char pad[0x44]; TexInfo* info; };
struct TexMan { char pad[8]; Tex** texs; };
struct Glyph { float u0, u1, v0, v1; };
struct Font {
    int tex;
    char pad4[0xC];
    V4 colors[8];
    char pad90[4];
    float space;
    char pad98;
    unsigned char height;
    char pad9A[2];
    int count;
    Glyph glyphs[(0xBE0 - 0xA0) / 16];
    unsigned char kerning;
    signed char kern[1];
};

extern "C" {
extern char g_Video[];
extern long long D_005381F8;
/* render state block at 0x00539210, accessed as one object (keeps retail's reload of 0x0053923C) */
typedef struct G_A330 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; TexMan* f48; int pad4C[33]; int fD0;
} G_A330;
extern G_A330 D_00539210;
void cTexMan_SetActive(TexMan* m, int idx);
void XLib_NewStrip(char* r);
void XLib_NextBatchVert(char* r);
void cVector_opAssign(void* d, const void* s);
void tIRGBA_opAssign_tRGBAR(void* out, const void* in);
float tVifFloatToInt_short_4_Bias(void);
V4* cVector_ctor_float_float_float_float(V4* o, float x, float y, float z, float w);
void XLib_DrawSprites2(char* r);
void cFont_Display_charP_tRGBAR_float_float_etc(Font* f, const char* s, V4* col, float x, float y, float z, float lo, float hi, float fade);
}

#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define EntAt(i) ((Ent*)(g_Video + 0xFB0 + (i) * 0x38))
static inline Tex* TexQ(TexMan* m, int i) { return m->texs[i]; }

static inline void Emit(const V4& pos, const V4& col, float u, float v)
{
    V4 tmp;
    Ent* e;
    float uu;
    XLib_NextBatchVert(g_Video);
    e = EntAt(D_00539210.f10);
    cVector_opAssign(e->pos + (D_00539224 - 1) * 16, &pos);
    tIRGBA_opAssign_tRGBAR(e->c30 + (D_00539224 - 1) * 16, &col);
    uu = u + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(e->c34 + (D_00539224 - 1) * 16, cVector_ctor_float_float_float_float(&tmp, uu, v + tVifFloatToInt_short_4_Bias(), 1.0f, 0.0f));
    D_005381F8 = 6LL << 32;
}

void cFont_Display_charP_tRGBAR_float_float_etc(Font* f, const char* s, V4* col, float x, float y, float z, float lo, float hi, float fade)
{
    const unsigned char* p;
    int n;
    float texW;
    if (*s == 0)
        return;
    p = (const unsigned char*)s;
    texW = (int)TexQ(g_TextureMgr, f->tex)->info->w;
    g_DrawMode = 5;
    cTexMan_SetActive(g_TextureMgr, f->tex);
    D_00539228 = 0;
    D_00539238 = (unsigned char)((g_DrawMode & 1) ? 3 : 2);
    D_0053923C = (g_DrawMode & 1) ? 0x41 : 0x62;
    n = 0;
    {
        int m = D_0053923C;
        Ent* e;
        D_0053923C = m & ~1;
        e = EntAt(D_00539210.f10);
        e->pos += D_00539224 * 16;
        e->c2C += D_00539224 * 16;
        e->c30 += D_00539224 * 16;
        e->c34 += D_00539224 * 16;
        XLib_NewStrip(g_Video);
        D_00539224 = 0;
    }
    {
        V4 c;
        V4 p1;
        V4 p2;
        int ch;
        c.x = col->x;
        c.y = col->y;
        c.z = col->z;
        c.w = col->w;
        for (ch = *p; ch; ch = *p) {
            float adv;
            if (ch < 32 || ch > f->count + 32) {
                if (ch >= 16 && ch < 24) {
                    V4* cp = &f->colors[ch - 16];
                    c.x = cp->x;
                    c.y = cp->y;
                    c.z = cp->z;
                    c.w = cp->w;
                }
                p++;
                continue;
            }
            if (ch != 32) {
                int idx = ch - 33;
                Glyph* g = &f->glyphs[idx];
                float u0 = g->u0;
                float u1 = g->u1;
                float v0 = g->v0;
                float v1 = g->v1;
                float pw;
                float w = u1 - u0;
                pw = texW * w;
                bool skip = false;
                adv = 2.0f;
                if (!(fade <= 0.0f)) {
                    if (x < lo + fade)
                        c.w = col->w * (x - lo) / fade;
                    else if (!(x <= hi - fade))
                        c.w = col->w * (hi - x) / fade;
                    else
                        c.w = col->w;
                    if (x + pw < lo)
                        skip = true;
                    else if (!(x <= hi))
                        break;
                    else if (x < lo) {
                        c.w = 0.0f;
                        { float d = (lo - x) / pw; u0 += d * w; }
                        w = u1 - u0;
                        pw = texW * w;
                        x = lo;
                    }
                }
                if (skip) {
                    x += pw;
                } else {
                    p1 = V4(x, y, z, 1.0f);
                    Emit(p1, c, u0, v0);
                    x += pw;
                    if (!(fade <= 0.0f)) {
                        if (x < lo + fade)
                            c.w = col->w * (x - lo) / fade;
                        else if (!(x <= hi - fade))
                            c.w = col->w * (hi - x) / fade;
                        else
                            c.w = col->w;
                        if (!(x <= hi)) {
                            c.w = 0.0f;
                            { float d = (x - hi) / pw; u1 -= d * w; }
                            x = hi;
                        }
                    }
                    p2 = V4(x, y - f->height, z, 1.0f);
                    Emit(p2, c, u1, v1);
                    n += 2;
                }
                if (f->kerning) {
                    int c2 = p[1];
                    signed char k = c2 - 33;
                    if (k && c2 != 32)
                        adv -= *(f->kern + k + idx * f->count);
                }
            } else {
                adv = f->space;
            }
            p++;
            x += adv;
        }
    }
    if (n)
        XLib_DrawSprites2(g_Video);
}
