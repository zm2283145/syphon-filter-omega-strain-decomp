typedef struct { int off; int a; int b; int kind; } E2ED168;
typedef struct { int a; int n; char p[0x20]; E2ED168 *e[(0x228 - 0x28) / 4]; } U2ED168;
typedef struct { int a; int cnt; char p[0x20]; E2ED168 *objs[64]; int vals[64]; } S2ED168;
extern U2ED168 D_0058BD18[];
void func_002ED168(S2ED168 *s, U2ED168 *u, int base)
{
    int i;
    E2ED168 *e;
    if (s == 0 || u == 0) return;
    for (i = 0; i < u->n; i++) {
        e = u->e[i];
        if (s->cnt >= 64) return;
        if (e->kind >= 16) {
            func_002ED168(s, &D_0058BD18[e->kind], base + e->off);
        } else {
            s->vals[s->cnt] = base + e->off;
            s->objs[s->cnt] = e;
            s->cnt++;
        }
    }
}