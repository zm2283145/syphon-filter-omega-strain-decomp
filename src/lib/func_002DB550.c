#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct Ent {
    int f0;
    unsigned short f4, f6, f8, fA, fC;
    char name[1];
} Ent;
typedef struct Msg {
    unsigned char b0;
    char pad1[7];
    unsigned short s8, sA, sC, sE, s10;
    char pad12[4];
    char name[0x12];
} Msg;
extern unsigned int D_0048C450;
extern int D_00598410;
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern unsigned char func_002E6090(unsigned int);
extern void func_002DB188(Ent **, unsigned int, unsigned int);
extern char *String_Copy(char *, const char *);
extern int func_002DE880(int, unsigned int, int, int, int, Msg *);
int func_002DB550(unsigned int slot, int who)
{
    Msg m;
    void *p = 0;
    void *q = 0;
    Ent *e;
    int r;
    if ((unsigned int)(who + 1) > 0x100) return 0x17;
    if (slot >= 4) return 0x17;
    r = func_002E51B8(slot, &p);
    if (r) return r;
    if (p == 0) return 8;
    r = func_002E52D8(slot, F(p, unsigned int, 0x400), &q);
    if (r) return r;
    if (q == 0) return 8;
    func_002DB188(&e, slot, F(p, unsigned int, 0x400));
    if (e == 0) return 0x15;
    if ((unsigned int)(F(q, int, 0x14) - 4) < 2) {
    m.b0 = func_002E6090(F(p, unsigned int, 0x400));
    m.s8 = e->f4;
    m.sA = e->f6;
    m.sC = e->f8;
    m.sE = e->fA;
    m.s10 = e->fC;
    String_Copy(m.name, e->name);
    func_002DE880(0x50, D_0048C450, who, D_00598410, 0x24, &m);
    return 0;
    }
    return 0x15;
}


