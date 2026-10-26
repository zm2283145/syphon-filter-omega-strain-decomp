/*
 * lib/libc: 3 files, 001246D8-00124BC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001246D8 */
typedef struct reent_X { int _errno; char pad[0x34]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; long (*_seek)(void*, long, int); int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void __sinit(reent_X* r);
extern int fflush(FILE_X* fp);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
long Libc_Ftell(register FILE_X * fp)
{
  long pos;

  CHECK_INIT (fp);

  if (fp->_seek == 0)
    {
      fp->_data->_errno = 29;
      return -1L;
    }

  fflush (fp);
  if (fp->_flags & 0x1000)
    pos = fp->_offset;
  else
    {
      pos = (*fp->_seek) (fp->_cookie, (long) 0, 1);
      if (pos == -1L)
	return pos;
    }
  if (fp->_flags & 0x0004)
    {
      pos -= fp->_r;
      if (HASUB (fp))
	pos -= fp->_ur;
    }
  else if (fp->_flags & 0x0008 && fp->_p != 0)
    {
      pos += fp->_p - fp->_bf_base;
    }

  return pos;
}
/* merge_units: end func_001246D8 */

/* merge_units: begin func_001247E0 */
typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(void *, const char *, int); int (*_seek)(); int (*_close)();
} FILE;
struct __siov { const void *iov_base; unsigned int iov_len; };
struct __suio { struct __siov *uio_iov; int uio_iovcnt; int uio_resid; };
extern int __swsetup(FILE *);
extern void *Libc_Memmove(void *, const void *, unsigned int);
extern void *Libc_Memchr(const void *, int, unsigned int);
#if 0 /* merge_units */
extern int fflush(FILE *);
#endif /* merge_units */
#define fflush(a0) (fflush((FILE_X *)(a0))) /* merge_units */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define COPY(n) (void) Libc_Memmove((void *) fp->_p, (void *) p, (unsigned int) (n))
#define GETIOV(extra_work) \
  while (len == 0) \
    { \
      extra_work; \
      p = iov->iov_base; \
      len = iov->iov_len; \
      iov++; \
    }
#define cantwrite(fp) ((((fp)->_flags & 0x0008) == 0 || (fp)->_bf._base == 0) && __swsetup(fp))
int __sfvwrite(register FILE *fp, register struct __suio *uio)
{
    register unsigned int len;
    register const char *p;
    register struct __siov *iov;
    register int w, s;
    char *nl;
    int nlknown, nldist;

    if ((len = uio->uio_resid) == 0)
        return 0;
    if (cantwrite(fp))
        return -1;
    iov = uio->uio_iov;
    len = 0;
    if (fp->_flags & 0x0002) {
        do {
            GETIOV(;);
            w = (*fp->_write)(fp->_cookie, p, MIN(len, 1024));
            if (w <= 0)
                goto err;
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else if ((fp->_flags & 0x0001) == 0) {
        do {
            GETIOV(;);
            w = fp->_w;
            if (fp->_flags & 0x0200) {
                if (len < w)
                    w = len;
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
                w = len;
            } else if (fp->_p > fp->_bf._base && len > w) {
                COPY(w);
                fp->_p += w;
                if (fflush(fp))
                    goto err;
            } else if (len >= (w = fp->_bf._size)) {
                w = (*fp->_write)(fp->_cookie, p, w);
                if (w <= 0)
                    goto err;
            } else {
                w = len;
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
            }
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else {
        nlknown = 0;
        do {
            GETIOV(nlknown = 0);
            if (!nlknown) {
                nl = Libc_Memchr((void *)p, '\n', len);
                nldist = nl ? nl + 1 - p : len + 1;
                nlknown = 1;
            }
            s = MIN(len, nldist);
            w = fp->_w + fp->_bf._size;
            if (fp->_p > fp->_bf._base && s > w) {
                COPY(w);
                fp->_p += w;
                if (fflush(fp))
                    goto err;
            } else if (s >= (w = fp->_bf._size)) {
                w = (*fp->_write)(fp->_cookie, p, w);
                if (w <= 0)
                    goto err;
            } else {
                w = s;
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
            }
            if ((nldist -= w) == 0) {
                if (fflush(fp))
                    goto err;
                nlknown = 0;
            }
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    }
    return 0;

err:
    fp->_flags |= 0x0040;
    return -1;
}
#undef fflush /* merge_units */
/* merge_units: end func_001247E0 */

/* merge_units: begin func_00124BC0 */
typedef struct { char p[0xC]; short _flags; char q[0x4A]; } F00124BC0;
typedef struct G00124BC0 { struct G00124BC0 *_next; int _niobs; F00124BC0 *_iobs; } G00124BC0;
int Newlib_Fwalk(char *ptr, int (*function)(F00124BC0 *))
{
    F00124BC0 *fp;
    int n, ret = 0;
    G00124BC0 *g;
    for (g = (G00124BC0 *)(ptr + 0x1D8); g != 0; g = g->_next)
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags != 0) ret |= (*function)(fp);
    return ret;
}
/* merge_units: end func_00124BC0 */
