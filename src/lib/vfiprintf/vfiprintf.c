/*
 * lib/vfiprintf: 2 files, 0012B520-0012B568
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012B520 */
#include "types.h"
#include "buffer_release_clear.h"

/* compiler: ee-gcc 2.96 -O2 */
/* Release and clear a buffer. */
DEFINE_BUFFER_RELEASE_CLEAR(func_0012B520)
/* merge_units: end func_0012B520 */

/* merge_units: begin func_0012B568 */
typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)();
    SBUF _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    SBUF _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;extern int func_0012B620(FILE *, const char *, void *);
extern int func_001234E0(FILE *);
int func_0012B568(FILE *fp, const char *fmt, void *ap)
{
    int ret;
    FILE fake;
    unsigned char buf[1024];

    fake._data = fp->_data;
    fake._flags = fp->_flags & ~0x2;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;

    fake._bf._base = fake._p = buf;
    fake._bf._size = fake._w = sizeof(buf);
    fake._lbfsize = 0;

    ret = func_0012B620(&fake, fmt, ap);
    if (ret >= 0 && func_001234E0(&fake))
        ret = -1;
    if (fake._flags & 0x40)
        fp->_flags |= 0x40;
    return ret;
}
/* merge_units: end func_0012B568 */
