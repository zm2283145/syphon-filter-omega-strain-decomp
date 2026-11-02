/* 00410E50 cSubtitleFont::Display(unsigned long*, const char*, const tRGBA&, float, float, const tRECT&, const char*) const
 * (MovieSubtitles.cc), rebuilt from the prototype DWARF/.line data. Each glyph corner is one GIF vertex macro. */
#pragma cplusplus on
#include "types.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct cMatrix;
struct tRGBA { float r, g, b, a; };
struct tRECT { float x, y, w, h; };
struct tGlyph { float u0, u1, v0, v1; };
struct cTexInfo { int pad0; unsigned short w; unsigned short h; };
struct cTexture { char pad[0x44]; cTexInfo* info; };
struct cTexMan { char pad[8]; cTexture** texs; cTexture* Get(int i) { return texs[i]; } };
struct XLib;
struct cSubtitleFont {
    int tex;
    char pad004[0x90 - 4];
    unsigned char charHeight;
    char pad091[3];
    float spaceWidth;
    char pad098;
    unsigned char scale;
    char pad09A[2];
    int kernStride;
    tGlyph glyphs[180];
    unsigned char hasKern;
    signed char kern[1];
};

extern "C" {
extern XLib g_Video;
extern cTexMan* g_TextureMgr;
const float* XLib_GetVPScale(const XLib*);
const float* XLib_GetVPOffset(const XLib*);
const cMatrix* XLib_GetCompMat(const XLib*);
cVector cMatrix_opMul_cVectorR(const cMatrix*, const cVector*);
int nSFO_Macros_FTOI(float);
}

#define SCE_GS_SET_UV(u, v) ((unsigned long)(u) | ((unsigned long)(v) << 16))
#define SCE_GS_SET_RGBAQ(r, g, b, a, q) ((unsigned long)(r) | ((unsigned long)(g) << 8) | ((unsigned long)(b) << 16) | ((unsigned long)(a) << 24) | ((unsigned long)(q) << 32))
#define SCE_GS_SET_XYZ(x, y, z) ((unsigned long)(x) | ((unsigned long)(y) << 16) | ((unsigned long)(z) << 32))

static inline void Project(const cVector& pos, int& sx, int& sy)
{
    const float* scale = XLib_GetVPScale(&g_Video);
    const float* offset = XLib_GetVPOffset(&g_Video);
    cVector p = cMatrix_opMul_cVectorR(XLib_GetCompMat(&g_Video), &pos);
    float q = 1.0f / p.w;
    p.x *= scale[0] * q;
    p.y *= scale[1] * q;
    p.x += offset[0];
    p.y += offset[1];
    sx = nSFO_Macros_FTOI(p.x);
    sy = nSFO_Macros_FTOI(p.y);
}
/* Each GIF A+D register pair advances gif by one quadword. Written as an int-cast assignment (not `gif += 2`):
 * MW folds self-assignments (`x = x + c`) into later store offsets, retail keeps one addiu per pair.
 * Together with opt_lifetimes off (below) every version of gif stays in one register. */
#define GIF_NEXT() gif = (unsigned long*)((int)gif + 16)
#define GIF_VERTEX(X, Y, U, V) \
    { \
        cVector pos(X, Y, 0.0f, 1.0f); \
        int sx, sy; \
        Project(pos, sx, sy); \
        int r = nSFO_Macros_FTOI(128.0f * irgba.r); \
        int g = nSFO_Macros_FTOI(128.0f * irgba.g); \
        int b = nSFO_Macros_FTOI(128.0f * irgba.b); \
        int a = nSFO_Macros_FTOI(128.0f * irgba.a); \
        int tu = nSFO_Macros_FTOI(16.0f * U); \
        int tv = nSFO_Macros_FTOI(16.0f * V); \
        gif[0] = SCE_GS_SET_UV(tu, tv); gif[1] = 3; GIF_NEXT(); \
        gif[0] = SCE_GS_SET_RGBAQ(r, g, b, a, 0x3F800000); gif[1] = 1; GIF_NEXT(); \
        gif[0] = SCE_GS_SET_XYZ(sx, sy, 0); gif[1] = 5; GIF_NEXT(); \
    }

/* retail keeps gif in one register through all six pair increments (see GIF_NEXT) */
#pragma opt_lifetimes off

extern "C" unsigned long* cSubtitleFont_Display(const cSubtitleFont* self, unsigned long* gif, const char* str, const tRGBA& irgba,
                                                float ix, float iy, const tRECT& disp, const char* strEnd)
{
    if (*str == 0)
        return gif;
    const unsigned char* cp;
    float charH;
    float imageW;
    float imageH;
    float minx;
    float maxx;
    float miny;
    float maxy;
    miny = 0.5f * -disp.h;
    cp = (const unsigned char*)str;
    charH = self->scale * self->charHeight;
    imageW = (int)g_TextureMgr->Get(self->tex)->info->w;
    imageH = (int)g_TextureMgr->Get(self->tex)->info->h;
    minx = 0.5f * -disp.w;
    maxx = 0.5f * disp.w;
    maxy = 0.5f * disp.h;
    while (*cp != 0 && cp != (const unsigned char*)strEnd) {
        float charSpcW = 2.0f;
        if (*cp != ' ') {
            int idx = *cp - 33;
            float u0 = self->glyphs[idx].u0 * imageW;
            float u1 = self->glyphs[idx].u1 * imageW;
            float v0 = self->glyphs[idx].v0 * imageH;
            float v1 = self->glyphs[idx].v1 * imageH;
            float width = u1 - u0;
            bool vis = ix >= minx && ix + width <= maxx && iy - charH >= miny && iy <= maxy;
            if (vis) {
                GIF_VERTEX(ix, iy, u0, v0)
                ix += width;
                GIF_VERTEX(ix, iy - charH, u1, v1)
            }
            if (self->hasKern) {
                unsigned char nextChar = cp[1];
                signed char k = nextChar - 33;
                if (k && nextChar != ' ')
                    charSpcW -= self->kern[k + self->kernStride * idx];
            }
        } else {
            charSpcW = self->spaceWidth;
        }
        cp++;
        ix += charSpcW;
    }
    return gif;
}
