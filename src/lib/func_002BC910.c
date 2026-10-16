typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC910;
extern CtxC910 D_0051ECC0;
extern int func_002B4FA8(int);
extern void func_002BC828(void);
int func_002BC910(void)
{
    D_0051ECC0.x24--;
    if (D_0051ECC0.x24 <= 0) {
        if (D_0051ECC0.x4 != -1) {
            func_002B4FA8(D_0051ECC0.x20);
        }
        func_002BC828();
    }
    return 0;
}
