/*
 * lib/medius: 2 files, 002FCE88-002FCFE8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FCE88 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int rt_msg_client_get_connection(int, void **);
extern int rt_circ_buf_get_used(void *, int *);
extern int rt_msg_client_set_scratch_buf_min_size(int);
extern int rt_circ_buf_copy(int, void *, int);
extern void rt_msg_client_send_buffer(void *, int, int, int);
extern void rt_msg_client_change_state(void *, int);
extern void rt_msg_client_send_disconnect(void *);
extern void rt_comm_destroy(int);
extern void rt_msg_client_free_connection_index(int);
int rt_msg_client_idisconnect(unsigned short id)
{
    void *c = 0;
    int x = 0;
    unsigned char st = D_004908EC;
    int r;
    unsigned int i;
    void *q, *e;
    if (st != 1) return 5;
    r = rt_msg_client_get_connection(id, &c);
    if (r != 0) return r;
    if (c != 0) {
    if (F(c, int, 8) != st) {
        if (F(c, int, 8) == 8) {
            q = F(c, void *, 0x80);
            if (q != 0 && rt_circ_buf_get_used((char *)q + 0x68, &x) == 0) {
                if (x != 0) {
                    rt_msg_client_set_scratch_buf_min_size(x);
                    if (rt_circ_buf_copy(D_004908F8, (char *)q + 0x68, x) == 0)
                        rt_msg_client_send_buffer(q, D_004908F8, x, 10000);
                }
                rt_msg_client_change_state(c, 9);
                rt_msg_client_send_disconnect(q);
            }
        }
        rt_msg_client_change_state(c, 10);
        for (i = 0; i < 2; i++) {
            q = ((struct { char pad[0x70]; void *arr[2]; } *)((char *)c + 8))->arr[i];
            if (q) rt_comm_destroy(F(q, int, 0x1C));
        }
        rt_msg_client_change_state(c, 1);
    }
    rt_msg_client_free_connection_index(id);
    }
    return 0;
}
/* merge_units: end func_002FCE88 */

/* merge_units: begin func_002FCFE8 */
extern unsigned short D_004908F0;
extern int rt_msg_client_is_valid_connection_id(unsigned short);
extern int rt_msg_client_idisconnect(unsigned short);
int rt_msg_client_idisconnect_all(void)
{
    unsigned int i = 0;
    int r;
    if (D_004908EC != 1) return 5;
    for (; i < D_004908F0; i++) {
        if (rt_msg_client_is_valid_connection_id(i) == 1) {
            r = rt_msg_client_idisconnect(i);
            if (r) return r;
        }
    }
    return 0;
}
/* merge_units: end func_002FCFE8 */
