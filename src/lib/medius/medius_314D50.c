/*
 * lib/medius: 3 files, 00314D50-00314F58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00314D50 */
typedef struct { int idx; unsigned int n; unsigned char b8; char pad; unsigned char bA; char pad2; int size; char pad3[0x204 - 0x10]; void *buf; } Obj4D50;
extern short D_00491432;
extern unsigned char D_00491430;
extern Obj4D50 *D_0052AC98[];
extern int NetIsValidConnectionIndex(int id);
extern int rt_memory_allocate_init_zero(void *pp, unsigned long size);
extern void rt_memory_free(void *pp);
int NetStreamMediaCreateInfo(int idx, unsigned int n)
{
    int ok, r;
    Obj4D50 **pp;
    Obj4D50 *o;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (NetIsValidConnectionIndex(idx) != ok) return 0x17;
    if (idx >= 4) return 0x17;
    if (n > 256) return 0x17;
    if (n == 0) return 0x17;
    if (D_0052AC98[idx] == 0) {
        if (rt_memory_allocate_init_zero(&D_0052AC98[idx], 0x228) != 0) return 0x29;
    }
    pp = &D_0052AC98[idx];
    o = *pp;
    if (o == 0) return 0x29;
    if (o->buf) rt_memory_free(&o->buf);
    r = rt_memory_allocate_init_zero(&o->buf, n * 8);
    if (r != 0) {
        rt_memory_free(pp);
        *pp = 0;
        return 0x29;
    }
    if (o->buf == 0) return 0x29;
    o->n = n;
    o->idx = idx;
    o->size = 0x100;
    o->bA = 0;
    o->b8 = 0;
    return r;
}
/* merge_units: end func_00314D50 */

/* merge_units: begin func_00314EA8 */
typedef struct { char pad[0x204]; int sub; } Obj4EA8;
#if 0 /* merge_units */
extern Obj4EA8 *D_0052AC98[];
#endif /* merge_units */
#define D_0052AC98 ((Obj4EA8 **)&D_0052AC98) /* merge_units */

#if 0 /* merge_units */
extern void rt_memory_free(void *p);
#endif /* merge_units */
#define rt_memory_free(a0) (rt_memory_free((a0))) /* merge_units */

int NetStreamMediaDestroyInfo(int idx)
{
    int ok;
    Obj4EA8 **p;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (NetIsValidConnectionIndex(idx) != ok) return 0x17;
    if (idx >= 4) return 0x17;
    p = &D_0052AC98[idx];
    if (*p == 0) return 0x17;
    if ((*p)->sub) rt_memory_free(&(*p)->sub);
    rt_memory_free(p);
    *p = 0;
    return 0;
}
#undef D_0052AC98 /* merge_units */
#undef rt_memory_free /* merge_units */
/* merge_units: end func_00314EA8 */

/* merge_units: begin func_00314F58 */
#if 0 /* merge_units */
extern int D_0052AC98[];
#endif /* merge_units */
#define D_0052AC98 ((int*)&D_0052AC98) /* merge_units */

int NetStreamMediaGetInfo(int id, int *out)
{
    int ok;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (NetIsValidConnectionIndex(id) != ok) return 0x17;
    if (out == 0) return 0x17;
    *out = D_0052AC98[id];
    return 0;
}
#undef D_0052AC98 /* merge_units */
/* merge_units: end func_00314F58 */
