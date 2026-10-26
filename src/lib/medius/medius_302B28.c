/*
 * lib/medius: 4 files, 00302B28-00302E68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302B28 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern int rt_udp_get_local_address(int h, int a, int b);
extern int rt_udp_get_resolved_address(int h, int a, int b);
int rt_p2p_get_my_address(UpnpObj *o, int mode, int a, int b)
{
    int r;
    int ret = 2;
    if (o == 0) return ret;
    if (mode == 0) {
        if (rt_udp_get_local_address(o->h180, a, b) != 0) return 7;
    } else if (mode == 1) {
        if (rt_udp_get_resolved_address(o->h180, a, b) != 0) return 7;
    } else return 2;
    return 0;
}
/* merge_units: end func_00302B28 */

/* merge_units: begin func_00302B88 */
int rt_p2p_get_host_index(UpnpObj *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 4) { *out = i; break; }
        if (o->ent[i].type == 7) { *out = i; break; }
    }
    return 0;
}
/* merge_units: end func_00302B88 */

/* merge_units: begin func_00302C00 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt_00302C00;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; void *h180; UpnpEnt_00302C00 *ent; int count; int f18C; int f190;
} UpnpObj_00302C00;
extern int rt_udp_get_buffer_stats(void *h, int key, int dir, int *a, int *b, int *c);
int rt_p2p_get_buffer_stats(UpnpObj_00302C00 *o, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d)
{
    int x = 0;
    int y = 0;
    int z = 0;
    unsigned int t1 = 0;
    unsigned int t3 = 0;
    unsigned int t4 = 0;
    unsigned int t0 = 0;
    int i;
    int rv = 2;

    if (o == 0)
        return rv;
    if (a == 0)
        return rv;
    if (b == 0)
        return rv;
    if (c == 0)
        return rv;
    if (d == 0)
        return rv;
    {
        *b = 0;
        *a = 0;
        *d = 0;
        *c = 0;
        for (i = 0; i < o->count; i++) {
            if (o->ent[i].f4 != -1) {
                if (rt_udp_get_buffer_stats(o->h180, o->ent[i].f4, 0, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t3 += x;
                t4 += y;
                if (rt_udp_get_buffer_stats(o->h180, o->ent[i].f4, 1, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t1 += x;
                t1 += y;
            }
            if (o->ent[i].f8 != -1) {
                if (rt_udp_get_buffer_stats(o->h180, o->ent[i].f8, 0, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t3 += x;
                t4 += y;
                if (rt_udp_get_buffer_stats(o->h180, o->ent[i].f8, 1, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t1 += x;
                t1 += y;
            }
        }
        *a = t4;
        *b = t0;
        if (t3 != 0)
            *c = t4 / t3 * 100;
        else
            *c = 0;
        if (t1 != 0)
            *d = t0 / t1 * 100;
        else
            *d = 0;
        rv = 0;
    }
out:
    return rv;
}
/* merge_units: end func_00302C00 */

/* merge_units: begin func_00302E68 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt_00302E68;
typedef struct {
    UpnpSlot slot[32]; void *h180; UpnpEnt_00302E68 *ent; int count; int f18C; int f190;
} UpnpObj_00302E68;
int rt_p2p_get_peer_buffer_stats(UpnpObj_00302E68 *o, int idx, int *a, int *b, int *c, int *d)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int rv = 2;

    if (o == 0)
        return rv;
    if (o->count < idx)
        return rv;
    if (a == 0)
        return rv;
    if (c == 0)
        return rv;
    if (b == 0)
        return rv;
    if (d == 0)
        return rv;
    {
        *b = 0;
        *a = 0;
        *d = 0;
        *c = 0;
        if (o->ent[idx].f4 != -1) {
            if (rt_udp_get_buffer_stats(o->h180, o->ent[idx].f4, 0, &x, &y, &z) != 0) return 0;
            *b += x;
            *a += y;
            if (rt_udp_get_buffer_stats(o->h180, o->ent[idx].f4, 1, &x, &y, &z) != 0) return 0;
            *d += x;
            *c += y;
        }
        if (o->ent[idx].f8 != -1) {
            if (rt_udp_get_buffer_stats(o->h180, o->ent[idx].f8, 0, &x, &y, &z) != 0) return 0;
            *b += x;
            *a += y;
            if (rt_udp_get_buffer_stats(o->h180, o->ent[idx].f8, 1, &x, &y, &z) != 0) return 0;
            *d += x;
            *c += y;
        }
        rv = 0;
    }
out:
    return rv;
}
/* merge_units: end func_00302E68 */
