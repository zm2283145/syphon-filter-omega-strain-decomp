/*
 * lib/libc: 2 files, 00125660-00125D88
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00125660 */
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
extern void func_001261B0(void *);
extern void func_00126230(void *);
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
struct mallinfo { int arena; int ordblks; };
extern struct mallinfo D_00489B78;
extern unsigned long D_00489B58;
extern char *D_00489B60;
extern unsigned long D_00489B68, D_00489B70;
extern char *func_00128658(void *, int);
extern void _free_r(void *, void *);
#define sbrked_mem (D_00489B78.arena)
#define initial_top ((mchunkptr)(bin_at(0)))
#define MINSIZE 16
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
extern void func_00125408(void *, INTERNAL_SIZE_T);
#define last(b) ((b)->bk)
#define first(b) ((b)->fd)
#define next_bin(b) ((mbinptr)((char *)(b) + 2 * sizeof(mbinptr)))
#define prev_bin(b) ((mbinptr)((char *)(b) - 2 * sizeof(mbinptr)))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define SMALLBIN_WIDTH 8
#define MAX_SMALLBIN 63
#define is_small_request(nb) (nb < MAX_SMALLBIN_SIZE - SMALLBIN_WIDTH)
#define long_sub_size_t(x, y) (((x) < (y)) ? (-(long)((y) - (x))) : (long)((x) - (y)))
#define request2size(req) \
 (((unsigned long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
  (unsigned long)(MINSIZE + MALLOC_ALIGN_MASK)) ? ((MINSIZE + MALLOC_ALIGN_MASK) & ~(MALLOC_ALIGN_MASK)) : \
   (((unsigned long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK))) & ~(MALLOC_ALIGN_MASK)))
void *_malloc_r(void *reent_ptr, unsigned int bytes)
{
    mchunkptr victim;
    INTERNAL_SIZE_T victim_size;
    int idx;
    mbinptr bin;
    mchunkptr remainder;
    long remainder_size;
    int remainder_index;
    unsigned long block;
    int startidx;
    mchunkptr fwd;
    mchunkptr bck;
    mbinptr q;

    INTERNAL_SIZE_T nb = request2size(bytes);

    func_001261B0(reent_ptr);

    if (is_small_request(nb)) {
        idx = smallbin_index(nb);
        q = bin_at(idx);
        victim = last(q);
        if (victim != q) {
            victim_size = chunksize(victim);
            unlink(victim, bck, fwd);
            set_inuse_bit_at_offset(victim, victim_size);
            func_00126230(reent_ptr);
            return chunk2mem(victim);
        }
        idx += 2;
    } else {
        idx = bin_index(nb);
        bin = bin_at(idx);
        for (victim = last(bin); victim != bin; victim = victim->bk) {
            victim_size = chunksize(victim);
            remainder_size = long_sub_size_t(victim_size, nb);
            if (remainder_size >= (long)MINSIZE) {
                --idx;
                break;
            } else if (remainder_size >= 0) {
                unlink(victim, bck, fwd);
                set_inuse_bit_at_offset(victim, victim_size);
                func_00126230(reent_ptr);
                return chunk2mem(victim);
            }
        }
        ++idx;
    }

    if ((victim = last_remainder->fd) != last_remainder) {
        victim_size = chunksize(victim);
        remainder_size = long_sub_size_t(victim_size, nb);
        if (remainder_size >= (long)MINSIZE) {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | PREV_INUSE);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | PREV_INUSE);
            set_foot(remainder, remainder_size);
            func_00126230(reent_ptr);
            return chunk2mem(victim);
        }
        clear_last_remainder;
        if (remainder_size >= 0) {
            set_inuse_bit_at_offset(victim, victim_size);
            func_00126230(reent_ptr);
            return chunk2mem(victim);
        }
        frontlink(victim, victim_size, remainder_index, bck, fwd);
    }

    if ((block = idx2binblock(idx)) <= binblocks) {
        if ((block & binblocks) == 0) {
            idx = (idx & ~(BINBLOCKWIDTH - 1)) + BINBLOCKWIDTH;
            block <<= 1;
            while ((block & binblocks) == 0) {
                idx += BINBLOCKWIDTH;
                block <<= 1;
            }
        }
        for (;;) {
            startidx = idx;
            q = bin = bin_at(idx);
            do {
                for (victim = last(bin); victim != bin; victim = victim->bk) {
                    victim_size = chunksize(victim);
                    remainder_size = long_sub_size_t(victim_size, nb);
                    if (remainder_size >= (long)MINSIZE) {
                        remainder = chunk_at_offset(victim, nb);
                        set_head(victim, nb | PREV_INUSE);
                        unlink(victim, bck, fwd);
                        link_last_remainder(remainder);
                        set_head(remainder, remainder_size | PREV_INUSE);
                        set_foot(remainder, remainder_size);
                        func_00126230(reent_ptr);
                        return chunk2mem(victim);
                    } else if (remainder_size >= 0) {
                        set_inuse_bit_at_offset(victim, victim_size);
                        unlink(victim, bck, fwd);
                        func_00126230(reent_ptr);
                        return chunk2mem(victim);
                    }
                }
                bin = next_bin(bin);
                if (idx < MAX_SMALLBIN) {
                    bin = next_bin(bin);
                    ++idx;
                }
            } while ((++idx & (BINBLOCKWIDTH - 1)) != 0);
            do {
                if ((startidx & (BINBLOCKWIDTH - 1)) == 0) {
                    binblocks &= ~block;
                    break;
                }
                --startidx;
                q = prev_bin(q);
            } while (first(q) == q);
            if ((block <<= 1) <= binblocks && (block != 0)) {
                while ((block & binblocks) == 0) {
                    idx += BINBLOCKWIDTH;
                    block <<= 1;
                }
            } else
                break;
        }
    }

    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)MINSIZE) {
        func_00125408(reent_ptr, nb);
        remainder_size = long_sub_size_t(chunksize(top), nb);
        if (chunksize(top) < nb || remainder_size < (long)MINSIZE) {
            func_00126230(reent_ptr);
            return 0;
        }
    }
    victim = top;
    set_head(victim, nb | PREV_INUSE);
    top = chunk_at_offset(victim, nb);
    set_head(top, remainder_size | PREV_INUSE);
    func_00126230(reent_ptr);
    return chunk2mem(victim);
}
/* merge_units: end func_00125660 */

/* merge_units: begin func_00125D88 */
int _mbtowc_r(void *r, int *pwc, const char *s, unsigned int n, void *state)
{
  int dummy;
  unsigned char *t = (unsigned char *)s;
  if (pwc == 0)
    pwc = &dummy;
  if (s != 0 && n == 0)
    return -1;
  if (s == 0)
    return 0;
  *pwc = (int)*t;
  return (*t != '\0');
}
/* merge_units: end func_00125D88 */
