/* newlib stdio.c: __sread, __swrite, __sseek and __sclose.  Compiler: EE-GCC 2.96 -O2 -G0. */
struct _reent;
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
    unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    struct __sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;

#define __SAPP 0x0100
#define __SOFF 0x1000
#define SEEK_END 2

extern long func_00127E38(struct _reent *, int, void *, int);         /* _read_r */
extern long func_0012EB58(struct _reent *, int, const void *, int);   /* _write_r */
extern long func_00124F80(struct _reent *, int, long, int);           /* _lseek_r */
extern int func_00121E20(struct _reent *, int);                       /* _close_r */

int func_00128D10(void *cookie, char *buf, int n)   /* __sread */
{
  register FILE *fp = (FILE *) cookie;
  register int ret;

  ret = func_00127E38 (fp->_data, fp->_file, buf, n);

  /* If the read succeeded, update the current offset.  */
  if (ret >= 0)
    fp->_offset += ret;
  else
    fp->_flags &= ~__SOFF;	/* paranoia */
  return ret;
}

int func_00128D78(void *cookie, char const *buf, int n)   /* __swrite */
{
  register FILE *fp = (FILE *) cookie;

  if (fp->_flags & __SAPP)
    (void) func_00124F80 (fp->_data, fp->_file, (long) 0, SEEK_END);
  fp->_flags &= ~__SOFF;	/* in case O_APPEND mode is set */
  return func_0012EB58 (fp->_data, fp->_file, buf, n);
}

long func_00128DF8(void *cookie, long offset, int whence)   /* __sseek */
{
  register FILE *fp = (FILE *) cookie;
  register long ret;

  ret = func_00124F80 (fp->_data, fp->_file, (long) offset, whence);
  if (ret == -1L)
    fp->_flags &= ~__SOFF;
  else
    {
      fp->_flags |= __SOFF;
      fp->_offset = ret;
    }
  return ret;
}

int func_00128E60(void *cookie)   /* __sclose */
{
  FILE *fp = (FILE *) cookie;

  return func_00121E20 (fp->_data, fp->_file);
}
