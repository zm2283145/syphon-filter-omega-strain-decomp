typedef struct {
    unsigned short h;
    char pad[0x92];
    void (*cb)(unsigned short h, unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short len, unsigned char *data);
} Obj0450;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(void);
extern void rt_msg_get_ubyte(unsigned char *src, unsigned char *dst);
int rt_msg_client_process_system_message(Obj0450 *o, int unused, unsigned char *pkt, int len)
{
    unsigned char b[4];
    int st = D_004908EC;
    if (st != 1) return 5;
    if (rt_msg_client_is_valid_connection() != st) return 2;
    if (pkt == 0) return 2;
    if (o->cb) {
        rt_msg_get_ubyte(pkt, &b[0]);
        rt_msg_get_ubyte(pkt + 1, &b[1]);
        rt_msg_get_ubyte(pkt + 2, &b[2]);
        rt_msg_get_ubyte(pkt + 3, &b[3]);
        o->cb(o->h, b[0], b[1], b[2], b[3], (unsigned short)len - 4, pkt + 4);
    }
    return 0;
}
