extern int sprintf(char *, const char *, ...);
extern int func_0010BD90(int, char *);
int func_0010BD58(int x, const char *fmt, int a, int b, int c, int d, int e, int f)
{
    char buf[256];
    sprintf(buf, fmt, a, b, c, d, e, f);
    return func_0010BD90(x, buf);
}