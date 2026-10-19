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

extern long Newlib_ReadR(struct _reent *, int, void *, int);         /* _read_r */
extern long Newlib_WriteR(struct _reent *, int, const void *, int);   /* _write_r */
extern long Newlib_LseekR(struct _reent *, int, long, int);           /* _lseek_r */
extern int Newlib_CloseR(struct _reent *, int);                       /* _close_r */

int Newlib_Sread(void *cookie, char *buf, int n)   /* __sread */
{
  register FILE *fp = (FILE *) cookie;
  register int ret;

  ret = Newlib_ReadR (fp->_data, fp->_file, buf, n);

  /* If the read succeeded, update the current offset.  */
  if (ret >= 0)
    fp->_offset += ret;
  else
    fp->_flags &= ~__SOFF;	/* paranoia */
  return ret;
}

int Newlib_Swrite(void *cookie, char const *buf, int n)   /* __swrite */
{
  register FILE *fp = (FILE *) cookie;

  if (fp->_flags & __SAPP)
    (void) Newlib_LseekR (fp->_data, fp->_file, (long) 0, SEEK_END);
  fp->_flags &= ~__SOFF;	/* in case O_APPEND mode is set */
  return Newlib_WriteR (fp->_data, fp->_file, buf, n);
}

long Newlib_Sseek(void *cookie, long offset, int whence)   /* __sseek */
{
  register FILE *fp = (FILE *) cookie;
  register long ret;

  ret = Newlib_LseekR (fp->_data, fp->_file, (long) offset, whence);
  if (ret == -1L)
    fp->_flags &= ~__SOFF;
  else
    {
      fp->_flags |= __SOFF;
      fp->_offset = ret;
    }
  return ret;
}

int Newlib_Sclose(void *cookie)   /* __sclose */
{
  FILE *fp = (FILE *) cookie;

  return Newlib_CloseR (fp->_data, fp->_file);
}
