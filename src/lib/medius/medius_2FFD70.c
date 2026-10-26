#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(void);
extern int rt_msg_get_u2byte(int, unsigned short *);
extern int rt_msg_client_change_state(void *, int);
extern int rt_msg_client_is_valid_connection_id(int);
int rt_msg_client_process_connect_complete(void *s, int kind, int addr, unsigned int len)
{
    unsigned short port;
    unsigned char st = D_004908EC;
    int r;
    void (*cb)(int, int, int, int, int);
    int id;
    if (st != 1) return 5;
    r = rt_msg_client_is_valid_connection();
    if (r != st) return 2;
    if (addr == 0 || kind != 0x1A) return 2;
    if (r >= len) return r;
    if (rt_msg_get_u2byte(addr, &port) != 0) return 7;
    F(s, unsigned short, 0x5A) = port;
    r = rt_msg_client_change_state(s, 8);
    if (r != 0) return r;
    cb = F(s, void *, 0x84);
    if (cb != 0) {
        id = F(s, unsigned short, 0);
        cb(id, 1, F(s, unsigned short, 0x58), F(s, unsigned short, 0x5A), 0);
        if (rt_msg_client_is_valid_connection_id(id) == 0) return 0xB;
    }
    return 0;
}