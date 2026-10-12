const unsigned int D_0048C4B0[1] = { 0x0 };
extern int func_00302C00(int, int *, int *, int *, int *);
extern int func_002DCD00(unsigned int);
extern int func_002FBFB8(int, int *, int *, int *, int *);
extern int func_002E5008(int, int);
int func_002DCF40(unsigned int a, int *o0, int *o1, int *o2, int *o3)
{
    int v[4];
    int r;
    if (a == 0xFFFF || a == 0) {
        if (func_00302C00((*(int*)D_0048C4B0), &v[0], &v[1], &v[2], &v[3])) return 0x25;
    } else {
        r = func_002E5008(func_002FBFB8(func_002DCD00(a), &v[0], &v[1], &v[2], &v[3]), 0x18);
        if (r) return r;
    }
    if (o0) *o0 = v[0];
    if (o1) *o1 = v[1];
    if (o2) *o2 = v[2];
    if (o1) *o3 = v[3];
    return 0;
}
