#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { char b[16]; } K16;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(void);
extern int rt_msg_get_ubyte(unsigned char *, unsigned char *);
extern int rt_msg_get_u2byte(unsigned char *, unsigned short *);
extern int rt_msg_client_is_server_compatible(int, int, int, int, unsigned char *);
extern int rt_msg_client_store_msg_in_send_buf(int, int, int, int, int, int);
extern int rt_msg_client_change_state(void *, int);
int rt_msg_client_process_accept_aux_udp(void *s, int kind, unsigned char *src, unsigned int len)
{
    struct { unsigned char v[4]; unsigned short port; } l;
    unsigned char st = D_004908EC;
    int x;
    long y; /* long: compare against 1 must not share the SI constant 1 */
    l.v[3] = 0;
    if (st != 1) return 5;
    __asm__ __volatile__(""); /* scheduling barrier needed for retail insn order */
    if (rt_msg_client_is_valid_connection() != st) return 2;
    if (src == 0) return 2;
    switch (kind) {
    case 0x19: x = F(s, int, 8); break;
    default: return 2;
    }
    if (x != 6) return 1;
    y = F(s, int, 4);
    if (y != 1) return 1;
    if (len == 0) { return 1; }
    __asm__ __volatile__(""); /* forces retail's beql + ld s0 delay slot for len == 0 */
    if (rt_msg_get_ubyte(src, &l.v[0]) != 0) return 7;
    src++;
    { unsigned int n; __asm__("li %0, 1" : "=r"(n)); /* fresh 1: stops cse reusing s3 */ if (n >= len) return 1; }
    if (rt_msg_get_ubyte(src, &l.v[1]) != 0) return 7;
    src++;
    { unsigned int n = 2; if (n >= len) return 1; }
    if (rt_msg_get_ubyte(src, &l.v[2]) != 0) return 7;
    src++;
    { int e = rt_msg_client_is_server_compatible(F(s, int, 4), l.v[0], l.v[1], l.v[2], &l.v[3]);
    if (e != 0) return e; }
    if (l.v[3] != y) return 0x10;
    { unsigned int n = 4; if (n >= len) return 1; }
    if (rt_msg_get_u2byte(src, &l.port) != 0) return 7;
    src += 2;
    if (l.port != F(s, unsigned short, 0x58)) return 1;
    if (x >= len) return 1;
    if (rt_msg_get_u2byte(src, (unsigned short *)((char *)s + 0x5A)) != 0) return 7;
    src += 2;
    if (len < 0x17) return 1;
    F(s, K16, 0x5C) = *(K16 *)src;
    src += 16;
    { unsigned int n = 0x18; if (n >= len) return 1; }
    if (rt_msg_get_u2byte(src, (unsigned short *)((char *)s + 0x6C)) != 0) return 7;
    { int e = rt_msg_client_store_msg_in_send_buf(F(s, int, 0x80), 0x17, 0xFFFF, 0, 0, 1);
    if (e != 0) return e; }
    return rt_msg_client_change_state(s, 7);
}

