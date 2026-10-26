/*
 * lib/medius: 2 files, 002FDC60-002FDDF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FDC60 */
typedef struct { char pad[0x20]; char f20[8]; char f28[0xC]; char f34[4]; } S;
typedef struct { char pad[0x1C]; int f1C; } M;
typedef struct { unsigned short id; char pad[2]; int f4; int f8; char pad2[0x16]; unsigned short f22; char pad3[0x18]; int f3C; unsigned short f40; char pad4[0x36]; S *sub[2]; M *main; } O;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(O *);
extern int rt_comm_is_connected(int, unsigned char *);
extern int rt_msg_client_map_comm_error(int);
extern int rt_time_start(void *);
extern int rt_msg_client_have_encryption_key(unsigned short, unsigned char *);
extern int rt_msg_client_store_pkey_msg_in_send_buf(M *, unsigned short);
extern int rt_msg_client_store_connect_msg_in_send_buf(int, M *, unsigned short, int, unsigned short);
extern int rt_msg_client_change_state(O *, int);
int rt_msg_client_update_comm_wait(O *o)
{
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned int i;
    int r;
    S *s;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection(o) != 1) return 2;
    if (o->f8 != 2) return 2;
    r = rt_msg_client_map_comm_error(rt_comm_is_connected(o->main->f1C, &a));
    if (r) return r;
    if (a == 1) {
        for (i = 0; i < 2; i++) {
            s = o->sub[i];
            if (s) {
                if (rt_time_start(s->f20)) return 0x18;
                if (rt_time_start(s->f28)) return 0x18;
                if (rt_time_start(s->f34)) return 0x18;
            }
        }
        r = rt_msg_client_have_encryption_key(o->id, &b);
        if (r) return r;
        if (b == 1) {
            r = rt_msg_client_store_pkey_msg_in_send_buf(o->main, o->f22);
            if (r) return r;
            r = rt_msg_client_change_state(o, 3);
            if (r) return r;
        } else {
            r = rt_msg_client_store_connect_msg_in_send_buf(o->f4, o->main, o->f22, o->f3C, o->f40);
            if (r) return r;
            r = rt_msg_client_change_state(o, 4);
            if (r) return r;
        }
    }
    return 0;
}
/* merge_units: end func_002FDC60 */

/* merge_units: begin func_002FDDF0 */
typedef struct {
    int f0; char p4; unsigned char f5; unsigned short f6;
    char p8[0x18]; char f20[0x10]; unsigned int f30; char f34[8]; unsigned short f3C; char p3E[2];
    unsigned int f40; unsigned char f44; char p45; unsigned short f46; char p48[0x20]; char f68[4];
} S_002FDDF0;
typedef struct { unsigned short id; char p2[6]; int f8; char pC[0x64]; char f70[8]; } O_002FDDF0;
#if 0 /* merge_units */
extern int rt_msg_client_is_valid_connection(O_002FDDF0 *);
#endif /* merge_units */
#define rt_msg_client_is_valid_connection(a0) (rt_msg_client_is_valid_connection((O *)(a0))) /* merge_units */

extern int rt_msg_client_is_valid_channel(S_002FDDF0 *);
extern int rt_time_elapsed(void *, unsigned int *);
extern int NetConn_BufferMessage(S_002FDDF0 *, int, int, unsigned char *, int, int);
extern int rt_msg_client_store_connect_aux_udp(O_002FDDF0 *, S_002FDDF0 *);
extern int rt_msg_client_store_flush_msg_in_send_buf(S_002FDDF0 *, unsigned short);
extern int NetConn_Flush(S_002FDDF0 *);
extern int NetConn_Drain(S_002FDDF0 *);
extern int rt_circ_buf_get_used(void *, unsigned int *);
extern int rt_circ_buf_normalize_with_buf(void *, int, int);
int rt_msg_client_update_send(O_002FDDF0 *o, S_002FDDF0 *s)
{
    unsigned char msg = 0xA5;
    unsigned int t, n;
    int flushed = 0;
    int pending = 0;
    int r;
    n = 0;
    t = 0;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection(o) != 1) return 2;
    if (rt_msg_client_is_valid_channel(s) != 1) return 2;
    if (s->f5 != 1) return 2;
    if (o->id != s->f6) return 2;
    if (o->f8 == 8) {
        if (s->f30) {
            if (rt_time_elapsed(s->f34, &t)) return 0x18;
            if (t > s->f30) {
                r = NetConn_BufferMessage(s, 5, 0xFFFF, &msg, 1, 0);
                if (r) return r;
                if (rt_time_start(s->f34)) return 0x18;
                s->f3C++;
            }
        }
    } else if (o->f8 == 6 && s->f0 == 1) {
        if (rt_time_elapsed(o->f70, &t)) return 0x18;
        if (t > 200) {
            r = rt_msg_client_store_connect_aux_udp(o, s);
            if (r) return r;
        }
    }
    if (s->f44 == 1 && s->f46 != 0xFFFF) {
        r = rt_msg_client_store_flush_msg_in_send_buf(s, s->f46);
        if (r) return r;
    }
    if (rt_time_elapsed(s->f20, &t)) return 0x18;
    if (t > s->f40 || s->f40 == 0 || s->f44 == 1 || o->f8 != 8) {
        flushed = 1;
        if (NetConn_Flush(s) == 8) pending = 1;
        else s->f44 = 0;
    }
    if (rt_circ_buf_get_used(s->f68, &n)) return 0x15;
    if (n) {
        if (flushed == 1) {
            r = NetConn_Drain(s);
            if (r) return r;
            if (rt_circ_buf_normalize_with_buf(s->f68, 0, 0)) return 0x15;
        }
        if (pending) {
            if (NetConn_Flush(s) != 8) s->f44 = 0;
        }
    }
    return 0;
}
#undef rt_msg_client_is_valid_connection /* merge_units */
/* merge_units: end func_002FDDF0 */
