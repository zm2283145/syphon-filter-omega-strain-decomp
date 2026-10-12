#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int), *func_00358480(int);
extern void func_003581C0(void);
extern int func_00358158(void), func_003583A0(void *, int), func_00358578(int), func_00359728(void *, void *);
extern int func_0034B180(void *, int, int, int, void *, int);
extern void func_00358500(void *, void *);

int func_0035A300(int fd, int level, int optname, void *optval, unsigned int *optlen)
{
    char buf[16];
    int tmp;
    void *ctx, *sock;
    int r = -1;
    unsigned int len;
    int st;
    ctx = func_003581E0(0);
    if (!ctx) return -1;
    sock = func_00358480(fd);
    if (!sock) return func_003583A0(ctx, 9);
    if (level == 6) {
        if (F(sock,12,int) == 0) return func_003583A0(ctx, 9);
        st = F(sock,16,int);
        if (st == 1 || st == 2) {
            len = 4;
            if (optname == 1) goto ok;
        }
        return func_003583A0(ctx, 0x6D);
    } else if (level == 0) {
        if (F(sock,16,int)) return func_003583A0(ctx, 0x6D);
        if (optname == 9) {
            len = 4;
        } else if (optname == 10) {
            len = 4;
        } else if (optname == 11) {
            len = 4;
        } else {
            return func_003583A0(ctx, 0x6D);
        }
        r = func_00359728(ctx, sock);
        if (r) return func_003583A0(ctx, r);
    } else {
        return func_003583A0(ctx, 0x6D);
    }
ok:
    if (!optval || !optlen || *optlen < len) return func_003583A0(ctx, 0x16);
    func_003581C0();
    if (level == 6 && optname == 1) {
        r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 2, &tmp, 4);
        *(int *)optval = tmp & 1;
    } else if (level == 0) {
        if (optname == 9) {
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 5, buf, 0x10);
            func_00358500(optval, buf);
        } else if (optname == 10) {
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 7, optval, 4);
        } else if (optname == 11) {
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 9, optval, 4);
        }
    }
    if (func_00358158() < 0) return func_003583A0(ctx, -1);
    if (r < 0) return func_003583A0(ctx, func_00358578(r));
    *optlen = len;
    return func_003583A0(ctx, 0);
}



