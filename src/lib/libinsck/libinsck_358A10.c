/*
 * lib/libinsck: 2 files, 00358A10-00358BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358A10 */
#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void *Insck_GetThreadContext(int),*Insck_FindSocket(int);
extern void func_003581C0(void);
extern int func_00358158(void),Insck_SetErrno(void *,int),Insck_MapLibnetError(int);
extern int func_0034B138(void *,int,int,int);
static inline int finish8A10(void *ctx,int err,int site){
 int r=Insck_SetErrno(ctx,err);
 /* Preserve each error-return boundary without emitting instructions.
    The two list walks intentionally share their boundary (site 3). */
 __asm__ volatile("" :: "i"(site) : "memory");
 return r;
}
int Insck_Shutdown(int fd,int mode){
 void *ctx=Insck_GetThreadContext(0),*sock,*p;
 int r;
 if(!ctx)return -1;
 sock=Insck_FindSocket(fd);
 if(!sock)return finish8A10(ctx,9,0);
 if(F(sock,12,int)){
  func_003581C0();
  r=func_0034B138((char *)ctx+20,F(ctx,84,int),F(sock,12,int),mode);
  if(func_00358158()<0)return finish8A10(ctx,-1,1);
  if(r<0)return finish8A10(ctx,Insck_MapLibnetError(r),2);
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
 Insck_SetErrno(ctx,0);
 return 0;
}
/* merge_units: end func_00358A10 */

/* merge_units: begin func_00358BB0 */
typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; void *x50; } N81E0;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern int D_00492CCC;
extern int D_00492CC8;
extern void func_0034B7E8(void *);
extern void func_00357D88(void *);
#if 0 /* merge_units */
extern int func_003581C0(void);
#endif /* merge_units */
#define func_003581C0() ((int)func_003581C0()) /* merge_units */

extern int func_00358158(void);
extern int GetThreadId(void);
extern int DeleteSema(int);
void func_00358BB0(N81E0 *n)
{
    N81E0 *x = n->next;
    if (n->prev) n->prev->next = x;
    else D_00492CD0 = x;
    if (n->next) n->next->prev = n->prev;
    else D_00492CD4 = n->prev;
    func_0034B7E8(n->x14);
    func_00357D88(n->x50);
    func_00357D88(n);
    D_00492CCC--;
}
#undef func_003581C0 /* merge_units */
/* merge_units: end func_00358BB0 */
