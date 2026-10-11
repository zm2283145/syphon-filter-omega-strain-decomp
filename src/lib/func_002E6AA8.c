typedef struct { signed char f0; unsigned char f1; char name[6]; char f8[8]; } Q;
typedef struct { char pad[0x400]; int f400; } Ctx;
extern char D_00588074[];
extern unsigned short D_0058D178, D_0058C0B0;
extern int func_002E51B8(int, Ctx **);
extern int func_002DD440(char *, char *);
extern int strcmp(const char *, const char *);
extern int func_002DCD00(int);
extern int func_002F84D0(int, int, char *);
extern int func_002DD5B8(int, int, char *, int);
int func_002E6AA8(int h, int b, int c, Q *q)
{
    char name[16];
    Ctx *ctx[1];
    int h2 = h;
    ctx[0] = 0;
    if (q == 0) return -1;
    if (func_002E51B8(h, ctx) || ctx[0] == 0) return -1;
    func_002DD440(name, q->name);
    if (q->f0 == 0) h2 = 0;
    if (strcmp(name, D_00588074) != 0 || q->f1 != ctx[0]->f400) {
        if (h == 0xFFFF) func_002F84D0(-1, q->f1, q->f8);
        else if (h == 0) func_002F84D0(0, q->f1, q->f8);
        else func_002F84D0(func_002DCD00(h), q->f1, q->f8);
    }
    func_002DD5B8(h2, q->f1, name, D_0058D178 == 0 ? D_0058C0B0 : D_0058D178);
    return 0x48;
}


