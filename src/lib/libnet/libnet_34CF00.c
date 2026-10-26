/*
 * lib/libnet: 2 files, 0034CF00-0034CF80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034CF00 */
extern int IopRing_Send(int a, void *b, int c, int d, int e, int g, int *h, int *err);
int libnetb_send_echo(int a, unsigned short v, int c, int *out, int *err)
{
    unsigned short s = v;
    int l4 = 0;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    if (c == 0) return ret;
    if (err == 0) return ret;
    if (a == 0) return ret;
    ret = IopRing_Send(a, &s, 2, 0, c, 0, &l4, err);
    if (l4 == 2) *out = 1;
    return ret;
}
/* merge_units: end func_0034CF00 */

/* merge_units: begin func_0034CF80 */
typedef struct { int f0; int f4; int f8; int size; int h10; int p14; int h18; int p1C; int f20; int f24; } NetPool_F80;
extern int rt_memory_align_alloc_init_zero(int *h, int size, int align);
extern int rt_memory_free(int *h);
int libnetb_alloc_bufs(NetPool_F80 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    ret = 1;
    if (o->size + 0x40 > 0x2000) return ret;
    if (rt_memory_align_alloc_init_zero(&o->h10, 0x2040, 0x40) != 0) return 3;
    o->f20 = o->p14;
    if (rt_memory_align_alloc_init_zero(&o->h18, 0x2040, 0x40) != 0) {
        rt_memory_free(&o->h10);
        return 3;
    }
    o->f24 = o->p1C;
    return 0;
}
/* merge_units: end func_0034CF80 */
