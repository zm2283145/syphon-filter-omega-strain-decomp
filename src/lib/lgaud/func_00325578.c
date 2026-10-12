extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
extern char D_004B8258[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudGetRemainingPlaybackBytes(int device, int *bytes)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 0x13, 0, buf, 0x20, buf, 0x30, 0, 0) == 0) {
        device = *D_00491474;
        *bytes = D_00491474[8];
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358(D_004B8258);
    func_0010D180(D_0049147C);
    return 0x80000000;
}