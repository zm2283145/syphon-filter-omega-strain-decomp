/*
 * lib/libc: 2 files, 00124058-001241C8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00124058 */
typedef struct { unsigned int prev_size; unsigned int size; } *mchunkptr;
extern char *D_00489748[];
struct mallinfo { int arena; int ordblks; };
extern struct mallinfo D_00489B78;
const unsigned int D_00489B60[2] = { 0xFFFFFFFF, 0x0 };
extern void Newlib_MallocLock(void *);
extern void Newlib_MallocUnlock(void *);
extern char *Newlib_SbrkR(void *, int);
#define top ((mchunkptr)(D_00489748[2]))
int Newlib_MallocTrimR(void *ptr, unsigned int pad)
{
    long top_size;
    long extra;
    char *current_brk;
    char *new_brk;
    unsigned long pagesz = 4096;

    Newlib_MallocLock(ptr);
    top_size = top->size & ~3;
    extra = ((top_size - pad - 16 + (pagesz - 1)) / pagesz - 1) * pagesz;
    if (extra < (long)pagesz) {
        Newlib_MallocUnlock(ptr);
        return 0;
    } else {
        current_brk = (char *)(Newlib_SbrkR(ptr, 0));
        if (current_brk != (char *)(top) + top_size) {
            Newlib_MallocUnlock(ptr);
            return 0;
        } else {
            new_brk = (char *)(Newlib_SbrkR(ptr, -extra));
            if (new_brk == (char *)(-1)) {
                current_brk = (char *)(Newlib_SbrkR(ptr, 0));
                top_size = current_brk - (char *)top;
                if (top_size >= (long)16) {
                    D_00489B78.arena = current_brk - (*(char **)D_00489B60);
                    top->size = top_size | 1;
                }
                Newlib_MallocUnlock(ptr);
                return 0;
            } else {
                top->size = (top_size - extra) | 1;
                D_00489B78.arena -= extra;
                Newlib_MallocUnlock(ptr);
                return 1;
            }
        }
    }
}
/* merge_units: end func_00124058 */

/* merge_units: begin func_001241C8 */
struct _reent { int _errno; char p[0x34]; int __sdidinit; };
typedef long fpos_t;
typedef struct { unsigned char *_base; int _size; } SBUF;
typedef struct {
    unsigned char *_p; int _r; int _w; short _flags; short _file; SBUF _bf; int _lbfsize;
    void *_cookie; int (*_read)(); int (*_write)(); fpos_t (*_seek)(void *, fpos_t, int); int (*_close)();
    SBUF _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1];
    SBUF _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;
struct stat { int st_dev; unsigned int st_mode; int a, b; long st_size; char rest[0x50]; };
extern struct _reent *D_00489738;
extern void __sinit(struct _reent *);
extern int fflush(FILE *);
extern void Newlib_Smakebuf(FILE *);
extern int func_00124678(struct _reent *, int, struct stat *);
extern void _free_r(struct _reent *, void *);
extern int __srefill(FILE *);
extern fpos_t Newlib_Sseek(void *, fpos_t, int);
#define POS_ERR (-(fpos_t)1)
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) __sinit((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub._base != 0)
#define FREEUB(fp) { if ((fp)->_ub._base != (fp)->_ubuf) _free_r(fp->_data, (char *)(fp)->_ub._base); (fp)->_ub._base = 0; }
int func_001241C8(register FILE *fp, long offset, int whence)
{
    struct _reent *ptr;
    fpos_t (*seekfn)(void *, fpos_t, int);
    fpos_t target, curoff;
    unsigned int n;
    struct stat st;
    int havepos;

    CHECK_INIT(fp);
    ptr = fp->_data;
    if (fp->_flags & 0x100 && fp->_flags & 0x8)
        fflush(fp);
    if ((seekfn = fp->_seek) == 0) {
        ptr->_errno = 29;
        return -1;
    }
    switch (whence) {
    case 1:
        fflush(fp);
        if (fp->_flags & 0x1000)
            curoff = fp->_offset;
        else {
            curoff = (*seekfn)(fp->_cookie, (fpos_t)0, 1);
            if (curoff == -1L)
                return -1;
        }
        if (fp->_flags & 0x4) {
            curoff -= fp->_r;
            if (HASUB(fp))
                curoff -= fp->_ur;
        } else if (fp->_flags & 0x8 && fp->_p != 0)
            curoff += fp->_p - fp->_bf._base;
        offset += curoff;
        whence = 0;
        havepos = 1;
        break;
    case 0:
    case 2:
        havepos = 0;
        break;
    default:
        ptr->_errno = 22;
        return -1;
    }

    if (fp->_bf._base == 0)
        Newlib_Smakebuf(fp);
    if (fp->_flags & (0x8 | 0x10 | 0x2 | 0x800))
        goto dumb;
    if ((fp->_flags & 0x400) == 0) {
        if (seekfn != Newlib_Sseek
            || fp->_file < 0
            || func_00124678(ptr, fp->_file, &st)
            || (st.st_mode & 0170000) != 0100000) {
            fp->_flags |= 0x800;
            goto dumb;
        }
        fp->_blksize = 1024;
        fp->_flags |= 0x400;
    }

    if (whence == 0)
        target = offset;
    else {
        if (func_00124678(ptr, fp->_file, &st))
            goto dumb;
        target = st.st_size + offset;
    }

    if (!havepos) {
        if (fp->_flags & 0x1000)
            curoff = fp->_offset;
        else {
            curoff = (*seekfn)(fp->_cookie, 0L, 1);
            if (curoff == POS_ERR)
                goto dumb;
        }
        curoff -= fp->_r;
        if (HASUB(fp))
            curoff -= fp->_ur;
    }

    if (HASUB(fp)) {
        curoff += fp->_r;
        n = fp->_up - fp->_bf._base;
        curoff -= n;
        n += fp->_ur;
    } else {
        n = fp->_p - fp->_bf._base;
        curoff -= n;
        n += fp->_r;
    }

    if ((fp->_flags & 0x2000) == 0 &&
        target >= curoff && target < curoff + n) {
        register int o = target - curoff;

        fp->_p = fp->_bf._base + o;
        fp->_r = n - o;
        if (HASUB(fp))
            FREEUB(fp);
        fp->_flags &= ~0x20;
        return 0;
    }

    curoff = target & ~(fp->_blksize - 1);
    if ((*seekfn)(fp->_cookie, curoff, 0) == POS_ERR)
        goto dumb;
    fp->_r = 0;
    if (HASUB(fp))
        FREEUB(fp);
    fp->_flags &= ~0x20;
    n = target - curoff;
    if (n) {
        if (__srefill(fp) || fp->_r < n)
            goto dumb;
        fp->_p += n;
        fp->_r -= n;
    }
    return 0;

dumb:
    if (fflush(fp) || (*seekfn)(fp->_cookie, offset, whence) == POS_ERR)
        return -1;
    if (HASUB(fp))
        FREEUB(fp);
    fp->_p = fp->_bf._base;
    fp->_r = 0;
    fp->_flags &= ~0x20;
    return 0;
}
/* merge_units: end func_001241C8 */
