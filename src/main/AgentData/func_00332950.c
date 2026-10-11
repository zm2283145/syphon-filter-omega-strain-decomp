typedef struct { signed char a, b, c, v; } E32950;
typedef struct { char pad[0xD8]; int count; E32950 e[1]; } T32950;
int func_00332950(T32950* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E32950* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return e->v != 0;
    }
    return 0;
}