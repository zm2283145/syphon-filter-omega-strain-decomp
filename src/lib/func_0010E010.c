typedef struct { unsigned char a; unsigned char b; } EE010;
typedef struct { int x0; int x4; EE010 e[0x200]; } QE010;
extern int D_00486198;
extern QE010 D_004E2408;
extern int D_004E2400;
extern void func_0010D190(int);
extern int func_0010D0A0(int);
int func_0010E010(int tid)
{
    register int v0 __asm__("$2");
    unsigned int t;
    int i;
    /* inline syscall: $v1 = syscall number */
    __asm__ volatile("li $3, -0x2F\n\tsyscall" : "=r"(v0) : : "$3");
    t = v0;
    if (t != tid) return func_0010D0A0(tid);
    if (t >= 0x100 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 0;
    D_004E2408.e[i].b = t;
    func_0010D190(D_004E2400);
    return t;
}


