typedef struct { int x0; int x4; int x8; int xC; } Ent0CB0;
extern Ent0CB0 D_004E5D00[];
extern int D_00486248;
extern void func_00110C50(void);
extern int WaitSema(int);
extern int SignalSema(int);

Ent0CB0 *func_00110CB0(void)
{
    Ent0CB0 *e;
    func_00110C50();
    WaitSema(D_00486248);
    for (e = D_004E5D00; e < D_004E5D00 + 32; e++) {
        if (e->x4 == 0) {
            e->x4 = 0x10000000;
            SignalSema(D_00486248);
            return e;
        }
    }
    SignalSema(D_00486248);
    return 0;
}