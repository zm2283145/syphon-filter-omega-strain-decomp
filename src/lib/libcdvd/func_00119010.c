typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
extern int D_00487890;
extern volatile int D_004878AC;
extern int D_00487898;
extern int D_004878CC;
extern int D_004E9D18;
extern int D_004E9D20;
extern RpcCd D_00489400;
extern char D_00498D30[];
extern char D_00498D58[];
extern void cmd_sem_init(void);
extern int PollSema(int);
extern int SignalSema(int);
extern int ReferThreadStatus(int, void *);
extern int sceCdSyncS(int);
extern void sceSifInitRpc(int);
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int scePrintf(const char *, ...);

int _sceCd_scmd_prechk(int cmd)
{
    int i;
    cmd_sem_init();
    if (D_004878AC != PollSema(D_004878AC)) {
        if (D_00487890 > 0) scePrintf(D_00498D30, cmd, D_00487898);
        return 0;
    }
    D_00487898 = cmd;
    ReferThreadStatus(D_004E9D18, &D_004E9D20);
    if (sceCdSyncS(1)) {
        SignalSema(D_004878AC);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_004878CC >= 0) return 1;
    while (1) {
        if (sceSifBindRpc(&D_00489400, 0x80000593, 0) < 0) {
            if (D_00487890 > 0) scePrintf(D_00498D58);
            i = 0x100000;
            while (i--) ;
            continue;
        }
        if (D_00489400.serve != 0) break;
        i = 0x100000;
        while (i--) ;
    }
    D_004878CC = 0;
    return 1;
}