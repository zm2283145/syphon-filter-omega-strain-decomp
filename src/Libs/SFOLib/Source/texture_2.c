/*
 * Libs/SFOLib/Source/texture: 6 files, 003BB620-003BBBC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BB620 */
#pragma push /* merge_units */
/* Set the 1-bit field at bit 5 and the 3-bit field at bits 6..8 of the 64-bit
 * register word at +0x58 from flag bits 2/3 of g_DrawMode. */
typedef struct {
    char pad[0x58];
    unsigned long reg;              /* 0x58 */
} Obj003BB620;

extern int g_DrawMode;

unsigned long* cTexture_GetTEX1_1(Obj003BB620* self)
{
    unsigned int enable;
    unsigned int mode;
    unsigned char bit4;
    unsigned char bit8;
    int flags;
    enable = 0;
    mode = 0;
    flags = g_DrawMode;
    bit4 = (flags & 4) != 0;
    bit8 = (flags & 8) != 0;
    if (flags & 0xC) {
        enable = 1;
        if (bit4) mode = 4;
        else if (bit8) mode = 5;
    }
    self->reg &= ~(unsigned long)0x1E0;
    self->reg |= ((unsigned long)enable << 5) | ((unsigned long)mode << 6);
    return &self->reg;
}
static inline void merge_flush_func_003BB620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB620 */

/* merge_units: begin func_003BB6B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Attach an info header to a texture entry and mark it. */
void cTexture_SetReallocData(TexEntry* self, TexInfo* info) {
    self->info = info;
    self->flags = self->flags | 0x1000;
    self->unk60 = 0;
    self->unk61 = 0;
}
static inline void merge_flush_func_003BB6B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB6B0 */

/* merge_units: begin func_003BB6D0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma cplusplus on
/* cTexture_Init_charP_int_int_int_etc: creates a texture header for a w x h image of the given pixel size
 * (GS block-aligned byte size, buffer width, PSM index) and builds the texture's GS
 * registers from it (cTexture_Init_charP_tTDXHeaderP_uint, cTexture_Init_charP_tTDXHeaderP_uint.c). */
typedef struct THdr6D0 {
    char pad00[4];
    unsigned short w;       /* 0x04 */
    unsigned short h;       /* 0x06 */
    unsigned short bpp;     /* 0x08 */
    unsigned short psm;     /* 0x0A */
    unsigned short tbw;     /* 0x0C */
    unsigned short size;    /* 0x0E */
    char pad10[0x22 - 0x10];
    unsigned short n22;     /* 0x22 */
    char pad24[0x40 - 0x24];
} THdr6D0;
struct Tex6D0;
extern "C" {
extern char D_004BD020[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void cTexture_Init_charP_tTDXHeaderP_uint(Tex6D0* self, const char* name, THdr6D0* hdr, int flags);
#endif /* merge_units */
struct Tex; /* merge_units */
struct TexHdr_003BBA10; /* merge_units */
void cTexture_Init_charP_tTDXHeaderP_uint(Tex* self, const char* name, TexHdr_003BBA10* hdr, int flags); /* merge_units */
#define cTexture_Init_charP_tTDXHeaderP_uint(a0, a1, a2, a3) (cTexture_Init_charP_tTDXHeaderP_uint((Tex *)(a0), (a1), (TexHdr_003BBA10 *)(a2), (a3))) /* merge_units */

void cTexture_Init_charP_int_int_int_etc(Tex6D0* self, const char* name, int w, int h, int bpp, int flags);
}
/* byte/quadword clear loop with addi counters (as in skybox_3BBBC0.c); not expressible in C */
static inline void MemClear_B6D0(void* d0, int n0)
{
    int n = n0;
    void* dst = d0;
    asm volatile {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v0, n, 0xF
        or $a0, $a0, $v0
        nop
        bgtz $a0, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
static inline void* Alloc_B6D0(int n, int line) { AllocGuard g; return cMemMan_Allocate(0, n, D_004BD020, line); }
static inline int BlockW(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 16 : (bpp == 8) ? 16 : 32;
}
static inline int BlockH(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 8 : (bpp == 8) ? 16 : 16;
}
static inline int BlockShift(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 6 : (bpp == 16) ? 7 : (bpp == 8) ? 8 : 9;
}

extern "C" void cTexture_Init_charP_int_int_int_etc(Tex6D0* self, const char* name, int w, int h, int bpp, int flags)
{
    int psm;
    THdr6D0* hdr;
    if (bpp == 16) psm = 2;
    else if (bpp == 24) psm = 1;
    else psm = 0;
    hdr = (THdr6D0*)Alloc_B6D0(0x40, 0x5E);
    MemClear_B6D0(hdr, 0x40);
    hdr->w = w;
    hdr->h = h;
    flags |= 0x1000;
    hdr->bpp = bpp;
    hdr->psm = psm;
    hdr->tbw = (w >> 6) <= 0 ? 1 : w >> 6;
    {
        unsigned int bw, bh;
        int aw, ah;
        int sh;
        w = (w < h) ? h : w;
        bw = BlockW(bpp);
        bh = BlockH(bpp);
        aw = bw * ((int)(w + bw - 1) / (int)bw);
        ah = bh * ((int)(h + bh - 1) / (int)bh);
        sh = BlockShift(bpp);
        hdr->size = (aw * ah) >> sh;
    }
    hdr->n22 = 1;
    cTexture_Init_charP_tTDXHeaderP_uint(self, name, hdr, flags);
}
#undef cTexture_Init_charP_tTDXHeaderP_uint /* merge_units */
static inline void merge_flush_func_003BB6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB6D0 */

/* merge_units: begin func_003BBA10 */
#pragma push /* merge_units */
typedef struct TexHdr_003BBA10 {
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
} TexHdr_003BBA10;

typedef struct Tex {
    char name[0x44];
    TexHdr_003BBA10* hdr;            /* 0x44 */
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
static inline int HasClut(Tex* t) { return (*(TexHdr_003BBA10**)((char*)t + 0x44))->n10 > 0; }

void cTexture_Init_charP_tTDXHeaderP_uint(Tex* self, const char* name, TexHdr_003BBA10* hdr, int flags)
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
static inline void merge_flush_func_003BBA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BBA10 */

/* merge_units: begin func_003BBBC0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cFileMan_dtor(char *, int);                            
int cFileMan_ctor_charP_cFileIOP_bool(char *, char *, int, int);                    
int XLib_RequestDeleteDmaData(char *, int, int);                       
int cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(int, char *, int);                       
int GetFileStreamMan();                                
int operator_delete(char * );                          
int sprintf(char *, char *, char * );                        
extern char g_Video;

char * cTexture_dtor(char * arg0, short arg1) {
    int spD0[32];
    int sp30[40];
    int temp_v1;

    if (arg0 != NULL) {
        temp_v1 = F_(arg0, 0x48, int);
        if (temp_v1 & 0x1000) {
            if (temp_v1 & 0x2000) {
                sprintf(spD0, "%s.TDX", arg0);
                cFileMan_ctor_charP_cFileIOP_bool(sp30, spD0, 0, 0);
                cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), sp30, 1);
                cFileMan_dtor(sp30, -1);
            } else {
                XLib_RequestDeleteDmaData(&g_Video, F_(arg0, 0x44, int), -1);
            }
        }
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
static inline void merge_flush_func_003BBBC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BBBC0 */

/* merge_units: begin func_003BBC90 */
#pragma push /* merge_units */
static inline void MemClear_3BB(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a1, dst, 0xF
        andi $v1, n, 0xF
        or $a1, $a1, $v1
        nop
        bgtz $a1, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}
#pragma opt_propagation off
void* cTexture_ctor(void* d)
{
    MemClear_3BB(d, 0x70);
    return d;
}
#pragma opt_propagation reset
static inline void merge_flush_func_003BBC90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BBC90 */
