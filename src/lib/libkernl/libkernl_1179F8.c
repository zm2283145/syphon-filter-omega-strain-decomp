/*
 * lib/libkernl: 6 files, 001179F8-00117CD8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001179F8 */
extern int DIntr(void);
extern int EIntr(void);
extern int iGetTimerCount(int);
int GetTimerCount(int a)
{
    int s = DIntr();
    int r = iGetTimerCount(a);
    if (s) EIntr();
    return r;
}
/* merge_units: end func_001179F8 */

/* merge_units: begin func_00117A48 */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; void *h; int gp; void *arg; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void UnlinkAlarm(Alarm *);
extern long long iGetTimerSystemTime(void);
extern void SetNextComp(long long);
extern void InsertAlarm(Alarm *);

int iSetTimerHandler(int id, long long t, void *h, void *arg)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (a->flags & 2) UnlinkAlarm(a);
    a->h = h;
    if (h == 0) {
        a->flags &= ~2;
    } else {
        a->flags |= 2;
        a->x20 = t;
        __asm__ volatile ("sw $gp, %0" : "=m" (a->gp) : : "memory");
        a->arg = arg;
        if (a->flags & 1) InsertAlarm(a);
    }
    SetNextComp(iGetTimerSystemTime());
    return 0;
}
/* merge_units: end func_00117A48 */

/* merge_units: begin func_00117B40 */
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
int iSetTimerHandler(int, int, int, int);
#endif /* merge_units */
#define iSetTimerHandler(a0, a1, a2, a3) (iSetTimerHandler((a0), (long long)(a1), (void *)(a2), (void *)(a3))) /* merge_units */
                    

int SetTimerHandler(int arg0, int arg1, int arg2, int arg3) {
    int temp_s0;
    int temp_s4;

    temp_s4 = DIntr();
    temp_s0 = iSetTimerHandler(arg0, arg1, arg2, arg3);
    if (temp_s4 != 0) {
        EIntr();
    }
    return temp_s0;
}
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
#undef iSetTimerHandler /* merge_units */
/* merge_units: end func_00117B40 */

/* merge_units: begin func_00117BC0 */
extern long Libgcc_Udivdi3(long, long);

void TimerBusClock2USec(long t, int *sec, int *usec)
{
    int q = Libgcc_Udivdi3(t, 0x8CA0000);
    if (sec) *sec = q;
    if (usec) *usec = Libgcc_Udivdi3((t - (unsigned long)(unsigned int)q * 0x8CA0000u) * 1000000, 0x8CA0000);
}
/* merge_units: end func_00117BC0 */

/* merge_units: begin func_00117C68 */
long TimerUSec2BusClock(unsigned int sec, unsigned int usec)
{
    unsigned long t = (unsigned long)sec * 0x8CA0000u;
    return t + Libgcc_Udivdi3((unsigned long)usec * 0x8CA0000u, 1000000);
}
/* merge_units: end func_00117C68 */

/* merge_units: begin func_00117CD8 */
/* libgcc __floatdisf is the retail SoftFloat_S64ToFloat */
__asm__("__floatdisf = SoftFloat_S64ToFloat");
float TimerBusClock2Freq(unsigned long x)
{
    float f = (float)x;
    float r;
    /* div.s after the li.s mtc1: the SCE assembler pads the cop1 hazard with two nops */
    __asm__("nop\n\tnop\n\tdiv.s %0, %1, %2" : "=f"(r) : "f"(147456000.0f), "f"(f));
    return r;
}
/* merge_units: end func_00117CD8 */
