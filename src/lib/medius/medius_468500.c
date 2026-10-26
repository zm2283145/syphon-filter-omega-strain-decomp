typedef struct { int x0, x4, x8, xC, x10; int (*x14)(void); int x18, x1C; } P00468500;
extern short D_00497CC0;
unsigned int D_00497D60[1] = { 0x0 };
extern int D_00497D70;
extern int D_00497CF4;
extern int D_00497DC4;
extern int D_00497CC8;
extern int D_00497CCC;
extern int MediusSetProcessingState(int);
extern int NetSetDefaultInitializeParams(P00468500 *);
extern void MediusSetSystemMessageCallback(int);
extern int MediusLocalSystemMessageCallback(void);
extern int NetInitialize(P00468500 *, char *);
extern int NetGetLocalTime(int *);
extern int RegisterPackets(void);
int MediusInitialize(int *cfg, int *out)
{
    P00468500 p;
    char buf[0x20];
    if (D_00497CC0 == 1) {
        *out = -1;
        return -0x12;
    }
    MediusSetProcessingState(0);
    NetSetDefaultInitializeParams(&p);
    p.x8 = cfg[0];
    if (cfg[5]) {
        MediusSetSystemMessageCallback(cfg[5]);
        p.x18 = cfg[6];
    } else {
        MediusSetSystemMessageCallback(0);
    }
    p.x14 = MediusLocalSystemMessageCallback;
    if (NetInitialize(&p, buf)) {
        *out = -1;
        return -1;
    }
    (*(int*)D_00497D60) = cfg[1];
    D_00497D70 = cfg[2];
    D_00497CF4 = cfg[3];
    D_00497DC4 = cfg[4];
    D_00497CC8 = cfg[7];
    NetGetLocalTime(&D_00497CCC);
    if (RegisterPackets()) {
        *out = -1;
        return -1;
    }
    D_00497CC0 = 1;
    *out = 0;
    return 0;
}
