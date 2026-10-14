typedef struct S {
    int a;
    int b;
} S;
extern int func_002F5818(S *s, int *n);
/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) func_002F5618(void *p, S *s, int n) { return 0; }
extern int func_002F5398(S *s);
extern int func_002F5508(S *s, void *p, int n);
int func_002F5748(S *s, unsigned char flag, void *p)
{
    int n;
    int ret;
    n = 0;
    if (s == 0) return 2;
    if (flag && p == 0) return 2;
    if (s->a != 0) {
        ret = func_002F5818(s, &n);
        if (ret) return ret;
        if (n == 0) {
            s->a = 0;
            s->b = 0;
        } else if (flag == 1) {
            ret = func_002F5618(p, s, n);
            if (ret) return ret;
            ret = func_002F5398(s);
            if (ret) return ret;
            ret = func_002F5508(s, p, n);
            if (ret) return ret;
        }
    }
    return 0;
}
