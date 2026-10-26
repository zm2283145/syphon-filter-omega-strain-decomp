/*
 * lib/medius: 3 files, 00302130-00302218
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302130 */
extern void ScrambleSeed(unsigned int *key);
extern void seedMTUsingArray(unsigned int *key, int n);
static __inline__ long rd(unsigned int a) { return *(volatile unsigned int *)a; }
void setNewSeed_platform(long seed)
{
    unsigned int key[64];
    ScrambleSeed(key);
    key[13] = seed;
    key[14] = rd(0x10000000);
    key[15] = rd(0x10000800);
    key[16] = rd(0x10001000);
    key[17] = rd(0x10001800);
    seedMTUsingArray(key, 0x40);
}
/* merge_units: end func_00302130 */

/* merge_units: begin func_003021D0 */
typedef struct { unsigned char ok; int f4; int f8; } ScfSem_1D0;
extern int rt_mutex_platform_create(ScfSem_1D0 *o);
int rt_mutex_create(ScfSem_1D0 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    o->ok = 0;
    o->f4 = 0;
    o->f8 = 0;
    ret = rt_mutex_platform_create(o);
    if (ret != 0) return ret;
    o->ok = 1;
    return ret;
}
/* merge_units: end func_003021D0 */

/* merge_units: begin func_00302218 */
typedef struct { unsigned char ok; int f4; int f8; } ScfSem_218;
extern int rt_mutex_platform_destroy(ScfSem_218 *o);
int rt_mutex_destroy(ScfSem_218 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    if (o->ok != 1) return ret;
    ret = rt_mutex_platform_destroy(o);
    if (ret == 0) o->ok = 0;
    return ret;
}
/* merge_units: end func_00302218 */
