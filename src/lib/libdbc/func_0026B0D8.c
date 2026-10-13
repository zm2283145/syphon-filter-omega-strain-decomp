typedef struct { int x0, x4, x8; unsigned char data[0x200]; int x20C; } DbcRD;
extern char D_004F85C8[];
extern DbcRD D_004F8640;
extern int sceSifCallRpc(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0026B1C8(const char *, ...);

int sceDbcReceiveData(int a, int b, int *len, unsigned char *out)
{
    DbcRD *p = &D_004F8640;
    int i, r;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    if (sceSifCallRpc(D_004F85C8, 0x8000131A, 0, &D_004F8640, 0x280, &D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8("sceDbcReceiveData: rpc error
");
        return 0;
    }
    if (p->x20C >= 0) {
        *len = p->x8;
        for (i = 0; i < p->x8; i++) out[i] = p->data[i];
    }
    return p->x20C;
}