extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, unsigned char **);
extern void func_002DCA70(unsigned int, unsigned int);
extern void func_002E8C50(unsigned int, unsigned int, unsigned int, unsigned int);
int func_002E8228(unsigned int port, int unused, unsigned int b, unsigned char *m)
{
    char *p = 0;
    unsigned char *q = 0;
    int ret = -1;
    unsigned int idx;
    if (m == 0) return ret;
    if (port >= 4) return ret;
    if (b >= 0x100) return ret;
    if (func_002E51B8(port, &p) != 0) return -1;
    if (p == 0) goto fail;
    if (func_002E52D8(port, m[1], &q) != 0) return -1;
    if (q == 0) {
fail:
        return -1;
    }
    if (q[0x28] != 1) return -1;
    *(int *)(q + 0x14) = m[0];
    idx = *(unsigned int *)(p + 0x400);
    if (idx >= 0x100) return ret;
    func_002DCA70(port, m[1]);
    if (*(int *)(*(char **)(p + (idx << 2)) + 0x14) == 5) func_002E8C50(port, m[1], m[2], m[3]);
    return 4;
}

