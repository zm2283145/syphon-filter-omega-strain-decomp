typedef struct { short a, b, c; unsigned short port; } C2FE958;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(C2FE958 *);
extern int rt_msg_client_calc_connect_msg_size(int, unsigned short *);
extern int rt_memory_allocate_init_zero(void **, int);
extern int rt_msg_client_store_connect_msg_in_buf(void *, int, int, int, int, int, int);
extern int rt_msg_client_store_msg_in_send_buf(void *, int, int, void *, int, int);
extern void rt_memory_free(void *);
int rt_msg_client_store_connect_msg_in_send_buf(unsigned int kind, C2FE958 *c, unsigned short flags, int data, unsigned short len)
{
    unsigned short sz;
    void *buf;
    unsigned char st = D_004908EC;
    int r;
    buf = 0;
    sz = 0;
    if (st != 1) return 5;
    if (rt_msg_client_is_valid_channel(c) != st) return 2;
    if (data == 0 && len != 0) return 2;
    if (kind >= 2) return 2;
    r = rt_msg_client_calc_connect_msg_size(len, &sz);
    if (r != 0) return r;
    if (rt_memory_allocate_init_zero(&buf, sz) != 0) return 8;
    r = rt_msg_client_store_connect_msg_in_buf(buf, sz, kind, c->port, flags, data, len);
    if (r == 0)
        r = rt_msg_client_store_msg_in_send_buf(c, kind ? 0x15 : 0, 0xFFFF, buf, sz, 1);
    if (buf) rt_memory_free(&buf);
    return r;
}