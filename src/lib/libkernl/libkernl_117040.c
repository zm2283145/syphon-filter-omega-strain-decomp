/*
 * lib/libkernl: 7 files, 00117040-00117508
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00117040 */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; int id; unsigned int flags; unsigned long x10; unsigned long x18; unsigned long x20; unsigned long (*handler)(int,unsigned long,unsigned long,void *,void *); void *gp; void *arg; } Alarm;
typedef struct { volatile unsigned long a; int id; int seq; int cnt; Alarm *free; Alarm *head; int cur; } TimCtl;
extern TimCtl D_00487848;
extern void SetT2_MODE(unsigned int);
extern Alarm *UnlinkAlarm(Alarm *);
extern void InsertAlarm(Alarm *);
extern void SetNextComp(unsigned long);
#define T1_COUNT (*(volatile unsigned int *)0x10001000)
#define T1_MODE (*(volatile unsigned int *)0x10001010)
static inline unsigned long GetTime(void){
 unsigned int cnt=T1_COUNT,mode=T1_MODE;
 if(mode&0x800){D_00487848.a++;SetT2_MODE(mode&~0x400);cnt=T1_COUNT;}
 return ((D_00487848.a<<16)|cnt)<<((mode&3)*4);
}
int cbTimerHandler(int cause,void *arg,void *addr){
 Alarm *a,*next;unsigned long now,target,r;
 if(T1_MODE&0x400){
  a=D_00487848.head;
  while(a){
   target=a->x20+a->x10-a->x18;
   now=GetTime();
   if(now<target)break;
   next=UnlinkAlarm(a);
   now=now+a->x18-a->x10;
   D_00487848.cur=((int)a<<4)|a->id;
   /* load the alarm owner's $gp before the callback (no C equivalent) */
   {__asm__ volatile("lw $gp, %0"::"m"(a->gp));
   r=a->handler(((int)a<<4)|a->id,a->x20,now,a->arg,addr);}
   if(r==0)a->flags&=~2;
   else if(r==-1){a->next=D_00487848.free;D_00487848.free=a;a->flags=0;a->id=0;}
   else{if(r<0x3999)r=0x3999;a->x20+=r;InsertAlarm(a);}
   a=next;
  }
 }
 D_00487848.cur=-1;
 SetNextComp(GetTime());
 GetTime();
 /* re-enable interrupts on exit (COP0) */
 __asm__ volatile("sync\n\tei");
 return 0;
}
/* merge_units: end func_00117040 */

/* merge_units: begin func_001172E0 */
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; void *free; void *head; volatile int cur; } TimCtl_001172E0;
#if 0 /* merge_units */
extern TimCtl_001172E0 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_001172E0*)&D_00487848) /* merge_units */


unsigned long iGetTimerSystemTime(void)
{
    unsigned long t;
    /* SDK inline asm: read T1 count and overflow with fixed t0-t2 scratch */
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "lwu %0, 0(%1)\n\t"
        "lw $8, 0x10(%1)\n\t"
        "ld $10, %2\n\t"
        "andi $9, $8, 0x800\n\t"
        "beqz $9, 1f\n\t"
        "addiu $9, $0, 2\n\t"
        "lwu %0, 0(%1)\n\t"
        "daddiu $10, $10, 1\n"
        "1:\n\t"
        "andi $8, $8, 3\n\t"
        "dsll $10, $10, 16\n\t"
        "movz $9, $0, $8\n\t"
        "or %0, %0, $10\n\t"
        "dsllv $9, $9, $8\n\t"
        "dsllv %0, %0, $9\n\t"
        ".set pop"
        : "=&r"(t) : "r"(0x10001000), "m"(D_00487848.a) : "$8", "$9", "$10");
    return t;
}
#undef D_00487848 /* merge_units */
/* merge_units: end func_001172E0 */

/* merge_units: begin func_00117330 */
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; void *free; void *head; volatile int cur; } TimCtl_00117330;
#if 0 /* merge_units */
extern TimCtl_00117330 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_00117330*)&D_00487848) /* merge_units */

extern int DIntr(void);
extern int EIntr(void);

unsigned long GetTimerSystemTime(void)
{
    unsigned long t;
    int s = DIntr();
    /* SDK inline asm: read T1 count and overflow atomically with fixed t0-t2 scratch */
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "lwu %0, 0(%1)\n\t"
        "lw $8, 0x10(%1)\n\t"
        "ld $10, %2\n\t"
        "andi $9, $8, 0x800\n\t"
        "beqz $9, 1f\n\t"
        "addiu $9, $0, 2\n\t"
        "lwu %0, 0(%1)\n\t"
        "daddiu $10, $10, 1\n"
        "1:\n\t"
        "andi $8, $8, 3\n\t"
        "dsll $10, $10, 16\n\t"
        "movz $9, $0, $8\n\t"
        "or %0, %0, $10\n\t"
        "dsllv $9, $9, $8\n\t"
        "dsllv %0, %0, $9\n\t"
        ".set pop"
        : "=&r"(t) : "r"(0x10001000), "m"(D_00487848.a) : "$8", "$9", "$10");
    if (s) EIntr();
    return t;
}
#undef D_00487848 /* merge_units */
/* merge_units: end func_00117330 */

/* merge_units: begin func_001173B0 */
typedef struct Alarm_001173B0 { struct Alarm_001173B0 *next; struct Alarm_001173B0 *prev; volatile int id; int flags; unsigned long long x10; unsigned long long x18; unsigned long long x20; unsigned long (*x28)(int); } Alarm_001173B0;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm_001173B0 *free; Alarm_001173B0 *head; volatile int cur; } TimCtl_001173B0;
#if 0 /* merge_units */
extern TimCtl_001173B0 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_001173B0*)&D_00487848) /* merge_units */


int iAllocTimerCounter(void)
{
    Alarm_001173B0 *a = D_00487848.free;
    if (!a) return 0x80008005;
    D_00487848.cnt++;
    a->x28 = 0;
    a->flags = 0;
    D_00487848.free = a->next;
    a->x18 = 0;
    D_00487848.seq++;
    a->id = ((D_00487848.seq << 1) & 0x3FE) | 1;
    return ((int)a << 4) | a->id;
}
#undef D_00487848 /* merge_units */
/* merge_units: end func_001173B0 */

/* merge_units: begin func_00117420 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
int DIntr();
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */
                                
#if 0 /* merge_units */
int EIntr();
#endif /* merge_units */
#define EIntr() (EIntr()) /* merge_units */
                                  
#if 0 /* merge_units */
int iAllocTimerCounter();
#endif /* merge_units */
#define iAllocTimerCounter() (iAllocTimerCounter()) /* merge_units */
                                

int AllocTimerCounter(void) {
    int temp_s0;
    int temp_s1;

    temp_s0 = DIntr();
    temp_s1 = iAllocTimerCounter();
    if (temp_s0 != 0) {
        EIntr();
    }
    return temp_s1;
}
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
#undef iAllocTimerCounter /* merge_units */
/* merge_units: end func_00117420 */

/* merge_units: begin func_00117468 */
typedef struct Alarm_00117468 { struct Alarm_00117468 *next; struct Alarm_00117468 *prev; volatile int id; int flags; unsigned long long x10; unsigned long long x18; unsigned long long x20; int x28; } Alarm_00117468;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm_00117468 *free; Alarm_00117468 *head; volatile int cur; } TimCtl_00117468;
#if 0 /* merge_units */
extern TimCtl_00117468 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_00117468*)&D_00487848) /* merge_units */

#if 0 /* merge_units */
extern void UnlinkAlarm(Alarm_00117468 *);
#endif /* merge_units */
#define UnlinkAlarm(a0) ((void)UnlinkAlarm((Alarm *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern unsigned long long iGetTimerSystemTime(void);
#endif /* merge_units */
#define iGetTimerSystemTime() ((unsigned long long)iGetTimerSystemTime()) /* merge_units */

#if 0 /* merge_units */
extern void InsertAlarm(Alarm_00117468 *);
#endif /* merge_units */
#define InsertAlarm(a0) (InsertAlarm((Alarm *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void SetNextComp(unsigned long long);
#endif /* merge_units */
#define SetNextComp(a0) (SetNextComp((unsigned long)(a0))) /* merge_units */

int iFreeTimerCounter(int id)
{
    Alarm_00117468 *a = (Alarm_00117468 *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (a->flags & 2) UnlinkAlarm(a);
    a->id = 0;
    a->flags = 0;
    a->next = D_00487848.free;
    D_00487848.free = a;
    D_00487848.cnt--;
    return 0;
}
#undef D_00487848 /* merge_units */
#undef UnlinkAlarm /* merge_units */
#undef iGetTimerSystemTime /* merge_units */
#undef InsertAlarm /* merge_units */
#undef SetNextComp /* merge_units */
/* merge_units: end func_00117468 */

/* merge_units: begin func_00117508 */
#if 0 /* merge_units */
extern int iFreeTimerCounter(int);
#endif /* merge_units */
#define iFreeTimerCounter(a0) (iFreeTimerCounter((a0))) /* merge_units */

int FreeTimerCounter(int a)
{
    int s = DIntr();
    int r = iFreeTimerCounter(a);
    if (s) EIntr();
    return r;
}
#undef iFreeTimerCounter /* merge_units */
/* merge_units: end func_00117508 */
