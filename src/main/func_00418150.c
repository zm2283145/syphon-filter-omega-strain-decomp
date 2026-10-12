typedef struct { char p0[12]; signed char fC; char pD[3]; int f10; int f14; } E418;
int func_00329930(E418 *, E418 *);
static inline void cc418(E418 *d, E418 *s) { func_00329930(d, s); d->fC = s->fC; d->f10 = s->f10; d->f14 = s->f14; }
void func_00418150(E418 *p, int n, E418 *v) {
    for (; n != 0; --n, ++p) cc418(p, v);
}