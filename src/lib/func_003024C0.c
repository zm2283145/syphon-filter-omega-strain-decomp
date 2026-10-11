typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } ScfSemaParam;
typedef struct { unsigned char ok; int f4; int f8; int sema; int f10; } ScfSem_4C0;
extern int CreateSema(ScfSemaParam *p);
int func_003024C0(ScfSem_4C0 *o)
{
    ScfSemaParam p;
    int id;
    int ret = 2;
    if (o == 0) return ret;
    o->f10 = 0;
    p.maxCount = 1;
    p.initCount = 1;
    id = CreateSema(&p);
    if (id == -1) return 1;
    o->sema = id;
    return 0;
}