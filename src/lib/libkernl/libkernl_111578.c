extern int D_0048623C;
extern char D_004E5F28[];
extern void* memset(void* p, int c, unsigned int n);
int sceFsReset(void)
{
    D_0048623C = 0;
    memset(D_004E5F28, 0, 4);
    __asm__ __volatile__("");
    return 0;
}