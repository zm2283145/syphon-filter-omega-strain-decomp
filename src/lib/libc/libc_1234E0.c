/*
 * lib/libc: 5 files, 001234E0-00123808
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001234E0 */
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
struct _reent { int _errno; char p0[0x34]; int __sdidinit; char p1[0x1D8 - 0x3C]; struct _glue __sglue; };extern struct _reent *D_00489738;
extern void __sinit(struct _reent *);
extern int Newlib_Fwalk(struct _reent *, int (*)(FILE *));
int fflush(FILE *fp)
{
    int n, t;
    unsigned char *p;
    if (fp == 0) return Newlib_Fwalk(D_00489738, fflush);
    do {
        if ((fp)->_data == 0)
            (fp)->_data = D_00489738;
        if (!(fp)->_data->__sdidinit)
            __sinit((fp)->_data);
    } while (0);
    t = fp->_flags;
    if ((t & 8) == 0 || (p = fp->_bf._base) == 0) return 0;
    n = fp->_p - p;
    fp->_p = p;
    fp->_w = t & (1 | 2) ? 0 : fp->_bf._size;
    while (n > 0) {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= 0x40;
            return -1;
        }
        p += t;
        n -= t;
    }
    return 0;
}
/* merge_units: end func_001234E0 */

/* merge_units: begin func_001235F8 */
typedef struct { unsigned char *_p; int _r; } FILE_001235F8;
extern int __srefill(FILE_001235F8 *);
extern void *Libc_Memchr(const void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
char *Libc_Fgets(char *buf, int n, FILE_001235F8 *fp)
{
    unsigned int len;
    char *s;
    unsigned char *p, *t;

    if (n < 2)
        return 0;

    s = buf;
    n--;
    do {
        if ((len = fp->_r) <= 0) {
            if (__srefill(fp)) {
                if (s == buf)
                    return 0;
                break;
            }
            len = fp->_r;
        }
        p = fp->_p;
        if (len > n)
            len = n;
        t = (unsigned char *)Libc_Memchr((void *)p, '\n', len);
        if (t != 0) {
            len = ++t - p;
            fp->_r -= len;
            fp->_p = t;
            (void)memcpy((void *)s, (void *)p, len);
            s[len] = 0;
            return buf;
        }
        fp->_r -= len;
        fp->_p += len;
        (void)memcpy((void *)s, (void *)p, len);
        s += len;
    } while ((n -= len) != 0);
    *s = 0;
    return buf;
}
/* merge_units: end func_001235F8 */

/* merge_units: begin func_00123730 */
extern int Newlib_Sread(); extern int Newlib_Swrite(); extern int Newlib_Sseek(); extern int Newlib_Sclose();
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x24]; void* _data; } FILE_00123730;
void Newlib_Std(FILE_00123730* ptr, int flags, int file, void* data)
{
  ptr->_p = 0;
  ptr->_r = 0;
  ptr->_w = 0;
  ptr->_flags = flags;
  ptr->_file = file;
  ptr->_bf_base = 0;
  ptr->_bf_size = 0;
  ptr->_lbfsize = 0;
  ptr->_cookie = ptr;
  ptr->_read = Newlib_Sread;
  ptr->_write = Newlib_Swrite;
  ptr->_seek = Newlib_Sseek;
  ptr->_close = Newlib_Sclose;
  ptr->_data = data;
}
/* merge_units: end func_00123730 */

/* merge_units: begin func_00123790 */
extern void* _malloc_r(void* d, unsigned int n);
extern void* memset(void* p, int c, unsigned int n);
struct glue_00123790 { struct glue_00123790* _next; int _niobs; void* _iobs; };
struct glue_00123790* Newlib_Sfmoreglue(void* d, int n)
{
  struct glue_00123790 *g;
  g = (struct glue_00123790 *) _malloc_r (d, sizeof (*g) + n * 0x58);
  if (g == 0)
    return 0;
  g->_next = 0;
  g->_niobs = n;
  g->_iobs = (void *) (g + 1);
  memset (g->_iobs, 0, n * 0x58);
  return g;
}
/* merge_units: end func_00123790 */

/* merge_units: begin func_00123808 */
#if 0 /* merge_units */
extern struct _glue *Newlib_Sfmoreglue(struct _reent *, int);
#endif /* merge_units */
#define Newlib_Sfmoreglue(a0, a1) ((struct _glue *)Newlib_Sfmoreglue((void *)(a0), (a1))) /* merge_units */

FILE *Newlib_Sfp(struct _reent *d)
{
    FILE *fp;
    int n;
    struct _glue *g;
    if (!d->__sdidinit) __sinit(d);
    for (g = &d->__sglue;; g = g->_next) {
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags == 0) goto found;
        if (g->_next == 0 && (g->_next = Newlib_Sfmoreglue(d, 4)) == 0) break;
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
#undef Newlib_Sfmoreglue /* merge_units */
/* merge_units: end func_00123808 */
