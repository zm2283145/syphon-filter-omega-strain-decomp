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
extern void func_00123940(struct _reent *);
extern int func_001234E0(FILE *);
extern void func_00124FE0(FILE *);
extern int func_00124678(struct _reent *, int, struct stat *);
extern void func_00123D60(struct _reent *, void *);
extern int func_001284D8(FILE *);
extern fpos_t func_00128DF8(void *, fpos_t, int);
#define POS_ERR (-(fpos_t)1)
#define CHECK_INIT(fp) do { if ((fp)->_data == 0) (fp)->_data = D_00489738; if (!(fp)->_data->__sdidinit) func_00123940((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub._base != 0)
#define FREEUB(fp) { if ((fp)->_ub._base != (fp)->_ubuf) func_00123D60(fp->_data, (char *)(fp)->_ub._base); (fp)->_ub._base = 0; }
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
        func_001234E0(fp);
    if ((seekfn = fp->_seek) == 0) {
        ptr->_errno = 29;
        return -1;
    }
    switch (whence) {
    case 1:
        func_001234E0(fp);
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
        func_00124FE0(fp);
    if (fp->_flags & (0x8 | 0x10 | 0x2 | 0x800))
        goto dumb;
    if ((fp->_flags & 0x400) == 0) {
        if (seekfn != func_00128DF8
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
        if (func_001284D8(fp) || fp->_r < n)
            goto dumb;
        fp->_p += n;
        fp->_r -= n;
    }
    return 0;

dumb:
    if (func_001234E0(fp) || (*seekfn)(fp->_cookie, offset, whence) == POS_ERR)
        return -1;
    if (HASUB(fp))
        FREEUB(fp);
    fp->_p = fp->_bf._base;
    fp->_r = 0;
    fp->_flags &= ~0x20;
    return 0;
}