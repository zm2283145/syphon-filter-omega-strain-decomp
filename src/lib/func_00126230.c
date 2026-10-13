extern int D_00489BA4;
extern int D_00489BA0;
extern int D_004868D0;
extern void SignalSema(int);
void func_00126230(void)
{
    if (--D_00489BA4 == 0) {
        D_00489BA0 = -1;
        SignalSema(D_004868D0);
    }
}