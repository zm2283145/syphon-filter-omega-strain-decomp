typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
typedef struct { int _errno; void* _stdin; void* _stdout; } reent_001272F8;
extern int _vfprintf_r(void* ptr, void* fp, const char* fmt, va_list ap);
int func_001272F8(reent_001272F8* ptr, const char* fmt, ...)
{
  int ret;
  va_list ap;
  va_start (ap, fmt);
  ret = _vfprintf_r (ptr, ptr->_stdout, fmt, ap);
  va_end (ap);
  return ret;
}