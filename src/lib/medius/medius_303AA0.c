/*
 * lib/medius: 2 files, 00303AA0-00303B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00303AA0 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; unsigned char b194; char pad2[0x1B]; void (*cb)(void *buf, int len, int code); } UpnpObj;
extern int rt_p2p_get_peer_by_connection(UpnpObj *o, int key, int *out);
extern int rt_udp_disconnect(int h, int key);
#define UPNP_MARK_FLAG(name, field, ON_ALL) void name(UpnpObj *o, int key) { int idx; if (key == -2) { ON_ALL; return; } idx = -2; if (rt_p2p_get_peer_by_connection(o, key, &idx) != 0 || idx == -2) { rt_udp_disconnect(o->h180, key); return; } o->ent[idx].field = 1; }
UPNP_MARK_FLAG(rt_p2p_handle_read_event, bF, o->b194 = 1)
/* merge_units: end func_00303AA0 */

/* merge_units: begin func_00303B30 */
UPNP_MARK_FLAG(rt_p2p_handle_write_event, bE, (void)0)
/* merge_units: end func_00303B30 */
