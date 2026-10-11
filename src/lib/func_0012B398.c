typedef struct reent_X { int _errno; char pad[0x34]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; long (*_seek)(void*, long, int); int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void func_00123940(reent_X* r);
extern int func_001234E0(FILE_X* fp);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) func_00123940 ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
extern int func_0012B2B0(FILE_X* fp);
int func_0012B398(int c, register FILE_X *fp)
{
  if (c == -1)
    return (-1);

  CHECK_INIT (fp);

  fp->_flags &= ~0x0020;

  if ((fp->_flags & 0x0004) == 0)
    {
      if ((fp->_flags & 0x0010) == 0)
	return -1;
      if (fp->_flags & 0x0008)
	{
	  if (func_001234E0 (fp))
	    return -1;
	  fp->_flags &= ~0x0008;
	  fp->_w = 0;
	  fp->_lbfsize = 0;
	}
      fp->_flags |= 0x0004;
    }
  c = (unsigned char) c;

  if (HASUB (fp))
    {
      if (fp->_r >= fp->_ub_size && func_0012B2B0 (fp))
	return -1;
      *--fp->_p = c;
      fp->_r++;
      return c;
    }

  if (fp->_bf_base != 0 && fp->_p > fp->_bf_base && fp->_p[-1] == c)
    {
      fp->_p--;
      fp->_r++;
      return c;
    }

  fp->_ur = fp->_r;
  fp->_up = fp->_p;
  fp->_ub_base = fp->_ubuf;
  fp->_ub_size = sizeof (fp->_ubuf);
  fp->_ubuf[sizeof (fp->_ubuf) - 1] = c;
  fp->_p = &fp->_ubuf[sizeof (fp->_ubuf) - 1];
  fp->_r = 1;
  return c;
}