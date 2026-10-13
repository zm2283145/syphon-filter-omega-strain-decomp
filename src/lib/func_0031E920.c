typedef struct {
    float x;
    float y;
    char pad8[0x13 - 8];
    unsigned char flag;
} S_0031E920;
void func_0031E920(S_0031E920* s, float lim)
{
    float x = s->x;
    float y;
    if (x > 160000.0f) y = (x * -0x1.846f3ap-24f + 0x1.c49362p+1f) * x + 62071.0f; else y = (x * -0x1.7417b8p-18f + 0x1.030488p+2f) * x + 362.0f;
    s->y = y;
    s->flag = y < lim;
}
