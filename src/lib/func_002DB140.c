extern void *memset(void *, int, unsigned int);
extern char *func_002DD2E8(int);
extern char *D_0051F0D0;
extern char D_0048C440;
void func_002DB140(void)
{
    char **pp = &D_0051F0D0;
    *pp = func_002DD2E8(0x400);
    D_0048C440 = 0;
    memset(*pp, 0, 0x400);
}