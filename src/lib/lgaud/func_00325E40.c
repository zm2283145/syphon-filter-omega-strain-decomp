extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
extern char D_004B8318[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
int func_00325E40(int device, unsigned char a, unsigned char b)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    {
    int *buf = D_00491474;
    buf[3] = device;
    ((unsigned char *)buf)[16] = a;
    }
    ((unsigned char *)D_00491474)[17] = b;
    if (func_00110528(D_0052AD00, 0xE, 0, D_00491474, 0x20, D_00491474, 0x20, 0, 0) == 0) {
        ret = *D_00491474;
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358(D_004B8318);
    func_0010D180(D_0049147C);
    return 0x80000000;
}