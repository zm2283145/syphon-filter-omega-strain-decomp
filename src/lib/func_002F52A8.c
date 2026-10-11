extern void *memset(void *, int, unsigned int);
extern int Net_AllocZeroed(int *, unsigned long);
int func_002F52A8(int *s, unsigned int n, int x)
{
    int r;
    if (s == 0) return 2;
    if (n == 0) return 2;
    memset(s, 0, 0x18);
    r = Net_AllocZeroed(s + 4, n);
    if (r) return 3;
    if (s[4] == 0) return 3;
    s[5] = x;
    s[2] = n;
    s[1] = 0;
    s[3] = 0;
    s[0] = 0;
    return r;
}
