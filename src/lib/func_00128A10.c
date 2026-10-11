typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _base; int _size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x50-0x30]; int _offset; void* _data; } FILE_X;
extern int func_0012C390(FILE_X* fp, const char* fmt, va_list ap);
int func_00128A10(void *ptr, char *str, unsigned int size, const char *fmt, ...)
{
  int ret;
  va_list ap;
  FILE_X f;

  f._flags = 0x0008 | 0x0200;
  f._base = f._p = (unsigned char *) str;
  f._size = f._w = (size > 0 ? size - 1 : 0);
  f._data = ptr;
  va_start (ap, fmt);
  ret = func_0012C390 (&f, fmt, ap);
  va_end (ap);
  if (size > 0)
    *f._p = 0;
  return (ret);
}
