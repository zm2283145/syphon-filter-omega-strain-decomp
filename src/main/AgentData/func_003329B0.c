typedef struct { signed char a, b, c, v; } E329B0;
typedef struct { char pad[0xD8]; int count; E329B0 e[1]; } T329B0;
int func_003329B0(T329B0* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E329B0* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return 1;
    }
    return 0;
}