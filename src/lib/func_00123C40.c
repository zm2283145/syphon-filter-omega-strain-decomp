typedef struct reent_X { char pad[0x3C]; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
extern void* memcpy(void*, const void*, unsigned int);
extern int __srefill(FILE_X* fp);
unsigned int fread(void *buf, unsigned int size, unsigned int count, FILE_X * fp)
{
  register unsigned int resid;
  register char *p;
  register int r;
  unsigned int total;

  if ((resid = count * size) == 0)
    return 0;
  if (fp->_r < 0)
    fp->_r = 0;
  total = resid;
  p = buf;
  while (resid > (r = fp->_r))
    {
      (void) memcpy ((void *) p, (void *) fp->_p, (unsigned int) r);
      fp->_p += r;
      p += r;
      resid -= r;
      if (__srefill (fp))
	{
	  return (total - resid) / size;
	}
    }
  (void) memcpy ((void *) p, (void *) fp->_p, resid);
  fp->_r -= resid;
  fp->_p += resid;
  return count;
}