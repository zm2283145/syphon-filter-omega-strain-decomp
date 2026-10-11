typedef struct { unsigned char *_p; int _r; int _w; short _flags; short _file; unsigned char *_base; int _size; int _lbfsize; char pad[0x54 - 0x1C]; void *_data; } F00128AA8;
extern void *D_00489738;
extern int func_0012C390(F00128AA8 *, const char *, __builtin_va_list);
int snprintf(char *str, unsigned int size, const char *fmt, ...)
{
    int ret;
    __builtin_va_list ap;
    F00128AA8 f;
    f._flags = 0x208;
    f._base = f._p = (unsigned char *)str;
    f._size = f._w = (size > 0 ? size - 1 : 0);
    f._data = D_00489738;
    __builtin_stdarg_start(ap, fmt);
    ret = func_0012C390(&f, fmt, ap);
    if (size > 0) *f._p = 0;
    return ret;
}
