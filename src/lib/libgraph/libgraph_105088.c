/*
 * lib/libgraph: 2 files, 00105088-001054A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00105088 */
/* libmpeg _getRef0 (SDK 2.2 mpc.c) on the context-pointer libmpeg: rec[2] at 0x5A8, cur at 0x828,
   refBlockp at 0x834; lumaCopy/chromaCopy tables are D_00485F08/D_00485F28 (.data). The spill-slot
   order needs n/luma/chroma declared after the other locals and dst initialised in its declaration. */
typedef struct {
    void *dst;
    int xoff;
    int rows0;
    int rows1;
    int stride;
    void *src0;
    void *src1;
} MCRefDesc;

typedef struct {
    int refBuf;
    int ipuBuf;
    void *srcAddr[2][4];
    void (*lumaFn[4])();
    void (*chromaFn[4])();
    MCRefDesc luma[4];
    MCRefDesc chroma[4];
    void *dst;
    int count;
    int intra;
    int coded;
    int busy;
    int skip;
} MCRecord;

typedef struct {
    char pad0[0x5A8];
    MCRecord rec[2];
    int cur;
    char pad82C[0x834 - 0x82C];
    int refBlockp;
} Mpeg5088;

extern void (*D_00485F08[8])();
extern void (*D_00485F28[8])();

void func_00105088(Mpeg5088 *mp, int *img, int lineOff, int predIdx, int yoff, int h, int x, int y,
                   int mvx, int mvy, int fld, int avg)
{
    int dst = mp->refBlockp;
    int lumaCmd, chromaCmd;
    int ix, rx, ry, px, py, fy, blk, t, xh, yh;
    int cmvx, cmvy, cpx, cpy, cyoff, ch;
    int base, idx, lrow, lrow2, cbase, crow, crow2;
    int n = mp->rec[mp->cur].count;
    MCRefDesc *luma = &mp->rec[mp->cur].luma[n];
    MCRefDesc *chroma = &mp->rec[mp->cur].chroma[n];

    ix = mvx >> 1;
    rx = ix + x;
    if (fld) {
        ry = (mvy >> 1) * 2 + lineOff + yoff + y;
    } else {
        ry = (mvy >> 1) + lineOff + yoff + y;
    }
    px = rx >> 4;
    py = ry >> 4;
    blk = px * img[0x10 / 4] + py;
    fy = ry - py * 16;
    xh = mvx & 1;
    yh = mvy & 1;
    luma->xoff = rx - px * 16;
    luma->dst = (void *)(dst + (predIdx + yoff) * 32);
    if (yh) {
        if (fy + (h << fld) >= 16) {
            t = (16 >> fld) - (fy >> fld) - 1;
            luma->rows0 = t;
            luma->rows1 = h - t;
        } else {
            luma->rows0 = h;
            luma->rows1 = 0;
        }
    } else {
        if (fy + (h << fld) >= 17) {
            t = (16 >> fld) - (fy >> fld);
            luma->rows0 = t;
            luma->rows1 = h - t;
        } else {
            luma->rows0 = h;
            luma->rows1 = 0;
        }
    }
    base = mp->rec[mp->cur].refBuf + n * 0x600;
    lrow = fy * 16;
    luma->src0 = (void *)(base + lrow);
    lrow2 = lrow + 0x300;
    luma->src1 = (void *)(base + lrow2);
    luma->stride = 16 << fld;
    lumaCmd = (avg << 2) | (xh << 1) | yh;

    cmvx = mvx / 2;
    cmvy = mvy / 2;
    rx = (cmvx >> 1) + (x >> 1);
    cyoff = yoff >> 1;
    ch = h >> 1;
    if (fld) {
        ry = (cmvy >> 1) * 2 + lineOff + cyoff + (y >> 1);
    } else {
        ry = (cmvy >> 1) + lineOff + cyoff + (y >> 1);
    }
    cpx = rx >> 3;
    cpy = ry >> 3;
    fy = ry - cpy * 8;
    xh = cmvx & 1;
    yh = cmvy & 1;
    chroma->xoff = rx - cpx * 8;
    chroma->dst = (void *)(dst + 0x200 + (predIdx + cyoff) * 16);
    if (yh) {
        if (fy + (ch << fld) >= 8) {
            t = (8 >> fld) - (fy >> fld) - 1;
            chroma->rows0 = t;
            chroma->rows1 = ch - t;
        } else {
            chroma->rows0 = ch;
            chroma->rows1 = 0;
        }
    } else {
        if (fy + (ch << fld) >= 9) {
            t = (8 >> fld) - (fy >> fld);
            chroma->rows0 = t;
            chroma->rows1 = ch - t;
        } else {
            chroma->rows0 = ch;
            chroma->rows1 = 0;
        }
    }
    cbase = ((cpx - px) * 2 + (cpy - py)) * 0x180 + base;
    crow = fy * 8 + 0x100;
    crow2 = fy * 8 + 0x400;
    chroma->src0 = (void *)(cbase + crow);
    chroma->src1 = (void *)(cbase + crow2);
    chroma->stride = 8 << fld;
    chromaCmd = (avg << 2) | (xh << 1) | yh;

    idx = mp->cur;
    mp->rec[idx].srcAddr[0][n] = (void *)(img[0] + blk * 0x180);
    mp->rec[idx].srcAddr[1][n] = (void *)(img[0] + (blk + img[0x10 / 4]) * 0x180);
    mp->rec[idx].lumaFn[n] = D_00485F08[lumaCmd];
    mp->rec[idx].chromaFn[n] = D_00485F28[chromaCmd];
    mp->rec[idx].count += 1;
}
/* merge_units: end func_00105088 */

/* merge_units: begin func_001054A8 */
/* libmpeg _doMC (SDK 2.2 mpc.c) on the context-pointer libmpeg: runs the per-reference luma/chroma
   copy routines, then copies the intra block / prediction / prediction+residual to the destination
   (func_00106418 = _copyRefImage, func_001063B8 = _copyAddRefImage, func_0010BD90 = _Error). */


typedef struct {
    int refBuf;
    int ipuBuf;
    void *srcAddr[2][4];
    void (*lumaFn[4])(MCRefDesc *);
    void (*chromaFn[4])(MCRefDesc *);
    MCRefDesc luma[4];
    MCRefDesc chroma[4];
    int dst;
    int count;
    int intra;
    int coded;
    int busy;
    int skip;
} MCRecord_001054A8;

typedef struct {
    char pad0[0x5A8];
    MCRecord_001054A8 rec[2];
    int cur;
    char pad82C[0x834 - 0x82C];
    int refBlockp;
} Mpeg54A8;

extern void func_0010BD90(Mpeg54A8 *mp, char *str);
extern void func_00106418(int dst, int src);
extern void func_001063B8(int dst, int src, int res);

void func_001054A8(Mpeg54A8 *mp, int idx)
{
    int i;

    if (mp->rec[idx].busy != 0) {
        for (i = 0; i < mp->rec[idx].count; i++) {
            mp->rec[idx].lumaFn[i](&mp->rec[idx].luma[i]);
            mp->rec[idx].chromaFn[i](&mp->rec[idx].chroma[i]);
        }
    }
    if (mp->rec[idx].intra != 0 && mp->rec[idx].skip != 0) {
        func_0010BD90(mp, "intra && skip MB");
    }
    if (mp->rec[idx].intra != 0) {
        func_00106418(mp->rec[idx].dst, mp->rec[idx].ipuBuf);
    } else if (mp->rec[idx].skip != 0) {
        func_00106418(mp->rec[idx].dst, mp->refBlockp);
    } else {
        func_001063B8(mp->rec[idx].dst, mp->refBlockp, mp->rec[idx].ipuBuf);
    }
}
/* merge_units: end func_001054A8 */
