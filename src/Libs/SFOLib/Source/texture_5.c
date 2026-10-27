/*
 * Libs/SFOLib/Source/texture: 3 files, 003BB620-003BB6D0
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
void cTexture_Init_charP_tTDXHeaderP_uint(Tex6D0* self, const char* name, THdr6D0* hdr, int flags);
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
static inline void merge_flush_func_003BB6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BB6D0 */
