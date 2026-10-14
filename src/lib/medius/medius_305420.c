/*
 * lib/medius: 3 files, 00305420-003055E8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00305420 */
typedef struct { int state; char pad[0x24]; } Slot5420;
typedef struct { char pad[0x184]; Slot5420 *slots; int count; } Owner5420;
int func_00305420(Owner5420 *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    for (i = 0; i < o->count; i++) {
        if (o->slots[i].state == 3) {
            *out = i;
            o->slots[i].state = 4;
            break;
        }
        if (o->slots[i].state == 6) {
            *out = i;
            o->slots[i].state = 7;
            break;
        }
    }
    return 0;
}
/* merge_units: end func_00305420 */

/* merge_units: begin func_003054C8 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { unsigned int magic; int n; int pad; } UpnpMsg3;
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);

int func_003054C8(UpnpObj *o, int n, int base)
{
    UpnpMsg3 m;
    int i;
    int found;
    m.magic = 0xEFF0CDAB;
    i = 0;
    found = 0;
    m.n = base;
    if (n) {
        if (base < n) i = n - 1;
    } else i = o->count - 1;
    for (; base < i; i--) {
        if (o->ent[i].type == 3) found = 1;
        if (o->ent[i].type == 4) found = 1;
    }
    if (!found) {
        for (i = 0; i < o->count; i++) {
            if (o->ent[i].type - 3 < 2u) {
                RtUdp_SendToPeerEndpoint(o, i, 7, &m, 12);
            }
        }
    }
    return 0;
}
/* merge_units: end func_003054C8 */

/* merge_units: begin func_003055E8 */
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct { UpnpSlot slot[32]; int h180; } UpnpObj_003055E8;
typedef struct { int f0; char a[16]; char b[16]; unsigned short pa; unsigned short pb; int f28; } PeerInfo;
typedef struct { int type; int f4; int f8; char pad[6]; char name[16]; unsigned short port; } PeerOut;
extern int func_00307598(int h, int ep, char *addr, unsigned short *port);
extern int func_003079E0(int h, int ep, int val);
extern void func_002F9728(void *buf);
extern int func_002F8C50(int a, int peer, void *buf);
extern int func_00308278(int h, int ep);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);

int func_003055E8(UpnpObj_003055E8 *o, PeerInfo *in, PeerOut *out)
{
    char addr[16];
    unsigned short port;
    unsigned int i;
    if (o == 0) return 0;
    if (in == 0) return 0;
    i = 0;
    do {
        if (o->slot[i].h == -1) continue;
        if (func_00307598(o->h180, o->slot[i].h, addr, &port) != 0) break;
        if (String_CompareN(addr, in->a, 16) == 0 && port == in->pa && port != 0) {
            char buf[64];
            func_003079E0(o->h180, o->slot[i].h, in->f28);
            func_002F9728(buf);
            func_002F8C50(-1, in->f28, buf);
            func_00308278(o->h180, o->slot[i].h);
            strncpy(out->name, in->b, 16);
            out->port = in->pb;
            out->f4 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
        if (String_CompareN(addr, in->b, 16) == 0 && port == in->pb && port != 0) {
            char buf[64];
            func_003079E0(o->h180, o->slot[i].h, in->f28);
            func_002F9728(buf);
            func_002F8C50(-1, in->f28, buf);
            func_00308278(o->h180, o->slot[i].h);
            strncpy(out->name, in->a, 16);
            out->port = in->pa;
            out->f8 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
    } while (++i < 32);
    return 0;
}
/* merge_units: end func_003055E8 */
