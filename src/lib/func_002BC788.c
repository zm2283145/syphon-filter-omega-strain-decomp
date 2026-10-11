typedef struct { int v; int pad[6]; } EC788;
extern EC788 D_00518A0C[];
extern int func_0026A8C8(int h);
int func_002BC788(int i)
{
    return func_0026A8C8(D_00518A0C[i].v) != 3;
}
