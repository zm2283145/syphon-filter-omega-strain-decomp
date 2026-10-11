typedef struct { signed char a, b, c, v; } E32A10;
typedef struct { char pad[0xD8]; int count; E32A10 e[(0xB72 - 0xDC) / 4]; char p[2]; unsigned char dirty; } T32A10;
static inline unsigned char Has32A10(T32A10* self, int a, int b, int c)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E32A10* e = &self->e[i];
        if (e->a == a && e->b == b && e->c == c)
            return 1;
    }
    return 0;
}
void func_00332A10(T32A10* self, int a, int b, int c)
{
    if (!Has32A10(self, a, b - 1, c - 1)) {
        E32A10* e = &self->e[self->count++];
        e->a = a;
        e->b = b - 1;
        e->c = c - 1;
        e->v = 0;
        self->dirty = 1;
    }
}