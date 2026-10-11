typedef struct { int a; int err; } R2E1158;
extern int D_0048C458;
extern unsigned char D_0048C4AC;
extern int func_002E56D0(unsigned char *);
extern void func_002E1248(int *, R2E1158 *);
int func_002E1158(int *req, R2E1158 *res)
{
    unsigned char st = 0;
    unsigned char ready;
    if (res == 0) return 0x17;
    res->err = 0x1E;
    res->a = 1;
    if (req == 0) {
        res->err = 0x17;
        return 0x17;
    }
    if (D_0048C458 != 1) {
        res->err = 0x11;
        return 0x11;
    }
    if (*req != 1) {
        res->err = 0x26;
        return 0x26;
    }
    ready = D_0048C4AC;
    if (ready != 1) {
        res->err = 0x1A;
        return 0x1A;
    }
    res->err = func_002E56D0(&st);
    if (res->err == 0) {
        if (st == 1) func_002E1248(req, res);
    }
    return res->err;
}
