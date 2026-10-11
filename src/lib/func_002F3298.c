extern int Net_AllocZeroed(int** out, unsigned long n);
int* func_002F3298(void)
{
    int* p = 0;
    Net_AllocZeroed(&p, 8);
    if (p) {
        p[0] = 0;
        p[1] = 0;
    }
    return p;
}
