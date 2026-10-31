typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
extern int D_00487890;
extern int D_004878A4;
extern int D_004878A0;
extern int D_004878A8;
extern int D_004878AC;
extern volatile int D_004878B8;
extern int D_004878BC;
extern int D_004878C0;
extern int D_004878C4;
extern int D_004878C8;
extern int D_004878CC;
extern int D_004878D0;
extern int D_004878D4;
extern int D_004E9D18;
extern RpcCd D_004E9F28;
extern int D_004E9F80;
extern int D_00488A80[];
extern char D_00498D70[];
extern char D_00498D90[];
extern int sceCdSyncS(int);
extern void sceSifInitRpc(unsigned int);
extern int GetThreadId(void);
extern void sceSifWriteBackDCache(void *, int);
extern void cdvd_exit(void);
extern void cmd_sem_init(void);
extern int PowerOffCB(void);
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int sceSifCallRpc(RpcCd *, int, int, void *, int, void *, int, void *, void *);
extern int scePrintf(const char *, ...);

/* libcdvd: binds the init RPC and reads the IOP module's version reply.
 * The busy flag (D_004878A4) and the read mode (D_004878B8) are volatile;
 * the bind-state reset order was found by searching the sched1 output
 * against the retail store/relocation order. */
int sceCdInit(int mode)
{
    int *p;
    int ver;
    int r;
    int w;
    int type;
    int v1;
    int v2;

    if (sceCdSyncS(1) != 0) {
        return 0;
    }
    sceSifInitRpc(0);
    D_004E9D18 = GetThreadId();
    *(volatile int *)&D_004878A4 = 1;
    D_004878C4 = -1;
    D_004878BC = -1;
    D_004878CC = -1;
    D_004878C8 = -1;
    D_004878D0 = -1;
    D_004878C0 = -1;
    D_004878B8 = 0;
    D_004878D4++;
    while (1) {
        r = sceSifBindRpc(&D_004E9F28, 0x80000592, 0);
        if (r < 0) {
            if (D_00487890 > 0) {
                scePrintf(D_00498D70, r, D_004878D4);
            }
            w = 0x100000;
            while (w--) {}
            continue;
        }
        if (D_004E9F28.serve != 0) {
            D_004E9F80 = mode;
            D_004878D0 = 0;
            sceSifWriteBackDCache(&D_004E9F80, 4);
            p = D_00488A80;
            if (sceSifCallRpc(&D_004E9F28, 0, 0, &D_004E9F80, 4, p, 16, 0, 0) < 0) {
                *(volatile int *)&D_004878A4 = 0;
                return 0;
            }
            break;
        }
        w = 0x100000;
        while (w--) {}
    }
    v1 = *(int *)((int)(p + 1) | 0x20000000);
    v2 = *(int *)((int)(p + 2) | 0x20000000);
    type = *(int *)((int)(p + 3) | 0x20000000);
    ver = 1;
    if (type == 0xFF) {
    } else if (type == 0xFE) {
        D_00487890 = 1;
    } else if (v1 / 256 < 2 || v2 / 256 < 2) {
        ver = 2;
    }
    *(volatile int *)&D_004878A4 = 0;
    switch (mode) {
    case 5:
        if (D_00487890 > 0) {
            scePrintf(D_00498D90);
        }
        cdvd_exit();
        *(volatile int *)&D_004878A8 = -1;
        *(volatile int *)&D_004878AC = -1;
        *(volatile int *)&D_004878A0 = -1;
        break;
    case 0:
    case 1:
    default:
        cmd_sem_init();
        PowerOffCB();
        break;
    }
    return ver;
}