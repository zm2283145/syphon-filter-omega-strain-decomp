/*
 * lib/libkernl: 4 files, 0010E2F8-0010E378
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010E2F8 */
#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { int value; int pad; } Request;
extern void func_0010D590(int kind, Request* req);

/* Sends request kind 2 carrying one value. */
void func_0010E2F8(int value)
{
    Request req;
    req.value = value;
    func_0010D590(2, &req);
}
/* merge_units: end func_0010E2F8 */

/* merge_units: begin func_0010E320 */
/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc), not Metrowerks. */

typedef struct { int value; int code; } Request_0010E320;
#if 0 /* merge_units */
extern void func_0010D590(int kind, Request_0010E320* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) (func_0010D590((a0), (Request *)(a1))) /* merge_units */


/* Sends request kind 3 with (value, sign-extended byte code). */
void func_0010E320(int value, char code)
{
    Request_0010E320 req;
    req.value = value;
    req.code = code;
    func_0010D590(3, &req);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E320 */

/* merge_units: begin func_0010E350 */
#if 0 /* merge_units */
extern void func_0010D590(int kind, void* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) (func_0010D590((a0), (Request *)(a1))) /* merge_units */

void func_0010E350(int a) { int r[4]; r[0] = a; func_0010D590(4, r); }
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E350 */

/* merge_units: begin func_0010E378 */
/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { int code; int a; int b; char pad[0x14]; } Request_0010E378;
#if 0 /* merge_units */
extern void func_0010D590(int kind, Request_0010E378* req);
#endif /* merge_units */
#define func_0010D590(a0, a1) (func_0010D590((a0), (Request *)(a1))) /* merge_units */


/* Sends request kind 0x20 with (byte code, a, b). */
void func_0010E378(unsigned char code, int a, int b)
{
    Request_0010E378 req;
    req.a = a;
    req.code = code;
    req.b = b;
    func_0010D590(0x20, &req);
}
#undef func_0010D590 /* merge_units */
/* merge_units: end func_0010E378 */
