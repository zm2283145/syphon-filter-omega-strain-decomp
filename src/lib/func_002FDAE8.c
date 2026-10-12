typedef struct { char pad[5]; unsigned char f5; } S;
typedef struct { char pad[0x28]; char f28[8]; int f30; } M;
typedef struct { unsigned short id; char pad[6]; int f8; char pad2[0x6C]; S *sub[2]; M *main; } O;
extern unsigned char D_004908EC;
extern int func_002FE720(O *);
extern int func_002FDC60(O *);
extern int func_002FDDF0(O *, S *);
extern int func_002FE090(O *, S *, unsigned char);
extern int func_003060F0(void *, unsigned int *);
int func_002FDAE8(O *o, unsigned char flag)
{
    unsigned int t = 0;
    unsigned int i;
    int r;
    M *m;
    if (D_004908EC != 1) return 5;
    if (func_002FE720(o) != 1) return 2;
    if (o->f8 == 2) {
        r = func_002FDC60(o);
        if (r) return r;
        if (o->f8 == 2) return 0;
    }
    for (i = 0; i < 2; i++) {
        if (o->sub[i] && o->sub[i]->f5 == 1) {
            r = func_002FDDF0(o, o->sub[i]);
            if (r) return r;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->sub[i] && o->sub[i]->f5 == 1) {
            r = func_002FE090(o, o->sub[i], flag);
            if (r) return r;
        }
    }
    if (o->f8 == 8) {
        m = o->main;
        if (m->f30) {
            if (func_003060F0(m->f28, &t)) return 0x18;
            if (t > 35000) return 0x19;
        }
    }
    return 0;
}

