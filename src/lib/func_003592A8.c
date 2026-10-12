#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
extern void func_003581C0(void);
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
