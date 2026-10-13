typedef struct { int a, b; char *out; } Reent127358;
typedef struct { char pad[0x54]; Reent127358 *data; } File127358;
extern Reent127358 *D_00489738;
extern int func_0012C390(void *, const char *, __builtin_va_list);
int printf(const char *fmt, ...)
{
    int ret;
    __builtin_va_list ap;
    Reent127358 *ptr = D_00489738;
    __builtin_stdarg_start(ap, fmt);
    ((File127358 *)ptr->out)->data = ptr;
    ret = func_0012C390(ptr->out, fmt, ap);
    __builtin_va_end(ap);
    return ret;
}