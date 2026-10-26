extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_channel(void);
extern int rt_time_start(void *tm);
extern int rt_time_elapsed(void *tm, unsigned int *elapsed);
extern int Socket_Write(int sock, unsigned char *data, int len, unsigned short *done);
int rt_msg_client_send_buffer(int sock_, unsigned char *data, int len, unsigned int timeout)
{
    /* pinned copy: retail keeps sock in s3 and timeout in s4 (as rt_p2p_handle_connect_event) */
    register int sock asm("$19") = sock_;
    char tm[16];
    unsigned int elapsed = 0;
    unsigned short done = 0;
    unsigned char st = D_004908EC;
    int r;
    if (st != 1) return 5;
    if (rt_msg_client_is_valid_channel() != st) return 2;
    if (data == 0) return 2;
    if (rt_time_start(tm) != 0) return 0x18;
    do {
        r = Socket_Write(sock, data, len, &done);
        if (r != 0) return r;
        len -= done;
        data += done;
        if (rt_time_elapsed(tm, &elapsed) != 0) return 0x18;
        if (timeout < elapsed) return 0xD;
    } while (len != 0);
    return 0;
}
