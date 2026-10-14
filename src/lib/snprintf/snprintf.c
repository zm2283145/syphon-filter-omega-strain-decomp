/* newlib snprintf.c: _snprintf_r and snprintf.  Compiler: EE-GCC 2.96 -O2 -G0. */
typedef unsigned int size_t;
typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)

struct _reent;
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
    unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    struct __sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;
struct _reent { int _errno; FILE *_stdin, *_stdout, *_stderr; };

#define __SWR  0x0008
#define __SSTR 0x0200

extern struct _reent *D_00489738;   /* _impure_ptr */
#define _REENT D_00489738
extern int vfprintf(FILE *, const char *, va_list);   /* vfprintf */

int _snprintf_r(struct _reent *ptr, char *str, size_t size, const char *fmt, ...)   /* _snprintf_r */
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = (size > 0 ? size - 1 : 0);
    f._data = ptr;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    if (size > 0)
        *f._p = 0;
    return ret;
}

int snprintf(char *str, size_t size, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = (size > 0 ? size - 1 : 0);
    f._data = _REENT;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    if (size > 0)
        *f._p = 0;
    return ret;
}