typedef struct { unsigned char mask[0x24]; int n; int f28; } R;
typedef struct { char pad[0x400]; int self; char pad2[0x40]; int n; } S;
typedef struct {
    unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3;
    int f4; unsigned int f8; char name[0x10];
    char *f1C; char *f20; int f24; int f28; int f2C; int f30; int f34; int *f38; int *f3C;
} E;
typedef struct { int pad; int f4; int f8; } X;
typedef struct { int size; int n; char pad[0x20]; X *items[0x40]; int offs[0x40]; } T;
typedef struct {
    unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3;
    unsigned char f4; unsigned short f6; unsigned short id;
    int fC; int f10; char name[0x10];
} H;
extern unsigned int D_0048C450;
extern T D_0058DF98[];
extern char D_0051FAD8[];
extern int D_0058806C;
extern unsigned int D_005983F4;
extern int (*D_00590218[])(int, unsigned int);
extern int func_002DD968(E **, unsigned int);
extern int func_002E51B8(unsigned int, S **);
extern void func_002E2DD0(R *, unsigned int);
extern unsigned char func_002E6090(unsigned int);
extern char *String_Copy(char *, const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002DB188(int *, unsigned int, int);
extern int func_002DE5E8(signed char, unsigned int, unsigned int, unsigned int, int, void *, R *);
extern int func_002DE880(signed char, unsigned int, int, unsigned int, int, void *);

int func_002E3340(int to, unsigned int id)
{
    H h;
    R r;
    E *e;
    S *s;
    T *t;
    register X *x asm("$5"); /* pinned: retail keeps x in a1 across the copy loop */
    int ret;
    int i;
    int off;
    int sz;
    int ok;
    int j;

    e = 0;
    s = 0;
    if (id >= 0x1000) return 0x17;
    func_002DD968(&e, id);
    if (e == 0) return 0xA;
    ret = func_002E51B8(D_0048C450, &s);
    if (ret != 0) return ret;
    if (s == 0) return ret;
    if (e->f1 != 0) {
        if (to == -1) func_002E2DD0(&r, id);
        else if (D_00590218[e->f1](to, id) == 0) return 0;
    }
    t = &D_0058DF98[e->f0];
    if (t == 0) return 0xA;
    if (e->f4 != -1 && e->f4 != s->self) return 8;
    off = 0x24;
    h.f0 = func_002E6090(e->f8);
    h.id = id;
    h.f6 = e->f4;
    h.f1 = e->f0;
    h.f2 = e->f1;
    h.f4 = e->f2;
    h.f3 = e->f3;
    h.fC = e->f2C;
    h.f10 = e->f30;
    String_Copy(h.name, e->name);
    memcpy(D_0051FAD8, &h, sizeof(h));
    for (i = 0; i < t->n; i++) {
        x = t->items[i];
        if (x == 0) return 0xA;
        sz = x->f4 * x->f8;
        if (sz > 0x1FE - off) break;
        memcpy(&D_0051FAD8[off], e->f1C + t->offs[i], sz);
        off += sz;
        e->f3C[i] = D_0058806C;
    }
    e->f34 = D_0058806C;
    if (to == -1) {
        memcpy(e->f20, e->f1C, t->size);
        for (j = 0; j < s->n; j++) {
            func_002DB188(&ok, D_0048C450, j);
            if (ok != 0) e->f38[j] = D_0058806C;
        }
    } else {
        e->f38[to] = D_0058806C;
    }
    if (e->f1 != 0 && to == -1) func_002DE5E8(0x50, D_0048C450, 0, D_005983F4, off, D_0051FAD8, &r);
    else func_002DE880(0x50, D_0048C450, to, D_005983F4, off, D_0051FAD8);
    return 0;
}
