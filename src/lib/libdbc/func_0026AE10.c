typedef struct { int x0, x4, x8; unsigned char data[0x1084]; } DbcSD2;
extern char D_004F85F0[];
extern DbcSD2 D_004F88C0;
extern int D_004FBB80;
extern char D_004A86C8[];
extern char D_004A86F8[];
extern char D_004A8718[];
extern int func_00110528(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_00110720(void *);
extern int func_0026B1C8(const char *, ...);
extern int func_0010D1A0(int);
extern int func_0010D180(int);

int sceDbcSendData2(int a, int b, int *len, unsigned char *in)
{
    DbcSD2 *p;
    int i;
    if (*len > 0x1080) {
        func_0026B1C8(D_004A86C8, *len);
        return 0;
    }
    func_0010D1A0(D_004FBB80);
    p = &D_004F88C0;
    p->x0 = a;
    p->x4 = b;
    p->x8 = *len;
    for (i = 0; i < *len; i++) p->data[i] = in[i];
    if (func_00110720(D_004F85F0) == 1) {
        func_0026B1C8(D_004A86F8);
        func_0010D180(D_004FBB80);
        return 0;
    }
    if (func_00110528(D_004F85F0, 0x8000131B, 1, &D_004F88C0, 0x1090, &D_004F88C0, 0x1090, 0, 0) < 0) {
        func_0026B1C8(D_004A8718);
        func_0010D180(D_004FBB80);
        return 0;
    }
    func_0010D180(D_004FBB80);
    return 1;
}