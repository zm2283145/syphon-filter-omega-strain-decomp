typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
extern int vfiprintf(void* p, const char* fmt, va_list ap);
int func_001239D0(void* p, const char* fmt, ...)
{
  int ret;
  va_list ap;
  va_start (ap, fmt);
  ret = vfiprintf (p, fmt, ap);
  va_end (ap);
  return ret;
}