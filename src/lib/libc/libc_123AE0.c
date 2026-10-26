typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    SBUF _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    SBUF _lb; int _blksize; int _offset; void *_data;
} FILE;extern int Newlib_Sflags(void *, const char *, int *);
extern FILE *Newlib_Sfp(void *);
extern int Newlib_OpenR(void *, const char *, int, int);
extern int Newlib_Sread(), Newlib_Swrite(), Newlib_Sseek(), Newlib_Sclose();
extern int Libc_Fseek(FILE *, long, int);
FILE *Newlib_FopenR(void *ptr, const char *file, const char *mode)
{
    register FILE *fp;
    register int f;
    int flags, oflags;

    if ((flags = Newlib_Sflags(ptr, mode, &oflags)) == 0)
        return 0;
    if ((fp = Newlib_Sfp(ptr)) == 0)
        return 0;
    if ((f = Newlib_OpenR(fp->_data, file, oflags, 0666)) < 0) {
        fp->_flags = 0;
        return 0;
    }
    fp->_file = f;
    fp->_flags = flags;
    fp->_cookie = (void *)fp;
    fp->_read = Newlib_Sread;
    fp->_write = Newlib_Swrite;
    fp->_seek = Newlib_Sseek;
    fp->_close = Newlib_Sclose;
    if (fp->_flags & 0x100)
        Libc_Fseek(fp, 0, 2);
    return fp;
}