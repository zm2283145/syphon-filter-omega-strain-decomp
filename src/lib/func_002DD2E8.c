extern int Net_AllocZeroed(int* out, unsigned long n);
extern void printf(const char* msg);
int func_002DD2E8(unsigned int n)
{
    int p = 0;
    if (Net_AllocZeroed(&p, n))
        printf("rt_memory_allocate failed 
");
    return p;
}
