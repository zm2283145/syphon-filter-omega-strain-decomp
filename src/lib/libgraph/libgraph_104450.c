/*
 * lib/libgraph: 4 files, 00104450-001045B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00104450 */
typedef struct { unsigned int *buf; int x4; int *tag; } Pkt4450;

unsigned int *func_00104450(Pkt4450 *p)
{
    unsigned int *a = p->buf;
    int *tag = p->tag;
    while ((unsigned int)a & 0xC) *a++ = 0;
    if (tag) { int n = (((char *)a - (char *)tag) >> 4) - 1; *tag += n; }
    p->buf = a;
    p->tag = 0;
    return a;
}
/* merge_units: end func_00104450 */

/* merge_units: begin func_001044A8 */
typedef struct { unsigned int *buf; int x4; unsigned int *tag; } Pkt44A8;
#if 0 /* merge_units */
extern unsigned int *func_00104450(Pkt44A8 *);
#endif /* merge_units */
#define func_00104450(a0) (func_00104450((Pkt4450 *)(a0))) /* merge_units */


void func_001044A8(Pkt44A8 *p, unsigned int x1, unsigned int x2, unsigned int n)
{
    unsigned int *a;
    p->tag = func_00104450(p);
    a = p->buf;
    *a++ = n | 0x10000000;
    a[0] = 0;
    a[1] = x1;
    a[2] = x2;
    p->buf = a + 3;
}
#undef func_00104450 /* merge_units */
/* merge_units: end func_001044A8 */

/* merge_units: begin func_00104520 */
typedef struct { unsigned int *buf; int x4; unsigned int *tag; } Pkt4520;
#if 0 /* merge_units */
extern unsigned int *func_00104450(Pkt4520 *);
#endif /* merge_units */
#define func_00104450(a0) (func_00104450((Pkt4450 *)(a0))) /* merge_units */


void func_00104520(Pkt4520 *p, unsigned int addr, unsigned int id, unsigned int x2, unsigned int x3, unsigned int n)
{
    unsigned int *a;
    func_00104450(p);
    a = p->buf;
    { unsigned int t = id | 0x30000000; *a++ = n | t; }
    a[0] = addr & 0x9FFFFFFF;
    a[1] = x2;
    a[2] = x3;
    p->buf = a + 3;
}
#undef func_00104450 /* merge_units */
/* merge_units: end func_00104520 */

/* merge_units: begin func_001045B8 */
typedef struct { unsigned int *buf; int x4; unsigned int *tag; } Pkt45B8;
#if 0 /* merge_units */
extern unsigned int *func_00104450(Pkt45B8 *);
#endif /* merge_units */
#define func_00104450(a0) (func_00104450((Pkt4450 *)(a0))) /* merge_units */


void func_001045B8(Pkt45B8 *p, unsigned int x1, unsigned int x2, unsigned int n)
{
    unsigned int *a;
    p->tag = func_00104450(p);
    a = p->buf;
    *a++ = n | 0x70000000;
    a[0] = 0;
    a[1] = x1;
    a[2] = x2;
    p->buf = a + 3;
}
#undef func_00104450 /* merge_units */
/* merge_units: end func_001045B8 */
