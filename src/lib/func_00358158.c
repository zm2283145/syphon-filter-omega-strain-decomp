typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam8158;
extern int CreateSema(SemaParam8158 *);
extern int func_0010D1A0(int);
unsigned int D_00492CC8[1] = { 0xFFFFFFFF };

int func_00358158(void)
{
    SemaParam8158 p;
    int r;
    if ((*(int*)D_00492CC8) < 0) {
        p.option = 0;
        p.initCount = 1;
        p.maxCount = 1;
        r = CreateSema(&p);
        (*(int*)D_00492CC8) = r;
        if (r < 0) return -1;
    }
    return func_0010D1A0((*(int*)D_00492CC8)) > -1 ? 0 : -1;
}