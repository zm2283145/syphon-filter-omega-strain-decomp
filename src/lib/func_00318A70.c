typedef struct { float f; int i; } P8A70;
extern P8A70* (*D_004E1D34)(int, int);
int func_00318A70(P8A70** out)
{
    P8A70* p = D_004E1D34(1, 8);
    *out = p;
    if (p == 0)
        return 1;
    p->i = 0;
    p->f = 100.0f;
    return 0;
}
