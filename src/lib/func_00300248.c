#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int rt_msg_get_u2byte(unsigned char *, unsigned short *);
extern void KM_AddSymmetricKey(int, int, unsigned char *);
/* weak stub: the callee was defined in the same original unit (restores the retail branch choice) */
int __attribute__((weak, section(".dtors_drop"))) rt_msg_client_store_connect_msg_in_send_buf(int a, int b, int c, int d, int e) { return 0; }
extern int rt_msg_client_change_state(void *, int);
int rt_msg_client_process_crypt_key_peer(void *s, int kind, unsigned char *data, int len)
{
    unsigned short port = 0xFFFF;
    int r;
    if (D_004908EC != 1) return 5;
    if (s == 0) return 2;
    if (data == 0) return 2;
    if (kind == 0x1B) {
        rt_msg_get_u2byte(data, &port);
        data += 2;
        len -= 2;
    }
    if (len != 0x40) return 2;
    KM_AddSymmetricKey(F(s, unsigned short, 0), port, data);
    if (F(s, int, 8) == 3) {
        r = rt_msg_client_store_connect_msg_in_send_buf(F(s, int, 4), F(s, int, 0x80), F(s, unsigned short, 0x22), F(s, int, 0x3C), F(s, unsigned short, 0x40));
        if (r != 0) return r;
        r = rt_msg_client_change_state(s, 4);
        if (r != 0) return r;
    }
    return 0;
}
