typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _base; int _size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x50-0x30]; int _offset; void* _data; } FILE_X;
extern long func_00124F80(void* r, int fd, long off, int whence);
long func_00128DF8(void *cookie, long offset, int whence)
{
  register FILE_X *fp = (FILE_X *) cookie;
  register long ret;

  ret = func_00124F80 (fp->_data, fp->_file, (long) offset, whence);
  if (ret == -1L)
    fp->_flags &= ~0x1000;
  else
    {
      fp->_flags |= 0x1000;
      fp->_offset = ret;
    }
  return ret;
}