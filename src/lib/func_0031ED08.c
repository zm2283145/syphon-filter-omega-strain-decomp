typedef struct {
    float a;
    float b;
    float c;
    short pad;
    short e;
    short f;
    signed char g;
    unsigned char h;
    unsigned char i;
    unsigned char j;
} S;

extern const float D_004E1C34;
extern void *(*D_004E1D34)(int n, int size);

int func_0031ED08(S **pp, short n, float f)
{
    S *s;
    if (pp == 0) return 1;
    *pp = 0;
    s = D_004E1D34(1, 0x18);
    if (s == 0) return 1;
    *pp = s;
    s->a = 5059644.0f;
    s->b = 15636450.0f;
    s->e = 0; s->f = 0; s->g = -2; s->h = 0; s->i = 0; s->j = 0;
    s->c = f * D_004E1C34 / n;
    return 0;
}
