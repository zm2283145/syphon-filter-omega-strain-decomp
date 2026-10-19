/*
 * lib/libgcc: 7 files, 00121BF0-00121C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121BF0 */
#include "types.h"

extern int strtol(int, int, int);

int atol(int a0) {
    return strtol(a0, 0, 10);
}
/* merge_units: end func_00121BF0 */

/* merge_units: begin func_00121C10 */
extern int Libc_Memmove(int, int, int);

int func_00121C10(int a0, int a1, int a2) {
    return Libc_Memmove(a1, a0, a2);
}
/* merge_units: end func_00121C10 */

/* merge_units: begin func_00121C30 */
void* func_00121C30(const void* key, const void* base, unsigned int nmemb, unsigned int size, int (*compar)(const void*, const void*))
{
    void* current;
    unsigned int lower = 0;
    unsigned int upper = nmemb;
    unsigned int index;
    int result;
    if (nmemb == 0 || size == 0)
        return 0;
    while (lower < upper) {
        index = (lower + upper) / 2;
        current = (void*)(((char*)base) + (index * size));
        result = compar(key, current);
        if (result < 0)
            upper = index;
        else if (result > 0)
            lower = index + 1;
        else
            return current;
    }
    return 0;
}
/* merge_units: end func_00121C30 */

/* merge_units: begin func_00121D00 */
extern void* D_00489738;
extern void Newlib_MallocLock(void* r);
extern void Newlib_MallocUnlock(void* r);
extern void* Newlib_CallocR(void* reent, unsigned int n, unsigned int elem_size);
void* Libc_Calloc(unsigned int n, unsigned int size)
{
    void* r;
    Newlib_MallocLock(D_00489738);
    r = Newlib_CallocR(D_00489738, n, size);
    Newlib_MallocUnlock(D_00489738);
    return r;
}
/* merge_units: end func_00121D00 */

/* merge_units: begin func_00121D68 */
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
void* Newlib_CallocR(void* reent, unsigned int n, unsigned int elem_size)
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
/* merge_units: end func_00121D68 */

/* merge_units: begin func_00121E20 */
extern int D_0058805C;
extern int Newlib_SysClose(int fd);
struct reent_00121E20 { int _errno; };
int Newlib_CloseR(struct reent_00121E20* ptr, int fd)
{
    int ret;
    D_0058805C = 0;
    if ((ret = Newlib_SysClose(fd)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}
/* merge_units: end func_00121E20 */

/* merge_units: begin func_00121E78 */
typedef unsigned int __ULong;
typedef int __Long;
typedef struct _Bigint {
    struct _Bigint *_next;
    int _k, _maxwds, _sign, _wds;
    __ULong _x[1];
} _Bigint;
extern int Newlib_Mcmp(_Bigint *a, _Bigint *b);
#define Storeinc(a,b,c) (((unsigned short *)a)[0] = (unsigned short)c, ((unsigned short *)a)[1] = (unsigned short)b, a++)
#define Sign_Extend(a,b)

int Newlib_Quorem(_Bigint *b, _Bigint *S)
{
    int n;
    __Long borrow, y;
    __ULong carry, q, ys;
    __ULong *bx, *bxe, *sx, *sxe;
    __Long z;
    __ULong si, zs;

    n = S->_wds;
    if (b->_wds < n)
        return 0;
    sx = S->_x;
    sxe = sx + --n;
    bx = b->_x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend (borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend (borrow, z);
            Storeinc (bx, z, y);
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->_x;
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    if (Newlib_Mcmp (b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->_x;
        sx = S->_x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            Sign_Extend (borrow, y);
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Sign_Extend (borrow, z);
            Storeinc (bx, z, y);
        } while (sx <= sxe);
        bx = b->_x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    return q;
}
/* merge_units: end func_00121E78 */
