/*
 * lib/medius: 3 files, 002FD980-002FDA18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD980 */
extern unsigned char D_004908EC;
extern int rt_comm_display_state(void);
extern int rt_msg_client_map_comm_error(int);
int rt_msg_client_idisplay_comm_state(void)
{
    int r;
    if (D_004908EC != 1)
        return 5;
    r = rt_msg_client_map_comm_error(rt_comm_display_state());
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD980 */

/* merge_units: begin func_002FD9B8 */
extern int rt_msg_client_get_valid_connection(unsigned short, char **);
extern int rt_comm_get_interface_data(int, int);
int rt_msg_client_iget_interface_data(unsigned short a, int b)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    r = rt_msg_client_get_valid_connection(a, &p);
    if (r) return r;
    r = rt_msg_client_map_comm_error(rt_comm_get_interface_data(*(int *)(*(char **)(p + 0x80) + 0x1C), b));
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD9B8 */

/* merge_units: begin func_002FDA18 */
typedef struct {
    unsigned short id; short pad;
    int f4;
    int f8;
    char pad2[0x84 - 0xC];
    void (*cb)(unsigned short, int, int, int, int);
} O;
#if 0 /* merge_units */
extern int rt_msg_client_get_valid_connection(unsigned short, O **);
#endif /* merge_units */
#define rt_msg_client_get_valid_connection(a0, a1) (rt_msg_client_get_valid_connection((a0), (char * *)(a1))) /* merge_units */

extern int rt_msg_client_update_connection(O *, unsigned char);
extern int rt_msg_client_is_waiting_to_connect(int);
extern int rt_msg_client_is_valid_connection_id(unsigned short);
extern int rt_msg_client_change_state(O *, int);
int rt_msg_client_update_single(unsigned short id, unsigned char k)
{
    O *o[1];
    int r;
    o[0] = 0;
    r = rt_msg_client_get_valid_connection(id, o);
    if (r) return r;
    r = rt_msg_client_update_connection(o[0], k);
    if (r != 0 && k == 1 && rt_msg_client_is_waiting_to_connect(o[0]->f8) == 1) {
    if (o[0]->cb) {
        unsigned short h = o[0]->id;
        o[0]->cb(id, 0, 0, 0, 1);
        if (rt_msg_client_is_valid_connection_id(h) == 0) return 0xB;
    }
    rt_msg_client_change_state(o[0], 0xB);
    }
    return r;
}
#undef rt_msg_client_get_valid_connection /* merge_units */
/* merge_units: end func_002FDA18 */
