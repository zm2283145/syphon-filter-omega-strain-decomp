extern void func_00107748(void *);
extern void func_00107DC8(void *, int);
extern int func_00107CA8(void *, int);

void func_00108048(char *m)
{
    int n;
    func_00107748(m);
    n = -(*(volatile int *)0x10002020 & 7) & 7;
    if (n) func_00107DC8(m, n);
    while (func_00107CA8(m, 0x18) != 1 && *(int *)(m + 0x10A0) == 0) func_00107DC8(m, 8);
}