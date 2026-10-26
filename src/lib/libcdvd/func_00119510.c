typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
extern int D_00487890;
extern volatile int D_004878AC;
extern int D_004878C8;
extern RpcCd D_004E9F50;
/* asm label: same symbol, but changes gcse's name hash so the hi-part pseudos
   are numbered as in the original build (priority tie-break) */
extern int D_004E9F90 __asm__("D_004E9F90");
extern int D_00488A80[];
extern char D_00498DA0[];
extern char D_00498DB8[];
extern char D_00498DD8[];
extern void cmd_sem_init(void);
extern int PollSema(int);
extern int SignalSema(int);
extern int sceCdSyncS(int);
extern void func_0010FBC0(int);
extern void sceSifWriteBackDCache(void *, int);
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int sceSifCallRpc(RpcCd *, int, int, void *, int, void *, int, void *, void *);
extern void scePrintf(const char *, ...);

/* busy-wait; the nop has no C equivalent */
#define DELAY() { int j = 0x100000; do { j--; __asm__ volatile("nop"); } while (j != -1); }

int sceCdDiskReady_old(int mode)
{
    int ret;
    if (D_00487890 > 0) scePrintf(D_00498DA0);
    cmd_sem_init();
    if (D_004878AC != PollSema(D_004878AC)) return 6;
    if (sceCdSyncS(1)) {
        SignalSema(D_004878AC);
        return mode != 8 ? 6 : -1;
    }
    func_0010FBC0(0);
    if (D_004878C8 < 0) {
        do {
            if (sceSifBindRpc(&D_004E9F50, 0x8000059A, 0) < 0) {
                if (D_00487890 > 0) scePrintf(D_00498DB8);
                DELAY();
                continue;
            }
            if (D_004E9F50.serve != 0) {
                D_004878C8 = 0;
                break;
            }
            DELAY();
        } while (1);
    }
    D_004E9F90 = mode;
    sceSifWriteBackDCache(&D_004E9F90, 4);
    if (sceSifCallRpc(&D_004E9F50, 0, 0, &D_004E9F90, 4, D_00488A80, 4, 0, 0) < 0) {
        SignalSema(D_004878AC);
        return mode != 8 ? 6 : -1;
    }
    if (D_00487890 > 0) scePrintf(D_00498DD8);
    ret = *(int *)((int)D_00488A80 | 0x20000000);
    SignalSema(D_004878AC);
    return ret;
}

