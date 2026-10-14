typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
extern int D_00487890;
extern volatile int D_004878A8;
extern int D_0048789C;
extern int D_004878BC;
extern int D_004E9D18;
extern int D_004E9D20;
extern RpcCd D_00488A50;
extern char D_00498CD0[];
extern char D_00498CF8[];
extern void func_00118718(void);
extern int func_0010D1B0(int);
extern int SignalSema(int);
extern int ReferThreadStatus(int, void *);
extern int sceCdSync(int);
extern void func_0010FBC0(int);
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int scePrintf(const char *, ...);

int func_00118CF8(int cmd)
{
    int i;
    func_00118718();
    if (D_004878A8 != func_0010D1B0(D_004878A8)) {
        if (D_00487890 > 0) scePrintf(D_00498CD0, cmd, D_0048789C);
        return 0;
    }
    D_0048789C = cmd;
    ReferThreadStatus(D_004E9D18, &D_004E9D20);
    if (sceCdSync(1)) {
        SignalSema(D_004878A8);
        return 0;
    }
    func_0010FBC0(0);
    if (D_004878BC >= 0) return 1;
    while (1) {
        if (sceSifBindRpc(&D_00488A50, 0x80000595, 0) < 0) {
            if (D_00487890 > 0) scePrintf(D_00498CF8);
            i = 0x100000;
            while (i--) ;
            continue;
        }
        if (D_00488A50.serve != 0) break;
        i = 0x100000;
        while (i--) ;
    }
    D_004878BC = 0;
    return 1;
}