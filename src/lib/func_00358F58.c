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
