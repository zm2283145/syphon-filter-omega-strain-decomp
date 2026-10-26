extern int Insck_Getsockopt(int, int, int, void *, int *);
int sceNetGlueGetsockopt(int s, int level, int opt, unsigned char *val, int *len)
{
    unsigned char c; int n;
    if (level == 0 && (unsigned int)(opt - 10) < 2 && val && len && *len == 1) {
        int r;
        n = 4;
        r = Insck_Getsockopt(s, 0, opt, &c, &n);
        if (r == 0) *val = c;
        return r;
    }
    return Insck_Getsockopt(s, level, opt, val, len);
}