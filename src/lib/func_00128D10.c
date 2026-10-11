typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _base; int _size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x50-0x30]; int _offset; void* _data; } FILE_X;
extern long func_00127E38(void* r, int fd, void* buf, int n);
int func_00128D10(void *cookie, char *buf, int n)
{
  register FILE_X *fp = (FILE_X *) cookie;
  register int ret;

  ret = func_00127E38 (fp->_data, fp->_file, buf, n);

  if (ret >= 0)
    fp->_offset += ret;
  else
    fp->_flags &= ~0x1000;
  return ret;
}