extern unsigned char D_004908EC;
extern int func_002F6550(void);
extern int func_003010C8(int);
int func_002FD980(void)
{
    int r;
    if (D_004908EC != 1)
        return 5;
    r = func_003010C8(func_002F6550());
    __asm__ __volatile__("");
    return r;
}
