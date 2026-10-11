extern int func_00326230(void);
extern int func_003262E8(void);
extern void func_00326690(void *, int);

void func_00326728(void *t)
{
    int tz = func_00326230();
    int d = func_003262E8() * 60 - 540;
    func_00326690(t, tz + d);
}
