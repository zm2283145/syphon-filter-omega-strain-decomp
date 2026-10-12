extern int func_002FB2D8(void **out, long sz);
extern void *memset(void *, int, unsigned int);
int Net_AllocZeroed(void **out, long sz)
{
    int r;
    if (out == 0) return 1;
    *out = 0;
    r = func_002FB2D8(out, sz);
    if (r) return r;
    if (*out) {
        memset(*out, 0, sz);
        return 0;
    }
    return 1;
}
