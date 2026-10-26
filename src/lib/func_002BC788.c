typedef struct { int v; int pad[6]; } EC788;
extern EC788 D_00518A0C[];
extern int sceDbcGetConnection(int h);
int func_002BC788(int i)
{
    return sceDbcGetConnection(D_00518A0C[i].v) != 3;
}
