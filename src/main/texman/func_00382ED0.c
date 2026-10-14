#pragma cplusplus on

struct TexMan {
    int used;
    char pad[0x48C - 4];
    int last;
};

static inline int BlockW(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 16 : (bpp == 8) ? 16 : 32;
}

static inline int BlockH(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 8 : 16;
}

static inline int BlockShift(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 6 : (bpp == 16) ? 7 : (bpp == 8) ? 8 : 9;
}
extern "C" int func_00382ED0(TexMan* self, int w, int h, int bpp)
{
    int last = self->last;
    if (last == self->used) {
        unsigned int bw, bh;
        int aw, ah;
        int sh;
        w = (w < h) ? h : w;
        bw = BlockW(bpp);
        bh = BlockH(bpp);
        aw = bw * ((int)(w + bw - 1) / (int)bw);
        ah = bh * ((int)(h + bh - 1) / (int)bh);
        sh = BlockShift(bpp);
        self->used += (aw * ah) >> sh;
        self->last = self->used;
    }
    return last;
}

