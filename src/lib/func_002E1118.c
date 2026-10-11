extern void *memset(void *, int, unsigned int);
int func_002E1118(int *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x74);
    p[0] = 1;
    return 0;
}
