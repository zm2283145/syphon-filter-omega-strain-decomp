typedef struct { unsigned char a; unsigned char pad; unsigned short b; } H2FED28;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(void);
extern int NetPacket_WritePrefix(char *, H2FED28 *, unsigned short *);
extern int rt_msg_client_send_buffer(int, char *, unsigned short, int);
int rt_msg_client_send_disconnect(int conn)
{
    char buf[16];
    H2FED28 h;
    unsigned short len = 0;
    unsigned char st = D_004908EC;
    int v, r;
    if (st != 1) return 5;
    v = rt_msg_client_is_valid_channel();
    if (v != st) return 2;
    h.a = v;
    h.b = 0;
    r = NetPacket_WritePrefix(buf, &h, &len);
    if (r) return r;
    return rt_msg_client_send_buffer(conn, buf, len, 0x2710);
}
