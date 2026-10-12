typedef struct { unsigned char b[4]; } ScfU32u;
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned char flags; ScfU32u seq; } ScfAckIn;
typedef struct { unsigned char flags; int seq; } ScfAck;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x2C]; int timer[2]; char pad3[0x3C]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int RtUdp_UpdateRtt(ScfSock *s, ScfPeer *e, unsigned char flags, int seq);
extern int func_002FABD0(int *list, void **node);
extern unsigned int func_002FAEE8(void *node);
extern int func_00308F58(void *node, ScfHdr *out);
extern int func_002FA830(int *list, void *node);
extern void *func_002FAF00(void *node);
extern void func_003060D8(int *timer);

int RtUdp_HandleAck(ScfSock *s, int idx, ScfAckIn *in)
{
    ScfHdr hd;
    unsigned char aflags;
    int aseq;
    void *node = 0;
    ScfPeer *e;
    int ret;
    aflags = 0;
    aseq = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    memcpy(&aflags, &in->flags, 1);
    memcpy(&aseq, &in->seq, 4);
    ret = RtUdp_UpdateRtt(s, e, aflags, aseq);
    if (func_002FABD0(&e->list, &node) != 0) return 10;
    while (node != 0) {
        if (func_002FAEE8(node) != 0) {
            ret = func_00308F58(node, &hd);
            if (ret == 0 && hd.flags == aflags && hd.seq == aseq) {
                if (func_002FA830(&e->list, node) != 0) ret = 10;
                if (hd.len == 0) {
                    if (hd.flags & 0x40) e->type = 11;
                    if (hd.flags & 0x10) e->type = 4;
                } else if ((hd.id & 0x80) && hd.len == 0x40) {
                    e->type = 11;
                }
                func_003060D8(e->timer);
                return ret;
            }
        }
        node = func_002FAF00(node);
    }
    return ret;
}


