/*
 * lib/medius: 2 files, 002E2CE0-002E2DD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E2CE0 */
extern unsigned int D_0048C450;
extern int D_00598408;
extern int NetGetConnInfo(unsigned int, char **);
extern int NetIGetObject(char **, unsigned int);
extern int RemoteObjectUpdate(int, unsigned int, int);
extern int SendGroupedFieldUpdate(unsigned int, int, int);
extern int NetSendDmeMessage(int, unsigned int, int, int, int, void *);

int NetIReleaseObjectPrivateOwnership(unsigned int id)
{
    struct { short id; } msg;
    char *q;
    char *p;
    int r;

    q = 0;
    p = 0;
    if (id >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return 0;
    NetIGetObject(&q, id);
    if (q == 0) return 8;
    if (*(int *)(q + 4) == *(int *)(p + 0x400)) {
        *(int *)(q + 4) = -1;
        RemoteObjectUpdate(*(int *)(q + 4), id, -2);
        msg.id = id;
        SendGroupedFieldUpdate(id, 0x50, 1);
        NetSendDmeMessage(0x50, D_0048C450, -1, D_00598408, 2, &msg);
        return 0;
    }
    return 8;
}
/* merge_units: end func_002E2CE0 */

/* merge_units: begin func_002E2DD0 */
typedef struct { unsigned char mask[0x24]; int n; int f28; } R;
typedef struct { char pad[0x400]; int self; char pad2[0x40]; int n; } S;
extern int (*D_00590218[])(int, unsigned int);
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, S **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (char * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int NetIGetObject(unsigned char **, unsigned int);
#endif /* merge_units */
#define NetIGetObject(a0, a1) (NetIGetObject((char * *)(a0), (a1))) /* merge_units */

extern int NetIGetClient(int *, unsigned int, int);
extern void NetSetClientTargetActive(R *, int);

void NetGetFilteredObjectTargetClients(R *r, unsigned int id)
{
    unsigned char *e = 0;
    S *s = 0;
    int x;
    int (*cb)(int, unsigned int);
    int i, j;
    unsigned char *p;

    if (r == 0) return;
    if (id >= 0x1000) return;
    if (D_0048C450 >= 4) return;
    if (NetGetConnInfo(D_0048C450, &s) != 0) return;
    if (s == 0) return;
    NetIGetObject(&e, id);
    if (e == 0) return;
    cb = D_00590218[e[1]];
    r->n = s->n;
    r->f28 = -1;
    j = 0x20;
    p = &r->mask[0x20];
    for (; j >= 0; j--) *p-- = 0;
    for (i = 0; i < s->n; i++) {
        x = 0;
        NetIGetClient(&x, D_0048C450, i);
        if (x != 0 && i != s->self && cb(i, id) != 0) NetSetClientTargetActive(r, i);
    }
}
#undef NetGetConnInfo /* merge_units */
#undef NetIGetObject /* merge_units */
/* merge_units: end func_002E2DD0 */
