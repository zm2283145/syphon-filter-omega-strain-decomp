/*
 * lib/libinsck: 3 files, 0035A300-0035A890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035A300 */
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *thread_enter(int), *socket_info(int);
extern void unblock(void);
extern int func_00358158(void), thread_leave(void *, int), conv_errno(int), connect_check(void *, void *);
extern int sceInetControl(void *, int, int, int, void *, int);
extern void conv_addr_from_inet(void *, void *);

int sceInsockGetsockopt(int fd, int level, int optname, void *optval, unsigned int *optlen)
{
    char buf[16];
    int tmp;
    void *ctx, *sock;
    int r = -1;
    unsigned int len;
    int st;
    ctx = thread_enter(0);
    if (!ctx) return -1;
    sock = socket_info(fd);
    if (!sock) return thread_leave(ctx, 9);
    if (level == 6) {
        if (F(sock,12,int) == 0) return thread_leave(ctx, 9);
        st = F(sock,16,int);
        if (st == 1 || st == 2) {
            len = 4;
            if (optname == 1) goto ok;
        }
        return thread_leave(ctx, 0x6D);
    } else if (level == 0) {
        if (F(sock,16,int)) return thread_leave(ctx, 0x6D);
        if (optname == 9) {
            len = 4;
        } else if (optname == 10) {
            len = 4;
        } else if (optname == 11) {
            len = 4;
        } else {
            return thread_leave(ctx, 0x6D);
        }
        r = connect_check(ctx, sock);
        if (r) return thread_leave(ctx, r);
    } else {
        return thread_leave(ctx, 0x6D);
    }
ok:
    if (!optval || !optlen || *optlen < len) return thread_leave(ctx, 0x16);
    unblock();
    if (level == 6 && optname == 1) {
        r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 2, &tmp, 4);
        *(int *)optval = tmp & 1;
    } else if (level == 0) {
        if (optname == 9) {
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 5, buf, 0x10);
            conv_addr_from_inet(optval, buf);
        } else if (optname == 10) {
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 7, optval, 4);
        } else if (optname == 11) {
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), 9, optval, 4);
        }
    }
    if (func_00358158() < 0) return thread_leave(ctx, -1);
    if (r < 0) return thread_leave(ctx, conv_errno(r));
    *optlen = len;
    return thread_leave(ctx, 0);
}
/* merge_units: end func_0035A300 */

/* merge_units: begin func_0035A590 */
#if 0 /* merge_units */
extern int sceInetControl(void *, void *, void *, int, void *, int);
#endif /* merge_units */
#define sceInetControl(a0, a1, a2, a3, a4, a5) (sceInetControl((a0), (int)(a1), (int)(a2), (a3), (a4), (a5))) /* merge_units */

extern void conv_addr_to_inet(void *, const void *);

int sceInsockSetsockopt(int fd, int level, int optname, const void *optval, unsigned int optlen)
{
    char buf[16];
    char b12[32];
    char b13[32];
    int tmp;
    void *ctx, *sock;
    int r = -1;
    unsigned int len;
    int st;
    ctx = thread_enter(0);
    if (!ctx) return -1;
    sock = socket_info(fd);
    if (!sock) return thread_leave(ctx, 9);
    if (level == 6) {
        if (F(sock,12,int) == 0) return thread_leave(ctx, 0x6D);
        st = F(sock,16,int);
        if (st == 1 || st == 2) {
            len = 4;
            if (optname == 1) goto ok;
        }
        return thread_leave(ctx, 0x6D);
    } else if (level == 0) {
        if (F(sock,16,int)) return thread_leave(ctx, 0x6D);
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
            return thread_leave(ctx, 0x6D);
        }
        r = connect_check(ctx, sock);
        if (r) return thread_leave(ctx, r);
    } else {
        return thread_leave(ctx, 0x6D);
    }
ok:
    if (!optval || optlen < len) return thread_leave(ctx, 0x16);
    unblock();
    if (level == 6 && optname == 1) {
        tmp = *(int *)optval != 0;
        r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 3, &tmp, 4);
    } else if (level == 0) {
        if (optname == 9) {
            conv_addr_to_inet(buf, optval);
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 4, buf, 0x10);
        } else if (optname == 10) {
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 6, (void *)optval, len);
        } else if (optname == 11) {
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 8, (void *)optval, len);
        } else if (optname == 12) {
            conv_addr_to_inet(b12, optval);
            conv_addr_to_inet(b12 + 16, (char *)optval + 4);
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 10, b12, 0x20);
        } else if (optname == 13) {
            conv_addr_to_inet(b13, optval);
            conv_addr_to_inet(b13 + 16, (char *)optval + 4);
            r = sceInetControl((char *)ctx + 0x14, F(ctx,0x54,void *), F(sock,12,void *), 11, b13, 0x20);
        }
    }
    if (func_00358158() < 0) return thread_leave(ctx, -1);
    if (r < 0) return thread_leave(ctx, conv_errno(r));
    return thread_leave(ctx, 0);
}
#undef sceInetControl /* merge_units */
/* merge_units: end func_0035A590 */

/* merge_units: begin func_0035A890 */
extern void unblock(void),conv_addr_from_inet(void *,void *);
extern int func_00358158(void),thread_leave(void *,int),conv_errno(int),conv_port_from_inet(int);
static inline int finishA890(void *ctx,int err){
 int r=thread_leave(ctx,err);
 /* Return after publishing the socket error. */
 __asm__ volatile("" ::: "memory");
 return r;
}
int _get_peer_or_sock_name(int fd,void *addr,unsigned int *len,int peer){
 int info[19],r,port,id;
 void *ctx=thread_enter(0),*sock,*head;
 if(!ctx)return -1;
 if(*len<16)return finishA890(ctx,22);
 sock=socket_info(fd);
 if(!sock)return finishA890(ctx,9);
 if(!F(sock,12,int)){
  if(peer)return finishA890(ctx,22);
  if(F(sock,16,int)!=2 || !(head=F(sock,80,void *)) || (id=F(head,12,int),sock=head,!id))return finishA890(ctx,9);
 }
 unblock();
 r=sceInetControl((char *)ctx+20,F(ctx,84,int),F(sock,12,int),1,info,76);
 if(func_00358158()<0)return finishA890(ctx,-1);
 if(r<0)return finishA890(ctx,conv_errno(r));
 F(addr,1,unsigned char)=2;
 if(peer){conv_addr_from_inet((char *)addr+4,info+9);port=info[13];}
 else{conv_addr_from_inet((char *)addr+4,info+4);port=info[8];}
 F(addr,2,unsigned short)=conv_port_from_inet(port);
 /* Publish the converted port before the address length. */
 __asm__ volatile("" ::: "memory");
 *len=16;
 return finishA890(ctx,0);
}
/* merge_units: end func_0035A890 */
