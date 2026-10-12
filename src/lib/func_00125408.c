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
unsigned long D_00489B68 = 0;
unsigned long D_00489B70 = 0;
extern char *func_00128658(void *, int);
extern void func_00123D60(void *, void *);
#define sbrked_mem (D_00489B78.arena)
#define initial_top ((mchunkptr)(bin_at(0)))
#define MINSIZE 16
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
void func_00125408(void *reent_ptr, INTERNAL_SIZE_T nb)
{
    char *brk;
    INTERNAL_SIZE_T front_misalign;
    INTERNAL_SIZE_T correction;
    char *new_brk;
    INTERNAL_SIZE_T top_size;

    mchunkptr old_top = top;
    INTERNAL_SIZE_T old_top_size = chunksize(old_top);
    char *old_end = (char *)(chunk_at_offset(old_top, old_top_size));

    INTERNAL_SIZE_T sbrk_size = nb + D_00489B58 + MINSIZE;
    unsigned long pagesz = 4096;

    if (D_00489B60 != (char *)(-1))
        sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);

    brk = (char *)(func_00128658(reent_ptr, sbrk_size));

    if (brk == (char *)(-1) ||
        (brk < old_end && old_top != initial_top))
        return;

    sbrked_mem += sbrk_size;

    if (brk == old_end) {
        top_size = sbrk_size + old_top_size;
        set_head(top, top_size | PREV_INUSE);
    } else {
        if (D_00489B60 == (char *)(-1))
            D_00489B60 = brk;
        else
            sbrked_mem += brk - (char *)old_end;

        front_misalign = (unsigned long)chunk2mem(brk) & MALLOC_ALIGN_MASK;
        if (front_misalign > 0) {
            correction = (MALLOC_ALIGNMENT) - front_misalign;
            brk += correction;
        } else
            correction = 0;

        correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));

        new_brk = (char *)(func_00128658(reent_ptr, correction));
        if (new_brk == (char *)(-1)) return;

        sbrked_mem += correction;

        top = (mchunkptr)brk;
        top_size = new_brk - brk + correction;
        set_head(top, top_size | PREV_INUSE);

        if (old_top != initial_top) {
            if (old_top_size < MINSIZE) {
                set_head(top, PREV_INUSE);
                return;
            }
            old_top_size = (old_top_size - 3 * SIZE_SZ) & ~MALLOC_ALIGN_MASK;
            set_head_size(old_top, old_top_size);
            chunk_at_offset(old_top, old_top_size)->size = SIZE_SZ | PREV_INUSE;
            chunk_at_offset(old_top, old_top_size + SIZE_SZ)->size = SIZE_SZ | PREV_INUSE;
            if (old_top_size >= MINSIZE)
                func_00123D60(reent_ptr, chunk2mem(old_top));
        }
    }

    if ((unsigned long)sbrked_mem > (unsigned long)D_00489B68)
        D_00489B68 = sbrked_mem;
    if ((unsigned long)(sbrked_mem) > (unsigned long)D_00489B70)
        D_00489B70 = sbrked_mem;
}