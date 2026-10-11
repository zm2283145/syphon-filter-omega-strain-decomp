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
extern void func_00118718(void);
extern int func_0010D1B0(int);
extern int func_0010D180(int);
extern int func_0010D060(int, void *);
extern int func_00118FA0(int);
extern void D_0010FBC0(int);
extern int func_00110358(RpcCd *cd, unsigned int id, int mode);
extern int func_0010F388(const char *, ...);

int func_00119010(int cmd)
{
    int i;
    func_00118718();
    if (D_004878AC != func_0010D1B0(D_004878AC)) {
        if (D_00487890 > 0) func_0010F388(D_00498D30, cmd, D_00487898);
        return 0;
    }
    D_00487898 = cmd;
    func_0010D060(D_004E9D18, &D_004E9D20);
    if (func_00118FA0(1)) {
        func_0010D180(D_004878AC);
        return 0;
    }
    D_0010FBC0(0);
    if (D_004878CC >= 0) return 1;
    while (1) {
        if (func_00110358(&D_00489400, 0x80000593, 0) < 0) {
            if (D_00487890 > 0) func_0010F388(D_00498D58);
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