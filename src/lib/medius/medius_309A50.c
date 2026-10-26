typedef struct { unsigned char b[64]; } ScfBlk64;
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x18]; int sendlist; char pad2[0x54]; int f74; char pad3[0xC]; int f84; char pad4[4]; int f8C; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
typedef struct { int f0; int f4; int f8; } ScfInfo;
extern int rt_list_buf_get_head(int *list, void **node);
extern int rt_udp_get_packet_header(void *node, ScfHdr *out);
extern int rt_udp_set_packet_header(void *node, ScfHdr *in);
extern int rt_udp_send_reset(ScfSock *s, ScfPeer *e);
extern int KM_CompareSymmetricKey(int a, int b, ScfBlk64 *blk);
extern int KM_AddSymmetricKey(int a, int b, ScfBlk64 *blk);
extern int KM_GetSymmetricKey(int a, int b, ScfBlk64 *blk);
extern int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, ScfInfo *info);
extern int rt_udp_send_peerkey(ScfSock *s, ScfPeer *e, ScfBlk64 *data);

int rt_udp_process_peerkey(ScfSock *s, ScfPeer *e, ScfInfo *info, ScfBlk64 *data, unsigned short len)
{
    ScfBlk64 blk;
    ScfHdr hd;
    void *node = 0;
    int ret = 0;
    int r;
    int h;
    if (len != 0x40) return 7;
    if (e == 0) return 7;
    if (e->f74 == 0 && info->f4 != 0 && (e->type == 8 || e->type == 9)) {
        e->f74 = info->f4;
        node = 0;
        e->f84 = info->f8;
        rt_list_buf_get_head(&e->sendlist, &node);
        if (node == 0) {
            e->type = 6;
            rt_udp_send_reset(s, e);
            return 7;
        }
        rt_udp_get_packet_header(node, &hd);
        hd.val = e->f74;
        rt_udp_set_packet_header(node, &hd);
    }
    h = e->f8C;
    blk = *data;
    r = KM_CompareSymmetricKey(-1, h, &blk);
    if (r == 0) {
        r = RtUdp_QueueAck(s, e, info);
        if (r != 0) return r;
    } else {
        if (r > 0) {
            KM_AddSymmetricKey(-1, h, &blk);
            r = RtUdp_QueueAck(s, e, info);
            if (r != 0) return r;
        } else {
            KM_GetSymmetricKey(-1, h, &blk);
            r = RtUdp_QueueAck(s, e, info);
            if (r != 0) return r;
        }
        if (e->type != 11 && e->type != 12) {
            ret = rt_udp_send_peerkey(s, e, &blk);
            if (ret != 0) {
                e->type = 6;
                return 7;
            }
        }
    }
    return ret;
}

