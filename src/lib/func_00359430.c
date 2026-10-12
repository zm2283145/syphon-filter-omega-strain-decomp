#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int), *func_00358480(int);
extern void func_003581C0(void);
extern int func_00358158(void), func_003583A0(void *, int), func_00358578(int), func_003590C0(void *, void *);
extern int func_0034AD40(void *, int, int, int);
extern int func_0034AD88(void *, int, int, int);
extern int func_0034B180(void *, int, int, int, void *, int);
extern void func_00357D88(void *);
extern void func_00358500(void *, void *);
extern short func_00358558(int);
struct Req;
extern struct Req *D_00492CD8;
extern struct Req *D_00492CDC;

int func_00359430(int fd, char *addr, unsigned int *len)
{
    int info[19];
    void *ctx = func_003581E0(0), *sock, *n, *t;
    int r;
    if (!ctx) return -1;
    if (*len < 16) return func_003583A0(ctx, 0x16);
    sock = func_00358480(fd);
    if (!sock) return func_003583A0(ctx, 9);
    if (F(sock,16,int) != 2) return func_003583A0(ctx, 0x5F);
    n = F(sock,0x50,void *);
    if (!n) return func_003583A0(ctx, -1);
    if ((F(sock,0x50,void *) = F(n,0,void *)) != 0) F(F(n,0,void *),4,void *) = 0;
    else F(sock,0x54,void *) = 0;
    t = F(sock,0x58,void *);
    F(n,0,void *) = t;
    if (t) F(t,4,void *) = n;
    else F(sock,0x5C,void *) = n;
    F(n,4,void *) = 0;
    F(sock,0x58,void *) = n;
    func_003581C0();
    r = func_0034AD40((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), -1);
    if (func_00358158() < 0) {
        r = -1;
        goto unlinkA;
    }
    if (r < 0 && r != -0x1FB) {
        r = func_00358578(r);
        goto unlinkA;
    }
    if (F(n,4,void *)) F(F(n,4,void *),0,void *) = F(n,0,void *);
    else F(sock,0x58,void *) = F(n,0,void *);
    if (F(n,0,void *)) F(F(n,0,void *),4,void *) = F(n,4,void *);
    else F(sock,0x5C,void *) = F(n,4,void *);
    t = D_00492CD8;
    F(n,0,void *) = t;
    if (t) F(t,4,void *) = n;
    else D_00492CDC = n;
    F(n,4,void *) = 0;
    D_00492CD8 = n;
    r = func_003590C0(ctx, sock);
    if (r) goto unlinkB;
    func_003581C0();
    r = func_0034B180((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), 1, info, 0x4C);
    if (func_00358158() < 0) {
        r = -1;
        goto unlinkB;
    }
    if (r < 0) {
        r = func_00358578(r);
        goto unlinkB;
    }
    addr[1] = 2;
    func_00358500(addr + 4, (char *)info + 0x24);
    F(addr,2,short) = func_00358558(info[13]);
    *len = 0x10;
    func_003583A0(ctx, 0);
    return F(n,8,int);
unlinkA:
    if (F(n,4,void *)) F(F(n,4,void *),0,void *) = F(n,0,void *);
    else F(sock,0x58,void *) = F(n,0,void *);
    if (F(n,0,void *)) F(F(n,0,void *),4,void *) = F(n,4,void *);
    else F(sock,0x5C,void *) = F(n,4,void *);
    func_0034AD88((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), 0);
    func_00357D88(n);
    return func_003583A0(ctx, r);
unlinkB:
    {
    void *p = F(n,4,void *), *x = F(n,0,void *);
    if (p) {
        F(p,0,void *) = x;
        x = F(n,0,void *);
        p = F(n,4,void *);
    } else D_00492CD8 = x;
    if (x) F(x,4,void *) = p;
    else D_00492CDC = p;
    }
    func_0034AD88((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), 0);
    func_00357D88(n);
    return func_003583A0(ctx, r);
}



