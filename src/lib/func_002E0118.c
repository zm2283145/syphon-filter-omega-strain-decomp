extern int func_002E6010(void);
extern int func_002E0210(int *, int *, int *);
extern int func_002E0760(int *, int *, int *);
int func_002E0118(int *req, int *res)
{
    int r, t; int *k;
    if (res == 0) return 0x17;
    res[1] = 3;
    res[0] = 1;
    r = func_002E6010();
    if (r) return r;
    if (req == 0) {
        res[1] = 0x17;
        return 0x17;
    }
    if (*req != 1) {
        res[1] = 0x26;
        return 0x26;
    }
    k = req + 2; t = *k;
    if (t == 1 || t == 3 || t == 4) res[1] = func_002E0210(req, k, res);
    else if (t == 2) res[1] = func_002E0760(req, k, res);
    else res[1] = 0x17;
    return res[1];
}
