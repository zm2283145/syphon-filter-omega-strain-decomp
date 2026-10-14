/*
 * lib/libkernl: 6 files, 0010DE60-0010E1C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DE60 */
/* SDK helper thread: request ring dispatcher */
typedef struct { unsigned char cmd; unsigned char arg; } ReqDE60;
typedef struct { unsigned int idx; int pad; ReqDE60 q[512]; } RingDE60;
extern int D_004E2400;
extern int WaitSema(int);
extern int func_0010D090(int);
extern int func_0010D010(int);
extern int func_0010D0D0(int);
extern int func_0010F350(const char *, ...);
void func_0010DE60(RingDE60 *r)
{
    for (;;) {
        unsigned int i;
        WaitSema(D_004E2400);
        i = r->idx & 0x1FF;
        r->idx = i + 1;
        switch (r->q[i].cmd) {
        case 0:
            func_0010D090(r->q[i].arg);
            break;
        case 1:
            func_0010D010(r->q[i].arg);
            break;
        case 2:
            func_0010D0D0(r->q[i].arg);
            break;
        default:
            func_0010F350("## internel error in libkernl.a!\n");
            break;
        }
    }
}
/* merge_units: end func_0010DE60 */

/* merge_units: begin func_0010DF38 */
/* SDK helper-thread start: semaphore + thread creation */
typedef struct { int status; void (*func)(void *); void *stack; int stack_size; void *gp_reg; int initial_priority; int current_priority; unsigned int attr; unsigned int option; int waitType; int waitId; int wakeupCount; } ThreadParamDF38;
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParamDF38;
extern int D_00486198;
extern int D_004E2408[2];
extern char D_004E2000[];
extern char D_004E9B70[];
#if 0 /* merge_units */
extern void func_0010DE60(void *);
#endif /* merge_units */
#define func_0010DE60(a0) (func_0010DE60((RingDE60 *)(a0))) /* merge_units */

extern int CreateSema(SemaParamDF38 *);
extern int CreateThread(ThreadParamDF38 *);
extern int DeleteSema(int);
extern int StartThread(int, void *);
extern int func_0010D050(void);
extern int ChangeThreadPriority(int, int);
int func_0010DF38(void)
{
    ThreadParamDF38 tp;
    SemaParamDF38 sp;
    if (D_00486198 > 0) return -1;
    sp.init_count = 0;
    sp.max_count = 0xFF;
    D_004E2400 = CreateSema(&sp);
    if (D_004E2400 < 0) return -1;
    tp.func = func_0010DE60;
    tp.stack = D_004E2000;
    tp.stack_size = 0x400;
    tp.gp_reg = D_004E9B70;
    tp.initial_priority = 0;
    D_00486198 = CreateThread(&tp);
    if (D_00486198 < 0) {
        DeleteSema(D_004E2400);
        return -1;
    }
    D_004E2408[0] = 0;
    D_004E2408[1] = 0;
    StartThread(D_00486198, D_004E2408);
    ChangeThreadPriority(func_0010D050(), 1);
    return D_00486198;
}
#undef func_0010DE60 /* merge_units */
/* merge_units: end func_0010DF38 */

/* merge_units: begin func_0010E010 */
typedef struct { unsigned char a; unsigned char b; } EE010;
typedef struct { int x0; int x4; EE010 e[0x200]; } QE010;
#if 0 /* merge_units */
extern QE010 D_004E2408;
#endif /* merge_units */
#define D_004E2408 (*(QE010*)&D_004E2408) /* merge_units */

extern void iSignalSema(int);
extern int func_0010D0A0(int);
int iWakeupThread(int tid)
{
    register int v0 __asm__("$2");
    unsigned int t;
    int i;
    /* inline syscall: $v1 = syscall number */
    __asm__ volatile("li $3, -0x2F\n\tsyscall" : "=r"(v0) : : "$3");
    t = v0;
    if (t != tid) return func_0010D0A0(tid);
    if (t >= 0x100 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 0;
    D_004E2408.e[i].b = t;
    iSignalSema(D_004E2400);
    return t;
}
#undef D_004E2408 /* merge_units */
/* merge_units: end func_0010E010 */

/* merge_units: begin func_0010E0A8 */
typedef struct { unsigned char a; unsigned char b; } EE0A8;
typedef struct { int x0; int x4; EE0A8 e[0x200]; } QE0A8;
#if 0 /* merge_units */
extern QE0A8 D_004E2408;
#endif /* merge_units */
#define D_004E2408 (*(QE0A8*)&D_004E2408) /* merge_units */

int func_0010E0A8(unsigned int c)
{
    int i;
    if (c >= 0x80 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 1;
    D_004E2408.e[i].b = c;
    iSignalSema(D_004E2400);
    return c;
}
#undef D_004E2408 /* merge_units */
/* merge_units: end func_0010E0A8 */

/* merge_units: begin func_0010E128 */
typedef struct { unsigned char a; unsigned char b; } EE128;
typedef struct { int x0; int x4; EE128 e[0x200]; } QE128;
#if 0 /* merge_units */
extern QE128 D_004E2408;
#endif /* merge_units */
#define D_004E2408 (*(QE128*)&D_004E2408) /* merge_units */

extern int func_0010D0E0(int);
int func_0010E128(int tid)
{
    register int v0 __asm__("$2");
    unsigned int t;
    int i;
    /* inline syscall: $v1 = syscall number */
    __asm__ volatile("li $3, -0x2F\n\tsyscall" : "=r"(v0) : : "$3");
    t = v0;
    if (t != tid) return func_0010D0E0(tid);
    if (t >= 0x100 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 2;
    D_004E2408.e[i].b = t;
    iSignalSema(D_004E2400);
    return t;
}
#undef D_004E2408 /* merge_units */
/* merge_units: end func_0010E128 */

/* merge_units: begin func_0010E1C0 */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; void *option; } SemaParamE1C0;
#if 0 /* merge_units */
extern int CreateSema(SemaParamE1C0 *);
#endif /* merge_units */
#define CreateSema(a0) (CreateSema((SemaParamDF38 *)(a0))) /* merge_units */

extern int func_00117C68(int, int);
extern int func_00117E18(int, int (*)(int, int, int, int), int);
extern int func_0010E288(int, int, int, int);
int DelayThread(int a)
{
    SemaParamE1C0 sp;
    int s, sema, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    if (!(s & 0x10000)) return 0x80008008;
    sp.max_count = 1;
    sp.option = "DelayThread";
    sp.init_count = 0;
    sema = CreateSema(&sp);
    if (sema < 0) return 0x80008003;
    r = func_00117E18(func_00117C68(0, a), func_0010E288, sema);
    if (r < 0) {
        DeleteSema(sema);
        return r;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return 0;
}
#undef CreateSema /* merge_units */
/* merge_units: end func_0010E1C0 */
