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
extern void Newlib_MallocLock(void *);
extern void Newlib_MallocUnlock(void *);
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
extern char *Newlib_SbrkR(void *, int);
extern void _free_r(void *, void *);
#define sbrked_mem (D_00489B78.arena)
#define initial_top ((mchunkptr)(bin_at(0)))
#define MINSIZE 16
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
extern void Newlib_MallocExtendTop(void *, INTERNAL_SIZE_T);
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
extern void *memcpy(void *, const void *, unsigned int);
extern void *_malloc_r(void *, unsigned int);
#define fREe _free_r
#define mALLOc _malloc_r
#define inuse(p) ((((mchunkptr)(((char *)(p)) + ((p)->size & ~PREV_INUSE)))->size) & PREV_INUSE)
#define prev_inuse(p) ((p)->size & PREV_INUSE)
#define prev_chunk(p) ((mchunkptr)(((char *)(p)) - ((p)->prev_size)))
#define next_chunk(p) ((mchunkptr)(((char *)(p)) + ((p)->size & ~PREV_INUSE)))
#define MALLOC_COPY(dest,src,nbytes) \
do { \
  INTERNAL_SIZE_T mcsz = (nbytes); \
  if(mcsz <= 9*sizeof(mcsz)) { \
    INTERNAL_SIZE_T* mcsrc = (INTERNAL_SIZE_T*) (src); \
    INTERNAL_SIZE_T* mcdst = (INTERNAL_SIZE_T*) (dest); \
    if(mcsz >= 5*sizeof(mcsz)) {     *mcdst++ = *mcsrc++; \
                                     *mcdst++ = *mcsrc++; \
      if(mcsz >= 7*sizeof(mcsz)) {   *mcdst++ = *mcsrc++; \
                                     *mcdst++ = *mcsrc++; \
        if(mcsz >= 9*sizeof(mcsz)) { *mcdst++ = *mcsrc++; \
                                     *mcdst++ = *mcsrc++; }}} \
                                     *mcdst++ = *mcsrc++; \
                                     *mcdst++ = *mcsrc++; \
                                     *mcdst   = *mcsrc  ; \
  } else memcpy(dest, src, mcsz); \
} while(0)
void *_realloc_r(void *reent_ptr, void *oldmem, unsigned int bytes)
{
    INTERNAL_SIZE_T nb;
    mchunkptr oldp;
    INTERNAL_SIZE_T oldsize;
    mchunkptr newp;
    INTERNAL_SIZE_T newsize;
    void *newmem;
    mchunkptr next;
    INTERNAL_SIZE_T nextsize;
    mchunkptr prev;
    INTERNAL_SIZE_T prevsize;
    mchunkptr remainder;
    INTERNAL_SIZE_T remainder_size;
    mchunkptr bck;
    mchunkptr fwd;

    if (oldmem == 0) return mALLOc(reent_ptr, bytes);

    Newlib_MallocLock(reent_ptr);

    newp = oldp = mem2chunk(oldmem);
    newsize = oldsize = chunksize(oldp);

    nb = request2size(bytes);

    if ((long)(oldsize) < (long)(nb)) {
        next = chunk_at_offset(oldp, oldsize);
        if (next == top || !inuse(next)) {
            nextsize = chunksize(next);
            if (next == top) {
                if ((long)(nextsize + newsize) >= (long)(nb + MINSIZE)) {
                    newsize += nextsize;
                    top = chunk_at_offset(oldp, nb);
                    set_head(top, (newsize - nb) | PREV_INUSE);
                    set_head_size(oldp, nb);
                    Newlib_MallocUnlock(reent_ptr);
                    return chunk2mem(oldp);
                }
            } else if (((long)(nextsize + newsize) >= (long)(nb))) {
                unlink(next, bck, fwd);
                newsize += nextsize;
                goto split;
            }
        } else {
            next = 0;
            nextsize = 0;
        }

        if (!prev_inuse(oldp)) {
            prev = prev_chunk(oldp);
            prevsize = chunksize(prev);
            if (next != 0) {
                if (next == top) {
                    if ((long)(nextsize + prevsize + newsize) >= (long)(nb + MINSIZE)) {
                        unlink(prev, bck, fwd);
                        newp = prev;
                        newsize += prevsize + nextsize;
                        newmem = chunk2mem(newp);
                        MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                        top = chunk_at_offset(newp, nb);
                        set_head(top, (newsize - nb) | PREV_INUSE);
                        set_head_size(newp, nb);
                        Newlib_MallocUnlock(reent_ptr);
                        return newmem;
                    }
                } else if (((long)(nextsize + prevsize + newsize) >= (long)(nb))) {
                    unlink(next, bck, fwd);
                    unlink(prev, bck, fwd);
                    newp = prev;
                    newsize += nextsize + prevsize;
                    newmem = chunk2mem(newp);
                    MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                    goto split;
                }
            }
            if (prev != 0 && (long)(prevsize + newsize) >= (long)nb) {
                unlink(prev, bck, fwd);
                newp = prev;
                newsize += prevsize;
                newmem = chunk2mem(newp);
                MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
                goto split;
            }
        }

        newmem = mALLOc(reent_ptr, bytes);
        if (newmem == 0) {
            Newlib_MallocUnlock(reent_ptr);
            return 0;
        }
        if ((newp = mem2chunk(newmem)) == next_chunk(oldp)) {
            newsize += chunksize(newp);
            newp = oldp;
            goto split;
        }
        MALLOC_COPY(newmem, oldmem, oldsize - SIZE_SZ);
        fREe(reent_ptr, oldmem);
        Newlib_MallocUnlock(reent_ptr);
        return newmem;
    }

split:
    remainder_size = long_sub_size_t(newsize, nb);
    if (remainder_size >= (long)MINSIZE) {
        remainder = chunk_at_offset(newp, nb);
        set_head_size(newp, nb);
        set_head(remainder, remainder_size | PREV_INUSE);
        set_inuse_bit_at_offset(remainder, remainder_size);
        fREe(reent_ptr, chunk2mem(remainder));
    } else {
        set_head_size(newp, newsize);
        set_inuse_bit_at_offset(newp, newsize);
    }
    Newlib_MallocUnlock(reent_ptr);
    return chunk2mem(newp);
}