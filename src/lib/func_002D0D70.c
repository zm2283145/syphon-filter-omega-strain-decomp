extern void *memset(void *, int, unsigned int);
int func_002D0D70(int *p)
{
    if (p == 0) return -0xD;
    memset(p, 0, 0xA0);
    p[0] = 0;
    p[0x27] = 0;
    return 0;
}
