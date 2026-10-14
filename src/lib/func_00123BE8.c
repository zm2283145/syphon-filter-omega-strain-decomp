typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
extern int vfprintf(void* p, const char* fmt, va_list ap);
int func_00123BE8(void* p, const char* fmt, ...)
{
  int ret;
  va_list ap;
  va_start (ap, fmt);
  ret = vfprintf (p, fmt, ap);
  va_end (ap);
  return ret;
}