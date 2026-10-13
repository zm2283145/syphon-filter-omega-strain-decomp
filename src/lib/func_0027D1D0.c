typedef struct { int status; void* func; void* stack; int stack_size; void* gp_reg; int initial_priority; int current_priority; unsigned int attr; unsigned int option; } TP27D1D0;
typedef struct { unsigned char b[16]; } B27D1D0;
extern char D_004E9B70[];
extern B27D1D0 D_00506140;
extern void func_0027D160(void* p);
extern int CreateThread(TP27D1D0* p);
extern int StartThread(int th, void* arg);
extern int func_0010CF70(int th);
int func_0027D1D0(B27D1D0* arg, void* stack, int size, int prio)
{
    TP27D1D0 tp;
    int th;
    tp.func = func_0027D160;
    tp.stack = stack;
    tp.stack_size = size;
    tp.initial_priority = prio;
    tp.gp_reg = D_004E9B70;
    th = CreateThread(&tp);
    if (th <= 0) return -1;
    D_00506140 = *arg;
    if (StartThread(th, 0) < 0) {
        func_0010CF70(th);
        return -1;
    }
    return th;
}