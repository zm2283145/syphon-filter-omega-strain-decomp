typedef struct Alarm { struct Alarm *next; struct Alarm *prev; int id; unsigned int flags; unsigned long x10; unsigned long x18; unsigned long x20; unsigned long (*handler)(int,unsigned long,unsigned long,void *,void *); void *gp; void *arg; } Alarm;
typedef struct { volatile unsigned long a; int id; int seq; int cnt; Alarm *free; Alarm *head; int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00116A80(unsigned int);
extern Alarm *func_00117008(Alarm *);
extern void func_00116F80(Alarm *);
extern void func_00116DF0(unsigned long);
#define T1_COUNT (*(volatile unsigned int *)0x10001000)
#define T1_MODE (*(volatile unsigned int *)0x10001010)
static inline unsigned long GetTime(void){
 unsigned int cnt=T1_COUNT,mode=T1_MODE;
 if(mode&0x800){D_00487848.a++;func_00116A80(mode&~0x400);cnt=T1_COUNT;}
 return ((D_00487848.a<<16)|cnt)<<((mode&3)*4);
}
int func_00117040(int cause,void *arg,void *addr){
 Alarm *a,*next;unsigned long now,target,r;
 if(T1_MODE&0x400){
  a=D_00487848.head;
  while(a){
   target=a->x20+a->x10-a->x18;
   now=GetTime();
   if(now<target)break;
   next=func_00117008(a);
   now=now+a->x18-a->x10;
   D_00487848.cur=((int)a<<4)|a->id;
   /* load the alarm owner's $gp before the callback (no C equivalent) */
   {__asm__ volatile("lw $gp, %0"::"m"(a->gp));
   r=a->handler(((int)a<<4)|a->id,a->x20,now,a->arg,addr);}
   if(r==0)a->flags&=~2;
   else if(r==-1){a->next=D_00487848.free;D_00487848.free=a;a->flags=0;a->id=0;}
   else{if(r<0x3999)r=0x3999;a->x20+=r;func_00116F80(a);}
   a=next;
  }
 }
 D_00487848.cur=-1;
 func_00116DF0(GetTime());
 GetTime();
 /* re-enable interrupts on exit (COP0) */
 __asm__ volatile("sync\n\tei");
 return 0;
}
