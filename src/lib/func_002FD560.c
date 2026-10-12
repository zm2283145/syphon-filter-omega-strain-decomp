extern unsigned char D_004908EC;
extern int func_002F6400(void *p);
extern int func_003010C8(int);
int func_002FD560(void *p)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (p == 0) return 2;
    r = func_003010C8(func_002F6400(p));
    __asm__ __volatile__(""); /* barrier: retail keeps jal + return, no sibling call */
    return r;
}

