#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern int func_001089E0(void *);
extern void func_00108AB0(void *, int, int);
extern int func_00108B40(void *, int);
extern int func_00108130(void *);
extern int func_0010B500(void *);
extern int func_0010BB28(void *);

int func_0010B9B0(char *mp, int a, int b)
{
    char *p;
    int ret;
    int more;
    int ok;
    int x;

    more = 0;
    p = F_(mp, 0x40, char *);
    F_(p, 0x138, int) = 0;
    if (b == -1 || a < b)
        more = 1;
    if (F_(p, 0x8, int) == 0) {
        F_(mp, 0x8, int) = 0;
        F_(p, 0x8, int) = 1;
    }
    if (func_00108B40(p, 0) && more)
        func_001089E0(p);
    if (F_(p, 0x10A0, int))
        return 0;
    F_(p, 0x138, int) = 1;
    if (func_00108130(p) == 0) {
        func_0010BB28(mp);
        F_(p, 0x0, int) = 1;
        return 0;
    }
    x = 2;
    if (F_(p, 0xEC, int) != 1)
        x = 1;
    if (F_(p, 0x18C, int) != x)
        return -1;
    ok = 0;
    if (func_00108B40(p, 1))
        ok = 1;
    ret = 0;
    if (ok && more)
        {
        if (func_001089E0(p))
            ret = 1;
    }
    if (F_(p, 0x10A0, int))
        return 0;
    func_00108AB0(p, F_(p, 0x130, int), F_(p, 0x4, int));
    F_(p, 0x138, int) = 0;
    F_(mp, 0x8, int) = F_(p, 0x130, int) - F_(p, 0xC4, int);
    F_(p, 0x130, int)++;
    F_(p, 0x4, int)++;
    if (!more)
        func_0010B500(mp);
    return ret;
}


