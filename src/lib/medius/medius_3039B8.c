extern void rt_p2p_handle_read_event(void *o, int a, int b);
extern void rt_p2p_handle_write_event(void *o, int a, int b);
extern void rt_p2p_handle_connect_event(void *o, int a, int b);
extern void rt_p2p_handle_accept_event(void *o, int a, int b);
extern void rt_p2p_handle_connected_event(void *o, int a, int b);
extern void rt_p2p_handle_resolve_event(void *o, int a, int b);
extern void rt_p2p_handle_timeout_event(void *o, int a, int b);
extern void rt_p2p_handle_reset_event(void *o, int a, int b);
extern void rt_p2p_handle_closed_event(void *o, int a, int b);
extern void rt_p2p_handle_error_event(void *o, int a, int b);

void rt_udp_event_cb(int unused, int a, int code, int b, void *o)
{
    if (o == 0) return;
    switch (code) {
    case 0: rt_p2p_handle_read_event(o, a, b); break;
    case 1: rt_p2p_handle_write_event(o, a, b); break;
    case 2: rt_p2p_handle_connect_event(o, a, b); break;
    case 3: rt_p2p_handle_accept_event(o, a, b); break;
    case 4: rt_p2p_handle_connected_event(o, a, b); break;
    case 5: rt_p2p_handle_resolve_event(o, a, b); break;
    case 6: rt_p2p_handle_timeout_event(o, a, b); break;
    case 7: rt_p2p_handle_reset_event(o, a, b); break;
    case 8: rt_p2p_handle_closed_event(o, a, b); break;
    case 9: rt_p2p_handle_error_event(o, a, b); break;
    }
}
