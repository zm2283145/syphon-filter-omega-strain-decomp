/*
 * lib/libc: 2 files, 00123330-001233E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00123330 */
typedef struct A00123330 { struct A00123330 *_next; int _ind; void (*_fns[32])(void); } A00123330;
typedef struct { char p[0x3C]; void (*__cleanup)(void *); char q[0x108]; A00123330 *_atexit; } R00123330;
extern R00123330 *D_00489738;
extern void Newlib_SysExit_Thunk(int);
void Libc_Exit(int code)
{
    A00123330 *p;
    int n;
    for (p = D_00489738->_atexit; p; p = p->_next)
        for (n = p->_ind; --n >= 0;)
            (*p->_fns[n])();
    if (D_00489738->__cleanup) (*D_00489738->__cleanup)(D_00489738);
    Newlib_SysExit_Thunk(code);
}
/* merge_units: end func_00123330 */

/* merge_units: begin func_001233E0 */
typedef struct reent_X { char pad[0x38]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
#if 0 /* merge_units */
extern reent_X* D_00489738;
#endif /* merge_units */
#define D_00489738 (*(reent_X **)&D_00489738) /* merge_units */

extern void __sinit(reent_X* r);
extern void _free_r(reent_X* r, void* p);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
#define FREEUB(fp) { if ((fp)->_ub_base != (fp)->_ubuf) _free_r((fp)->_data, (char *)(fp)->_ub_base); (fp)->_ub_base = 0; }
#define HASLB(fp) ((fp)->_lb_base != 0)
#define FREELB(fp) { _free_r((fp)->_data, (char *)(fp)->_lb_base); (fp)->_lb_base = 0; }
extern int fflush(FILE_X* fp);
int Libc_Fclose(FILE_X * fp)
{
  int r;

  if (fp == 0)
    return (0);
  CHECK_INIT (fp);
  if (fp->_flags == 0)
    return (0);
  r = fp->_flags & 0x0008 ? fflush (fp) : 0;
  if (fp->_close != 0 && (*fp->_close) (fp->_cookie) < 0)
    r = -1;
  if (fp->_flags & 0x0080)
    _free_r (fp->_data, (char *) fp->_bf_base);
  if (HASUB (fp))
    FREEUB (fp);
  if (HASLB (fp))
    FREELB (fp);
  fp->_flags = 0;
  return (r);
}
#undef D_00489738 /* merge_units */
/* merge_units: end func_001233E0 */
