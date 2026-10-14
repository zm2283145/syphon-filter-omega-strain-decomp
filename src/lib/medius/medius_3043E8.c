/*
 * lib/medius: 6 files, 003043E8-00304800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003043E8 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { char pad[0x40]; char a40[16]; char a50[16]; unsigned short p60; unsigned short p62; } UpnpAddr;
extern int func_00302A38(UpnpObj *o, int peer, int mode, char *addr, unsigned short *port);
extern int String_CompareN(const char *, const char *, unsigned int);

int func_003043E8(UpnpObj *o, UpnpAddr *a, int *out)
{
    char addr[16];
    unsigned short port;
    int i;
    int match;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;
    if (a == 0) return 2;    for (i = 0; i < o->count; i++) {
        match = 0;
        func_00302A38(o, i, 0, addr, &port);
        String_CompareN(addr, a->a40, 16);
        func_00302A38(o, i, 1, addr, &port);
        if (String_CompareN(addr, a->a50, 16) == 0) match = (port == a->p62);
        if (match) { *out = i; break; }
    }
    return 0;
}
/* merge_units: end func_003043E8 */

/* merge_units: begin func_00304508 */
int func_00304508(UpnpObj *o, int key, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;    for (i = 0; i < o->count; i++) {
        if (key == o->ent[i].f4) { *out = i; break; }
        if (key == o->ent[i].f8) { *out = i; break; }
    }
    return 0;
}
/* merge_units: end func_00304508 */

/* merge_units: begin func_00304578 */
int func_00304578(UpnpObj *o, int *type, int *idx)
{
    int i;
    int t;
    if (type == 0) return 2;
    *type = 0;
    if (idx == 0) return 2;
    *idx = -2;
    if (o == 0) return 2;

    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 6) { *type = o->ent[i].type; *idx = i; break; }
        if (o->ent[i].type == 7 || o->ent[i].type == 5) { *type = o->ent[i].type; *idx = i; break; }
    }
    return 0;
}
/* merge_units: end func_00304578 */

/* merge_units: begin func_00304618 */
extern void *memset(void *, int, unsigned int);

int func_00304618(UpnpObj *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 0) {
            *out = i;
            memset(&o->ent[i], 0, sizeof(UpnpEnt));
            o->ent[i].f8 = o->ent[i].f4 = -1;
            break;
        }
    }
    return 0;
}
/* merge_units: end func_00304618 */

/* merge_units: begin func_003046C8 */
typedef struct { int magic; char a4[0x10]; char a14[0x10]; unsigned short p24; unsigned short p26; int peer; unsigned char b2C; char pad[3]; char b30[0x40]; } UpnpRec;
extern int func_00304578(UpnpObj *o, int *type, int *idx);
extern int func_00302B28(UpnpObj *o, int mode, void *a, void *b);
#if 0 /* merge_units */
extern int func_00302A38(UpnpObj *o, int peer, int mode, void *a, void *b);
#endif /* merge_units */
#define func_00302A38(a0, a1, a2, a3, a4) (func_00302A38((a0), (a1), (a2), (char *)(a3), (unsigned short *)(a4))) /* merge_units */

extern int func_002F8908(int, void *);
extern int func_002F8628(int, int, void *);
int func_003046C8(UpnpObj *o, int peer, UpnpRec *r)
{
    int type;
    int idx;
    int ret;
    idx = -2;
    type = 0;
    if (r == 0) return 2;
    if ((ret = func_00304578(o, &type, &idx)) != 0) return ret;
    memset(r, 0, 0x70);
    r->magic = 0xEFF0CDAB;
    r->peer = peer;    if (peer == idx) {
        r->b2C = 1;
        if ((ret = func_00302B28(o, 0, r->a4, &r->p24)) != 0) return ret;
        ret = func_00302B28(o, 1, r->a14, &r->p26);
        func_002F8908(-1, r->b30);
        if (ret == 0) goto ok;
        return ret;
    }
    if ((ret = func_00302A38(o, peer, 0, r->a4, &r->p24)) != 0) return ret;
    ret = func_00302A38(o, peer, 1, r->a14, &r->p26);
    func_002F8628(-1, peer, r->b30);
    if (ret != 0) return ret;
ok:
    return 0;
}
#undef func_00302A38 /* merge_units */
/* merge_units: end func_003046C8 */

/* merge_units: begin func_00304800 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt_00304800;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt_00304800 *ent;
    int count;
    int size;
    void *buf;
    unsigned char b194;
    char pad195[0x13];
    void (*cb1A8)(int peer, void *data, unsigned short len);
    void (*cb1AC)(void *addr, unsigned short port, void *data, unsigned short len);
} UpnpObj_00304800;
extern void *memcpy(void *, const void *, unsigned int);
extern int RtUdp_Read(int h, int ep, void *buf, int size, int *len);
extern int func_00304A98(UpnpObj_00304800 *o, int peer, void *data, int len);
extern int func_00307598(int h, int ep, void *addr, unsigned short *port);

int RtUdp_DrainReceive(UpnpObj_00304800 *o)
{
    char addr[16];
    unsigned short port;
    int len;
    int magic;
    int i;
    int got;
    int rv;

    for (i = 0; i < o->count; i++) {
        while (o->ent[i].bF != 0) {
            got = 0;
            if (o->ent[i].f4 != -1) {
                magic = 0;
                if (RtUdp_Read(o->h180, o->ent[i].f4, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = func_00304A98(o, i, o->buf, len);
                        if (rv != 0)
                            return rv;
                    }
                    got = 1;
                }
            }
            if (o->ent[i].f8 != -1) {
                magic = 0;
                if (RtUdp_Read(o->h180, o->ent[i].f8, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = func_00304A98(o, i, o->buf, len);
                        if (rv != 0)
                            return rv;
                    }
                    got = 1;
                }
            }
            if (!got)
                o->ent[i].bF = 0;
        }
    }
    while (o->b194 != 0) {
        if (func_00307598(o->h180, -2, addr, &port) != 0)
            return 7;
        if (RtUdp_Read(o->h180, -2, o->buf, o->size, &len) == 0 && len != 0)
            o->cb1AC(addr, port, o->buf, len);
        else
            o->b194 = 0;
    }
    return 0;
}
/* merge_units: end func_00304800 */
