typedef struct { int x0; char *x4; int x8; int xC; int x10; } E2EFB28;
typedef struct { unsigned short a, b; } M2EFB28;
extern int func_002DA918(int);
extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(int, int, char *, M2EFB28 *, int);
void func_002EFB28(char *s)
{
    char buf[16];
    M2EFB28 m;
    int i;
    E2EFB28 *e;
    if (s == 0) return;
    if (*(int *)(s + 0x58) == 0) return;
    m.a = *(unsigned short *)(s + 0xC);
    m.b = 0xFFFF;
    func_002EDD08(func_002DA918(*(int *)(s + 8)), buf, 0x12, 4);
    for (i = 0; i < *(int *)(s + 0x5C); i++) {
        e = (E2EFB28 *)(i * 0x14 + *(int *)(s + 0x60));
        if (e->x4 && e->x8 == 2)
            func_002D9A30(*(int *)(s + 8), *(int *)(e->x4 + 0x34), buf, &m, 4);
    }
}
