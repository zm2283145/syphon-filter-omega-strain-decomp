extern void *memset(void *, int, unsigned int);
int NetISetDefaultResolveAddrParams(int *p)
{
    if (p == 0) return 0x17;
    memset(p, 0, 0x20);
    p[0] = 1;
    return 0;
}
