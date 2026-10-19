/*
 * lib/libc: 3 files, 00123940-00123A28
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00123940 */
extern void func_00123900(void);
extern void func_00123730(void* ptr, int flags, int file, void* data);
typedef struct { char b[0x58]; } FILE_00123940;
struct glue_00123940 { struct glue_00123940* _next; int _niobs; FILE_00123940* _iobs; };
typedef struct { char pad0[0x38]; int __sdidinit; void (*__cleanup)(void); char pad1[0x1D8-0x40]; struct glue_00123940 __sglue; FILE_00123940 __sf[3]; } reent_00123940;
void __sinit(reent_00123940* s)
{
  s->__cleanup = func_00123900;
  s->__sdidinit = 1;
  func_00123730(s->__sf + 0, 4, 0, s);
  func_00123730(s->__sf + 1, 9, 1, s);
  func_00123730(s->__sf + 2, 10, 2, s);
  s->__sglue._next = 0;
  s->__sglue._niobs = 3;
  s->__sglue._iobs = &s->__sf[0];
}
/* merge_units: end func_00123940 */

/* merge_units: begin func_001239D0 */
typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
extern int vfiprintf(void* p, const char* fmt, va_list ap);
int Libc_Fiprintf(void* p, const char* fmt, ...)
{
  int ret;
  va_list ap;
  va_start (ap, fmt);
  ret = vfiprintf (p, fmt, ap);
  va_end (ap);
  return ret;
}
/* merge_units: end func_001239D0 */

/* merge_units: begin func_00123A28 */
struct reent_00123A28 { int _errno; };
int func_00123A28(struct reent_00123A28* ptr, const char* mode, int* optr)
{
  register int ret, m, o;

  switch (mode[0])
    {
    case 'r':
      ret = 0x0004;
      m = 0;
      o = 0;
      break;

    case 'w':
      ret = 0x0008;
      m = 1;
      o = 0x200 | 0x400;
      break;

    case 'a':
      ret = 0x0008 | 0x0100;
      m = 1;
      o = 0x200 | 0x8;
      break;

    default:
      ptr->_errno = 22;
      return (0);
    }
  if (mode[1] && (mode[1] == '+' || mode[2] == '+'))
    {
      ret = 0x0010;
      m = 2;
    }
  *optr = m | o;
  return ret;
}
/* merge_units: end func_00123A28 */
