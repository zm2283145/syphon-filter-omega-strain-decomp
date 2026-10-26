/*
 * lib/medius: 27 files, 002FB840-002FC928
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FB840 */
extern unsigned char D_00490900;
extern short D_004908EE;
extern char D_005297F0[];
extern int RecursiveLock_Acquire(void *, int);
extern int RecursiveLock_Release(void *, int);
extern int rt_mutex_destroy(void *);
extern int rt_msg_client_ishutdown(void);
int rt_msg_client_shutdown(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_ishutdown();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    if (r == 0 && D_004908EE == 0) {
        if (rt_mutex_destroy(D_005297F0)) return 0x1A;
        D_00490900 = 0;
    }
    return r;
}
/* merge_units: end func_002FB840 */

/* merge_units: begin func_002FB8F0 */
extern int rt_msg_client_iecho_shutdown(void);
int rt_msg_client_echo_shutdown(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iecho_shutdown();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB8F0 */

/* merge_units: begin func_002FB968 */
extern int rt_msg_client_ienable_echo(void *);
int rt_msg_client_enable_echo(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_ienable_echo(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB968 */

/* merge_units: begin func_002FB9F8 */
extern int NetSession_CreateSockets(void *, void *);
int rt_msg_client_connect(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = NetSession_CreateSockets(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FB9F8 */

/* merge_units: begin func_002FBA98 */
extern int rt_msg_client_idisconnect(unsigned short);
int rt_msg_client_disconnect(unsigned short a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_idisconnect(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBA98 */

/* merge_units: begin func_002FBB28 */
extern int rt_msg_client_idisconnect_all(void);
int rt_msg_client_disconnect_all(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_idisconnect_all();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBB28 */

/* merge_units: begin func_002FBBA0 */
extern int rt_msg_client_iupdate(unsigned short, unsigned char);
int rt_msg_client_update(unsigned short a, unsigned char b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iupdate(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBBA0 */

/* merge_units: begin func_002FBC40 */
extern int rt_msg_client_iecho_update(void);
int rt_msg_client_echo_update(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iecho_update();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBC40 */

/* merge_units: begin func_002FBCB8 */
extern int rt_msg_client_iupdate_all(unsigned char);
int rt_msg_client_update_all(unsigned char a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iupdate_all(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBCB8 */

/* merge_units: begin func_002FBD48 */
extern int rt_msg_client_isend_target(unsigned short, unsigned short, void *, void *, unsigned short);
int rt_msg_client_send_target(unsigned short a, unsigned short b, void *c, void *d, unsigned short e)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_isend_target(a, b, c, d, e);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBD48 */

/* merge_units: begin func_002FBE18 */
extern int rt_msg_client_isend_client_set(unsigned short, unsigned short, unsigned short, void *, void *, void *, unsigned short);
int rt_msg_client_send_client_set(unsigned short a, unsigned short b, unsigned short c, void *d, void *e, void *f, unsigned short g)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_isend_client_set(a, b, c, d, e, f, g);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBE18 */

/* merge_units: begin func_002FBF08 */
extern int rt_msg_client_isend_echo(void *, void *, unsigned short);
int rt_msg_client_send_echo(void *a, void *b, unsigned short c)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_isend_echo(a, b, c);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBF08 */

/* merge_units: begin func_002FBFB8 */
extern int rt_msg_client_iget_buffer_status(unsigned short, void *, void *, void *, void *);
int rt_msg_client_get_buffer_status(unsigned short a, void *b, void *c, void *d, void *e)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_buffer_status(a, b, c, d, e);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FBFB8 */

/* merge_units: begin func_002FC088 */
extern int rt_msg_client_iget_local_ip(void *);
int rt_msg_client_get_local_ip(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_local_ip(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC088 */

/* merge_units: begin func_002FC118 */
extern int rt_msg_client_iget_broadcast_ip(void *);
int rt_msg_client_get_broadcast_ip(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_broadcast_ip(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC118 */

/* merge_units: begin func_002FC1A8 */
extern int rt_msg_client_iget_host_by_name(void *, void *);
int rt_msg_client_get_host_by_name(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_host_by_name(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC1A8 */

/* merge_units: begin func_002FC248 */
extern int rt_msg_client_iget_connection_ip(unsigned short, void *);
int rt_msg_client_get_connection_ip(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_connection_ip(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC248 */

/* merge_units: begin func_002FC2E8 */
extern int rt_msg_client_ireceive_broadcasts(unsigned short, unsigned char);
int rt_msg_client_receive_broadcasts(unsigned short a, unsigned char b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_ireceive_broadcasts(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC2E8 */

/* merge_units: begin func_002FC388 */
extern int rt_msg_client_iget_metrics(void *, void *);
int rt_msg_client_get_metrics(void *a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_metrics(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC388 */

/* merge_units: begin func_002FC428 */
extern int rt_msg_client_iset_send_aggregation_time(unsigned short, void *);
int rt_msg_client_set_send_aggregation_time(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iset_send_aggregation_time(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC428 */

/* merge_units: begin func_002FC4C8 */
extern int rt_msg_client_iset_server_send_aggregation_time(unsigned short, void *);
int rt_msg_client_set_server_send_aggregation_time(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iset_server_send_aggregation_time(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC4C8 */

/* merge_units: begin func_002FC568 */
extern int rt_msg_client_iset_default_connect_options(void *);
int rt_msg_client_set_default_connect_options(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iset_default_connect_options(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC568 */

/* merge_units: begin func_002FC5F8 */
extern int rt_msg_client_iecho_set_default_options(void *);
int rt_msg_client_echo_set_default_options(void *a)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iecho_set_default_options(a);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC5F8 */

/* merge_units: begin func_002FC688 */
extern int rt_msg_client_idisplay_comm_state(void);
int rt_msg_client_display_comm_state(void)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_idisplay_comm_state();
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC688 */

/* merge_units: begin func_002FC700 */
extern int rt_msg_client_iget_interface_data(unsigned short, void *);
int rt_msg_client_get_interface_data(unsigned short a, void *b)
{
    int r = 1;
    if (D_00490900 != 1) return 0x1A;
    if (RecursiveLock_Acquire(D_005297F0, 0)) return 0x1A;
    r = rt_msg_client_iget_interface_data(a, b);
    if (RecursiveLock_Release(D_005297F0, 0)) return 0x1A;
    return r;
}
/* merge_units: end func_002FC700 */

/* merge_units: begin func_002FC7A0 */
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern int *D_004908F4;
extern int D_004908F8;
extern int D_004908FC;
extern unsigned char D_005297E0;
extern int rt_msg_client_is_valid_connection_id(unsigned short);
extern int rt_msg_client_free_connection_index(unsigned short);
#if 0 /* merge_units */
extern void rt_msg_client_iecho_shutdown(void);
#endif /* merge_units */
#define rt_msg_client_iecho_shutdown() ((void)rt_msg_client_iecho_shutdown()) /* merge_units */

extern int rt_comm_shutdown(void);
extern int rt_msg_client_map_comm_error(int);
extern int rt_memory_free(void *);
extern void KM_Cleanup(int);
int rt_msg_client_ishutdown(void)
{
    unsigned short i = 0;
    int r;
    if (D_004908EE <= 0) return 5;
    if (D_004908EC != 1) return 5;
    if (D_004908EE == 1) {
        for (; i < D_004908F0; i++) {
            if (D_004908F4[i]) {
                if (rt_msg_client_is_valid_connection_id(i) == 1) rt_msg_client_idisconnect(i);
                else rt_msg_client_free_connection_index(i);
            }
        }
        if (D_005297E0 == 1) rt_msg_client_iecho_shutdown();
        r = rt_msg_client_map_comm_error(rt_comm_shutdown());
        if (r) return r;
        if (D_004908F4) rt_memory_free(&D_004908F4);
        D_004908F4 = 0;
        D_004908F0 = 0;
        if (D_004908F8) {
            rt_memory_free(&D_004908F8);
            D_004908FC = 0;
        }
        KM_Cleanup(0);
        D_004908EC = 0;
    }
    D_004908EE--;
    return 0;
}
#undef rt_msg_client_iecho_shutdown /* merge_units */
/* merge_units: end func_002FC7A0 */

/* merge_units: begin func_002FC928 */
typedef struct { unsigned char on; char pad[3]; int h; } S2FC928;
#if 0 /* merge_units */
extern S2FC928 D_005297E0;
#endif /* merge_units */
#define D_005297E0 (*(S2FC928*)&D_005297E0) /* merge_units */

extern void rt_comm_destroy(int);
int rt_msg_client_iecho_shutdown(void)
{
    if (D_005297E0.on != 1) return 5;
    rt_comm_destroy(D_005297E0.h);
    D_005297E0.on = 0;
    return 0;
}
#undef D_005297E0 /* merge_units */
/* merge_units: end func_002FC928 */
