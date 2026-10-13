typedef struct { unsigned char a; unsigned char b; } EE128;
typedef struct { int x0; int x4; EE128 e[0x200]; } QE128;
extern int D_00486198;
extern QE128 D_004E2408;
extern int D_004E2400;
extern void iSignalSema(int);
extern int func_0010D0E0(int);
int func_0010E128(int tid)
{
    register int v0 __asm__("$2");
    unsigned int t;
    int i;
    /* inline syscall: $v1 = syscall number */
    __asm__ volatile("li $3, -0x2F\n\tsyscall" : "=r"(v0) : : "$3");
    t = v0;
    if (t != tid) return func_0010D0E0(tid);
    if (t >= 0x100 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 2;
    D_004E2408.e[i].b = t;
    iSignalSema(D_004E2400);
    return t;
}


