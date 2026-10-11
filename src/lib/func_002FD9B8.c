extern int func_002FE860(unsigned short, char **);
extern int func_002F6568(int, int);
extern int func_003010C8(int);
int func_002FD9B8(unsigned short a, int b)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    r = func_002FE860(a, &p);
    if (r) return r;
    r = func_003010C8(func_002F6568(*(int *)(*(char **)(p + 0x80) + 0x1C), b));
    __asm__ __volatile__("");
    return r;
}