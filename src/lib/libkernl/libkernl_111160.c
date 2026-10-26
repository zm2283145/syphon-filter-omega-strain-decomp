typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam1160;
extern int CreateSema(SemaParam1160 *);
int D_00486244 = -1;
void _sceFsSemInit(void)
{
    SemaParam1160 p;
    if (D_00486244 == -1) {
        p.option = 0;
        p.initCount = 1;
        p.maxCount = 1;
        D_00486244 = CreateSema(&p);
    }
}