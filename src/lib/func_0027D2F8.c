typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParamD2F8;
extern int CreateSema(SemaParamD2F8 *);
extern volatile int D_0048B378;

int func_0027D2F8(void)
{
    SemaParamD2F8 p;
    if (D_0048B378 >= 0) return -1;
    p.initCount = 0;
    p.maxCount = 1;
    D_0048B378 = CreateSema(&p);
    if (D_0048B378 < 0) return -1;
    return D_0048B378;
}