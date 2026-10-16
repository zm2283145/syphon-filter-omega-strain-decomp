#include "types.h"
typedef struct { char pad[0x44]; unsigned short* hdr; } FontTex;
typedef struct { char pad[8]; FontTex** tex; } FontMgr;
typedef struct { float x0, x1, y0, y1; } Glyph;
typedef struct {
    int texId;
    char pad4[0x94 - 0x4];
    float spaceWidth;
    char pad98[0x9C - 0x98];
    int glyphCount;
    Glyph glyphs[(0xBE0 - 0xA0) / 0x10];
    unsigned char hasKerning;
    signed char kerning[1];
} Font;
extern FontMgr* D_00539248;

int Font_GetStringWidth(Font* font, const unsigned char* s, int n) {
    float scale = (int)D_00539248->tex[font->texId]->hdr[2];
    float w = 0.0f;
    int c;
    while ((c = *s) != 0 && n > 0) {
        if ((unsigned char)c < 0x20 || (unsigned char)c > font->glyphCount + 0x20) {
            s++;
            continue;
        }
        {
            float adv;
            if (c != ' ') {
                int idx = c - 0x21;
                Glyph* g = &font->glyphs[idx];
                adv = 2.0f;
                w += scale * (g->x1 - g->x0);
                if (font->hasKerning) {
                    int k;
                    c = s[1];
                    k = (signed char)(c - 0x21);
                    if (k != 0 && c != ' ') {
                        adv -= font->kerning[(signed char)k + idx * font->glyphCount];
                    }
                }
            } else {
                adv = font->spaceWidth;
            }
            s++;
            w += adv;
            n--;
        }
    }
    return w;
}
