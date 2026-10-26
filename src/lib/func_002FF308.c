typedef struct { unsigned short id; char pad[6]; int f8; } O;
typedef struct { char pad[5]; unsigned char f5; unsigned short f6; char pad2[0x48]; char ring[4]; } P;
typedef struct { unsigned char type; char p1; unsigned short len; } H;
extern int D_004908F8[];
extern int rt_msg_client_is_valid_connection(O *);
extern int rt_msg_client_is_valid_channel(P *);
extern int rt_circ_buf_is_wrapped(void *, unsigned char *);
extern int rt_circ_buf_normalize_with_buf(void *, int, int);
extern int rt_circ_buf_get_used_nowrap(void *, unsigned int *);
extern int rt_msg_client_process_message(O *, P *, unsigned char, unsigned int, unsigned short);
extern int rt_circ_buf_free(void *, unsigned int);
extern int rt_circ_buf_get_start_used_ptr(void *, unsigned int *);
extern int rt_msg_client_get_header(unsigned int, H *, unsigned short *);
int rt_msg_client_process_recv_buf(O *o, P *p)
{
    H h;
    unsigned char full;
    unsigned short len;
    unsigned int avail;
    unsigned int data;
    int r;
    int one;
    void *q;
    int st;
    unsigned int n;
    data = 0;
    avail = 0;
    len = 0;
    one = rt_msg_client_is_valid_connection(o);
    if (one != 1) return 2;
    if (rt_msg_client_is_valid_channel(p) != one) return 2;
    if (p->f5 != 1) return 2;
    if (o->id != p->f6) return 2;
    q = p->ring;
    if (rt_circ_buf_is_wrapped(q, &full)) return 0x15;
    if (full == 1) {
        if (rt_circ_buf_normalize_with_buf(q, 1, D_004908F8[0])) return 0x15;
    }
    if (rt_circ_buf_get_used_nowrap(q, &avail) == 0) goto ok1;
err:
    return 0x15;
ok1:
    if (avail < 3) goto done;
    st = o->f8;
    goto next;
loop:
    data += len;
    r = rt_msg_client_process_message(o, p, h.type, data, h.len);
    if (r) return r;
    if (rt_circ_buf_free(q, n)) goto err;
    if (rt_circ_buf_get_used_nowrap(q, &avail)) goto err;
    if (avail < 3) goto done;
    if (st != o->f8) goto done;
next:
    if (rt_circ_buf_get_start_used_ptr(q, &data)) goto err;
    r = rt_msg_client_get_header(data, &h, &len);
    if (r) return r;
    n = len + h.len;
    if (h.len != 0 && (h.type & 0x80)) n += 4;
    if (avail >= n) goto loop;
done:
    return 0;
}
