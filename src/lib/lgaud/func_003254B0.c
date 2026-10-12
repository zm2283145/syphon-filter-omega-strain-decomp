extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudClose(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 3, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358("lgAudClose: rpc call failed
");
    func_0010D180(D_0049147C);
    return 0x80000000;
}