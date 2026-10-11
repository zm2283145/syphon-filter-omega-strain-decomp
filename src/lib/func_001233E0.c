typedef struct reent_X { char pad[0x38]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void func_00123940(reent_X* r);
extern void func_00123D60(reent_X* r, void* p);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) func_00123940 ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
#define FREEUB(fp) { if ((fp)->_ub_base != (fp)->_ubuf) func_00123D60((fp)->_data, (char *)(fp)->_ub_base); (fp)->_ub_base = 0; }
#define HASLB(fp) ((fp)->_lb_base != 0)
#define FREELB(fp) { func_00123D60((fp)->_data, (char *)(fp)->_lb_base); (fp)->_lb_base = 0; }
extern int func_001234E0(FILE_X* fp);
int func_001233E0(FILE_X * fp)
{
  int r;

  if (fp == 0)
    return (0);
  CHECK_INIT (fp);
  if (fp->_flags == 0)
    return (0);
  r = fp->_flags & 0x0008 ? func_001234E0 (fp) : 0;
  if (fp->_close != 0 && (*fp->_close) (fp->_cookie) < 0)
    r = -1;
  if (fp->_flags & 0x0080)
    func_00123D60 (fp->_data, (char *) fp->_bf_base);
  if (HASUB (fp))
    FREEUB (fp);
  if (HASLB (fp))
    FREELB (fp);
  fp->_flags = 0;
  return (r);
}