extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
typedef struct { int w[83]; } lgAudInfo;
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
int lgAudEnumerate(int idx, lgAudInfo *info)
{
    int *buf;
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (info == 0) {
        func_00127358("lgAudEnumerate: invalid parameter (description)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[2] = idx;
    if (func_00110528(D_0052AD00, 1, 0, buf, 0x20, buf, 0x170, 0, 0) == 0) {
        ret = *D_00491474;
        *info = *(lgAudInfo *)&D_00491474[8];
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358("lgAudEnumerate: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}