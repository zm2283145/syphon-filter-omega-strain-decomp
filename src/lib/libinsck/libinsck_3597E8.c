/*
 * lib/libinsck: 4 files, 003597E8-00359CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003597E8 */
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
/* merge_units: end func_003597E8 */

/* merge_units: begin func_00359998 */
extern int func_0034ADD0(void *, int, int, void *, unsigned int, int *, int);
static inline int finish9998(void *ctx, int err, int site)
{
    int r = func_003583A0(ctx, err);
    __asm__ volatile("" :: "i"(site) : "memory");
    return r;
}
long func_00359998(int fd, char *buf, unsigned int len, int flags)
{
    int opt;
    void *ctx, *sock;
    int total = 0;
    int chunk;
    int nb;
    int r;
    ctx = func_003581E0(0);
    if (!ctx) return -1;
    sock = func_00358480(fd);
    if (!sock) return finish9998(ctx, 9, 0);
    if (F(sock,16,int) == 0 || F(sock,16,int) == 3) {
        if (F(ctx,0x58,unsigned int) < len) return finish9998(ctx, 0x16, 0);
    }
    r = func_00359728(ctx, sock);
    if (r) return finish9998(ctx, r, 0);
    opt = 0;
    nb = flags & 0x40;
    while (len) {
        chunk = len;
        if (F(ctx,0x58,unsigned int) < len) chunk = F(ctx,0x58,unsigned int);
        func_003581C0();
        r = func_0034ADD0((char *)ctx + 0x14, F(ctx,0x54,int), F(sock,12,int), buf, chunk, &opt, F(sock,0x60,int));
        if (func_00358158() < 0) return finish9998(ctx, -1, 1);
        if (r < 0) return finish9998(ctx, func_00358578(r), 1);
        buf += r;
        len -= r;
        total += r;
        if (opt & 6) break;
        if (nb && (F(sock,16,int) == 1 || F(sock,16,int) == 2)) continue;
        if (r < chunk) break;
    }
    if (total == 0 && F(sock,0x60,int) >= 0 && !(opt & 4)) return finish9998(ctx, 0xB, 0);
    func_003583A0(ctx, 0);
    return total;
}
/* merge_units: end func_00359998 */

/* merge_units: begin func_00359B70 */
extern void func_003581C0(void),func_003584B8(void *,void *);
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int),func_00359728(void *,void *),func_00358530(int);
extern int func_0034B050(void *,int,int,void *,unsigned int,int *,void *,int,int);
static inline int error9B70(void *ctx,int err){ int r=func_003583A0(ctx,err); /* Return after error publication. */ __asm__ volatile("" ::: "memory"); return r; }
long func_00359B70(int fd,void *buf,unsigned int len,int flags,void *dest){
 int addr[4],out;
 void *ctx=func_003581E0(0),*sock;
 int r,err;
 if(!ctx)return -1;
 sock=func_00358480(fd);
 if(!sock)return error9B70(ctx,9);
 if(F(sock,16,int)!=0 && F(sock,16,int)!=3)return error9B70(ctx,95);
 if(F(ctx,88,unsigned int)<len)return error9B70(ctx,22);
 r=func_00359728(ctx,sock);
 if(r)return error9B70(ctx,r);
 out=0;
 func_003584B8(addr,(char *)dest+4);
 r=func_00358530(F(dest,2,unsigned short));
 func_003581C0();
 r=func_0034B050((char *)ctx+20,F(ctx,84,int),F(sock,12,int),buf,len,&out,addr,r,F(sock,100,int));
 if(func_00358158()<0)return error9B70(ctx,-1);
 if(r<0)return error9B70(ctx,func_00358578(r));
 func_003583A0(ctx,0);
 return r;
}
/* merge_units: end func_00359B70 */

/* merge_units: begin func_00359CE0 */
extern void func_003581C0(void),func_003584B8(void *,void *),func_00358500(void *,void *);
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int),func_00359728(void *,void *),func_00358530(int),func_00358558(int);
extern int func_0034AE98(void *,int,int,void *,unsigned int,int *,void *,int *,int);
static inline int error9CE0(void *ctx,int err){
 int r=func_003583A0(ctx,err);
 /* Return after publishing the receive error. */
 __asm__ volatile("" ::: "memory");
 return r;
}
long func_00359CE0(int fd,void *buf,unsigned int len,int flags,void *addr,unsigned int *addrlen){
 int ip[4],out,port;
 void *ctx=func_003581E0(0),*sock,*addrdata;
 int r;
 if(!ctx)return -1;
 if(*addrlen<16)return error9CE0(ctx,22);
 sock=func_00358480(fd);
 if(!sock)return error9CE0(ctx,9);
 if(F(sock,16,int)!=0 && F(sock,16,int)!=3)return error9CE0(ctx,95);
 if(F(ctx,88,unsigned int)<len)return error9CE0(ctx,22);
 r=func_00359728(ctx,sock);
 if(r)return error9CE0(ctx,r);
 addrdata=(char *)addr+4;
 out=0;
 func_003584B8(ip,addrdata);
 port=func_00358530(F(addr,2,unsigned short));
 func_003581C0();
 r=func_0034AE98((char *)ctx+20,F(ctx,84,int),F(sock,12,int),buf,len,&out,ip,&port,F(sock,96,int));
 if(func_00358158()<0)return error9CE0(ctx,-1);
 if(r<0)return error9CE0(ctx,func_00358578(r));
 F(addr,1,unsigned char)=2;
 func_00358500(addrdata,ip);
 F(addr,2,unsigned short)=func_00358558(port);
 *addrlen=16;
 func_003583A0(ctx,0);
 return r;
}
/* merge_units: end func_00359CE0 */
