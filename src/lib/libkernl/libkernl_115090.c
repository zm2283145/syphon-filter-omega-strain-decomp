typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char d[0xFC]; } Blk252;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int _lf_bind(void);
extern int _lf_version(void);
extern void *memcpy(void *, const void *, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);

int _sceSifLoadModule(const char *name, int size, void *data, int *out, int fno)
{
    if (_lf_bind() < 0) return -0x10000;
    if (_lf_version() != 0) return -0x10004;
    strncpy(D_004E61C0.name, name, 0xFC);
    D_004E61C0.name[0xFB] = 0;
    if (data != 0) {
        if (size > 0xFC) {
            *(Blk252 *)D_004E61C0.data = *(Blk252 *)data;
            D_004E61C0.ret = 0xFC;
        } else {
            memcpy(D_004E61C0.data, data, size);
            D_004E61C0.ret = size;
        }
    } else {
        D_004E61C0.data[0] = 0;
        D_004E61C0.ret = 0;
    }
    if (sceSifCallRpc(&D_004E63C0, fno, 0, &D_004E61C0, 0x200, &D_004E61C0, 8, 0, 0) < 0) return -0x10001;
    { int r = D_004E61C0.ret; *out = D_004E61C0.size; return r; }
}