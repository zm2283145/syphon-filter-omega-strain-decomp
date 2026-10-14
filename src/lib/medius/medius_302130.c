/*
 * lib/medius: 3 files, 00302130-00302218
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302130 */
extern void func_003020A8(unsigned int *key);
extern void func_00301D58(unsigned int *key, int n);
static __inline__ long rd(unsigned int a) { return *(volatile unsigned int *)a; }
void func_00302130(long seed)
{
    unsigned int key[64];
    func_003020A8(key);
    key[13] = seed;
    key[14] = rd(0x10000000);
    key[15] = rd(0x10000800);
    key[16] = rd(0x10001000);
    key[17] = rd(0x10001800);
    func_00301D58(key, 0x40);
}
/* merge_units: end func_00302130 */

/* merge_units: begin func_003021D0 */
typedef struct { unsigned char ok; int f4; int f8; } ScfSem_1D0;
extern int func_003024C0(ScfSem_1D0 *o);
int func_003021D0(ScfSem_1D0 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    o->ok = 0;
    o->f4 = 0;
    o->f8 = 0;
    ret = func_003024C0(o);
    if (ret != 0) return ret;
    o->ok = 1;
    return ret;
}
/* merge_units: end func_003021D0 */

/* merge_units: begin func_00302218 */
typedef struct { unsigned char ok; int f4; int f8; } ScfSem_218;
extern int func_00302518(ScfSem_218 *o);
int func_00302218(ScfSem_218 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    if (o->ok != 1) return ret;
    ret = func_00302518(o);
    if (ret == 0) o->ok = 0;
    return ret;
}
/* merge_units: end func_00302218 */
