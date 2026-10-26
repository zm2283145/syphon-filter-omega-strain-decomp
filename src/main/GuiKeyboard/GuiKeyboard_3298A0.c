typedef struct { int a, b, c; } S29930;
typedef struct { S29930 s0; int c; S29930 s1; unsigned char d; int e, f, g; } E2C;
extern void cString_opAssign(S29930* dst, S29930* src);void std_fill_n_Slide_int_fill_n(E2C* dst, int n, E2C* src)
{
    for (; n != 0; --n, ++dst) {
        cString_opAssign(&dst->s0, &src->s0);
        dst->c = src->c;
        cString_opAssign(&dst->s1, &src->s1);
        dst->d = src->d;
        dst->e = src->e;
        dst->f = src->f;
        dst->g = src->g;
    }
}