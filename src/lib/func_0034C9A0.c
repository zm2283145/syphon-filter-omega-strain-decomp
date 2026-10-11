typedef struct { void *a; void *b; int n; int z; } NetReq_9A0;
extern void func_0010D3E0(int a);
extern int func_0010D520(NetReq_9A0 *req, int n);
extern int func_0010D500(int h);
int func_0034C9A0(void *a, void *b, int n)
{
    NetReq_9A0 req;
    int h;
    int ret = 2;
    if (a == 0) return ret;
    if (b == 0) return ret;
    if (n == 0) return ret;
    func_0010D3E0(0);
    req.a = a; req.b = b; req.n = n; req.z = 0;
    h = func_0010D520(&req, 1);
    ret = 4;
    if (h == 0) return ret;
    while (func_0010D500(h) >= 0) ;
    return 0;
}