extern void *memset(void *, int, unsigned int);
extern unsigned char D_0048C4B4;
extern int D_00522758;
extern int D_0048C474;
extern void (*D_0048C470)(void *);
extern void func_003060F0(int *, unsigned int *);
typedef struct { int a, b, c, d, e; } M2E5ED8;
int func_002E5ED8(void)
{
    M2E5ED8 m;
    unsigned int t;
    if (D_0048C4B4) {
        func_003060F0(&D_00522758, &t);
        if (t >= 0x1F5) {
            memset(&m, 0, 0x14);
            m.e = D_0048C474;
            m.a = 0;
            m.b = 0;
            m.c = 0;
            m.d = 0;
            D_0048C470(&m);
            D_0048C4B4 = 0;
        }
    }
    return 0;
}
