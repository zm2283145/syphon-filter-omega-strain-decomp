#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
extern void func_003581C0(void);
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int);
extern int func_0034B138(void *,int,int,int);
static inline int finish8A10(void *ctx,int err,int site){
 int r=func_003583A0(ctx,err);
 /* Preserve each error-return boundary without emitting instructions.
    The two list walks intentionally share their boundary (site 3). */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int func_00358A10(int fd,int mode){
 void *ctx=func_003581E0(0),*sock,*p;
 int r;
 if(!ctx)return -1;
 sock=func_00358480(fd);
 if(!sock)return finish8A10(ctx,9,0);
 if(F(sock,12,int)){
  func_003581C0();
  r=func_0034B138((char *)ctx+20,F(ctx,84,int),F(sock,12,int),mode);
  if(func_00358158()<0)return finish8A10(ctx,-1,1);
  if(r<0)return finish8A10(ctx,func_00358578(r),2);
 }
 for(p=F(sock,80,void *);p;p=F(p,0,void *)){
  if(F(p,12,int)){
   func_003581C0();
   func_0034B138((char *)ctx+20,F(ctx,84,int),F(p,12,int),mode);
   if(func_00358158()<0)return finish8A10(ctx,-1,3);
  }
 }
 for(p=F(sock,88,void *);p;p=F(p,0,void *)){
  if(F(p,12,int)){
   func_003581C0();
   func_0034B138((char *)ctx+20,F(ctx,84,int),F(p,12,int),mode);
   if(func_00358158()<0)return finish8A10(ctx,-1,3);
  }
 }
 func_003583A0(ctx,0);
 return 0;
}


