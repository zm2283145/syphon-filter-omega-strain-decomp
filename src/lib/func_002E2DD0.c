typedef struct { unsigned char mask[0x24]; int n; int f28; } R;
typedef struct { char pad[0x400]; int self; char pad2[0x40]; int n; } S;
extern unsigned int D_0048C450;
extern int (*D_00590218[])(int, unsigned int);
extern int func_002E51B8(unsigned int, S **);
extern int func_002DD968(unsigned char **, unsigned int);
extern int func_002DB188(int *, unsigned int, int);
extern void func_002DDDD0(R *, int);

void func_002E2DD0(R *r, unsigned int id)
{
    unsigned char *e = 0;
    S *s = 0;
    int x;
    int (*cb)(int, unsigned int);
    int i, j;
    unsigned char *p;

    if (r == 0) return;
    if (id >= 0x1000) return;
    if (D_0048C450 >= 4) return;
    if (func_002E51B8(D_0048C450, &s) != 0) return;
    if (s == 0) return;
    func_002DD968(&e, id);
    if (e == 0) return;
    cb = D_00590218[e[1]];
    r->n = s->n;
    r->f28 = -1;
    j = 0x20;
    p = &r->mask[0x20];
    for (; j >= 0; j--) *p-- = 0;
    for (i = 0; i < s->n; i++) {
        x = 0;
        func_002DB188(&x, D_0048C450, i);
        if (x != 0 && i != s->self && cb(i, id) != 0) func_002DDDD0(r, i);
    }
}





