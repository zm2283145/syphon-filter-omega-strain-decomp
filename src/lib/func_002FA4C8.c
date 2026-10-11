extern void *memset(void *, int, unsigned int);
extern int func_002FB2D8(int *, unsigned long);
extern int func_002FAF48(char *);
int func_002FA4C8(char *s, unsigned int n)
{
    if (s == 0) return 2;
    if (n < 9) return 2;
    memset(s, 0, 0x18);
    if (func_002FB2D8((int *)(s + 0x10), n)) return 3;
    if (*(int *)(s + 0x10) == 0) return 3;
    *(int *)(s + 8) = n;
    n = func_002FAF48(s);
    __asm__ __volatile__("");
    return n;
}
