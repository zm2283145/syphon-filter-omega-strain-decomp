typedef struct { int count; int max_count; int init_count; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam_00116210;
extern int CreateSema(SemaParam_00116210* p);
int D_004868D0 = 0;
int D_004868D4 = 0;
void func_00116210(void)
{
    SemaParam_00116210 a;
    SemaParam_00116210 b;
    a.max_count = 1;
    a.init_count = 1;
    b.max_count = 1;
    b.init_count = 1;
    D_004868D0 = CreateSema(&a);
    D_004868D4 = CreateSema(&b);
}
