extern void *memset(void *, int, unsigned int);
extern int func_002E51B8(unsigned int, char **);
extern int func_002DDB98(int *, unsigned int);
extern int func_002DDC00(int *, unsigned int);
int func_002DDCA0(int *out, unsigned int idx)
{
    char *p = 0;
    int r;
    if (out == 0) return 0x17;
    memset(out, 0, 0xC);
    if (idx >= 4) return 0x17;
    r = func_002E51B8(idx, &p);
    if (r) return r;
    if (p == 0) return 0xF;
    r = func_002DDB98(out, idx);
    if (r) return r;
    r = func_002DDC00(out + 1, idx);
    if (r) return r;
    out[2] = out[1] + *(int *)(p + 0x440);
    return r;
}
