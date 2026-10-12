typedef struct { int x0, x4, x8; unsigned char data[0x2084]; } DbcSD3;
extern char D_004F8618[];
extern DbcSD3 D_004F99C0;
extern int D_004FBB80;
extern int func_00110528(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_00110720(void *);
extern int func_0026B1C8(const char *, ...);
extern int func_0010D1A0(int);
extern int func_0010D180(int);

int sceDbcSendData3(int a, int b, int *len, unsigned char *in, void *endf)
{
    DbcSD3 *p;
    int i;
    if (*len > 0x2080) {
        func_0026B1C8("libdbc: SendData3 data length too long
");
        return 0;
    }
    func_0010D1A0(D_004FBB80);
    p = &D_004F99C0;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (func_00110720(D_004F8618) == 1) {
        func_0026B1C8("dbcman : SendData3 BUSY
");
        func_0010D180(D_004FBB80);
        return 0;
    }
    if (func_00110528(D_004F8618, 0x8000131C, 1, &D_004F99C0, 0x2090, &D_004F99C0, 0x2090, endf, 0) < 0) {
        func_0010D180(D_004FBB80);
        return 0;
    }
    func_0010D180(D_004FBB80);
    return 1;
}