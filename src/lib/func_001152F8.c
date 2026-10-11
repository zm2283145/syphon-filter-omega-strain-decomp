typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern char *strncpy(char *, const char *, unsigned int);
int func_001152F8(const char *n1, const char *n2, int *out, int fno)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    strncpy(D_004E61C0.name, n1, 0xFC);
    D_004E61C0.name[0xFB] = 0;
    strncpy(D_004E61C0.data, n2, 0xFC);
    D_004E61C0.data[0xFB] = 0;
    if (func_00110528(&D_004E63C0, fno, 0, &D_004E61C0, 0x200, &D_004E61C0, 0x10, 0, 0) < 0) return -0x10001;
    if (D_004E61C0.ret == 0) return -0x10003;
    out[0] = D_004E61C0.ret;
    out[1] = D_004E61C0.size;
    return 0;
}