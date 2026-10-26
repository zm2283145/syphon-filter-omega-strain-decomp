extern int NetGetClientInfo(unsigned int, unsigned int, char **);
int NetGetNextMigrateOrder(unsigned int a, int *out)
{
    char *p = 0;
    unsigned int i = 0;
    int r, v;
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 4) return 0x17;
    for (; i < 0x100; i++) {
        r = NetGetClientInfo(a, i, &p);
        if (r) return r;
        if (p && *out < *(int *)(p + 0x24)) *out = *(int *)(p + 0x24);
    }
    v = *out + 1;
    *out = v;
    if (v == 0 || v == 0xFFFFFFF) *out = 1;
    return 0;
}
