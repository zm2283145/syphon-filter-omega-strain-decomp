/* SDK helper-thread start: semaphore + thread creation */
typedef struct { int status; void (*func)(void *); void *stack; int stack_size; void *gp_reg; int initial_priority; int current_priority; unsigned int attr; unsigned int option; int waitType; int waitId; int wakeupCount; } ThreadParamDF38;
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } SemaParamDF38;
extern int D_00486198;
extern int D_004E2400;
extern int D_004E2408[2];
extern char D_004E2000[];
extern char D_004E9B70[];
extern void func_0010DE60(void *);
extern int CreateSema(SemaParamDF38 *);
extern int func_0010CF60(ThreadParamDF38 *);
extern int func_0010D170(int);
extern int func_0010CF80(int, void *);
extern int func_0010D050(void);
extern int func_0010CFF0(int, int);
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
    D_00486198 = func_0010CF60(&tp);
    if (D_00486198 < 0) {
        func_0010D170(D_004E2400);
        return -1;
    }
    D_004E2408[0] = 0;
    D_004E2408[1] = 0;
    func_0010CF80(D_00486198, D_004E2408);
    func_0010CFF0(func_0010D050(), 1);
    return D_00486198;
}
