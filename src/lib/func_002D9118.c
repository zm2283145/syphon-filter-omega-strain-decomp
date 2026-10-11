extern int func_002D9CE0(int, char *, int, int *, int *);
extern int func_002D96C8(int, int, int, char *, int);
int func_002D9118(int a)
{
    char buf[0x500];
    int len;
    int x = 0;
    int r = 0;
    int n;
    for (;;) {
        n = func_002D9CE0(a, buf, 0x500, &len, &x);
        if (n < 0) { r = -1; break; }
        if (n == 0) break;
        if (func_002D96C8(a, len, x, buf, n)) { r = -1; break; }
    }
    return r;
}
