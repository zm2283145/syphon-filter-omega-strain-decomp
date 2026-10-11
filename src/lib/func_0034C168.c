typedef struct { int a; int b; int id; } NetObj_168;
extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
extern int func_0034D028(NetObj_168 *p);
extern int func_002FB3C0(NetObj_168 **pp);
int func_0034C168(void *cd, int *buf, NetObj_168 *p, int x)
{
    NetObj_168 *q;
    int r;
    if (p == 0) return -0x200;
    buf[0] = p->id;
    buf[1] = x;
    q = p;
    r = sceSifMCallRpc(cd, 0x66, 0, buf, 16, buf, 16, 0, 0);
    if (func_0034D028(q) != 0 || func_002FB3C0(&q) != 0) return -0x1F5;
    return r < 0 ? -0x1F5 : 0;
}