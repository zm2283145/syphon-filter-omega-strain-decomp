typedef struct reent_X { int _errno; char pad[0x34]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; long (*_seek)(void*, long, int); int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void func_00123940(reent_X* r);
extern int func_001234E0(FILE_X* fp);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) func_00123940 ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
long func_001246D8(register FILE_X * fp)
{
  long pos;

  CHECK_INIT (fp);

  if (fp->_seek == 0)
    {
      fp->_data->_errno = 29;
      return -1L;
    }

  func_001234E0 (fp);
  if (fp->_flags & 0x1000)
    pos = fp->_offset;
  else
    {
      pos = (*fp->_seek) (fp->_cookie, (long) 0, 1);
      if (pos == -1L)
	return pos;
    }
  if (fp->_flags & 0x0004)
    {
      pos -= fp->_r;
      if (HASUB (fp))
	pos -= fp->_ur;
    }
  else if (fp->_flags & 0x0008 && fp->_p != 0)
    {
      pos += fp->_p - fp->_bf_base;
    }

  return pos;
}