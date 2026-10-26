extern int libnetb_send_echo(int a, unsigned short b, int c, int *out, int *err);
int sceBInetSendEcho(void *cd, void *buf, int a, unsigned short b, int c)
{
    int out = 0;
    int err = -0x1F5;
    if (cd == 0) return -0x1F5;
    if (libnetb_send_echo(a, b, c, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}