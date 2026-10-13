int D_00489BA0 = -1;
int D_00489BA4 = 0;
extern int D_004868D0;
extern int func_0010D050(void);
extern void WaitSema(int);
void func_001261B0(void)
{
    int self = func_0010D050();
    if (D_00489BA0 == self) {
        D_00489BA4++;
        return;
    }
    WaitSema(D_004868D0);
    D_00489BA0 = self;
    D_00489BA4++;
}
