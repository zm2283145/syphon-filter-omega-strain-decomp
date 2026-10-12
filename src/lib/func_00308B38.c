typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x70]; } ScfPeer;
extern void *memset(void *d, int c, unsigned int n);
extern int func_002FAC20(int *list, void **node);
extern int func_002FA5F8(int *list, void *node, void *data, int len);
extern int func_002FA930(int *list, void *node, void *data, int len);
extern int func_002FA830(int *list, void *node);

int RtUdp_CopyPacket(ScfPeer *e, ScfHdr *hd, void *data, int len)
{
    ScfHdr tmp;
    int zero;
    void *node = 0;
    int ok = 0;
    int ret = 0;
    unsigned int i;
    int r;
    if (hd == 0) return 1;
    if (e == 0) return 1;
    hd->len = len;
    for (i = 0; i < 4; i++) {
        r = func_002FAC20(&e->list, &node);
        if (r != 0) {
            ret = 10;
            break;
        }
        switch (i) {
        case 0:
            memset(&tmp, 0, 12);
            r = func_002FA5F8(&e->list, node, &tmp, 12);
            if (r == 0) ok = 1;
            break;
        case 1:
            if (ok) r = func_002FA930(&e->list, node, hd, 12);
            break;
        case 2:
            if (len && data && ok) r = func_002FA930(&e->list, node, data, len);
            break;
        case 3:
            zero = 0;
            if (len && data && ok) r = func_002FA930(&e->list, node, &zero, 4);
            break;
        default:
            r = 1;
            break;
        }
        if (r != 0) {
            if (ok && func_002FAC20(&e->list, &node) == 0) func_002FA830(&e->list, node);
            ret = 10;
            break;
        }
    }
    return ret;
}
