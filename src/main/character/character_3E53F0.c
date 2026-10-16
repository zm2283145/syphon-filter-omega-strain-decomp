/*
 * main/character: 2 files, 003E53F0-003E5470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E53F0 */
#pragma push /* merge_units */
#include "types.h"

extern int func_002E9A10(void);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* buf, void* end, int size, int count);
extern int func_002E9F08(void* obj, void* callback);
extern char D_0055A1F0[];
extern void func_003E4CC0();

/* Runs the setup sequence; returns 1 only if every step succeeds. */
unsigned char func_003E53F0(void) {
    unsigned char ok = 0;
    char buf[0xC];
    int err;
    if (!func_002E9A10() && func_003FF2C0() && !(err = func_002E9A98(buf, buf + 0xC, 4, 1)) && !err
        && !func_002E9F08(D_0055A1F0, func_003E4CC0)) {
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E53F0 */

/* merge_units: begin func_003E5470 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int a; int b; int c; int d; } Hdr;
extern char D_0055A1E8[];
#if 0 /* merge_units */
extern int func_002E9A98(Hdr* h, void* dst, int size, int count);
#endif /* merge_units */
#define func_002E9A98(a0, a1, a2, a3) (func_002E9A98((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int func_002E9F08(void* table, void* fn);
#endif /* merge_units */
#define func_002E9F08(a0, a1) (func_002E9F08((a0), (a1))) /* merge_units */

extern void func_003E4DA0(void);
/* Reads four header words and registers the handler; returns 1 on success. */
unsigned char func_003E5470(void)
{
    Hdr h;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003FF2C0() != 0 &&
        func_002E9A98(&h, &h.a, 4, 1) == 0 &&
        func_002E9A98(&h, &h.b, 4, 1) == 0 &&
        func_002E9A98(&h, &h.c, 4, 1) == 0 &&
        func_002E9A98(&h, &h.d, 4, 1) == 0 &&
        func_002E9F08(D_0055A1E8, func_003E4DA0) == 0)
        ok = 1;
    return ok;
}
#undef func_002E9A98 /* merge_units */
#undef func_002E9F08 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5470 */
