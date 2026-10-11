typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam0C50;
extern int CreateSema(SemaParam0C50 *);
extern int D_00486248;
extern int D_0048624C;

void func_00110C50(void)
{
    SemaParam0C50 p;
    if (D_00486248 == -1) {
        p.option = 0;
        p.initCount = 1;
        p.maxCount = 1;
        D_00486248 = CreateSema(&p);
        D_0048624C = CreateSema(&p);
    }
}