typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; void *free; void *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern int func_001161A0(void);
extern int func_001161F8(void);

unsigned long func_00117330(void)
{
    unsigned long t;
    int s = func_001161A0();
    /* SDK inline asm: read T1 count and overflow atomically with fixed t0-t2 scratch */
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "lwu %0, 0(%1)\n\t"
        "lw $8, 0x10(%1)\n\t"
        "ld $10, %2\n\t"
        "andi $9, $8, 0x800\n\t"
        "beqz $9, 1f\n\t"
        "addiu $9, $0, 2\n\t"
        "lwu %0, 0(%1)\n\t"
        "daddiu $10, $10, 1\n"
        "1:\n\t"
        "andi $8, $8, 3\n\t"
        "dsll $10, $10, 16\n\t"
        "movz $9, $0, $8\n\t"
        "or %0, %0, $10\n\t"
        "dsllv $9, $9, $8\n\t"
        "dsllv %0, %0, $9\n\t"
        ".set pop"
        : "=&r"(t) : "r"(0x10001000), "m"(D_00487848.a) : "$8", "$9", "$10");
    if (s) func_001161F8();
    return t;
}
