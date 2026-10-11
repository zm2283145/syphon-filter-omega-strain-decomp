extern int D_00489BA0;
extern int D_00489BA4;
extern int D_004868D0;
extern int func_0010D050(void);
extern void func_0010D1A0(int);
void func_001261B0(void)
{
    int self = func_0010D050();
    if (D_00489BA0 == self) {
        D_00489BA4++;
        return;
    }
    func_0010D1A0(D_004868D0);
    D_00489BA0 = self;
    D_00489BA4++;
}
