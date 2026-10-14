/* libmpeg _doMC (SDK 2.2 mpc.c) on the context-pointer libmpeg: runs the per-reference luma/chroma
   copy routines, then copies the intra block / prediction / prediction+residual to the destination
   (func_00106418 = _copyRefImage, func_001063B8 = _copyAddRefImage, func_0010BD90 = _Error). */
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
} MCRecord;

typedef struct {
    char pad0[0x5A8];
    MCRecord rec[2];
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