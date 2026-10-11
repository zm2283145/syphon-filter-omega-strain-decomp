extern void *memset(void *, int, unsigned int);
extern int func_002FAF18(int *);
extern int func_002FB3C0(int *);
int func_002FA550(int *p)
{
    if (func_002FAF18(p) == 0) return 2;
    if (p[4]) func_002FB3C0(p + 4);
    memset(p, 0, 0x18);
    return 0;
}