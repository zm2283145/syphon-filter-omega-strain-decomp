/* Two SDK callback routines; prototype records confirm the internal boundary. */
register int gp asm("$28");

extern int D_004878A0;
extern int D_004878D8;
extern int D_004878B4;
extern int D_00487894;
extern int D_004E9D14;
extern int D_00487890;
extern int D_004E9D00;
extern int D_004E9D04;
extern int D_004878DC;
extern char D_00498C38[];

extern int WaitSema(int);
extern void ExitDeleteThread(void);
extern int scePrintf(const char *, ...);

void func_001184C0(void *arg)
{
    int save;

    while (1) {
        WaitSema(D_004878A0);
        if (D_004878D8 == -1) {
            D_004878B4 = 0;
            // Preserve the shutdown store before preparing the next global address.
            __asm__ volatile("");
            D_004878D8 = 0;
            D_00487894 = 0;
            D_004E9D14 = 0;
            ExitDeleteThread();
        }
        if (D_00487890 > 0) {
            scePrintf(D_00498C38, D_004E9D00, D_004878DC);
        }
        if (D_004E9D00 != 0 && *(volatile int *)&D_004878DC != 0) {
            // Keep GP saving inside the callback condition, outside its branch delay slot.
            __asm__ volatile("");
            save = gp;
            gp = *(volatile int *)&D_004E9D04;
            ((void (*)(int))D_004E9D00)(*(volatile int *)&D_004878DC);
            gp = save;
        }
        *(volatile int *)&D_004878B4 = 0;
    }
}

/* ---- sceCdInitEeCB (func_00118590) ---- */
struct ThreadParam { int status; void (*entry)(void *); void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; unsigned int attr; unsigned int option; int waitType; int waitId; int wakeupCount; };
extern int D_00487894;
extern int D_004E9D18;
extern struct ThreadParam D_004E9D20;
extern struct ThreadParam D_004E9D50;

extern int CreateThread(struct ThreadParam *);
extern int StartThread(int, void *);
extern int ChangeThreadPriority(int, int);
extern int GetThreadId(void);
extern int ReferThreadStatus(int, struct ThreadParam *);
extern void func_001184C0(void *);

int func_00118590(int priority, void *stack, int stackSize)
{
    int r = 1;

    if (D_00487894 == 0) {
        D_004E9D18 = GetThreadId();
        ReferThreadStatus(D_004E9D18, &D_004E9D20);
        D_004E9D50.stackSize = stackSize;
        D_004E9D50.gpReg = 0;
        D_004E9D50.entry = func_001184C0;
        D_004E9D50.stack = stack;
        D_004E9D50.initPriority = priority;
        D_00487894 = CreateThread(&D_004E9D50);
        StartThread(D_00487894, 0);
    } else {
        ChangeThreadPriority(D_00487894, priority);
        r = 0;
    }
    return r;
}
