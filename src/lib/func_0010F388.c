extern int func_0010ED58(const char *fmt, char *ap);
extern void func_0010EA70(void);
extern void *D_004861A4;
int func_0010F388(const char *fmt, ...)
{
    char *ap;
    void *old;
    int r;
    old = D_004861A4;
    D_004861A4 = func_0010EA70;
    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    r = func_0010ED58(fmt, ap);
    D_004861A4 = old;
    return r;
}