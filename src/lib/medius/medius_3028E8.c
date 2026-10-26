/*
 * lib/medius: 3 files, 003028E8-003029B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003028E8 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern void KM_Destroy(int a);
extern void KM_Cleanup(int a);
extern void rt_udp_destroy(int h);
extern int rt_memory_free(void *pp);
int rt_p2p_destroy(UpnpObj *o)
{
    UpnpObj *h = 0;
    int ret = 2;
    if (o == 0) return ret;
    h = o;
    KM_Destroy(-1);
    KM_Cleanup(-1);
    rt_udp_destroy(h->h180);
    if (h->f190) rt_memory_free(&h->f190);
    if (h->ent) rt_memory_free(&h->ent);
    rt_memory_free(&h);
    return 0;
}
/* merge_units: end func_003028E8 */

/* merge_units: begin func_00302968 */
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; char pad2[0x1C]; int f1B0; } UpnpObj_00302968;

extern int rt_udp_resolve_address(int h, int a, int b);
int rt_p2p_resolve_address(UpnpObj_00302968 *o, int a, int x)
{
    int ret = 2;
    if (o == 0) return ret;
    if (x == 0) return ret;
    if (rt_udp_resolve_address(o->h180, a, x) != 0) return 5;
    o->f1B0 = x;
    return 0;
}
/* merge_units: end func_00302968 */

/* merge_units: begin func_003029B8 */
int rt_p2p_get_current_address_type(UpnpObj *o, int idx, int *out)
{
    UpnpEnt *e;
    int ret = 2;
    if (out == 0) return ret;
    *out = -1;
    if (o == 0) return ret;
    if (idx < 0 || idx >= o->count) return 8;
    if (o->ent[idx].f4 != -1) *out = 0;
    else if (o->ent[idx].f8 != -1) *out = 1;
    return 0;
}
/* merge_units: end func_003029B8 */
