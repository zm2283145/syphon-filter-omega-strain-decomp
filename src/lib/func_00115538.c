typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern char *strncpy(char *, const char *, unsigned int);
int func_00115538(int id, void *in, int size)
{
    if (func_001148B8() < 0) return -0x10000;
    D_004E61C0.ret = id;
    D_004E61C0.size = size;
    if (size == 0) *(unsigned char *)D_004E61C0.name = *(unsigned char *)in;
    else if (size == 1) *(unsigned short *)D_004E61C0.name = *(unsigned short *)in;
    else if (size == 2) *(int *)D_004E61C0.name = *(int *)in;
    else return -0x10002;
    if (sceSifCallRpc(&D_004E63C0, 2, 0, &D_004E61C0, 0x20, &D_004E61C0, 0x10, 0, 0) < 0) return -0x10001;
    return 0;
}