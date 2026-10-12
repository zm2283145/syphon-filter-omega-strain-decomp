extern unsigned char D_004908EC;
extern int func_002F63E8(void *p);
extern int func_003010C8(int);
int func_002FD518(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = func_003010C8(func_002F63E8(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}

