extern int D_0049147C;
typedef struct { unsigned char Mode; char rest[11]; short x; } AudOpenParam;
typedef struct {
    int ret;
    int x4;
    int type;
    int dev;
    int x10[4];
    union { AudOpenParam open; int i[4]; } u;
} AudPkt;
extern AudPkt* D_00491474;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudOpen(int type, AudOpenParam *openparam, int *device)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (device == 0) {
        func_00127358("lgAudOpen: invalid parameter (device)\n");
        return 0x80000004;
    }
    if (openparam == 0) {
        func_00127358("lgAudOpen: invalid parameter (openparam)\n");
        return 0x80000004;
    }
    if (openparam->Mode == 0) {
        func_00127358("lgAudOpen: invalid parameter (openparam->Mode)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    D_00491474->type = type;
    D_00491474->u.open = *openparam;
    if (func_00110528(D_0052AD00, 2, 0, D_00491474, 0x30, D_00491474, 0x20, 0, 0) == 0) {
        ret = D_00491474->ret;
        *device = D_00491474->dev;
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358("lgAudOpen: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
