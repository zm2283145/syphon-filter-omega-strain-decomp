typedef struct { unsigned char b[64]; } ScfBlk64;
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x70]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
typedef struct { unsigned int type; } ScfNode;
extern int func_002FABD0(int *list, ScfNode **node);
extern char *func_002FAED0(ScfNode *node);
extern int func_00308E78(ScfNode *node, ScfHdr *out);
extern int func_00308F58(ScfNode *node, ScfHdr *out);
extern int func_00309120(ScfNode *node, ScfBlk64 **data, int *size);
extern int func_003090A8(ScfNode *node, int v);
extern int RtUdp_BuildHeader(ScfSock *s, ScfPeer *e, int kind, ScfHdr *hd);
extern int RtUdp_CopyPacket(ScfPeer *e, ScfHdr *hd, ScfBlk64 *data, int len);

int func_00309CA8(ScfSock *s, ScfPeer *e, ScfBlk64 *data)
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
        if (func_002FABD0(&e->list, &node) != 0) break;
        if (node == 0 || node->type == 0) break;
        dst = (ScfBlk64 *)func_002FAED0(node);
        func_00308E78(node, &hd0);
        func_00308F58(node, &hd);
        func_00309120(node, &dst, &size);
        if (!((hd.id & 0x80) && hd.len == 0x40)) break;
        func_003090A8(node, 0);
        *dst = *data;
        return 0;
    }
    if (RtUdp_BuildHeader(s, e, 4, &hd) != 0) {
        e->type = 6;
        return 7;
    }
    hd.flags |= 0x40;
    hd.id |= 0x80;
    hd.len = 0x40;
    return RtUdp_CopyPacket(e, &hd, data, 0x40);
}
