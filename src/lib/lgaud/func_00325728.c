extern int D_0049147C;
typedef struct { short v[8]; } lgAudMixer;
typedef struct { int ret; int x4; int x8; int dev; int x10[4]; union { lgAudMixer mr; int i[4]; } u; } Pkt;
extern Pkt* D_00491474;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudGetMixer(int dev, lgAudMixer *mr)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (mr == 0) {
        func_00127358("lgAudGetMixer: invalid parameter (mr)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    D_00491474->dev = dev;
    D_00491474->u.mr = *mr;
    if (func_00110528(D_0052AD00, 0xB, 0, D_00491474, 0x30, D_00491474, 0x30, 0, 0) == 0) {
        ret = D_00491474->ret;
        mr->v[6] = D_00491474->u.mr.v[6];
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358("lgAudGetMixer: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}

