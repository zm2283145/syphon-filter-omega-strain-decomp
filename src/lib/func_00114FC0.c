typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char c[4]; } Name4;
extern RpcCd D_004E63C0;
extern int D_004E61C0[];
extern Name4 D_004E63E8;
extern int D_00486260;
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern char *strncpy(char *, const char *, unsigned int);
int func_00114FC0(int a0)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    D_004E61C0[0] = a0;
    if (sceSifCallRpc(&D_004E63C0, 10, 0, D_004E61C0, 4, D_004E61C0, 4, 0, 0) < 0) return -0x10001;
    return D_004E61C0[0];
}