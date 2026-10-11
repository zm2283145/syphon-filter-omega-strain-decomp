extern unsigned char D_004908EC;
extern int func_002F6418(int, int);
extern int func_003010C8(int);
int func_002FD5A8(int a, int b)
{
    if (D_004908EC != 1) return 5;
    if (a == 0) return 2;
    if (b == 0) return 2;
    {
        int r = func_003010C8(func_002F6418(a, b));
        __asm__ __volatile__("");
        return r;
    }
}