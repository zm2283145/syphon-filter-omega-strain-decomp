typedef struct { unsigned int count; float rate; float peak; } Rate2F68F0;
typedef struct { int timer[2]; Rate2F68F0 r[4]; } Stats2F68F0;
extern Stats2F68F0 D_00525508;
extern int func_00306158(void *t, unsigned int *elapsed);
extern int func_002F6998(Rate2F68F0 *p, unsigned int ms);
extern int func_003060C0(void *t);
/* Recomputes the four transfer-rate counters once more than a second has elapsed. */
int func_002F68F0(void)
{
    Stats2F68F0 *s = &D_00525508;
    unsigned int ms;
    int r;

    if (func_00306158(s, &ms) != 0) return 1;
    if (ms > 1000) {
        r = func_002F6998(&s->r[0], ms); if (r) return r;
        r = func_002F6998(&s->r[1], ms); if (r) return r;
        r = func_002F6998(&s->r[2], ms); if (r) return r;
        r = func_002F6998(&s->r[3], ms); if (r) return r;
        if (func_003060C0(s) != 0) return 1;
    }
    return 0;
}
