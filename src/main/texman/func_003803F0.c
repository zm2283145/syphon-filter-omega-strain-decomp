typedef struct TdxH {
    unsigned short magic;
    unsigned short flags;
    char pad4[0x22 - 4];
    unsigned short nframes;
    unsigned short w;
    unsigned short h;
    char pad28[0x38 - 0x28];
    int stride;
    int relocated;
} TdxH;
extern int TexHeader_PixelOffset(TdxH* t);
extern int TexHeader_PaletteOffset(TdxH* t);
extern char* Tdx_GetFrame(TdxH* t, unsigned int n);
extern void Tdx_RelocateFrames(char* f, char* base, int w, int h, int pix, int pal);

int Tdx_Relocate(void* tdx, int data, unsigned int* fl)
{
    TdxH* t = (TdxH*)data;
    if (t->magic != 5) return 0;
    if (!t->relocated) {
        char* base;
        int pix;
        int i;
        unsigned int pal;
        base = (char*)t + 0x40;
        pix = TexHeader_PixelOffset(t);
        pal = TexHeader_PaletteOffset(t);
        for (i = 0; i < t->nframes; i++) {
            Tdx_RelocateFrames(Tdx_GetFrame(t, i), base, t->w, t->h, pix, pal);
            base += t->stride;
        }
        t->relocated = 1;
    }
    *fl |= 0x400;
    if (t->flags & 1) *fl |= 2;
    if (t->flags & 4) *fl |= 0x100;
    if (t->flags & 2) *fl |= 0x200;
    if (t->nframes > 1) *fl |= 0x800;
    return (int)t;
}




