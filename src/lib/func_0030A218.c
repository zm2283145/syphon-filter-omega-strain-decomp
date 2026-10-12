typedef struct { unsigned int type; char pad[0x8C]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
extern int RtUdp_CheckDuplicate(ScfSock *s, ScfPeer *e, void *p, unsigned char *dup);
extern int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, void *p);
extern int func_0030AB20(ScfSock *s, ScfPeer *e);

int func_0030A218(ScfSock *s, void *p, int idx)
{
    ScfPeer *e;
    unsigned char dup = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    RtUdp_CheckDuplicate(s, e, p, &dup);
    if (!dup) {
        if (e->type == 12) {
            e->type = 3;
            return RtUdp_QueueAck(s, e, p);
        } else if (e->type - 4 < 2) {
            return RtUdp_QueueAck(s, e, p);
        } else {
            e->type = 1;
            return func_0030AB20(s, e);
        }
    } else {
        return RtUdp_QueueAck(s, e, p);
    }
}
