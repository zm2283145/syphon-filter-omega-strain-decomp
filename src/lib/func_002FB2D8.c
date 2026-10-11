extern void *(*D_004908E0)(int);
extern void *func_00125368(int);
int func_002FB2D8(void **out, long sz)
{
    void *p;
    if (D_004908E0 == 0) {
        p = func_00125368(sz);
        *out = p;
        if (p == 0) return 1;
    } else {
        p = D_004908E0(sz);
        *out = p;
        if (p == 0) return 1;
    }
    return 0;
}
