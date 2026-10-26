extern int D_00489738;
extern int Newlib_FindenvR(int r, int x, void* st);
int Libc_Getenv(int x)
{
    int st[2];
    return Newlib_FindenvR(D_00489738, x, st);
}