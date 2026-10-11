extern void func_002F7F60(void);
extern int func_00301F40(void);
void func_002F9728(int *a)
{
    unsigned char i;
    func_002F7F60();
    for (i = 0; i < 16; i++) a[i] = func_00301F40();
}