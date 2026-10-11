typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _base; int _size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x50-0x30]; int _offset; void* _data; } FILE_X;
extern long func_00124F80(void* r, int fd, long off, int whence);
extern long func_0012EB58(void* r, int fd, const void* buf, int n);
int func_00128D78(void *cookie, char const *buf, int n)
{
  register FILE_X *fp = (FILE_X *) cookie;

  if (fp->_flags & 0x0100)
    func_00124F80 (fp->_data, fp->_file, (long) 0, 2);
  fp->_flags &= ~0x1000;
  return func_0012EB58 (fp->_data, fp->_file, buf, n);
}