typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _base; int _size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x50-0x30]; int _offset; void* _data; } FILE_X;
extern int func_001234E0(FILE_X* fp);
int func_001284A0(FILE_X* fp)
{
  if ((fp->_flags & (0x0001 | 0x0008)) == (0x0001 | 0x0008))
    return func_001234E0 (fp);
  return 0;
}