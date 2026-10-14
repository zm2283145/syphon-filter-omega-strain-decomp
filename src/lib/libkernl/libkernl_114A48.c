extern int D_00486260;
extern char D_004E63E8[];
extern void* memset(void* p, int c, unsigned int n);
int func_00114A48(void)
{
    D_00486260 = -1;
    memset(D_004E63E8, 0, 4);
    __asm__ __volatile__("");
    return 0;
}