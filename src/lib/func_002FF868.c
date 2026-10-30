typedef struct { char b[16]; } K16;
typedef struct {
    unsigned short id;
    char p2[2];
    int st;
    char p8[0x50];
    unsigned short f58;
    unsigned short f5A;
    K16 key;
    char p6C[0x18];
    int (*cb)(unsigned short, int, int, unsigned short, int);
} O;
extern unsigned char D_004908EC[];
extern int rt_msg_client_is_valid_connection(); /* called with no args: retail relies on o still in a0 (jal slot is nop) */
extern int rt_msg_get_ubyte(unsigned char *, unsigned char *);
extern int rt_msg_get_u2byte(unsigned char *, unsigned short *);
extern int rt_msg_client_is_server_compatible(int, unsigned char, unsigned char, unsigned char, unsigned char *);
extern int rt_msg_client_map_reject_reason(int *, unsigned char);
extern void KM_SetLocalClientID(unsigned short, unsigned short);
extern int rt_msg_client_change_state(O *, int);
extern int rt_msg_client_is_valid_connection_id(unsigned short);
int rt_msg_client_process_connect_result(O *o, int type, unsigned char *p, unsigned int len)
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short port;
    unsigned char b6;
    unsigned short n;
    int x;
    int one;
    unsigned short off;
    int r;
    int a;
    /* Keep the address-taken label for retail CSE boundaries; discard its unused anchor. */
    static void *keep __attribute__((section(".dtors_drop"))) = &&lab;
    x = 0;
    b3 = 0;
    if (D_004908EC[0] != 1) return 5;
lab:
    one = rt_msg_client_is_valid_connection();
    if (one != 1) return 2;
    if (p == 0) return 2;
    off = 0;
    if (!(off < len)) return 1; /* LEU-vs-0 gets PROB_EVEN -> beql with epilogue steal */
    if (rt_msg_get_ubyte(p, &b0)) return 7;
    off = 1;
    p++;
    if (!(off < len)) return 1;
    if (rt_msg_get_ubyte(p, &b1)) return 7;
    off = 2;
    p++;
    if (!(off < len)) return 1;
    if (rt_msg_get_ubyte(p, &b2)) return 7;
    p++;
    off = 3;
    r = rt_msg_client_is_server_compatible(o->st, b0, b1, b2, &b3);
    if (r) return r;
    if (b3 != one) return 0x10;
    if (type == 7) {
        if (!(off + 1 < len)) return 1;
        if (rt_msg_get_u2byte(p, &port)) return 7;
        p += 2;
        off = 5;
    } else if (type == 6) {
        if (!(off < len)) return 1;
        if (rt_msg_get_ubyte(p, &b6)) return 7;
        r = rt_msg_client_map_reject_reason(&x, b6);
        if (r) return r;
        p++;
        off = 4;
    } else {
        return 1;
    }
    if (!(off + 1 < len)) return 1;
    if (rt_msg_get_u2byte(p, &n)) return 7;
    p += 2;
    off += 2;
    if (len < off + 16) return 1;
    o->key = *(K16 *)p;
    if (type == 7) {
        o->f58 = port;
        o->f5A = n;
        KM_SetLocalClientID(o->id, port);
        if (o->st == 0) {
            r = rt_msg_client_change_state(o, 7);
            if (r) return r;
        } else if (o->st == 1) {
            r = rt_msg_client_change_state(o, 5);
            if (r) return r;
        } else {
            return 3;
        }
    } else {
        r = rt_msg_client_change_state(o, 0xB);
        if (r) return r;
        if (o->cb) {
            unsigned short id = o->id;
            o->cb(id, 0, 0, n, x);
            if (!rt_msg_client_is_valid_connection_id(id)) return 0xB;
        }
    }
    return 0;
}