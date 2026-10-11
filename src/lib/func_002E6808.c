extern int D_0048C4B0;
extern int func_00302E68(int, int, int *, int *, int *, int *);
int func_002E6808(unsigned int a, int b, int *o0, int *o1, int *o2, int *o3)
{
    int v[4];
    if (a != 0xFFFF && a != 0) return 0xF;
    if (func_00302E68(D_0048C4B0, b, &v[0], &v[1], &v[2], &v[3])) return 0x25;
    if (o0) *o0 = v[0];
    if (o2) *o2 = v[2];
    if (o1) *o1 = v[1];
    if (o3) *o3 = v[3];
    return 0;
}
