typedef struct { int v; int pad[6]; } EC2A8;
extern EC2A8 D_00518A1C[];
extern void _sceMcCoreReadPage2(int i, int a, int b, int c, int v);
void func_002BC2A8(int i, int a, int b, int c)
{
    _sceMcCoreReadPage2(i, a, b, c, D_00518A1C[i].v);
}
