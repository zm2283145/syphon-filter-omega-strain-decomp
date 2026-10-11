typedef struct {
    unsigned short port; short pad;
    int a; int b; int c; int d; int e; int f;
    void *g;
    void *f0; void *f1; void *f2; void *f3; void *f4; void *f5;
} Cfg;
extern unsigned char D_0048C4AC;
extern unsigned char D_0048C4B5;
extern unsigned short D_0058C0B0;
extern int D_0048C49C;
extern int D_0048C4A0;
extern int D_0048C460;
extern int D_0048C4B0;
extern char D_00522760[];
extern void func_002E6178(void);
extern void func_002E6230(void);
extern void func_002E63F0(void);
extern void func_002E64E0(void);
extern void func_002E6590(void);
extern void func_002E6600(void);
extern int func_00302698(Cfg *, int *);
extern int func_003028E8(int);
int func_002DF708(void)
{
    Cfg c;
    if (D_0048C4AC == 0) {
    c.port = D_0058C0B0;
    c.a = 8;
    c.b = 0x200;
    c.c = D_0048C49C;
    c.d = D_0048C4A0;
    c.e = 0x1E;
    c.f = D_0048C460;
    c.f0 = func_002E6178;
    c.f1 = func_002E6230;
    c.f2 = func_002E63F0;
    c.f3 = func_002E64E0;
    c.f4 = func_002E6590;
    c.f5 = func_002E6600;
    if (D_0048C4B5) c.g = D_00522760; else c.g = 0;
    if (func_00302698(&c, &D_0048C4B0)) {
        func_003028E8(D_0048C4B0);
        D_0048C4B0 = 0;
        return 0x25;
    }
    D_0048C4AC = 1;
    }
    return 0;
}

