extern int D_0049147C;
extern int* D_00491474;
extern int D_0049146C;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
extern void *memcpy(void *, const void *, unsigned int);extern int func_00325F38(int, int *);
int lgAudPrepareForReboot(void)
{
    int ret;
    int *buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (func_00325F38(1, 0)) {
        func_00127358("lgAudPrepareForReboot: error: an async call is in progress...\n");
        return 0x80000008;
    }
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = -1;
    if (func_00110528(D_0052AD00, 0x14, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        ret = *D_00491474;
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358("lgAudPrepareForReboot: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}