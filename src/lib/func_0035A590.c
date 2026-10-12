#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int), *func_00358480(int);
extern void func_003581C0(void);
extern int func_00358158(void), func_003583A0(void *, int), func_00358578(int), func_00359728(void *, void *);
extern int func_0034B180(void *, void *, void *, int, void *, int);
extern void func_003584B8(void *, const void *);

int func_0035A590(int fd, int level, int optname, const void *optval, unsigned int optlen)
{
    char buf[16];
    char b12[32];
    char b13[32];
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
        if (F(sock,12,int) == 0) return func_003583A0(ctx, 0x6D);
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
        } else if (optname == 12) {
            len = 8;
        } else if (optname == 13) {
            len = 8;
        } else {
            return func_003583A0(ctx, 0x6D);
        }
        r = func_00359728(ctx, sock);
        if (r) return func_003583A0(ctx, r);
    } else {
        return func_003583A0(ctx, 0x6D);
    }
ok:
    if (!optval || optlen < len) return func_003583A0(ctx, 0x16);
    func_003581C0();
    if (level == 6 && optname == 1) {
        tmp = *(int *)optval != 0;
        r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 3, &tmp, 4);
    } else if (level == 0) {
        if (optname == 9) {
            func_003584B8(buf, optval);
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 4, buf, 0x10);
        } else if (optname == 10) {
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 6, (void *)optval, len);
        } else if (optname == 11) {
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 8, (void *)optval, len);
        } else if (optname == 12) {
            func_003584B8(b12, optval);
            func_003584B8(b12 + 16, (char *)optval + 4);
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 10, b12, 0x20);
        } else if (optname == 13) {
            func_003584B8(b13, optval);
            func_003584B8(b13 + 16, (char *)optval + 4);
            r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 11, b13, 0x20);
        }
    }
    if (func_00358158() < 0) return func_003583A0(ctx, -1);
    if (r < 0) return func_003583A0(ctx, func_00358578(r));
    return func_003583A0(ctx, 0);
}

