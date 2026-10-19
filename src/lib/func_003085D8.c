typedef struct RtPkt RtPkt;
typedef struct { unsigned int w; int x4; int seq; } RtSeqHdr;
typedef struct {
    enum { S0 } state; int id; int pad8[5]; int list1C[2]; int x24; int x28; int pad2C[2]; int list34[6]; int timer[2];
    int pad54[12]; int x84; int pad88[2];
} RtEnt;
typedef struct RtTr {
    int pad0; RtEnt *ents; void *x8; int list0C[8]; unsigned int count; int pad30[2]; int x38; int pad3C[2];
    unsigned char pad44; unsigned char b45; char pad46[2]; unsigned int x48;
    void (*cb)(struct RtTr *, int, int, int, int); int ctx;
} RtTr;
extern unsigned char D_00491324[];
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_0030ED28(void *);
int __attribute__((weak, section(".dtors_drop"))) RtUdp_UpdateRegular(RtTr *o) { return 0; } /* stub: defined in the same original TU */
extern int func_003060F0(void *, unsigned int *);
extern int func_002FA5B0(void *);
extern void func_002FA550(void *);
extern int func_002FABD0(void *, RtPkt **);
extern int func_002FAEE8(RtPkt *);
extern void *func_002FAED0(RtPkt *);
extern RtPkt *func_002FAF00(RtPkt *);

int RtUdp_UpdateTransport(RtTr *o)
{
    RtSeqHdr h;
    unsigned int el;
    RtPkt *pk = 0;
    RtEnt *e;
    unsigned int i;
    int r;

    if (!o) return 2;
    if (o->x8) func_0030ED28(o->x8);
    if (o->x48 < 8) {
        if (D_00491324[0]) return 0;
    } else if (o->b45)
        return 0;
    r = RtUdp_UpdateRegular(o);
    if (r) return r;
    for (i = 0; i < o->count; i++) {
        e = &o->ents[i];
        switch (e->state) {
        case 0:
        case 10:
            break;
        case 1:
            o->cb(o, i, 7, e->id, o->ctx);
            break;
        case 2:
            func_002FA5B0(e->list1C);
            o->cb(o, i, 6, e->id, o->ctx);
            break;
        case 3:
            o->cb(o, i, 8, e->id, o->ctx);
            break;
        case 4:
            func_003060F0(e->timer, &el);
            if (el > 10000) {
                func_002FA550(e->list1C);
                func_002FA550(e->list34);
                memset(e, 0, sizeof(*e));
            }
            break;
        case 5:
            func_003060F0(e->timer, &el);
            if (el > 30000) e->state = 2;
            break;
        case 6:
            o->cb(o, i, 9, e->id, o->ctx);
            e->state = 4;
            break;
        case 7:
            o->cb(o, i, 2, e->id, o->ctx);
            break;
        case 8:
        case 9:
            func_003060F0(e->timer, &el);
            if (el > 30000) e->state = 2;
            break;
        case 11:
            e->state = 12;
            o->cb(o, i, 4, e->id, o->ctx);
            break;
        case 12:
            func_003060F0(e->timer, &el);
            if (el > 30000) {
                e->state = 2;
                break;
            }
            if ((unsigned int)(o->x38 + 32) < (unsigned int)(e->x24 - e->x28))
                o->cb(o, i, 1, e->id, o->ctx);
            func_002FABD0(e->list34, &pk);
            if (pk) {
                do {
                    if (func_002FAEE8(pk)) {
                        memcpy(&h, func_002FAED0(pk), sizeof(h));
                        if ((h.w & 6) != 6 && !(*(unsigned char *)&h.w & 4)) goto notify;
                        if (h.seq == e->x84 + 1 || e->x84 == 0) goto notify;
                    }
                    pk = func_002FAF00(pk);
                } while (pk);
            }
            break;
        notify:
            o->cb(o, i, 0, e->id, o->ctx);
            break;
        }
    }
    func_002FABD0(o->list0C, &pk);
    if (!pk) return 0;
    if (func_002FAEE8(pk)) o->cb(o, -2, 0, 0, o->ctx);
    return 0;
}
