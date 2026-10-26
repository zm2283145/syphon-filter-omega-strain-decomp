typedef struct S {
    int a;
    int b;
} S;
extern int rt_circ_buf_get_used(S *s, int *n);
/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) rt_circ_buf_copy(void *p, S *s, int n) { return 0; }
extern int rt_circ_buf_clear(S *s);
extern int rt_circ_buf_store(S *s, void *p, int n);
int rt_circ_buf_normalize_with_buf(S *s, unsigned char flag, void *p)
{
    int n;
    int ret;
    n = 0;
    if (s == 0) return 2;
    if (flag && p == 0) return 2;
    if (s->a != 0) {
        ret = rt_circ_buf_get_used(s, &n);
        if (ret) return ret;
        if (n == 0) {
            s->a = 0;
            s->b = 0;
        } else if (flag == 1) {
            ret = rt_circ_buf_copy(p, s, n);
            if (ret) return ret;
            ret = rt_circ_buf_clear(s);
            if (ret) return ret;
            ret = rt_circ_buf_store(s, p, n);
            if (ret) return ret;
        }
    }
    return 0;
}
