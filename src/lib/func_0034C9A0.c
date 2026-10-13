typedef struct { void *a; void *b; int n; int z; } NetReq_9A0;
extern void FlushCache(int a);
extern int sceSifSetDma(NetReq_9A0 *req, int n);
extern int sceSifDmaStat(int h);
int func_0034C9A0(void *a, void *b, int n)
{
    NetReq_9A0 req;
    int h;
    int ret = 2;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (n == 0) return ret;
    FlushCache(0);
    req.a = a; req.b = b; req.n = n; req.z = 0;
    h = sceSifSetDma(&req, 1);
    ret = 4;
    if (h == 0) return ret;
    while (sceSifDmaStat(h) >= 0) ;
    return 0;
}