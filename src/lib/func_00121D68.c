#include "types.h"
extern void* _malloc_r(void* reent, unsigned int n);
extern void* memset(void* p, int c, unsigned int n);
typedef struct { unsigned int prev_size; unsigned int size; } chunk_00121D68;
#define mem2chunk(mem) ((chunk_00121D68*)((char*)(mem) - 8))
#define chunksize(p) ((p)->size & ~3)
#define MALLOC_ZERO(charp, nbytes) \
do { \
  unsigned int mzsz = (nbytes); \
  if(mzsz <= 9*sizeof(mzsz)) { \
    unsigned int* mz = (unsigned int*) (charp); \
    if(mzsz >= 5*sizeof(mzsz)) { *mz++ = 0; *mz++ = 0; \
      if(mzsz >= 7*sizeof(mzsz)) { *mz++ = 0; *mz++ = 0; \
        if(mzsz >= 9*sizeof(mzsz)) { *mz++ = 0; *mz++ = 0; }}} \
    *mz++ = 0; *mz++ = 0; *mz = 0; \
  } else memset((charp), 0, mzsz); \
} while(0)
void* func_00121D68(void* reent, unsigned int n, unsigned int elem_size)
{
    chunk_00121D68* p;
    unsigned int csz;
    unsigned int sz = n * elem_size;
    void* mem = _malloc_r(reent, sz);
    if (mem == 0) return 0;
    else {
        p = mem2chunk(mem);
        csz = chunksize(p);
        MALLOC_ZERO(mem, csz - 4);
        return mem;
    }
}