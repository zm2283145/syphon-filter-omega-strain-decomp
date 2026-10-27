/*
 * lib/libinsck: 2 files, 00358A10-00358BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358A10 */
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *thread_enter(int),*socket_info(int);
extern void unblock(void);
extern int func_00358158(void),thread_leave(void *,int),conv_errno(int);
extern int sceInetAbort(void *,int,int,int);
static inline int finish8A10(void *ctx,int err,int site){
 int r=thread_leave(ctx,err);
 /* Preserve each error-return boundary without emitting instructions.
    The two list walks intentionally share their boundary (site 3). */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int sceInsockAbort(int fd,int mode){
 void *ctx=thread_enter(0),*sock,*p;
 int r;
 if(!ctx)return -1;
 sock=socket_info(fd);
 if(!sock)return finish8A10(ctx,9,0);
 if(F(sock,12,int)){
  unblock();
  r=sceInetAbort((char *)ctx+20,F(ctx,84,int),F(sock,12,int),mode);
  if(func_00358158()<0)return finish8A10(ctx,-1,1);
  if(r<0)return finish8A10(ctx,conv_errno(r),2);
 }
 for(p=F(sock,80,void *);p;p=F(p,0,void *)){
  if(F(p,12,int)){
   unblock();
   sceInetAbort((char *)ctx+20,F(ctx,84,int),F(p,12,int),mode);
   if(func_00358158()<0)return finish8A10(ctx,-1,3);
  }
 }
 for(p=F(sock,88,void *);p;p=F(p,0,void *)){
  if(F(p,12,int)){
   unblock();
   sceInetAbort((char *)ctx+20,F(ctx,84,int),F(p,12,int),mode);
   if(func_00358158()<0)return finish8A10(ctx,-1,3);
  }
 }
 thread_leave(ctx,0);
 return 0;
}
/* merge_units: end func_00358A10 */

/* merge_units: begin func_00358BB0 */
typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; void *x50; } N81E0;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern int D_00492CCC;
extern int D_00492CC8;
extern void sceLibnetTerminate(void *);
extern void my_free(void *);
#if 0 /* merge_units */
extern int unblock(void);
#endif /* merge_units */
#define unblock() ((int)unblock()) /* merge_units */

extern int func_00358158(void);
extern int GetThreadId(void);
extern int DeleteSema(int);
void thread_terminate(N81E0 *n)
{
    N81E0 *x = n->next;
    if (n->prev) n->prev->next = x;
    else D_00492CD0 = x;
    if (n->next) n->next->prev = n->prev;
    else D_00492CD4 = n->prev;
    sceLibnetTerminate(n->x14);
    my_free(n->x50);
    my_free(n);
    D_00492CCC--;
}
#undef unblock /* merge_units */
/* merge_units: end func_00358BB0 */
