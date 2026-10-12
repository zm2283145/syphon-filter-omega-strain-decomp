#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
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
