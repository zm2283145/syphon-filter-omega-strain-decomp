/*
 * lib/libc: 3 files, 00123BE8-00123D60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00123BE8 */
typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_stdarg_start((v),l)
#define va_end(v) __builtin_va_end(v)
extern int vfprintf(void* p, const char* fmt, va_list ap);
int func_00123BE8(void* p, const char* fmt, ...)
{
  int ret;
  va_list ap;
  va_start (ap, fmt);
  ret = vfprintf (p, fmt, ap);
  va_end (ap);
  return ret;
}
/* merge_units: end func_00123BE8 */

/* merge_units: begin func_00123C40 */
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
/* merge_units: end func_00123C40 */

/* merge_units: begin func_00123D60 */
#define INTERNAL_SIZE_T unsigned int
struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};
typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;
extern mbinptr D_00489748[];
unsigned long D_00489B50 = 0x20000;
unsigned long D_00489B58 = 0;
extern void func_001261B0(void *);
extern void func_00126230(void *);
extern int func_00124058(void *, unsigned int);
#define av_ D_00489748
#define SIZE_SZ 4
#define PREV_INUSE 0x1
#define SIZE_BITS 3
#define MAX_SMALLBIN_SIZE 512
#define BINBLOCKWIDTH 4
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 2 * SIZE_SZ))
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (bin_at(0)->size)
#define mem2chunk(mem) ((mchunkptr)((char *)(mem) - 2 * SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size & PREV_INUSE)
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define idx2binblock(ix) ((unsigned long)1 << (ix / BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}
void _free_r(void *reent_ptr, void *mem)
{
    mchunkptr p;
    INTERNAL_SIZE_T hd;
    INTERNAL_SIZE_T sz;
    int idx;
    mchunkptr next;
    INTERNAL_SIZE_T nextsz;
    INTERNAL_SIZE_T prevsz;
    mchunkptr bck;
    mchunkptr fwd;
    int islr;

    if (mem == 0)
        return;

    func_001261B0(reent_ptr);

    p = mem2chunk(mem);
    hd = p->size;

    sz = hd & ~PREV_INUSE;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);

    if (next == top) {
        sz += nextsz;
        if (!(hd & PREV_INUSE)) {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -prevsz);
            sz += prevsz;
            unlink(p, bck, fwd);
        }
        set_head(p, sz | PREV_INUSE);
        top = p;
        if ((unsigned long)(sz) >= (unsigned long)D_00489B50)
            func_00124058(reent_ptr, D_00489B58);
        func_00126230(reent_ptr);
        return;
    }

    set_head(next, nextsz);

    islr = 0;

    if (!(hd & PREV_INUSE)) {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -prevsz);
        sz += prevsz;
        if (p->fd == last_remainder)
            islr = 1;
        else
            unlink(p, bck, fwd);
    }

    if (!(inuse_bit_at_offset(next, nextsz))) {
        sz += nextsz;
        if (!islr && next->fd == last_remainder) {
            islr = 1;
            link_last_remainder(p);
        } else
            unlink(next, bck, fwd);
    }

    set_head(p, sz | PREV_INUSE);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);

    func_00126230(reent_ptr);
}
/* merge_units: end func_00123D60 */
