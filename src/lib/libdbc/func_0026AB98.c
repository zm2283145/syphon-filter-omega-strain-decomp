typedef struct { int x0, x4, x8, xC; unsigned char sdata[0x200]; unsigned char rdata[0x200]; int x410; } DbcSR;
extern char D_004F85C8[];
extern DbcSR D_004F8640;
extern char D_004A8688[];
extern int func_00110528(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0026B1C8(const char *, ...);

int sceDbcSRData(int a, int b, int *slen, unsigned char *sdata, int *rlen, unsigned char *rdata)
{
    DbcSR *p = &D_004F8640;
    int i, r;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *slen;
    p->xC = *rlen;
    for (i = 0; i < *slen; i++) p->sdata[i] = sdata[i];
    if (func_00110528(D_004F85C8, 0x80001318, 0, &D_004F8640, 0x280, &D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8(D_004A8688);
        return 0;
    }
    if (p->x410 >= 0) {
        *slen = p->x8;
        *rlen = p->xC;
        for (i = 0; i < p->xC; i++) rdata[i] = p->rdata[i];
    }
    return p->x410;
}