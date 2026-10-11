typedef struct { int a[4]; } Ent0D38;
extern Ent0D38 D_004E5D00[];
extern int D_00486248;
extern void func_00110C50(void);
extern int func_0010D1A0(int);
extern int func_0010D180(int);

Ent0D38 *func_00110D38(unsigned int idx)
{
    Ent0D38 *r;
    func_00110C50();
    func_0010D1A0(D_00486248);
    if (idx >= 32) {
        func_0010D180(D_00486248);
        return 0;
    }
    r = &D_004E5D00[idx];
    func_0010D180(D_00486248);
    return r;
}