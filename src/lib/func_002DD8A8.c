extern void *memset(void *, int, unsigned int);
extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, char **);
void func_002DD8A8(unsigned int a, unsigned int b)
{
    char *p = 0;
    char *q = 0;
    if (a >= 4) return;
    if (b >= 0x100) return;
    if (func_002E51B8(a, &p)) return;
    if (p == 0) return;
    if (func_002E52D8(a, b, &q)) return;
    if (q) memset(q, 0, 0x2C);
}
