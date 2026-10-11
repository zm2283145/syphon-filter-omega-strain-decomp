typedef struct { int v; int pad[6]; } EC2A8;
extern EC2A8 D_00518A1C[];
extern void func_002BC0C8(int i, int a, int b, int c, int v);
void func_002BC2A8(int i, int a, int b, int c)
{
    func_002BC0C8(i, a, b, c, D_00518A1C[i].v);
}
