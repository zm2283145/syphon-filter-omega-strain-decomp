typedef struct {
    char pad0[0xC];
    unsigned int state;
    char pad10[0x10];
    int h20;
    int h24;
    int cb28;
    int cb2C;
} Conn_2D9C10;
extern int AudioSendTo(int, char *, int, int, int);
int AudioSendToPlayer(int o, char *buf, int n, Conn_2D9C10 *cc)
{
    unsigned int st;
    int ret;
    Conn_2D9C10 *c;
    c = cc;
    ret = n;
    st = c->state;
    if (c->h20 != 0) {
        if (st == 2 || st == 0) {
            if (c->cb28 == 0)
                return -1;
            ret = AudioSendTo(o, buf, n, c->h20, c->cb28);
        }
    }
    if (c->h24 != 0 && st < 2) {
        int r;
        if (c->cb2C == 0)
            return -1;
        r = AudioSendTo(o, buf, n, c->h24, c->cb2C);
        if (r != n)
            ret = r;
    }
    return ret;
}


