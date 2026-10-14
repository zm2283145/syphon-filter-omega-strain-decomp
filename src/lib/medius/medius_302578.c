/*
 * lib/medius: 5 files, 00302578-00302670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302578 */
typedef struct { unsigned char ok; int f4; int f8; int sema; } ScfSem_578;
extern int func_0010D1B0(int s);
int func_00302578(ScfSem_578 *o, unsigned char *out)
{
    unsigned char ok;
    int ret = 2;
    if (o == 0) return ret;
    ok = o->ok;
    if (ok != 1) return ret;
    if (out == 0) return ret;
    *out = 0;
    if (func_0010D1B0(o->sema) != -1) *out = ok;
    return 0;
}
/* merge_units: end func_00302578 */

/* merge_units: begin func_003025E0 */
typedef struct { int f0; int f4; int f8; int sema; } ScfObj_5E0;
extern int SignalSema(int s);
int func_003025E0(ScfObj_5E0 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    return SignalSema(o->sema) == -1;
}
/* merge_units: end func_003025E0 */

/* merge_units: begin func_00302610 */
extern int func_0010D050(void);
int func_00302610(int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = func_0010D050();
    return 0;
}
/* merge_units: end func_00302610 */

/* merge_units: begin func_00302648 */
#define SCF_LOCK_PAIR(name, fn) int name(void) { fn(2); fn(3); return 0; }
extern void Alloc_Lock(int n);
extern void Alloc_Unlock(int n);
SCF_LOCK_PAIR(func_00302648, Alloc_Lock)
/* merge_units: end func_00302648 */

/* merge_units: begin func_00302670 */
SCF_LOCK_PAIR(func_00302670, Alloc_Unlock)
/* merge_units: end func_00302670 */
