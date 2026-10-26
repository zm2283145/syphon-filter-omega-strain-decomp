typedef struct { unsigned int v[100]; unsigned int cnt; int pos; char lock[4]; } Q;
typedef struct { char pad[0x444]; int n; } S;
extern int D_0048C450;
extern int NetGetConnInfo(int, S **);
extern int NetGetClientPingInfo(int, Q **);
extern int NetIGetSessionMasterClientIndex(int *, int);
int __attribute__((weak, section(".dtors_drop"))) NetIGetTime(int *p0) { return 0; }
extern int NetGetPercentileDelayToClient(int *, int);
extern int NetResetTime(char *);
extern int rt_time_get_time_stamp(void *);

void TimeBasePingCallback(int err, void *msg, unsigned int len, char *data, int sess, int idx)
{
    S *s = 0;
    Q *q;
    int t;
    int a;
    int b;
    int n;
    int h;

    if (NetGetConnInfo(sess, &s) != 0) return;
    if (s == 0) return;
    if (sess != D_0048C450) return;
    if (idx >= s->n) return;
    if (err != 0) return;
    t = 0x100;
    q = 0;
    NetGetClientPingInfo(idx, &q);
    h = len >> 1;
    if (q == 0) return;
    n = q->pos;
    q->v[n++] = h;
    if (q->cnt < 100) q->cnt++;
    NetIGetSessionMasterClientIndex(&t, sess);
    if (sess == D_0048C450 && idx == t && data != 0) {
        NetIGetTime(&a);
        NetGetPercentileDelayToClient(&b, idx);
        if (b >= h) NetResetTime(data + h);
    }
    if (n >= 100) n = 0;
    q->pos = n;
    rt_time_get_time_stamp(q->lock);
}




