/* newlib vfiprintf(): integer-only vfprintf. */
typedef __builtin_va_list va_list;
/* struct _reent, only the stdio init fields (+0x38 __sdidinit, +0x3C __cleanup) */
typedef struct reent_X { char pad[0x38]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; void* _seek; int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;            /* _impure_ptr */
extern void func_00123940(reent_X* r); /* __sinit */
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) func_00123940 ((fp)->_data); } while (0)
extern int _vfiprintf_r(reent_X* r, FILE_X* fp, const char* fmt, va_list ap);
/* Makes sure the stream has a reentrancy struct with stdio initialised, then formats. */
int vfiprintf(FILE_X *fp, const char *fmt0, va_list ap)
{
  CHECK_INIT (fp);
  return _vfiprintf_r (fp->_data, fp, fmt0, ap);
}