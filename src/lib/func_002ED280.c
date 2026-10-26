typedef struct { int off; int a; int b; int kind; int pad[4]; } E2ED280;
typedef struct { int a; int cnt; char name[0x20]; E2ED280 *objs[64]; int vals[64]; } S2ED280;
extern int D_0048C458;
extern int D_0048C4E0;
extern unsigned int D_0058DF70;
extern S2ED280 D_0058DF98[];
extern E2ED280 D_00590358[];
extern unsigned int D_00525408[];
extern char *strncpy(char *, const char *, unsigned int);
void RegisterChildStructure(S2ED280 *s, S2ED280 *u, int base);
int NetIRegisterStructure(int *out, const char *name, int a)
{
    S2ED280 *s;
    E2ED280 *e;
    int i = 0;
    if (D_0048C458 == 0) return 0x11;
    if (out == 0) return 0x17;
    if (name == 0) return 0x17;
    if (a <= 0) return 0x17;
    if (D_0058DF70 >= 0x10) return 8;
    s = &D_0058DF98[D_0058DF70];
    if (s == 0) return 0xA;
    s->a = a;
    s->cnt = 0;
    strncpy(s->name, name, 0x20);
    for (; i < D_0048C4E0; i++) {
        if (s->cnt >= 64) return 8;
        e = &D_00590358[D_00525408[i]];
        if (e != 0) {
            if (e->kind >= 16) {
                RegisterChildStructure(s, &D_0058DF98[e->kind - 16], e->off);
            } else {
                s->vals[s->cnt] = e->off;
                s->objs[s->cnt] = e;
                s->cnt++;
            }
        }
    }
    *out = D_0058DF70;
    D_0058DF70++;
    return 0;
}


