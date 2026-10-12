typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern char *strncpy(char *, const char *, unsigned int);
int func_00115448(int id, void *out, unsigned int size)
{
    if (func_001148B8() < 0) return -0x10000;
    if (size >= 3) goto invalid;
        D_004E61C0.ret = id;
        D_004E61C0.size = size;
        if (func_00110528(&D_004E63C0, 3, 0, &D_004E61C0, 0x20, &D_004E61C0, 0x20, 0, 0) < 0) return -0x10001;
        if (size == 0) { *(unsigned char *)out = *(unsigned char *)&D_004E61C0; goto success; }
        if (size == 1) { *(unsigned short *)out = *(unsigned short *)&D_004E61C0; goto success; }
        if (size == 2) goto word;
invalid:
    return -0x10002;
word:
    *(int *)out = D_004E61C0.ret;
success:
    return 0;
}
