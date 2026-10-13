typedef struct { int x0, x4, x8; unsigned char data[0x200]; int x20C; } DbcSD;
extern char D_004F85C8[];
extern DbcSD D_004F8640;
extern int D_004FBB80;
extern int sceSifCallRpc(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0026B1C8(const char *, ...);
extern int WaitSema(int);
extern int SignalSema(int);

int sceDbcSendData(int a, int b, int *len, unsigned char *in)
{
    DbcSD *p;
    int i;
    WaitSema(D_004FBB80);
    p = &D_004F8640;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (sceSifCallRpc(D_004F85C8, 0x80001319, 0, &D_004F8640, 0x280, &D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8("sceDbcSendData: rpc error
");
        SignalSema(D_004FBB80);
        return 0;
    }
    if (p->x20C >= 0) *len = p->x8;
    SignalSema(D_004FBB80);
    return p->x20C;
}