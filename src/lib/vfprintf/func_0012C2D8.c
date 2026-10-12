typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    SBUF _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    SBUF _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;extern int func_0012C390(FILE *, const char *, void *);
extern int func_001234E0(FILE *);
int func_0012C2D8(FILE *fp, const char *fmt, void *ap)
{
    int ret;
    FILE fake;
    unsigned char buf[1024];

    fake._data = fp->_data;
    fake._flags = fp->_flags & ~0x2;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;

    fake._bf._base = fake._p = buf;
    fake._bf._size = fake._w = sizeof(buf);
    fake._lbfsize = 0;

    ret = func_0012C390(&fake, fmt, ap);
    if (ret >= 0 && func_001234E0(&fake))
        ret = -1;
    if (fake._flags & 0x40)
        fp->_flags |= 0x40;
    return ret;
}