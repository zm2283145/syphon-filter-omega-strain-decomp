/*
 * lib/medius: 2 files, 002ED028-002ED168
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ED028 */
typedef struct { int d[4]; } Blk_D028;
typedef struct { int a; int b; int c; int d; Blk_D028 info; } Ent_D028;
extern int D_0048C458;
extern int D_0048C4E0;
extern unsigned int D_0058DF6C;
extern Ent_D028 D_00590358[];
extern unsigned int D_00525408[];
extern void *memcpy(void *, const void *, unsigned int);
int NetIObjectField(int *out, int a, int b, int d, int c, Blk_D028 *info)
{
    int n;
    unsigned int cnt;
    unsigned int sum = 0;
    int i;
    Ent_D028 *e = 0;
    if (D_0048C458 == 0) return 0x11;
    if (out == 0) return 0x17;
    if (b <= 0) return 0x17;
    if (c <= 0) return 0x17;
    n = D_0048C4E0;
    if (n >= 0x40) return 8;
    cnt = D_0058DF6C;
    if (cnt >= 0x400) return 8;
    for (i = 0; i < n; i++) {
        sum += D_00590358[cnt - n + i].b * D_00590358[cnt - n + i].c;
    }
    sum += b * c;
    if (sum >= 0x1DB) return 0x1F;
    e = &D_00590358[D_0058DF6C];
    if (e == 0) return 0xA;
    e->a = a;
    e->b = b;
    e->d = d;
    e->c = c;
    if (info != 0) memcpy(&e->info, info, sizeof(*info));
    D_00525408[D_0048C4E0] = D_0058DF6C;
    *out = D_0048C4E0;
    D_0048C4E0++;
    D_0058DF6C++;
    return 0;
}
/* merge_units: end func_002ED028 */

/* merge_units: begin func_002ED168 */
typedef struct { int off; int a; int b; int kind; } E2ED168;
typedef struct { int a; int n; char p[0x20]; E2ED168 *e[(0x228 - 0x28) / 4]; } U2ED168;
typedef struct { int a; int cnt; char p[0x20]; E2ED168 *objs[64]; int vals[64]; } S2ED168;
extern U2ED168 D_0058BD18[];
void RegisterChildStructure(S2ED168 *s, U2ED168 *u, int base)
{
    int i;
    E2ED168 *e;
    if (s == 0 || u == 0) return;
    for (i = 0; i < u->n; i++) {
        e = u->e[i];
        if (s->cnt >= 64) return;
        if (e->kind >= 16) {
            RegisterChildStructure(s, &D_0058BD18[e->kind], base + e->off);
        } else {
            s->vals[s->cnt] = base + e->off;
            s->objs[s->cnt] = e;
            s->cnt++;
        }
    }
}
/* merge_units: end func_002ED168 */
