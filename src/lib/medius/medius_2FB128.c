/*
 * lib/medius: 9 files, 002FB128-002FB518
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FB128 */
extern int func_002FABD0(int *, int *);
extern int func_002FAF00(int);
int func_002FB128(int *s, int key, int *out)
{
    int p = 0;
    int r;
    if (key == 0) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = func_002FABD0(s, &p);
    if (r) return r;
    while (func_002FAF00(p)) {
        if (func_002FAF00(p) == key) {
            *out = p;
            return 0;
        }
        p = func_002FAF00(p);
    }
    return 1;
}
/* merge_units: end func_002FB128 */

/* merge_units: begin func_002FB1C0 */
int func_002FB1C0(int *s)
{
    int p = 0;
    unsigned int min = s[2];
    unsigned int d;
    int r;
    r = func_002FABD0(s, &p);
    if (r) return r;
    while (p) {
        d = p - s[4];
        if (d < min) min = d;
        p = func_002FAF00(p);
    }
    s[0] = min;
    return 0;
}
/* merge_units: end func_002FB1C0 */

/* merge_units: begin func_002FB238 */
typedef struct N { int size; struct N *next; } N;
typedef struct { int x; unsigned int cur; unsigned int end; int free; int base; N *last; } L;
#if 0 /* merge_units */
extern int func_002FABD0(L *, N **);
#endif /* merge_units */
#define func_002FABD0(a0, a1) (func_002FABD0((int *)(a0), (int *)(a1))) /* merge_units */

int func_002FB238(L *l)
{
    N *n[1];
    unsigned int m = 0;
    int r;
    n[0] = 0;
    r = func_002FABD0(l, n);
    if (r) return r;
    while (n[0]) {
        unsigned int e = (int)n[0] + ((n[0]->size + 3) & ~3) - l->base + 8;
        n[0] = n[0]->next;
        if (m < e) m = e;
    }
    l->cur = (m + 3) & ~3;
    if (l->cur == l->end) l->cur = 0;
    return 0;
}
#undef func_002FABD0 /* merge_units */
/* merge_units: end func_002FB238 */

/* merge_units: begin func_002FB2D8 */
void *(*D_004908E0)(int) = 0;
extern void *Libc_Malloc(int);
int func_002FB2D8(void **out, long sz)
{
    void *p;
    if (D_004908E0 == 0) {
        p = Libc_Malloc(sz);
        *out = p;
        if (p == 0) return 1;
    } else {
        p = D_004908E0(sz);
        *out = p;
        if (p == 0) return 1;
    }
    return 0;
}
/* merge_units: end func_002FB2D8 */

/* merge_units: begin func_002FB350 */
extern int func_002FB2D8(void **out, long sz);
extern void *memset(void *, int, unsigned int);
int Net_AllocZeroed(void **out, long sz)
{
    int r;
    if (out == 0) return 1;
    *out = 0;
    r = func_002FB2D8(out, sz);
    if (r) return r;
    if (*out) {
        memset(*out, 0, sz);
        return 0;
    }
    return 1;
}
/* merge_units: end func_002FB350 */

/* merge_units: begin func_002FB3C0 */
void (*D_004908E4)(int) = 0;
extern void Libc_Free(int);
int func_002FB3C0(int *p)
{
    if (*p) {
        if (D_004908E4 == 0) Libc_Free(*p);
        else D_004908E4(*p);
        *p = 0;
    }
    return 0;
}
/* merge_units: end func_002FB3C0 */

/* merge_units: begin func_002FB418 */
#if 0 /* merge_units */
extern int func_002FB2D8(int *, unsigned long);
#endif /* merge_units */
#define func_002FB2D8(a0, a1) (func_002FB2D8((void * *)(a0), (long)(a1))) /* merge_units */

extern int func_002FB580(int *, int, unsigned short);
int func_002FB418(int *o, unsigned int size, unsigned short align)
{
    int r;
    if (o == 0 || size == 0) return 1;
    o[0] = 0;
    o[1] = 0;
    if (align >= 2) {
        size += align - 1;
        size += align - size % align;
    }
    r = func_002FB2D8(o, size);
    if (r) return r;
    r = func_002FB580(o + 1, o[0], align);
    __asm__ __volatile__("");
    return r;
}
#undef func_002FB2D8 /* merge_units */
/* merge_units: end func_002FB418 */

/* merge_units: begin func_002FB4A8 */
#if 0 /* merge_units */
extern int func_002FB418(void **, int, unsigned short);
#endif /* merge_units */
#define func_002FB418(a0, a1, a2) (func_002FB418((int *)(a0), (unsigned int)(a1), (a2))) /* merge_units */

int func_002FB4A8(void **b, int sz, unsigned short al)
{
    int r;
    if (b != 0) {
        if (sz == 0) return 1;
        b[0] = 0;
        b[1] = 0;
        r = func_002FB418(b, sz, al);
        if (r) return r;
        if (b[1] != 0) { memset(b[1], 0, sz); return 0; }
    }
    return 1;
}
#undef func_002FB418 /* merge_units */
/* merge_units: end func_002FB4A8 */

/* merge_units: begin func_002FB518 */
#if 0 /* merge_units */
extern int func_002FB3C0(int *);
#endif /* merge_units */
#define func_002FB3C0(a0) (func_002FB3C0((a0))) /* merge_units */

int func_002FB518(int *p)
{
    int r;
    if (p == 0) return 1;
    if (p[0]) {
        r = func_002FB3C0(p);
        if (r) return r;
        p[0] = 0;
    }
    p[1] = 0;
    return 0;
}
#undef func_002FB3C0 /* merge_units */
/* merge_units: end func_002FB518 */
