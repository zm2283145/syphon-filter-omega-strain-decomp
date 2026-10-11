extern int func_002FABD0(int *, int *);
extern int func_002FAF00(int);
int func_002FB1C0(int *s)
{
    int p = 0;
    unsigned int min = s[2];
    unsigned int d;
    int r;
    r = func_002FABD0(s, &p);
    if (r) return r;
    while (p) {
        d = p - s[4];
        if (d < min) min = d;
        p = func_002FAF00(p);
    }
    s[0] = min;
    return 0;
}
