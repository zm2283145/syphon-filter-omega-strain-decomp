/*
 * lib/medius: 2 files, 0030ECC0-0030ECF8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030ECC0 */
typedef struct { int f0; int f4; int f8; int state; char pad[0x205C]; void (*cb)(void *o, int a, int b, int c, unsigned short d, int e); } ScfConnCtx2;
typedef struct { char pad[0x58]; ScfConnCtx2 *ctx; int f5C; int f60; } ScfConn2;
extern int Net_AllocZeroed(void *pp, int size);
int func_0030ECC0(ScfConn2 *o)
{
    if (o->ctx == 0) {
        if (Net_AllocZeroed(&o->ctx, 0x2E70) != 0) return 3;
    }
    return 0;
}
/* merge_units: end func_0030ECC0 */

/* merge_units: begin func_0030ECF8 */
extern int rt_memory_free(void *pp);
int func_0030ECF8(ScfConn2 *o)
{
    rt_memory_free(&o->ctx);
    o->ctx = 0;
    return 0;
}
/* merge_units: end func_0030ECF8 */
