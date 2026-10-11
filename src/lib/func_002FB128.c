extern int func_002FABD0(int *, int *);
extern int func_002FAF00(int);
int func_002FB128(int *s, int key, int *out)
{
    int p = 0;
    int r;
    if (key == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = func_002FABD0(s, &p);
    if (r) return r;
    while (func_002FAF00(p)) {
        if (func_002FAF00(p) == key) {
            *out = p;
            return 0;
        }
        p = func_002FAF00(p);
    }
    return 1;
}
