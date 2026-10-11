typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char c[4]; } Name4;
typedef struct { int ret; int pad; char name[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern Name4 D_004E63E8;
extern int D_00486260;
extern int func_00110358(RpcCd *cd, unsigned int id, int mode);
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern char *strncpy(char *, const char *, unsigned int);
int func_00114F20(const char *name)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    strncpy(D_004E61C0.name, name, 0xFC);
    D_004E61C0.name[0xFB] = 0;
    if (func_00110528(&D_004E63C0, 9, 0, &D_004E61C0, 0x200, &D_004E61C0, 4, 0, 0) < 0) return -0x10001;
    return D_004E61C0.ret;
}