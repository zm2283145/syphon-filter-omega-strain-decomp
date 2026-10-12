struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
  unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
  void *_cookie; int (*_read)(); int (*_write)(); long (*_seek)(); int (*_close)();
  struct __sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
  struct __sbuf _lb; int _blksize; int _offset; void *_data;
} FILE;extern void *D_00489738;
extern int func_0012C390(FILE *, const char *, __builtin_va_list);
int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    __builtin_va_list ap;
    FILE f;
    f._flags = 0x0008 | 0x0200;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = 0x7fffffff;
    f._data = D_00489738;
    __builtin_stdarg_start(ap, fmt);
    ret = func_0012C390(&f, fmt, ap);
    __builtin_va_end(ap);
    *f._p = 0;
    return ret;
}