typedef struct { int a; unsigned short id; short p; int type; void (*cb)(int, void *, int, int, int, int); int time; int x; int y; } E2E55A0;
typedef struct { int t[4]; } T2E55A0;
extern E2E55A0 D_0058D188[];
extern char D_005880A0[];
extern short D_0058D178;
extern int func_00306018(int *);
extern void func_002DD440(void *, E2E55A0 *);
int func_002E55A0(void)
{
    T2E55A0 tmp;
    int now;
    unsigned int i;
    func_00306018(&now);
    for (i = 0; i < 127; i++) {
        if (D_0058D188[i].cb == 0) continue;
        if (now - D_0058D188[i].time - 30000 <= 0) continue;
        func_002DD440(&tmp, &D_0058D188[i]);
        func_002DD440(D_005880A0, &D_0058D188[i]);
        D_0058D178 = D_0058D188[i].id;
        if (D_0058D188[i].type == 1)
            D_0058D188[i].cb(0xE, &tmp, 0, 0, D_0058D188[i].x, D_0058D188[i].y);
        else
            ((void (*)(int, void *, int, int))D_0058D188[i].cb)(0xE, &tmp, 0, 0);
        D_0058D188[i].cb = 0;
    }
    return 0;
}