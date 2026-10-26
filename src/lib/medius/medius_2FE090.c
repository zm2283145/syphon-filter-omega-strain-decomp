/*
 * lib/medius: 2 files, 002FE090-002FE168
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FE090 */
typedef struct { char p[5]; unsigned char f5; unsigned short f6; } B;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(void);
extern int rt_msg_client_is_valid_channel(B *);
extern int rt_msg_client_recv_channel_circ_buf(B *);
extern int rt_msg_client_process_recv_buf(unsigned short *, B *);
int rt_msg_client_update_receive(unsigned short *a, B *b, unsigned char c)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection() != 1) return 2;
    if (rt_msg_client_is_valid_channel(b) != 1) return 2;
    if (b->f5 != 1) return 2;
    if (*a != b->f6) return 2;
    r = rt_msg_client_recv_channel_circ_buf(b);
    if (r) return r;
    if (c == 1) {
        r = rt_msg_client_process_recv_buf(a, b);
        if (r) return r;
    }
    return 0;
}
/* merge_units: end func_002FE090 */

/* merge_units: begin func_002FE168 */
typedef struct { unsigned char flag; char pad[3]; int x4; void (*cb)(char *, unsigned short); } S2FE168;
extern S2FE168 D_005297E0;
extern int rt_comm_receive_echo(int, unsigned char *, char *, unsigned short *);
extern int rt_msg_client_map_comm_error(int);
int rt_msg_client_iecho_update(void)
{
    char buf[16];
    unsigned char y;
    unsigned short x;
    int r;
    unsigned char st;
    x = 0;
    y = 0;
    st = D_004908EC;
    if (st != 1) return 5;
    if (D_005297E0.flag != st) return 5;
    do {
        r = rt_msg_client_map_comm_error(rt_comm_receive_echo(D_005297E0.x4, &y, buf, &x));
        if (r) return r;
        if (y != 1) break;
        if (D_005297E0.cb) D_005297E0.cb(buf, x);
    } while (y == 1);
    return 0;
}
/* merge_units: end func_002FE168 */
