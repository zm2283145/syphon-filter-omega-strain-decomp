extern int D_00489738;
extern void func_001261B0(int);
extern int _malloc_r(int, int);
extern void func_00126230(int);
int func_00125368(int a)
{
    int r;
    func_001261B0(D_00489738);
    r = _malloc_r(D_00489738, a);
    func_00126230(D_00489738);
    return r;
}