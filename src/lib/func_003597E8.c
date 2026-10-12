#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int), *func_00358480(int);
extern void func_003581C0(void);
extern int func_00358158(void), func_003583A0(void *, int), func_00358578(int), func_00359728(void *, void *);
extern int func_0034AFA8(void *, int, int, void *, unsigned int, int *, int);
static inline int finish97E8(void *ctx, int err, int site)
{
    int r = func_003583A0(ctx, err);
    __asm__ volatile("" :: "i"(site) : "memory");
    return r;
}
long func_003597E8(int fd, char *buf, unsigned int len, int flags)
{
    int opt;
    void *ctx, *sock;
    int total = 0;
    int chunk;
    int r;
    ctx = func_003581E0(0);
    if (!ctx) return -1;
    sock = func_00358480(fd);
    if (!sock) return finish97E8(ctx, 9, 0);
    if (F(sock,16,int) == 0 || F(sock,16,int) == 3) {
        if (F(ctx,0x58,unsigned int) < len) return finish97E8(ctx, 0x16, 0);
    }
    r = func_00359728(ctx, sock);
    if (r) return finish97E8(ctx, r, 0);
    if (flags & 1) opt = 2;
    else opt = 0;
    while (len) {
        chunk = F(ctx,0x58,unsigned int) < len ? F(ctx,0x58,unsigned int) : len;
        func_003581C0();
        r = func_0034AFA8((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), buf, chunk, &opt, F(sock,0x64,int));
        if (func_00358158() < 0) return finish97E8(ctx, -1, 1);
        if (r < 0) return finish97E8(ctx, func_00358578(r), 1);
        buf += r;
        len -= r;
        total += r;
        if (r < chunk) break;
    }
    if (total == 0 && F(sock,0x64,int) >= 0) return finish97E8(ctx, 0xB, 0);
    func_003583A0(ctx, 0);
    return total;
}

