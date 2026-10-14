/*
 * lib/libc: 4 files, 00124F60-00125138
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00124F60 */
extern int D_00489738;
extern int func_00124F28(int r);
int localeconv(void) { return func_00124F28(D_00489738); }
/* merge_units: end func_00124F60 */

/* merge_units: begin func_00124F80 */
extern int D_0058805C;
extern int func_0010D858(int fd, void* buf, unsigned int cnt);
struct reent_00124F80 { int _errno; };
int func_00124F80(struct reent_00124F80* ptr, int fd, void* buf, unsigned int cnt)
{
    int ret;
    D_0058805C = 0;
    if ((ret = func_0010D858(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}
/* merge_units: end func_00124F80 */

/* merge_units: begin func_00124FE0 */
typedef struct reent_X { char pad[0x3C]; void (*__cleanup)(void); } reent_X;
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; unsigned char* _ub_base; int _ub_size; unsigned char* _up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; unsigned char* _lb_base; int _lb_size; int _blksize; int _offset; reent_X* _data; } FILE_X;
struct stat_X { short st_dev; unsigned short st_ino; unsigned int st_mode; char rest[0x68]; };
extern int func_00124678(reent_X* r, int fd, struct stat_X* st);
extern void* _malloc_r(reent_X* r, unsigned int n);
extern int func_0010D910(int fd);
extern long func_00128DF8();
extern void func_00123900(void);
void func_00124FE0(register FILE_X *fp)
{
  register unsigned int size, couldbetty;
  register void *p;
  struct stat_X st;

  if (fp->_flags & 0x0002)
    {
      fp->_bf_base = fp->_p = fp->_nbuf;
      fp->_bf_size = 1;
      return;
    }
  if (fp->_file < 0 || func_00124678 (fp->_data, fp->_file, &st) < 0)
    {
      couldbetty = 0;
      size = 1024;
      fp->_flags |= 0x0800;
    }
  else
    {
      couldbetty = (st.st_mode & 0170000) == 0020000;
      size = 1024;
      if ((st.st_mode & 0170000) == 0100000 && fp->_seek == func_00128DF8)
	{
	  fp->_flags |= 0x0400;
	  fp->_blksize = size;
	}
      else
	fp->_flags |= 0x0800;
    }
  if ((p = _malloc_r (fp->_data, size)) == 0)
    {
      fp->_flags |= 0x0002;
      fp->_bf_base = fp->_p = fp->_nbuf;
      fp->_bf_size = 1;
    }
  else
    {
      fp->_data->__cleanup = func_00123900;
      fp->_flags |= 0x0080;
      fp->_bf_base = fp->_p = (unsigned char *) p;
      fp->_bf_size = size;
      if (couldbetty && func_0010D910 (fp->_file))
	fp->_flags |= 0x0001;
    }
}
/* merge_units: end func_00124FE0 */

/* merge_units: begin func_00125138 */
#include "types.h"
#if 0 /* merge_units */
extern void* D_00489738;
#endif /* merge_units */
#define D_00489738 (*(void **)&D_00489738) /* merge_units */

extern void func_001261B0(void* r);
extern void func_00126230(void* r);
extern void* func_001251A0(void* reent, unsigned int n, unsigned int elem_size);
void* func_00125138(unsigned int n, unsigned int size)
{
    void* r;
    func_001261B0(D_00489738);
    r = func_001251A0(D_00489738, n, size);
    func_00126230(D_00489738);
    return r;
}
#undef D_00489738 /* merge_units */
/* merge_units: end func_00125138 */
