extern short D_00491432;
extern unsigned char D_00491430;
extern char D_0052AC98[];
extern void *memset(void *d, int c, unsigned int n);
int func_00314380(void)
{
    if (D_00491432 == 0) {
        memset(D_0052AC98, 0, 16);
        D_00491430 = 1;
    }
    D_00491432++;
    return 0;
}
