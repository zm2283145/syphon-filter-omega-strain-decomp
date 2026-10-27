typedef struct { unsigned char b[64]; } ScfBlk64;
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x70]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
typedef struct { unsigned int type; } ScfNode;
extern int rt_list_buf_get_head(int *list, ScfNode **node);
extern char *rt_list_buf_get_data_ptr(ScfNode *node);
extern int rt_udp_get_send_header(ScfNode *node, ScfHdr *out);
extern int rt_udp_get_packet_header(ScfNode *node, ScfHdr *out);
extern int rt_udp_get_packet_data(ScfNode *node, ScfBlk64 **data, int *size);
extern int rt_udp_set_packet_seed(ScfNode *node, int v);
extern int rt_udp_setup_packet_header(ScfSock *s, ScfPeer *e, int kind, ScfHdr *hd);
extern int rt_udp_buffer_data_for_send(ScfPeer *e, ScfHdr *hd, ScfBlk64 *data, int len);

int rt_udp_send_peerkey(ScfSock *s, ScfPeer *e, ScfBlk64 *data)
{
    ScfHdr hd;
    ScfHdr hd0;
    ScfBlk64 *dst;
    int size;
    ScfNode *node;
    for (;;) {
        node = 0;
        dst = 0;
        size = 0;
        if (rt_list_buf_get_head(&e->list, &node) != 0) break;
        if (node == 0 || node->type == 0) break;
        dst = (ScfBlk64 *)rt_list_buf_get_data_ptr(node);
        rt_udp_get_send_header(node, &hd0);
        rt_udp_get_packet_header(node, &hd);
        rt_udp_get_packet_data(node, &dst, &size);
        if (!((hd.id & 0x80) && hd.len == 0x40)) break;
        rt_udp_set_packet_seed(node, 0);
        *dst = *data;
        return 0;
    }
    if (rt_udp_setup_packet_header(s, e, 4, &hd) != 0) {
        e->type = 6;
        return 7;
    }
    hd.flags |= 0x40;
    hd.id |= 0x80;
    hd.len = 0x40;
    return rt_udp_buffer_data_for_send(e, &hd, data, 0x40);
}
