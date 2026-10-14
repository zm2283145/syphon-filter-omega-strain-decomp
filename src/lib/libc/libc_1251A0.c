typedef unsigned int size_t;
typedef size_t INTERNAL_SIZE_T;
struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk* fd;
    struct malloc_chunk* bk;
};
typedef struct malloc_chunk* mchunkptr;
struct _reent;
extern void* _malloc_r(struct _reent*, size_t);
extern void func_001261B0(struct _reent*);
extern void func_00126230(struct _reent*);
extern void _free_r(struct _reent*, void*);
extern unsigned long func_0011B278(unsigned long, unsigned long);

#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT (SIZE_SZ + SIZE_SZ + SIZE_SZ + SIZE_SZ)
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define MINSIZE (sizeof(struct malloc_chunk))
#define chunk2mem(p) ((void*)((char*)(p) + 2*SIZE_SZ))
#define mem2chunk(mem) ((mchunkptr)((char*)(mem) - 2*SIZE_SZ))
#define request2size(req) \
 (((unsigned long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
  (unsigned long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
   (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define PREV_INUSE 0x1
#define IS_MMAPPED 0x2
#define SIZE_BITS (PREV_INUSE|IS_MMAPPED)
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define chunk_at_offset(p, s) ((mchunkptr)(((char*)(p)) + (s)))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char*)(p)) + (s)))->size |= PREV_INUSE)
#define long_sub_size_t(x, y) \
  (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))

void* func_001251A0(struct _reent* reent_ptr, size_t alignment, size_t bytes)
{
    INTERNAL_SIZE_T nb;
    char* m;
    mchunkptr p;
    char* brk;
    mchunkptr newp;
    INTERNAL_SIZE_T newsize;
    INTERNAL_SIZE_T leadsize;
    mchunkptr remainder;
    long remainder_size;

    if (alignment <= MALLOC_ALIGNMENT) return _malloc_r(reent_ptr, bytes);

    if (alignment < MINSIZE) alignment = MINSIZE;

    nb = request2size(bytes);
    m = (char*)(_malloc_r(reent_ptr, nb + alignment + MINSIZE));

    if (m == 0) return 0;

    func_001261B0(reent_ptr);

    p = mem2chunk(m);

    if (func_0011B278((unsigned long)(m), alignment) != 0)
    {
        brk = (char*)mem2chunk(((unsigned long)(m + alignment - 1)) & -((signed) alignment));
        if ((long)(brk - (char*)(p)) < (long)MINSIZE) brk = brk + alignment;

        newp = (mchunkptr)brk;
        leadsize = brk - (char*)(p);
        newsize = chunksize(p) - leadsize;

        set_head(newp, newsize | PREV_INUSE);
        set_inuse_bit_at_offset(newp, newsize);
        set_head_size(p, leadsize);
        _free_r(reent_ptr, chunk2mem(p));
        p = newp;
    }

    remainder_size = long_sub_size_t(chunksize(p), nb);

    if (remainder_size >= (long)MINSIZE)
    {
        remainder = chunk_at_offset(p, nb);
        set_head(remainder, remainder_size | PREV_INUSE);
        set_head_size(p, nb);
        _free_r(reent_ptr, chunk2mem(remainder));
    }

    func_00126230(reent_ptr);
    return chunk2mem(p);
}
