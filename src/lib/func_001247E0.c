typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(void *, const char *, int); int (*_seek)(); int (*_close)();
} FILE;
struct __siov { const void *iov_base; unsigned int iov_len; };
struct __suio { struct __siov *uio_iov; int uio_iovcnt; int uio_resid; };
extern int func_0012EBB8(FILE *);
extern void *func_00125FE8(void *, const void *, unsigned int);
extern void *func_00125DC0(const void *, int, unsigned int);
extern int func_001234E0(FILE *);
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define COPY(n) (void) func_00125FE8((void *) fp->_p, (void *) p, (unsigned int) (n))
#define GETIOV(extra_work) \
  while (len == 0) \
    { \
      extra_work; \
      p = iov->iov_base; \
      len = iov->iov_len; \
      iov++; \
    }
#define cantwrite(fp) ((((fp)->_flags & 0x0008) == 0 || (fp)->_bf._base == 0) && func_0012EBB8(fp))
int func_001247E0(register FILE *fp, register struct __suio *uio)
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
                if (func_001234E0(fp))
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
                nl = func_00125DC0((void *)p, '\n', len);
                nldist = nl ? nl + 1 - p : len + 1;
                nlknown = 1;
            }
            s = MIN(len, nldist);
            w = fp->_w + fp->_bf._size;
            if (fp->_p > fp->_bf._base && s > w) {
                COPY(w);
                fp->_p += w;
                if (func_001234E0(fp))
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
                if (func_001234E0(fp))
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
