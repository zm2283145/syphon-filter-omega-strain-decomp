typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    SBUF _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    SBUF _lb; int _blksize; int _offset; void *_data;
} FILE;extern int func_00123A28(void *, const char *, int *);
extern FILE *func_00123808(void *);
extern int func_00127298(void *, const char *, int, int);
extern int func_00128D10(), func_00128D78(), func_00128DF8(), func_00128E60();
extern int func_001241C8(FILE *, long, int);
FILE *func_00123AE0(void *ptr, const char *file, const char *mode)
{
    register FILE *fp;
    register int f;
    int flags, oflags;

    if ((flags = func_00123A28(ptr, mode, &oflags)) == 0)
        return 0;
    if ((fp = func_00123808(ptr)) == 0)
        return 0;
    if ((f = func_00127298(fp->_data, file, oflags, 0666)) < 0) {
        fp->_flags = 0;
        return 0;
    }
    fp->_file = f;
    fp->_flags = flags;
    fp->_cookie = (void *)fp;
    fp->_read = func_00128D10;
    fp->_write = func_00128D78;
    fp->_seek = func_00128DF8;
    fp->_close = func_00128E60;
    if (fp->_flags & 0x100)
        func_001241C8(fp, 0, 2);
    return fp;
}