typedef struct Ent {
    int f0;
    short f4, f6, f8, fA, fC;
    char fE;
} Ent;
extern Ent **D_0051F0D0;
extern int func_002E6088(unsigned int);
extern Ent *func_002DD2E8(int);
Ent *func_002DB270(unsigned int a, unsigned int i)
{
    Ent *p = 0;
    if (func_002E6088(i) != 1) return 0;
    if (a < 4) {
        if (i < 0x100) {
            p = func_002DD2E8(0x1C);
            D_0051F0D0[i] = p;
            p->f0 = 0;
            p->f4 = 0;
            p->f6 = 0;
            p->f8 = 0;
            p->fA = 0;
            p->fC = 0;
            p->fE = 0;
        }
        return p;
    }
    return 0;
}

