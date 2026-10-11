extern int func_0035A300(int, int, int, void *, int *);
int func_0045AC00(int s, int level, int opt, unsigned char *val, int *len)
{
    unsigned char c; int n;
    if (level == 0 && (unsigned int)(opt - 10) < 2 && val && len && *len == 1) {
        int r;
        n = 4;
        r = func_0035A300(s, 0, opt, &c, &n);
        if (r == 0) *val = c;
        return r;
    }
    return func_0035A300(s, level, opt, val, len);
}