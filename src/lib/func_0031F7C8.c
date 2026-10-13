extern void *(*D_004E1D34)(int, int);
extern int func_003220B8(void *pp);

typedef struct {
    void *sub;
    float *a;
    float *b;
    float *c;
    float *d;
    float *e;
    float *f;
    int pad1C;
    float g0, g1, g2, g3;
    float h;
    float i;
    int pad38;
    int j;
    int pad40;
    short k;
    int l;
    float m;
    int pad50;
} State;

int func_0031F7C8(State **pp)
{
    State *s;

    if (!pp)
        return 1;
    *pp = 0;
    s = D_004E1D34(1, sizeof(State));
    if (!s)
        return 1;
    *pp = s;
    if (!(s->a = D_004E1D34(0x284, 4)))
        return 1;
    if (!(s->b = D_004E1D34(0x50, 4)))
        return 1;
    if (func_003220B8(s))
        return 1;
    s->k = 1;
    s->l = 1;
    s->g0 = 1.0f;
    s->g1 = 1.0f;
    s->g2 = 1.0f;
    s->g3 = 1.0f;
    s->h = 1.0f;
    s->i = 80.0f;
    s->j = 0;    if (!(s->c = D_004E1D34(0x41, 4)))
        return 1;
    if (!(s->d = D_004E1D34(0x41, 4)))
        return 1;
    if (!(s->e = D_004E1D34(0x66, 4)))
        return 1;
    if (!(s->f = D_004E1D34(0x66, 4)))
        return 1;
    s->m = 100.0f;
    return 0;
}




