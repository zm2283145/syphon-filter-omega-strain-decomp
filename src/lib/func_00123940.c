extern void func_00123900(void);
extern void func_00123730(void* ptr, int flags, int file, void* data);
typedef struct { char b[0x58]; } FILE_00123940;
struct glue_00123940 { struct glue_00123940* _next; int _niobs; FILE_00123940* _iobs; };
typedef struct { char pad0[0x38]; int __sdidinit; void (*__cleanup)(void); char pad1[0x1D8-0x40]; struct glue_00123940 __sglue; FILE_00123940 __sf[3]; } reent_00123940;
void func_00123940(reent_00123940* s)
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