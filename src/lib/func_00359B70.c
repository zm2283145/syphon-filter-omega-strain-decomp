#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
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
