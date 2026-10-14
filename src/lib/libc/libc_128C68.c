typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; void* _data; } FILE_X;
extern int D_00489738;
extern unsigned int strlen(const char*);
extern int func_00128C60();
extern int __svfscanf(FILE_X* fp, const char* fmt, va_list ap);
int func_00128C68(const char *str, const char *fmt, ...)
{
  int ret;
  va_list ap;
  FILE_X f;

  f._flags = 0x0004;
  f._bf_base = f._p = (unsigned char *) str;
  f._bf_size = f._r = strlen (str);
  f._read = func_00128C60;
  f._ub_base = 0;
  f._lb_base = 0;
  f._data = (void*)D_00489738;
  va_start (ap, fmt);
  ret = __svfscanf (&f, fmt, ap);
  va_end (ap);
  return ret;
}