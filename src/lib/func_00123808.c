struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
    unsigned char *_p; int _r; int _w; short _flags; short _file;
    struct __sbuf _bf; int _lbfsize; void *_cookie;
    int (*_read)(void *, char *, int); int (*_write)(void *, const char *, int);
    int (*_seek)(void *, int, int); int (*_close)(void *);
    struct __sbuf _ub; unsigned char *_up; int _ur;
    unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;
struct _glue { struct _glue *_next; int _niobs; FILE *_iobs; };
struct _reent { int _errno; char p0[0x34]; int __sdidinit; char p1[0x1D8 - 0x3C]; struct _glue __sglue; };extern void __sinit(struct _reent *);
extern struct _glue *func_00123790(struct _reent *, int);
FILE *func_00123808(struct _reent *d)
{
    FILE *fp;
    int n;
    struct _glue *g;
    if (!d->__sdidinit) __sinit(d);
    for (g = &d->__sglue;; g = g->_next) {
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags == 0) goto found;
        if (g->_next == 0 && (g->_next = func_00123790(d, 4)) == 0) break;
    }
    d->_errno = 0xC;
    return 0;
found:
    fp->_flags = 1;
    fp->_p = 0;
    fp->_w = 0;
    fp->_r = 0;
    fp->_bf._base = 0;
    fp->_bf._size = 0;
    fp->_lbfsize = 0;
    fp->_file = -1;
    fp->_ub._base = 0;
    fp->_ub._size = 0;
    fp->_lb._base = 0;
    fp->_lb._size = 0;
    fp->_data = d;
    return fp;
}
