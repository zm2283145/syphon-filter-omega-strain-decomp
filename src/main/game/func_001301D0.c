extern int sprintf(char *, const char *, ...);
extern void String_Copy(char *, const char *);
extern int func_001302F0(void *);
extern char D_0049A908[];
extern int D_004EA050;
extern int D_00533870;

int func_001301D0(void *o, char *out)
{
    char buf[0x20];
    int count;
    int r;
    char *d;
    char *s;
    char c;
    int n;

    count = func_001302F0(o);
    r = (*(volatile int *)0x10000800 + D_00533870) % count;
    if (r == D_004EA050 && count > 1) {
        r = (r == count - 1) ? 0 : r + 1;
    }
    D_004EA050 = r;
    if (r == 0)
        String_Copy(buf, D_0049A908);
    else
        sprintf(buf, "DEMO%2.2d", r);
    d = out + 1;
    s = buf;
    n = 0;
    while ((*d++ = *s++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    out[0] = n;
    return 1;
}

