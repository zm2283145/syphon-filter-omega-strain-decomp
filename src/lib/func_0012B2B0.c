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
struct _reent { int _errno; char p0[0x34]; int __sdidinit; char p1[0x1D8 - 0x3C]; struct _glue __sglue; };extern unsigned char *_malloc_r(struct _reent *, int);
extern unsigned char *_realloc_r(struct _reent *, unsigned char *, int);
extern void *memcpy(void *, const void *, unsigned int);
int func_0012B2B0(FILE *fp)
{
    int i;
    unsigned char *p;
    if (fp->_ub._base == fp->_ubuf) {
        if ((p = _malloc_r(fp->_data, 0x400)) == 0) return -1;
        fp->_ub._base = p;
        fp->_ub._size = 0x400;
        p += 0x400 - sizeof(fp->_ubuf);
        for (i = sizeof(fp->_ubuf); --i >= 0;)
            p[i] = fp->_ubuf[i];
        fp->_p = p;
        return 0;
    }
    i = fp->_ub._size;
    p = _realloc_r(fp->_data, fp->_ub._base, i << 1);
    if (p == 0) return -1;
    memcpy(p + i, p, i);
    fp->_p = p + i;
    fp->_ub._base = p;
    fp->_ub._size = i << 1;
    return 0;
}
