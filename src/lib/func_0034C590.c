extern int IopRing_Send(int a, int b, int c, int d, int e, int g, int *out, int *err);
int sceBInetSendTo(void *cd, void *buf, int a, int b, int c, int *d, int e, int g, int h)
{
    int out = 0;
    int err = -0x1F5;
    if (cd == 0 || h < -1 || buf == 0) return -0x1F5;
    if (c == 0) return 0;
    if (IopRing_Send(a, b, c, *d, e, g, &out, &err) == 0) return out;
    return err ? err : -0x1F5;
}