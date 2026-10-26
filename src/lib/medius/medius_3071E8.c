/*
 * lib/medius: 3 files, 003071E8-00307488
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003071E8 */
typedef struct {
    int type;
    char pad4[0x20];
    unsigned int total0;
    unsigned int used0;
    char pad2C[0x10];
    unsigned int total1;
    unsigned int used1;
    char pad44[0x90 - 0x44];
} Ent71e8;

typedef struct {
    int pad0;
    Ent71e8 *ents;
    char pad8[0x24];
    unsigned int count;
} Mgr71e8;

int rt_udp_get_buffer_stats(Mgr71e8 *m, unsigned int idx, int which,
                  unsigned int *total, unsigned int *used, unsigned int *pct)
{
    Ent71e8 *e;
    unsigned int v;

    if (m == 0) return 2;
    if (idx >= m->count) return 3;
    if (m->ents == 0) return 3;
    e = &m->ents[idx];
    if (e->type != 12) return 3;
    if (which == 0) {
        if (total != 0) *total = e->total0;
        if (used != 0) *used = e->used0;
        if (pct != 0) {
            v = e->used0 * 100 / e->total0;
            *pct = v;
            if (v > 100) *pct = 100;
        }
        return 0;
    }
    if (which == 1) {
        if (total != 0) *total = e->total1;
        if (used != 0) *used = e->used1;
        if (pct != 0) {
            v = e->used1 * 100 / e->total1;
            *pct = v;
            if (v > 100) *pct = 100;
        }
        return 0;
    }
    return 1;
}
/* merge_units: end func_003071E8 */

/* merge_units: begin func_00307328 */
typedef struct {
    char name[16];
    unsigned short port;
} Req7328;

typedef struct {
    int sock;
    int pad4;
    void *upnp;
    char padC[0x34];
    int arg40;
    unsigned char pad44;
    unsigned char active;
    unsigned short port;
    unsigned int mode;
} Obj7328;

extern void *D_00491320;
extern unsigned char D_00491324;
extern int rt_upnp_create(void **out, int sock, unsigned short port);
extern int func_0030EFB0(void *obj, int value);
extern int func_0030EBF0(void *u, const char *name, unsigned short port, void *cb, Obj7328 *user);
extern void rt_udp_uber_resolve_cb(void);

int rt_udp_resolve_address(Obj7328 *o, Req7328 *r)
{
    if (o == 0) return 2;
    if (r == 0) return 1;
    if (o->active != 0) return 15;
    if (o->mode < 8) {
        if (D_00491320 == 0) {
            if (rt_upnp_create(&D_00491320, o->sock, o->port) != 0) return 15;
            if (func_0030EFB0(D_00491320, o->arg40) != 0) return 15;
        }
        o->upnp = D_00491320;
        if (D_00491324 == 0) {
            if (func_0030EBF0(D_00491320, r->name, r->port, rt_udp_uber_resolve_cb, o) != 0) return 15;
            o->active = 1;
            D_00491324 = 1;
            goto done;
        }
    } else {
        if (o->upnp == 0) {
            if (rt_upnp_create(&o->upnp, o->sock, o->port) != 0) return 15;
            if (func_0030EFB0(o->upnp, o->arg40) != 0) return 15;
        }
        if (func_0030EBF0(o->upnp, r->name, r->port, rt_udp_uber_resolve_cb, o) != 0) return 15;
    }
    o->active = 1;
done:
    return 0;
}
/* merge_units: end func_00307328 */

/* merge_units: begin func_00307488 */
typedef struct { char pad[8]; int h; } Obj7488;
extern int rt_upnp_get_external_address(int h);
extern int rt_udp_get_local_address(Obj7488 *o, void *a, void *b);
int rt_udp_get_resolved_address(Obj7488 *o, void *a, void *b)
{
    int r;
    if (o == 0) return 2;
    if (a == 0) return 1;
    if (b == 0) return 1;
    if (o->h != 0) {
        r = rt_upnp_get_external_address(o->h);
        if (r == 0) return r;
        return rt_udp_get_local_address(o, a, b);
    }
    return rt_udp_get_local_address(o, a, b);
}
/* merge_units: end func_00307488 */
