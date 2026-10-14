/*
 * lib/libkernl: 10 files, 0010E3A8-0010E550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010E3A8 */
#include "types.h"
extern int func_0010D590(int cmd, void* arg);
/* Issues request 0x21 with a single-word argument block. */
int func_0010E3A8(int a)
{
    int buf[4];
    buf[0] = a;
    return func_0010D590(0x21, buf);
}
/* merge_units: end func_0010E3A8 */

/* merge_units: begin func_0010E3D0 */
typedef struct { int a; int b; int c; int d; } Request_0010E3D0;
#if 0 /* merge_units */
extern void func_0010D590(int kind, Request_0010E3D0* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (void *)(a1))) /* merge_units */

void func_0010E3D0(int a, int b, unsigned short c)
{
    Request_0010E3D0 req;
    req.a = a;
    req.b = b;
    req.c = c;
    func_0010D590(-5, &req);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E3D0 */

/* merge_units: begin func_0010E408 */
/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

#if 0 /* merge_units */
extern void func_0010D590(int command, int* params);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (void *)(a1))) /* merge_units */


/* SDK: issues command -6 with parameters {a, b, (unsigned short)c}. */
void func_0010E408(int a, int b, unsigned short c)
{
    int params[3];
    params[0] = a;
    params[1] = b;
    params[2] = c;
    func_0010D590(-6, params);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E408 */

/* merge_units: begin func_0010E440 */
#if 0 /* merge_units */
extern void func_0010D590(int command, int* params);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (void *)(a1))) /* merge_units */


/* SDK (EE-GCC): issues command -7 with parameters {a, (signed char)b}. */
void func_0010E440(int a, signed char b) {
    int params[2];
    params[0] = a;
    params[1] = b;
    func_0010D590(-7, params);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E440 */

/* merge_units: begin func_0010E470 */
#if 0 /* merge_units */
extern void func_0010D590(int kind, void* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (a1))) /* merge_units */

void func_0010E470(int a) { int r[4]; r[0] = a; func_0010D590(-8, r); }
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E470 */

/* merge_units: begin func_0010E498 */
/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

#if 0 /* merge_units */
extern void func_0010D590(int command, int* params);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (void *)(a1))) /* merge_units */


/* SDK: issues command -9 with a single parameter. */
void func_0010E498(int a)
{
    int params[1];
    params[0] = a;
    func_0010D590(-9, params);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E498 */

/* merge_units: begin func_0010E4C0 */
#if 0 /* merge_units */
extern void func_0010D590(int kind, void* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) ((void)func_0010D590((a0), (a1))) /* merge_units */

void func_0010E4C0(int a) { int r[4]; r[0] = a; func_0010D590(0x10, r); }
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E4C0 */

/* merge_units: begin func_0010E4E8 */
typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E4E8;
extern Ring_0010E4E8 D_004E2840;
Ring_0010E4E8* func_0010E4E8(int size)
{
    Ring_0010E4E8* r = &D_004E2840;
    r->count = 0;
    r->wr = r->buf;
    r->rd = r->buf;
    r->size = size;
    return r;
}
/* merge_units: end func_0010E4E8 */

/* merge_units: begin func_0010E510 */
typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E510;
void func_0010E510(Ring_0010E510* r)
{
    r->count++;
    r->wr++;
    if (r->wr == r->buf + r->size) r->wr = r->buf;
}
/* merge_units: end func_0010E510 */

/* merge_units: begin func_0010E550 */
typedef struct { int size; int count; unsigned char* rd; unsigned char* wr; unsigned char buf[1]; } Ring_0010E550;
void ByteRing_Pop(Ring_0010E550* r)
{
    r->count--;
    r->rd++;
    if (r->rd == r->buf + r->size) r->rd = r->buf;
}
/* merge_units: end func_0010E550 */
