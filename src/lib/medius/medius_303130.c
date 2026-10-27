/*
 * lib/medius: 3 files, 00303130-00303598
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00303130 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; int h180; UpnpEnt *ent; int count; int f18C; int f190;
} UpnpObj;
typedef struct { char pad[0x40]; char a[16]; char b[16]; unsigned short pa; unsigned short pb; } UpnpInfo;
typedef struct { char addr[16]; unsigned short port; int peer; } UpnpAddr;
extern int rt_p2p_get_my_peer_status(UpnpObj *o, int *type, int *idx);
extern int rt_p2p_get_peer_by_address(UpnpObj *o, UpnpInfo *info, int *idx);
extern int rt_p2p_find_free_peer_index(UpnpObj *o, int *idx);
extern void KM_SetPublicKey(int a, int peer, UpnpInfo *info);
extern int GetKeyMaster(int a);
extern int GetKeyChain(int a, int peer);
extern void KM_CreateRandomRCKey(void *buf);
extern int KM_AddSymmetricKey(int a, int peer, void *buf);
extern int Libc_Strncmp(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int rt_udp_pre_accept(int h, UpnpAddr *a, int *out);
int rt_p2p_incoming_peer(UpnpObj *o, UpnpInfo *info)
{
    UpnpAddr s;
    char buf[64];
    int state = 0;
    int idx = -2;
    int r;
    UpnpEnt *e;
    int rv = 2;

    if (o != 0 && info != 0) {
        rt_p2p_get_my_peer_status(o, &state, &idx);
        if (state == 7) {
            idx = -2;
            rv = rt_p2p_get_peer_by_address(o, info, &idx);
            if (rv == 0) {
                if (idx == -2) {
                    rv = rt_p2p_find_free_peer_index(o, &idx);
                    if (rv == 0) {
                        rv = 10;
                        if (idx != -2) {
                            e = &o->ent[idx];
                            KM_SetPublicKey(-1, idx, info);
                            e->f24 = GetKeyChain(GetKeyMaster(-1), idx);
                            KM_CreateRandomRCKey(buf);
                            KM_AddSymmetricKey(-1, idx, buf);
                            s.peer = idx;
                            if (Libc_Strncmp(info->a, info->b, 16) == 0 && info->pa == info->pb) {
                                info->a[0] = 0;
                                info->pa = 0;
                            }
                            if (info->a[0] != 0 && info->pa != 0) {
                                strncpy(s.addr, info->a, 16);
                                s.port = info->pa;
                                r = rt_udp_pre_accept(o->h180, &s, &e->f4);
                                if (r != 0x15) {
                                    if (r != 0) { rv = 7; goto out; }
                                    e->type = 2;
                                }
                            }
                            if (info->b[0] != 0 && info->pb != 0) {
                                strncpy(s.addr, info->b, 16);
                                s.port = info->pb;
                                r = rt_udp_pre_accept(o->h180, &s, &e->f8);
                                if (r != 0x15) {
                                    if (r != 0) { rv = 7; goto out; }
                                    e->type = 2;
                                }
                            }
                            rv = 0;
                        }
                    }
                } else {
                    rv = 9;
                }
            }
        } else {
            rv = 0;
        }
    }
out:
    return rv;
}
/* merge_units: end func_00303130 */

/* merge_units: begin func_00303348 */
typedef struct {
    UpnpSlot slot[32]; int h180; UpnpEnt *ent; int count; int f18C; int f190; int f194; void *cb198;
} UpnpObj_00303348;
#if 0 /* merge_units */
extern int rt_p2p_get_my_peer_status(UpnpObj_00303348 *o, int *type, int *idx);
#endif /* merge_units */
#define rt_p2p_get_my_peer_status(a0, a1, a2) (rt_p2p_get_my_peer_status((UpnpObj *)(a0), (a1), (a2))) /* merge_units */

extern void *memset(void *d, int c, unsigned int n);
extern int rt_udp_connect(int h, UpnpAddr *a, int *out);
int rt_p2p_connect(UpnpObj_00303348 *o, UpnpInfo *info, void *cb)
{
    UpnpAddr sa;
    UpnpAddr sb;
    char buf[64];
    int state = 0;
    int idx = -2;
    int r;
    UpnpEnt *e;
    int rv = 2;

    if (o != 0 && info != 0 && cb != 0) {
    rt_p2p_get_my_peer_status(o, &state, &idx);
    if (state != 0)
        return 9;
    e = o->ent;
    memset(e, 0, sizeof(UpnpEnt));
    e->f8 = e->f4 = -1;
    KM_SetPublicKey(-1, 0, info);
    e->f24 = GetKeyChain(GetKeyMaster(-1), 0);
    KM_CreateRandomRCKey(buf);
    KM_AddSymmetricKey(-1, 0, buf);
    if (Libc_Strncmp(info->a, info->b, 16) == 0 && info->pa == info->pb) {
        info->a[0] = 0;
        info->pa = 0;
    }
    if (info->b[0] != 0 && info->pb != 0) {
        memset(&sb, 0, sizeof(sb));
        strncpy(sb.addr, info->b, 16);
        sb.port = info->pb;
        sb.peer = 0;
        r = rt_udp_connect(o->h180, &sb, &e->f8);
        if (r != 0x15) {
            if (r != 0)
                return 7;
            if (e->f8 == -1)
                return 7;
            e->type = 1;
        }
    }
    if (info->a[0] != 0 && info->pa != 0) {
        memset(&sa, 0, sizeof(sa));
        strncpy(sa.addr, info->a, 16);
        sa.port = info->pa;
        sa.peer = 0;
        r = rt_udp_connect(o->h180, &sa, &e->f4);
        if (r != 0x15) {
            if (r != 0)
                return 7;
            if (e->f4 == -1)
                return 7;
            e->type = 1;
        }
    }
    if (e->type != 1)
        return 7;
    o->cb198 = cb;
    rv = 0;
    }
    return rv;
}
#undef rt_p2p_get_my_peer_status /* merge_units */
/* merge_units: end func_00303348 */

/* merge_units: begin func_00303598 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt_00303598;
typedef struct { UpnpSlot slot[32]; int h180; UpnpEnt_00303598 *ent; int count; int f18C; int f190; } UpnpObj_00303598;
#if 0 /* merge_units */
extern void *memset(void *, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (a2))) /* merge_units */

extern int rt_udp_disconnect(int h, int key);
extern int rt_udp_deny(int h, int key);

int rt_p2p_disconnect(UpnpObj_00303598 *o)
{
    UpnpEnt_00303598 *e;
    int i;
    if (o == 0) return 2;    e = o->ent;
    for (i = 0; i < o->count; i++, e++) {
        if (e->f4 != -1) rt_udp_disconnect(o->h180, e->f4);
        if (e->f8 != -1) rt_udp_disconnect(o->h180, e->f8);
        memset(&o->ent[i], 0, sizeof(UpnpEnt_00303598));
        e->f4 = e->f8 = -1;
    }
    for (i = 0; i < 32; i++) {
        if (o->slot[i].h != -1) {
            rt_udp_deny(o->h180, o->slot[i].h);
            o->slot[i].h = -1;
        }
    }
    return 0;
}
#undef memset /* merge_units */
/* merge_units: end func_00303598 */
