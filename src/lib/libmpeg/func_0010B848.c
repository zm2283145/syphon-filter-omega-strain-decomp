#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern int func_001089E0(void *);
extern void func_00108AB0(void *, int, int);
extern int func_00108B40(void *, int);
extern int func_0010B500(void *);

static inline int dec(char *p)
{
    int t = func_00108B40(p, 0);
    int r = 0;
    if (t)
        r = func_001089E0(p) != 0;
    return r;
}

int func_0010B848(char *mp, int a, int b)
{
    char *p;
    int ret;
    int last;

    last = 0;
    p = F_(mp, 0x40, char *);
    if (b == -1 || a < b) {
        if (F_(p, 0x8, int) == 0) {
            F_(mp, 0x8, int) = 0;
            F_(p, 0x8, int) = 1;
        }
        ret = dec(p);
    } else {
        last = 1;
        ret = func_00108B40(p, 0);
        func_0010B500(mp);
    }
    if (F_(p, 0x10A0, int))
        return 0;
    func_00108AB0(p, F_(p, 0x130, int), F_(p, 0x4, int));
    if (F_(p, 0x18C, int) != 3 && last == 0)
        F_(p, 0x138, int) = F_(p, 0x138, int) == 0;
    F_(mp, 0x8, int) = F_(p, 0x130, int) - F_(p, 0xC4, int);
    if (F_(p, 0x138, int) == 0) {
        F_(p, 0x130, int)++;
        F_(p, 0x4, int)++;
    }
    return ret;
}

