typedef struct S S;
struct S {
    char p[0x48];
    int (*read)(S *, int *, char *, int);
    char p4c[0x58 - 0x4C];
    int f58;
    int f5c;
    int f60;
    char p64[0x90 - 0x64];
    int f90;
};
extern int func_002DA050(S *, int, char *, int);
int func_002D9190(S *s, int now)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    from[0] = 0;
    do {
        n = s->read(s, from, buf, 0x800);
        total += n;
        if (n > 0) {
            func_002DA050(s, from[0], buf, n);
            s->f58 = now;
        } else if (total == 0 && s->f60) {
            func_002DA050(s, from[0], buf, -1);
        }
        if (n < 0x800 && (n <= 0 || from[0] != 0x3F)) break;
    } while (n > 0);
    if (total == 0 && s->f60 && now - s->f58 >= 0x5DD) func_002DA050(s, s->f90, buf, 0);
    return total;
}
