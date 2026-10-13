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
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern void func_002DB188(Ent **, unsigned int, unsigned int);
extern Ent *func_002DB270(unsigned int, unsigned int);
extern void func_002DB720(unsigned int, unsigned int);
extern char *String_Copy(char *, const char *);

int func_002E6C78(unsigned int slot, int a1, int a2, Msg *m)
{
    Ent *e = 0;
    void *p = 0;
    void *q = 0;
    unsigned int id;
    int r;

    if (m == 0) return -1;
    r = 0x24;
    if (func_002E51B8(slot, &p) == 0 && p != 0
        && func_002E52D8(slot, F(p, unsigned int, 0x400), &q) == 0 && q != 0
        && (unsigned int)(F(q, int, 0x14) - 4) < 2) {
        id = m->b0;
        if (slot >= 4) return r;
        if (id >= 0x100) return r;
        func_002DB188(&e, slot, id);
        if (e == 0) {
            e = func_002DB270(slot, id);
            if (e == 0) return r;
        }
        e->f4 = m->s8;
        e->f6 = m->sA;
        e->f8 = m->sC;
        e->fA = m->sE;
        e->fC = m->s10;
        String_Copy(e->name, m->name);
        if (e->f0 == 0) func_002DB720(slot, id);
    }
    return 0x24;
}
