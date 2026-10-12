typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC960;
extern CtxC960 D_0051ECC0;
extern int String_CompareN(const char *, const char *, int);
extern int func_002BC868(int);
extern int func_002B5F98(int, int);
extern int func_002B6218(int, int, int, int, int *, int *);
extern void func_002BC910(void);
int func_002BC960(const char *name, int a1, int a2, int a3, int *out)
{
    int buf[16];
    int n;
    int r;
    if (func_002BC868(String_CompareN(name, "mc1", 3) == 0 ? 3 : 2) < 0) return -1;
    r = func_002B5F98(D_0051ECC0.x20, 0);
    if (r < 0 && (r & 0xFFFF) != 0x9003) {
        func_002BC910();
        return -1;
    }
    if (func_002B6218(D_0051ECC0.x20, a1, 0, 1, buf, &n) < 0) {
        func_002BC910();
        return -1;
    }
    *out = 0;
    if (n == 1) *out = buf[4];
    return D_0051ECC0.x24;
}