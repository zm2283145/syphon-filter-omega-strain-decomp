extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(void);
extern void KM_GetLocalPublicKey(int, char *);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int rt_msg_client_store_pkey_msg_in_send_buf(int conn)
{
    char buf[0x40];
    unsigned char st = D_004908EC;
    if (st != 1) return 5;
    if (rt_msg_client_is_valid_channel() != st) return 2;
    KM_GetLocalPublicKey(0, buf);
    return NetConn_BufferMessage(conn, 0x12, 0xFFFF, buf, 0x40, 1);
}
