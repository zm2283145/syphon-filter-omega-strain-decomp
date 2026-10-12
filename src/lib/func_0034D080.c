extern int sceSifMCallRpc(int, int, int, void *, int, void *, int, void *, void *);
extern int func_0034A418(int, unsigned int);
int func_0034D080(int cd, int *buf)
{
    int r;
    buf[0] = 0;
    buf[8] = (int)buf;
    buf[9] = 0;
    buf[1] = 0;
    if (sceSifMCallRpc(cd, 0x64, 0, buf, 0x50, buf, 0x50, 0, 0) < 0) return 1;
    if (buf[13] == 0 || buf[13] == 3) {
        if ((unsigned int)buf[6] < (unsigned int)(buf[2] + 0x40)) return 1;
        r = func_0034A418(buf[7], buf[6]);
        if (r != 0) return r;
    }
    return 0;
}
