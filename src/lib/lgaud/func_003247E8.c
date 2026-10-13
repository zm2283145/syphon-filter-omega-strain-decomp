extern int D_0049147C;
typedef struct { int ret; int x4; int x8; int dev; short x10; unsigned char flag; char x13; int x14[3]; int size; } Pkt;
extern Pkt* D_00491474;
extern int D_0049146C;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
extern void *memcpy(void *, const void *, unsigned int);

int lgAudRead(int dev, int flag, void *dest, int *len)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (dest == 0) {
        func_00127358("lgAudRead: invalid parameter (dest)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudRead: invalid parameter (size too big)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    {
        Pkt *buf = D_00491474;
        buf->dev = dev;
        buf->size = *len;
        buf->flag = flag;
    }
    if (func_00110528(D_0052AD00, 8, 0, D_00491474, 0x30, D_00491474, ((*len + 0x3F) >> 4) << 4, 0, 0) == 0) {
        ret = D_00491474->ret;
        memcpy(dest, (char *)D_00491474 + 0x30, D_00491474->size);
        *len = D_00491474->size;
        func_0010D180(D_0049147C);
        return ret;
    }
    *len = 0;
    func_00127358("lgAudRead: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}

