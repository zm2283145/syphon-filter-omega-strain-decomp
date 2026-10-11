typedef struct { int a, b, c; } S29930;
typedef struct { S29930 s0; int c; S29930 s1; unsigned char d; int e, f, g; } E2C;
extern void func_00329930(S29930* dst, S29930* src);E2C* func_003299D0(E2C* first, E2C* last, E2C* result)
{
    while (first < last) {
        --last;
        --result;
        func_00329930(&result->s0, &last->s0);
        result->c = last->c;
        func_00329930(&result->s1, &last->s1);
        result->d = last->d;
        result->e = last->e;
        result->f = last->f;
        result->g = last->g;
    }
    return result;
}