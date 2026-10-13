typedef struct { int a[4]; } Ent0D38;
extern Ent0D38 D_004E5D00[];
extern int D_00486248;
extern void func_00110C50(void);
extern int WaitSema(int);
extern int SignalSema(int);

Ent0D38 *func_00110D38(unsigned int idx)
{
    Ent0D38 *r;
    func_00110C50();
    WaitSema(D_00486248);
    if (idx >= 32) {
        SignalSema(D_00486248);
        return 0;
    }
    r = &D_004E5D00[idx];
    SignalSema(D_00486248);
    return r;
}