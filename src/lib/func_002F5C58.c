extern void *memset(void *, int, unsigned int);
int func_002F5C58(int *p)
{
    if (p == 0) return 2;
    memset(p, 0, 0xC);
    p[0] = 0;
    return 0;
}
