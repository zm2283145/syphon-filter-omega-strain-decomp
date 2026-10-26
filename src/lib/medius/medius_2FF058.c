/*
 * lib/medius: 2 files, 002FF058-002FF220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FF058 */
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { int type; unsigned short id; unsigned short len; unsigned short count; char data[0x200]; } B;
typedef struct { char p[0x44]; unsigned char f44; char p45; unsigned short f46; char p48[0x38]; B buf; } C;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(C *);
extern int rt_msg_client_is_valid_outgoing_msg(int);
extern int NetConn_Flush(C *);
int NetConn_BufferMessage(C *c, int type, unsigned short id, void *data, unsigned short len, unsigned char flag)
{
    B *b;
    int ok;
    int r;
    if (rt_msg_client_is_valid_channel(c) != 1) return 2;
    if (D_004908EC != 1) return 5;
    if (data == 0 && len != 0) return 2;
    if (rt_msg_client_is_valid_outgoing_msg(type) != 1) return 2;
    if (len > 0x200) return 2;
    b = &c->buf;
    if (b == 0) return 9;
    if (b->count != 0) {
        ok = 0;
        if ((type == 2 || type == 3) && b->type == type && b->id == id) {
            ok = 1;
            if (b->len + len > 0x200) ok = 0;
        }
    } else ok = 1;
    if (!ok) {
        r = NetConn_Flush(c);
        if (r) return r;
    }
    b->type = type;
    b->id = id;
    memcpy(b->data + b->len, data, len);
    b->len += len;
    b->count++;
    if (!(type == 2 || type == 3)) NetConn_Flush(c);
    if (flag == 1) {
        if (c->f44 == 1 && c->f46 != 0xFFFF) {
            if (c->f46 != id && id != 0xFFFF) c->f46 = 0xFFFE;
        } else c->f46 = id;
        c->f44 = 1;
    }
    return 0;
}
/* merge_units: end func_002FF058 */

/* merge_units: begin func_002FF220 */
typedef struct { char pad[0x68]; char q[4]; } C_002FF220;
extern int D_004908F8;
#if 0 /* merge_units */
extern int rt_msg_client_is_valid_channel(C_002FF220 *);
#endif /* merge_units */
#define rt_msg_client_is_valid_channel(a0) (rt_msg_client_is_valid_channel((C *)(a0))) /* merge_units */

extern int rt_circ_buf_get_avail_nowrap(void *, unsigned int *);
extern int NetConn_Drain(C_002FF220 *);
extern int rt_circ_buf_normalize_with_buf(void *, int, int);
int rt_msg_client_create_send_buf_space(C_002FF220 *c, unsigned int sz)
{
    unsigned int x[1];
    void *q;
    int r;
    x[0] = 0;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_channel(c) != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (rt_circ_buf_get_avail_nowrap(q, x)) return 0x15;
    if (x[0] < sz) {
        r = NetConn_Drain(c);
        if (r) return r;
        if (rt_circ_buf_normalize_with_buf(q, 1, D_004908F8)) return 0x15;
        if (rt_circ_buf_get_avail_nowrap(q, x)) return 0x15;
        if (x[0] < sz) return 0x14;
    }
    return 0;
}
#undef rt_msg_client_is_valid_channel /* merge_units */
/* merge_units: end func_002FF220 */
