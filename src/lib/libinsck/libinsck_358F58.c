/*
 * lib/libinsck: 5 files, 00358F58-00359728
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358F58 */
#define FIELD(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
extern int func_003583A0(void *,int),func_00358530(int),func_00358578(int);
extern void func_003584B8(void *,void *),func_003581C0(void);
extern int func_00358158(void);
extern int func_0034ACC8(void *,int,void *),func_0034AD40(void *,int,int,int);
static inline int finish8F58(void *ctx,int err){
 int r=func_003583A0(ctx,err);
 /* The retail wrapper returns after publishing the socket error. */
 __asm__ volatile("" ::: "memory");
 return r;
}
int func_00358F58(int fd,void *addr,int size){
 void *ctx=func_003581E0(0),*sock,*lock;
 int r;
 if(!ctx)return -1;
 sock=func_00358480(fd);
 if(!sock)return finish8F58(ctx,9);
 if(size!=16)return finish8F58(ctx,22);
 if(FIELD(addr,1,unsigned char)!=2)return finish8F58(ctx,106);
 func_003584B8((char *)sock+24,(char *)addr+4);
 FIELD(sock,40,int)=func_00358530(FIELD(addr,2,unsigned short));
 if(!FIELD(sock,20,int))FIELD(sock,20,int)=-1;
 lock=(char *)ctx+20;
 func_003581C0();
 r=func_0034ACC8(lock,FIELD(ctx,84,int),(char *)sock+16);
 if(func_00358158()<0)return finish8F58(ctx,-1);
 if(r<=0)return finish8F58(ctx,func_00358578(r));
 FIELD(sock,12,int)=r;
 func_003581C0();
 r=func_0034AD40(lock,FIELD(ctx,84,int),FIELD(sock,12,int),-1);
 if(func_00358158()<0)return finish8F58(ctx,-1);
 if(r<0)return finish8F58(ctx,func_00358578(r));
 return finish8F58(ctx,0);
}
/* merge_units: end func_00358F58 */

/* merge_units: begin func_003590C0 */
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
typedef struct { int w[16]; } Blob;
extern int func_00358678(void);
extern void *func_00357D50(int);
extern void func_00357D88(void *);
extern void *memset(void *, int, unsigned int);
extern void func_003581C0(void);
extern int func_00358578(int);
extern int func_0034ACC8(void *, int, void *);
extern int func_0034AD40(void *, int, int, int);

int func_003590C0(void *ctx, void *s)
{
    int r = func_00358678();
    void *n = func_00357D50(0x6C);
    void *t;
    if (n == 0) return 0xC;
    memset(n, 0, 0x6C);
    F(n,8,int) = r;
    F(n,16,Blob) = F(s,16,Blob);
    F(n,0x60,int) = -1;
    F(n,0x64,int) = -1;
    F(n,0x68,int) = -1;
    t = F(s,0x54,void *);
    F(n,4,void *) = t;
    if (t) F(t,0,void *) = n;
    else F(s,0x50,void *) = n;
    F(n,0,void *) = 0;
    F(s,0x54,void *) = n;
    func_003581C0();
    r = func_0034ACC8((char *)ctx + 0x14, F(ctx,0x54,int), (char *)n + 0x10);
    if (func_00358158() < 0) return -1;
    if (r <= 0) {
        if (F(n,0,void *)) F(F(n,0,void *),4,void *) = F(n,4,void *);
        else F(s,0x54,void *) = F(n,4,void *);
        if (F(n,4,void *)) F(F(n,4,void *),0,void *) = F(n,0,void *);
        else F(s,0x50,void *) = F(n,0,void *);
        func_00357D88(n);
        goto err;
    }
    F(n,0xC,int) = r;
    func_003581C0();
    r = func_0034AD40((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), 0);
    if (func_00358158() < 0) return -1;
    if (r < 0 && r != -500) {
    err:
        return func_00358578(r);
    }
    return 0;
}
/* merge_units: end func_003590C0 */

/* merge_units: begin func_003592A8 */
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int),func_003590C0(void *,void *);
extern int func_0034B180(void *,int,int,int,void *,int);
static inline int finish92A8(void *ctx,int err,int site){
 int r=func_003583A0(ctx,err);
 /* Keep distinct error boundaries; this compiler barrier emits no code. */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int func_003592A8(int fd,int count){
 int info[19];
 void *ctx=func_003581E0(0),*sock;
 int i,r;
 if(!ctx)return -1;
 sock=func_00358480(fd);
 if(!sock)return finish92A8(ctx,9,0);
 if(F(sock,16,int)!=1)return finish92A8(ctx,95,0);
 F(sock,16,int)=2;
 if(!F(sock,20,int))F(sock,20,int)=-1;
 for(i=0;i<count;i++){
  r=func_003590C0(ctx,sock);
  if(r)return finish92A8(ctx,r,1);
  if(i==0 && F(sock,20,int)==-1){
   func_003581C0();
   r=func_0034B180((char *)ctx+20,F(ctx,84,int),F(F(sock,80,void *),12,int),1,info,76);
   if(func_00358158()<0)return finish92A8(ctx,-1,2);
   if(r<0)return finish92A8(ctx,func_00358578(r),3);
   F(sock,20,int)=info[8];
  }
 }
 return finish92A8(ctx,0,0);
}
/* merge_units: end func_003592A8 */

/* merge_units: begin func_00359430 */
extern int func_0034AD88(void *, int, int, int);
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
/* merge_units: end func_00359430 */

/* merge_units: begin func_00359728 */
typedef struct { char pad[0x14]; char x14[0x40]; void *x54; } Sock9728;
typedef struct { char pad[0xC]; int xC; int x10; int x14; char x18[0x10]; int x28; } Req9728;

int func_00359728(Sock9728 *s, Req9728 *r)
{
    int n;
    if (r->xC != 0) return 0;
    if (r->x10 != 0 && r->x10 != 3) return 0x80;
    memset(r->x18, 0, 0x10);
    r->x28 = 0;
    if (r->x14 == 0) r->x14 = -1;
    n = func_0034ACC8(s->x14, (int)s->x54, &r->x10);
    if (n > 0) {
        r->xC = n;
        n = func_0034AD40(s->x14, (int)s->x54, n, -1);
        if (n >= 0) goto ok;
    }
    return func_00358578(n);
ok:
    return 0;
}
/* merge_units: end func_00359728 */
