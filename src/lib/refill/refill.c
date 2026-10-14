/* newlib refill.c: lflush and __srefill.  Compiler: EE-GCC 2.96 -O2 -G0. */
typedef struct reent_X { char pad[0x38]; int __sdidinit; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; int (*_read)(void*, char*, int); void* _write; void* _seek; int (*_close)(void*); unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern reent_X* D_00489738;
extern void __sinit(reent_X* r);
extern void _free_r(reent_X* r, void* p);
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit ((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub_base != 0)
#define FREEUB(fp) { if ((fp)->_ub_base != (fp)->_ubuf) _free_r((fp)->_data, (char *)(fp)->_ub_base); (fp)->_ub_base = 0; }
extern int fflush(FILE_X* fp);
extern void func_00124FE0(FILE_X* fp);
extern int func_00124BC0(reent_X* r, int (*f)(FILE_X*));
int func_001284A0(FILE_X *fp)   /* lflush */
{
  if ((fp->_flags & (0x0001 | 0x0008)) == (0x0001 | 0x0008))
    return fflush (fp);
  return 0;
}

int __srefill(register FILE_X * fp)
{
  CHECK_INIT (fp);

  fp->_r = 0;
  if (fp->_flags & 0x0020)
    return -1;

  if ((fp->_flags & 0x0004) == 0)
    {
      if ((fp->_flags & 0x0010) == 0)
	return -1;
      if (fp->_flags & 0x0008)
	{
	  if (fflush (fp))
	    return -1;
	  fp->_flags &= ~0x0008;
	  fp->_w = 0;
	  fp->_lbfsize = 0;
	}
      fp->_flags |= 0x0004;
    }
  else
    {
      if (HASUB (fp))
	{
	  FREEUB (fp);
	  if ((fp->_r = fp->_ur) != 0)
	    {
	      fp->_p = fp->_up;
	      return 0;
	    }
	}
    }

  if (fp->_bf_base == 0)
    func_00124FE0 (fp);

  if (fp->_flags & (0x0001 | 0x0002))
    (void) func_00124BC0 (fp->_data, func_001284A0);
  fp->_p = fp->_bf_base;
  fp->_r = (*fp->_read) (fp->_cookie, (char *) fp->_p, fp->_bf_size);
  fp->_flags &= ~0x2000;
  if (fp->_r <= 0)
    {
      if (fp->_r == 0)
	fp->_flags |= 0x0020;
      else
	{
	  fp->_r = 0;
	  fp->_flags |= 0x0040;
	}
      return -1;
    }
  return 0;
}