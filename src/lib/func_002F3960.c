extern void Net_AllocZeroed(void *, int);
int *func_002F3960(int a, int b)
{
    int *p = 0;
    Net_AllocZeroed(&p, 0x30);
    if (p) {
        p[0] = a;
        p[1] = b;
    }
    return p;
}