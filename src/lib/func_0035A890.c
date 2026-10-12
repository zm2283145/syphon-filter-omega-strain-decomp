#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *func_003581E0(int),*func_00358480(int);
extern void func_003581C0(void),func_00358500(void *,void *);
extern int func_00358158(void),func_003583A0(void *,int),func_00358578(int),func_00358558(int);
extern int func_0034B180(void *,int,int,int,void *,int);
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



