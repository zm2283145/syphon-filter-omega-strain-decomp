/*
 * lib/libinsck: 3 files, 0035A300-0035A890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035A300 */
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
/* merge_units: end func_0035A300 */

/* merge_units: begin func_0035A590 */
#if 0 /* merge_units */
extern int func_0034B180(void *, void *, void *, int, void *, int);
#endif /* merge_units */
#define func_0034B180(a0, a1, a2, a3, a4, a5) (func_0034B180((a0), (int)(a1), (int)(a2), (a3), (a4), (a5))) /* merge_units */

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
#undef func_0034B180 /* merge_units */
/* merge_units: end func_0035A590 */

/* merge_units: begin func_0035A890 */
extern void func_003581C0(void),func_00358500(void *,void *);
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int),func_00358558(int);
static inline int finishA890(void *ctx,int err){
 int r=func_003583A0(ctx,err);
 /* Return after publishing the socket error. */
 __asm__ volatile("" ::: "memory");
 return r;
}
int func_0035A890(int fd,void *addr,unsigned int *len,int peer){
 int info[19],r,port,id;
 void *ctx=func_003581E0(0),*sock,*head;
 if(!ctx)return -1;
 if(*len<16)return finishA890(ctx,22);
 sock=func_00358480(fd);
 if(!sock)return finishA890(ctx,9);
 if(!F(sock,12,int)){
  if(peer)return finishA890(ctx,22);
  if(F(sock,16,int)!=2 || !(head=F(sock,80,void *)) || (id=F(head,12,int),sock=head,!id))return finishA890(ctx,9);
 }
 func_003581C0();
 r=func_0034B180((char *)ctx+20,F(ctx,84,int),F(sock,12,int),1,info,76);
 if(func_00358158()<0)return finishA890(ctx,-1);
 if(r<0)return finishA890(ctx,func_00358578(r));
 F(addr,1,unsigned char)=2;
 if(peer){func_00358500((char *)addr+4,info+9);port=info[13];}
 else{func_00358500((char *)addr+4,info+4);port=info[8];}
 F(addr,2,unsigned short)=func_00358558(port);
 /* Publish the converted port before the address length. */
 __asm__ volatile("" ::: "memory");
 *len=16;
 return finishA890(ctx,0);
}
/* merge_units: end func_0035A890 */
