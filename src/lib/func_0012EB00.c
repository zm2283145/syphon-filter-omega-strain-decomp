typedef __builtin_va_list va_list;
typedef struct reent_X { char pad[0x38]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void __sinit(reent_X* r);
extern void _free_r(reent_X* r, void* p);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
#define FREEUB(fp) { if ((fp)->_ub_base != (fp)->_ubuf) _free_r((fp)->_data, (char *)(fp)->_ub_base); (fp)->_ub_base = 0; }
#define HASLB(fp) ((fp)->_lb_base != 0)
#define FREELB(fp) { _free_r((fp)->_data, (char *)(fp)->_lb_base); (fp)->_lb_base = 0; }
extern int vfprintf(FILE_X* fp, const char* fmt, va_list ap);
int func_0012EB00(reent_X *ptr, char *str, const char *fmt, va_list ap)
{
  int ret;
  FILE_X f;

  f._flags = 0x0008 | 0x0200;
  f._bf_base = f._p = (unsigned char *) str;
  f._bf_size = f._w = 0x7FFFFFFF;
  f._data = ptr;
  ret = vfprintf (&f, fmt, ap);
  *f._p = 0;
  return ret;
}