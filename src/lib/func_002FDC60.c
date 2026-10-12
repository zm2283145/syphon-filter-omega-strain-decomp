typedef struct { char pad[0x20]; char f20[8]; char f28[0xC]; char f34[4]; } S;
typedef struct { char pad[0x1C]; int f1C; } M;
typedef struct { unsigned short id; char pad[2]; int f4; int f8; char pad2[0x16]; unsigned short f22; char pad3[0x18]; int f3C; unsigned short f40; char pad4[0x36]; S *sub[2]; M *main; } O;
extern unsigned char D_004908EC;
extern int func_002FE720(O *);
extern int func_002F6628(int, unsigned char *);
extern int func_003010C8(int);
extern int func_003060C0(void *);
extern int func_00301758(unsigned short, unsigned char *);
extern int func_002FE8D8(M *, unsigned short);
extern int func_002FE958(int, M *, unsigned short, int, unsigned short);
extern int func_00301038(O *, int);
int func_002FDC60(O *o)
{
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned int i;
    int r;
    S *s;
    if (D_004908EC != 1) return 5;
    if (func_002FE720(o) != 1) return 2;
    if (o->f8 != 2) return 2;
    r = func_003010C8(func_002F6628(o->main->f1C, &a));
    if (r) return r;
    if (a == 1) {
        for (i = 0; i < 2; i++) {
            s = o->sub[i];
            if (s) {
                if (func_003060C0(s->f20)) return 0x18;
                if (func_003060C0(s->f28)) return 0x18;
                if (func_003060C0(s->f34)) return 0x18;
            }
        }
        r = func_00301758(o->id, &b);
        if (r) return r;
        if (b == 1) {
            r = func_002FE8D8(o->main, o->f22);
            if (r) return r;
            r = func_00301038(o, 3);
            if (r) return r;
        } else {
            r = func_002FE958(o->f4, o->main, o->f22, o->f3C, o->f40);
            if (r) return r;
            r = func_00301038(o, 4);
            if (r) return r;
        }
    }
    return 0;
}

