/*
 * lib/libc: 3 files, 0012B290-0012B398
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012B290 */
extern unsigned char D_00499C71[];
int Libc_Toupper(int c)
{
    return (D_00499C71[c] & 2) ? c - 0x20 : c;
}
/* merge_units: end func_0012B290 */

/* merge_units: begin func_0012B2B0 */
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
/* merge_units: end func_0012B2B0 */

/* merge_units: begin func_0012B398 */
typedef struct reent_X { int _errno; char pad[0x34]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; long (*_seek)(void*, long, int); int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void __sinit(reent_X* r);
extern int fflush(FILE_X* fp);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
#if 0 /* merge_units */
extern int func_0012B2B0(FILE_X* fp);
#endif /* merge_units */
#define func_0012B2B0(a0) (func_0012B2B0((FILE *)(a0))) /* merge_units */

int ungetc(int c, register FILE_X *fp)
{
  if (c == -1)
    return (-1);

  CHECK_INIT (fp);

  fp->_flags &= ~0x0020;

  if ((fp->_flags & 0x0004) == 0)
    {
      if ((fp->_flags & 0x0010) == 0)
	return -1;
      if (fp->_flags & 0x0008)
	{
	  if (fflush (fp))
	    return -1;
	  fp->_flags &= ~0x0008;
	  fp->_w = 0;
	  fp->_lbfsize = 0;
	}
      fp->_flags |= 0x0004;
    }
  c = (unsigned char) c;

  if (HASUB (fp))
    {
      if (fp->_r >= fp->_ub_size && func_0012B2B0 (fp))
	return -1;
      *--fp->_p = c;
      fp->_r++;
      return c;
    }

  if (fp->_bf_base != 0 && fp->_p > fp->_bf_base && fp->_p[-1] == c)
    {
      fp->_p--;
      fp->_r++;
      return c;
    }

  fp->_ur = fp->_r;
  fp->_up = fp->_p;
  fp->_ub_base = fp->_ubuf;
  fp->_ub_size = sizeof (fp->_ubuf);
  fp->_ubuf[sizeof (fp->_ubuf) - 1] = c;
  fp->_p = &fp->_ubuf[sizeof (fp->_ubuf) - 1];
  fp->_r = 1;
  return c;
}
#undef func_0012B2B0 /* merge_units */
/* merge_units: end func_0012B398 */
