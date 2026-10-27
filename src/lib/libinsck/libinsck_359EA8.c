typedef struct Sock9EA8 { struct Sock9EA8 *next,*prev; int fd,id; char params[64]; struct Sock9EA8 *head,*tail; int x58,x5c,a,b,timeout; } Sock9EA8;
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *thread_enter(int);
extern Sock9EA8 *socket_info(int),*D_00492CD8,*D_00492CDC;
extern void unblock(void),my_free(void *);
extern int func_00358158(void),thread_leave(void *,int),conv_errno(int);
extern int sceInetClose(void *,int,int,int);
static inline int finish9EA8(void *ctx,int err,int site){
 int r=thread_leave(ctx,err);
 /* Keep the list-cleanup error boundary distinct without emitted code. */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int sceInsockShutdown(int fd){
 void *ctx=thread_enter(0);
 Sock9EA8 *sock,*p,*prev;
 int r;
 if(!ctx)return -1;
 sock=socket_info(fd);
 if(!sock)return finish9EA8(ctx,9,0);
 r=0;
 if(sock->id){
  unblock();
  r=sceInetClose((char *)ctx+20,F(ctx,84,int),sock->id,sock->timeout);
  if(func_00358158()<0)return finish9EA8(ctx,-1,0);
 }
 prev=sock->prev;
 if(sock->next)sock->next->prev=prev;else D_00492CDC=prev;
 if(sock->prev)sock->prev->next=sock->next;else D_00492CD8=sock->next;
 while((p=sock->head)){
  sock->head=p->next;
  if(p->id){
   unblock();
   sceInetClose((char *)ctx+20,F(ctx,84,int),p->id,0);
   if(func_00358158()<0)return finish9EA8(ctx,-1,1);
  }
  my_free(p);
 }
 my_free(sock);
 if(r<0)return finish9EA8(ctx,conv_errno(r),0);
 return finish9EA8(ctx,0,0);
}
