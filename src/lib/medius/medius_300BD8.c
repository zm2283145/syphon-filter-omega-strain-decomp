/*
 * lib/medius: 2 files, 00300BD8-00300D68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00300BD8 */
typedef struct { int type; char pad[0x1C]; char f20[0x48]; char q[4]; } C;
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int rt_msg_client_is_valid_channel(void);
extern int rt_circ_buf_get_used_nowrap(void *, int *);
extern int rt_circ_buf_is_wrapped(void *, unsigned char *);
extern int rt_circ_buf_normalize_with_buf(void *, int, int);
extern int rt_circ_buf_get_start_used_ptr(void *, unsigned char **);
extern int rt_circ_buf_free(void *, unsigned short);
extern int rt_time_start(void *);
extern int Socket_Write(C *, unsigned char *, int, unsigned short *);
int NetConn_Drain(C *c)
{
    unsigned char flag;
    unsigned short wrote;
    int avail;
    unsigned char *data;
    void *q;
    int r;
    data = 0;
    avail = 0;
    wrote = 0;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_channel() != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (rt_circ_buf_get_used_nowrap(q, &avail) != 0) return 0x15;
    if (avail == 0) goto done;
    if (c->type == 1) {
        flag = 1;
        if (rt_circ_buf_is_wrapped(q, &flag) != 0) return 0x15;
        if (flag == 1) {
            if (rt_circ_buf_normalize_with_buf(q, 1, D_004908F8) != 0) return 0x15;
            if (rt_circ_buf_get_used_nowrap(q, &avail) != 0) return 0x15;
        }
    }
    do {
        if (rt_circ_buf_get_start_used_ptr(q, &data) != 0) return 0x15;
        wrote = 0;
        r = Socket_Write(c, data, avail, &wrote);
        if (r != 0) return r;
        if (wrote != 0) {
            if (rt_time_start(c->f20) != 0) return 0x18;
        }
        if (rt_circ_buf_free(q, wrote) != 0) return 0x15;
        if (rt_circ_buf_get_used_nowrap(q, &avail) != 0) return 0x15;
    } while (avail != 0 && wrote != 0);
done:
    return 0;
}
/* merge_units: end func_00300BD8 */

/* merge_units: begin func_00300D68 */
typedef struct {
    int type;
    char pad4;
    unsigned char ready;
    char pad6[2];
    char addr[0x10];
    unsigned short port;
    char pad1a[2];
    int h;
    char pad20[8];
    char f28[0x28];
    char q[4];
} R;
extern int rt_circ_buf_get_avail_nowrap(void *, unsigned int *);
extern int rt_circ_buf_get_start_avail_ptr(void *, unsigned char **);
extern int rt_comm_receive(int, unsigned char *, unsigned short, unsigned short *);
extern int rt_comm_receive_from(int, char *, unsigned short *, unsigned char *, int, unsigned short *);
extern int rt_msg_client_map_comm_error(int);
extern int NetRing_Commit(void *, unsigned short);
extern int strcmp(const char *, const char *);
int rt_msg_client_recv_channel_circ_buf(R *c)
{
    volatile unsigned short got;
    char addr[0x10];
    unsigned short port;
    unsigned int avail;
    unsigned char *data;
    void *q;
    unsigned short n;
    int more;
    int r;
    data = 0;
    avail = 0;
    got = 0;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_channel() != 1) return 2;
    if (c->ready != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (rt_circ_buf_normalize_with_buf(q, 0, 0) != 0) return 0x15;
    if (rt_circ_buf_get_avail_nowrap(q, &avail) != 0) return 0x15;
    if (avail == 0) goto done;
    do {
        got = 0;
        more = 0;
        if (rt_circ_buf_get_start_avail_ptr(q, &data) != 0) return 0x15;
        if (c->type == 0) {
            n = 0x1000;
            if (avail <= 0x1000) n = avail;
            r = rt_msg_client_map_comm_error(rt_comm_receive(c->h, data, n, &got));
            if (r != 0) return r;
            if (got == n) more = 1;
        } else if (c->type == 1) {
            if (avail >= 0x248) {
                r = rt_msg_client_map_comm_error(rt_comm_receive_from(c->h, addr, &port, data, 0x248, &got));
                if (r != 0) return r;
                if (got != 0) {
                    if (port != c->port || strcmp(addr, c->addr) != 0) got = 0;
                    more = 1;
                }
            }
        } else {
            return 3;
        }
        if (got != 0) {
            if (rt_time_start(c->f28) != 0) return 0x18;
            if (NetRing_Commit(q, got) != 0) return 0x15;
        }
        if (rt_circ_buf_get_avail_nowrap(q, &avail) != 0) return 0x15;
    } while (avail != 0 && more == 1);
done:
    return 0;
}
/* merge_units: end func_00300D68 */
