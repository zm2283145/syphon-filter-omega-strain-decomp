extern int D_0049147C;
typedef struct { int ret; int x4; int x8; int dev; short x10; unsigned char flag; char x13; int x14[3]; int size; } Pkt;
extern Pkt* D_00491474;
extern int D_0049146C;
extern char D_0052AD00[];
typedef union { struct { void *src; int *len; int ret; } s; int i[3]; } lgAudWriteReq;
extern lgAudWriteReq D_0052AEB0;
extern void func_00326040(lgAudWriteReq *req);
extern int func_00110720(void *cd);
extern int func_0010D1A0(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
extern void *memcpy(void *, const void *, unsigned int);

int lgAudAWrite(int dev, int flag, void *src, int *len)
{
    if (D_0049147C == -1)
        return 0x8000000A;
    if (src == 0) {
        func_00127358("lgAudAWrite: invalid parameter (src)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudAWrite: invalid parameter (*size too big)\n");
        return 0x80000004;
    }
    if (func_00110720(D_0052AD00)) {
        func_00127358("lgAudAWrite: error: another async call is in progress...\n");
        return 0x80000008;
    }
    func_0010D1A0(D_0049147C);
    {
        Pkt *buf = D_00491474;
        buf->dev = dev;
        buf->size = *len;
        buf->flag = flag;
    }
    D_0052AEB0.s.src = src;
    D_0052AEB0.s.len = len;
    memcpy((char *)D_00491474 + 0x30, src, D_00491474->size);
    if (func_00110528(D_0052AD00, 9, 1, D_00491474, ((*len + 0x3F) >> 4) << 4, D_00491474, 0x30, func_00326040, &D_0052AEB0) == 0)
        return 0;
    *len = 0;
    func_00127358("lgAudAWrite: rpc call failed\n");
    return 0x80000000;
}

