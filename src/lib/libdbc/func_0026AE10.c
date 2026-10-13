typedef struct { int x0, x4, x8; unsigned char data[0x1084]; } DbcSD2;
extern char D_004F85F0[];
extern DbcSD2 D_004F88C0;
extern int D_004FBB80;
extern int sceSifCallRpc(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int sceSifCheckStatRpc(void *);
extern int func_0026B1C8(const char *, ...);
extern int WaitSema(int);
extern int SignalSema(int);

int sceDbcSendData2(int a, int b, int *len, unsigned char *in)
{
    DbcSD2 *p;
    int i;
    if (*len > 0x1080) {
        func_0026B1C8("libdbc: SendData2 data length too long [%d]
", *len);
        return 0;
    }
    WaitSema(D_004FBB80);
    p = &D_004F88C0;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (sceSifCheckStatRpc(D_004F85F0) == 1) {
        func_0026B1C8("dbcman : SendData2 BUSY
");
        SignalSema(D_004FBB80);
        return 0;
    }
    if (sceSifCallRpc(D_004F85F0, 0x8000131B, 1, &D_004F88C0, 0x1090, &D_004F88C0, 0x1090, 0, 0) < 0) {
        func_0026B1C8("sceDbcSendData2: rpc error
");
        SignalSema(D_004FBB80);
        return 0;
    }
    SignalSema(D_004FBB80);
    return 1;
}