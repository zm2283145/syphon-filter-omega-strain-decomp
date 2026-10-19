typedef struct Sock9EA8 { struct Sock9EA8 *next,*prev; int fd,id; char params[64]; struct Sock9EA8 *head,*tail; int x58,x5c,a,b,timeout; } Sock9EA8;
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *Insck_GetThreadContext(int);
extern Sock9EA8 *Insck_FindSocket(int),*D_00492CD8,*D_00492CDC;
extern void func_003581C0(void),func_00357D88(void *);
extern int func_00358158(void),Insck_SetErrno(void *,int),Insck_MapLibnetError(int);
extern int func_0034AD88(void *,int,int,int);
static inline int finish9EA8(void *ctx,int err,int site){
 int r=Insck_SetErrno(ctx,err);
 /* Keep the list-cleanup error boundary distinct without emitted code. */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int Insck_Close(int fd){
 void *ctx=Insck_GetThreadContext(0);
 Sock9EA8 *sock,*p,*prev;
 int r;
 if(!ctx)return -1;
 sock=Insck_FindSocket(fd);
 if(!sock)return finish9EA8(ctx,9,0);
 r=0;
 if(sock->id){
  func_003581C0();
  r=func_0034AD88((char *)ctx+20,F(ctx,84,int),sock->id,sock->timeout);
  if(func_00358158()<0)return finish9EA8(ctx,-1,0);
 }
 prev=sock->prev;
 if(sock->next)sock->next->prev=prev;else D_00492CDC=prev;
 if(sock->prev)sock->prev->next=sock->next;else D_00492CD8=sock->next;
 while((p=sock->head)){
  sock->head=p->next;
  if(p->id){
   func_003581C0();
   func_0034AD88((char *)ctx+20,F(ctx,84,int),p->id,0);
   if(func_00358158()<0)return finish9EA8(ctx,-1,1);
  }
  func_00357D88(p);
 }
 func_00357D88(sock);
 if(r<0)return finish9EA8(ctx,Insck_MapLibnetError(r),0);
 return finish9EA8(ctx,0,0);
}
