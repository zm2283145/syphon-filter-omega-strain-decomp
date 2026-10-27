typedef struct TexHdr {
    char pad00[4];
    unsigned short w;       /* 0x04 */
    unsigned short h;       /* 0x06 */
    unsigned short bpp;     /* 0x08 */
    unsigned short psm;     /* 0x0A */
    unsigned short tbw;     /* 0x0C */
    unsigned short size;    /* 0x0E */
    unsigned short n10;     /* 0x10 */
    char pad12[4];
    unsigned short cpsm;    /* 0x16 */
    char pad18[4];
    unsigned short n1C;
    unsigned short n1E;
    unsigned short n20;
    unsigned short n22;
} TexHdr;

typedef struct Tex {
    char name[0x44];
    TexHdr* hdr;            /* 0x44 */
    int flags;              /* 0x48 */
    int count;              /* 0x4C */
    unsigned long tex0;     /* 0x50 */
    unsigned long tex1;     /* 0x58 */
    unsigned char b60;
    unsigned char b61;
    char pad62[2];
    int n64;
} Tex;

extern void Libc_Strcpy(char* d, const char* s);
static inline int HasClut(Tex* t) { return (*(TexHdr**)((char*)t + 0x44))->n10 > 0; }

void cTexture_Init_charP_tTDXHeaderP_uint(Tex* self, const char* name, TexHdr* hdr, int flags)
{
    if (hdr) {
        unsigned char tcc;
        unsigned char a;
        int tw;
        int th;
        int v;
        Libc_Strcpy(self->name, name);
        self->hdr = hdr;
        self->count = 0;
        self->flags = flags;
        tcc = 1; a = 1; if (self->hdr->bpp != 32 && !(self->flags & 0x100)) a = 0;
        if (!a && !(self->flags & 0x200)) tcc = 0;
        tw = 0;
        th = 0;
        v = self->hdr->w;
        while (v > 1) { v >>= 1; tw++; }
        v = self->hdr->h;
        while (v > 1) { v >>= 1; th++; }
        self->tex0 = ((unsigned long)self->hdr->tbw << 14) | ((unsigned long)self->hdr->psm << 20) |
                     ((long)tw << 26) | ((long)th << 30) | ((unsigned long)tcc << 34) |
                     ((unsigned long)self->hdr->cpsm << 51) | ((unsigned long)HasClut(self) << 61);
        self->tex1 = ((unsigned long)self->hdr->n1C << 2) | 0x200 | ((unsigned long)self->hdr->n1E << 19) |
                     ((unsigned long)self->hdr->n20 << 32);
        self->b60 = 0;
        self->b61 = 0;
        self->n64 = 1;
    }
}
