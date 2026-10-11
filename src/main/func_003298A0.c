typedef struct { int a, b, c; } S29930;
typedef struct { S29930 s0; int c; S29930 s1; unsigned char d; int e, f, g; } E2C;
extern void func_00329930(S29930* dst, S29930* src);void func_003298A0(E2C* dst, int n, E2C* src)
{
    for (; n != 0; --n, ++dst) {
        func_00329930(&dst->s0, &src->s0);
        dst->c = src->c;
        func_00329930(&dst->s1, &src->s1);
        dst->d = src->d;
        dst->e = src->e;
        dst->f = src->f;
        dst->g = src->g;
    }
}