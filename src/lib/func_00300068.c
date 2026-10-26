#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern int rt_msg_client_is_valid_connection(void);
extern int rt_msg_get_u2byte(int, unsigned short *);
extern int rt_msg_client_is_valid_connection_id(int);
int rt_msg_client_process_app_message(void *s, int kind, int addr, unsigned int len)
{
    /* gcc296 allocation tie: pin a copy of s to $s2 (retail register choice). */
    register char *ps asm("$18");
    unsigned short port = 0;
    int r;
    int hdr;
    void (*cb)(int, int, int, int);
    int id;
    ps = s;
    r = rt_msg_client_is_valid_connection();
    hdr = 0;
    if (r != 1 || addr == 0 || (kind != 2 && kind != 3 && kind != 10)) return 2;
    if (kind == 10) {
        port = 0xFFFF;
    } else {
        if (r >= len) return r;
        if (rt_msg_get_u2byte(addr, &port) != 0) return 7;
        addr += 2;
        hdr = 2;
    }
    cb = F(ps, void *, 0x88);
    if (cb != 0) {
        id = F(ps, unsigned short, 0);
        cb(id, port, addr, (unsigned short)(len - hdr));
        if (rt_msg_client_is_valid_connection_id(id) == 0) return 0xB;
    }
    return 0;
}


