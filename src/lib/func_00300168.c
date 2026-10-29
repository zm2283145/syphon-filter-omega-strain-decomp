#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(void *);
extern int rt_msg_get_ubyte(unsigned char *, unsigned char *);
extern int rt_msg_client_map_fdisconnect_reason(int *, unsigned char);
extern int rt_msg_client_is_valid_connection_id(int);

int rt_msg_client_process_disconnect_message(void *s, int kind, unsigned char *data, long len)
{
    unsigned char reason;
    int why = 0;
    int r;
    void (*cb)(int, int);
    int id;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection(s) != 1) return 2;
    if (data == 0) return 2;
    if (!__builtin_expect(len, 0)) return 1;
    if (rt_msg_get_ubyte(data, &reason) != 0) return 7;
    r = rt_msg_client_map_fdisconnect_reason(&why, reason);
    if (r != 0) return r;
    cb = F(s, void *, 0x90);
    if (cb != 0) {
        id = F(s, unsigned short, 0);
        cb(id, why);
        if (rt_msg_client_is_valid_connection_id(id) == 0) return 0xB;
    }
    return 0;
}
