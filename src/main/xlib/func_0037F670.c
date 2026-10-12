#include "types.h"
typedef struct { char p0[0x1C]; int w; int h; int bpp; int clut; char p2C[0x100]; int f12C; int f130; int f134; int f138; int f13C; int f140; } T37F670;
/* Computes the texture's VRAM page layout (page counts for image and CLUT). */
void func_0037F670(T37F670* t)
{
    int bw; unsigned char big; int bh; int pages; int cl; int ch;
    bw = (t->w + 63) >> 6;
    big = 1;
    if (t->bpp != 32 && t->bpp != 24) big = 0;
    if (big) bh = (t->h + 31) >> 5;
    else bh = (t->h + 63) >> 6;
    pages = bw * bh;
    if (t->clut == 16) ch = (t->h + 63) >> 6;
    else ch = (t->h + 31) >> 5;
    cl = t->clut > 0 ? bw * ch : 0;
    t->f12C = 0;
    t->f130 = t->f12C + pages;
    t->f138 = t->f130 + pages;
    t->f134 = t->f138;
    t->f13C = (t->f134 + cl) << 5;
    t->f140 = 0;
}
