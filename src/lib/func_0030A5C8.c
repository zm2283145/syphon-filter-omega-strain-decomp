typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { union { unsigned int w; struct { unsigned char flags; unsigned char id; unsigned short len; } f; } u; int val; unsigned int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x30]; int recvlist; char pad2[0x14]; int timer[2]; char pad3[0x2C]; unsigned int f80; char pad4[0xC]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x20]; void *buf; } ScfSock;
extern void func_003060D8(int *timer);
extern int RtUdp_CheckDuplicate(ScfSock *s, ScfPeer *e, ScfHdr *p, unsigned char *dup);
extern int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, ScfHdr *p);
extern int func_002FABD0(int *list, void **node);
extern unsigned int func_002FAEE8(void *node);
extern char *func_002FAED0(void *node);
extern void *func_002FAF00(void *node);
extern int func_002FAC20(int *list, void **node);
extern int func_002FA5F8(int *list, void *node, void *data, int len);
extern int func_002FA758(int *list, void *data, int len);

int RtUdp_ReceiveData(ScfSock *s, ScfHdr *p, int idx)
{
    ScfHdr hd;
    void *node = 0;
    unsigned char dup = 0;
    void *prev = 0;
    int inserted = 0;
    ScfPeer *e;
    int ret;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    func_003060D8(e->timer);
    ret = RtUdp_CheckDuplicate(s, e, p, &dup);
    if (!dup) {
        if ((p->u.w & 6) == 6 || (p->u.f.flags & 4)) {
            int *list = &e->recvlist;
            func_002FABD0(list, &node);
            for (; node != 0; node = func_002FAF00(node)) {
                if (func_002FAEE8(node) == 0) continue;
                *(ScfAddr12 *)&hd = *(ScfAddr12 *)func_002FAED0(node);
                if (!((hd.u.w & 6) == 6 || (hd.u.f.flags & 4))) continue;
                if ((int)(hd.seq - p->seq) > 0) {
                    if (hd.seq <= 0x7FFFFFFE) {
                        if (p->seq > 0x7FFFFFFE) {
                            prev = node;
                            continue;
                        }
                    } else if (p->seq <= 0x7FFFFFFE) goto older;
                    if (prev) {
                        if (func_002FA5F8(list, prev, s->buf, p->u.f.len + 12) != 0) return 10;
                    } else {
                        if (func_002FA758(list, s->buf, p->u.f.len + 12) != 0) return 10;
                    }
                    inserted = 1;
                    break;
                }
older:
                prev = node;
            }
            if (!inserted) {
                if (func_002FAC20(list, &node) != 0) return 10;
                if (func_002FA5F8(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
            }
            ret = RtUdp_QueueAck(s, e, p);
        } else {
            int *list;
            if (p->u.f.flags & 2) e->f80 = p->seq;
            list = &e->recvlist;
            if (func_002FAC20(list, &node) != 0) return 10;
            if (func_002FA5F8(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
        }
    } else if (p->u.f.flags & 4) {
        ret = RtUdp_QueueAck(s, e, p);
    }
    return ret;
}

