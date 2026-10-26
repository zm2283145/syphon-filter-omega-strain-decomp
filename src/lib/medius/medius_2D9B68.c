extern int D_00588060;
extern int D_00588064;
extern void rt_audio_iptostring(int, char *);
extern int rt_udp_send_unconnected(int, char *, unsigned short, int, unsigned short);
int AudioSendTo(char *s, int b, int c, int d, int e)
{
    char buf[16];
    rt_audio_iptostring(d, buf);
    if (rt_udp_send_unconnected(*(int *)(s + 0x8C), buf, e, b, c)) {
        D_00588064 += c;
        return -1;
    }
    D_00588060 += c;
    return c;
}
