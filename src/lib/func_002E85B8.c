extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern int func_002E52D8(unsigned int, unsigned int, char **);
extern int func_002DDB30(int *, unsigned int);
extern int func_002DCA70(unsigned int, int);
int func_002E85B8(unsigned int a, int b, unsigned int c, int *out)
{
    char *p = 0;
    char *q = 0;
    int n = 0x100;
    if (out == 0) return -1;
    if (a >= 4) return 4;
    if (c >= 0x100) return 4;
    if (D_0048C450 >= 4) return 4;
    if (func_002E51B8(D_0048C450, &p)) return 4;
    if (p) {
        if (func_002E52D8(D_0048C450, *(unsigned int *)(p + 0x400), &q)) return 4;
        if (q) {
            if (func_002DDB30(&n, D_0048C450)) return 4;
            if (n != 0x100) {
                register char *qq asm("$2") = q;
                register int m1 asm("$5") = -1;
                /* scheduling barrier: keeps the q reload after the a1 setup (fills the beq delay slot) */
                __asm__ volatile("" ::: "memory");
                {unsigned int g = D_0048C450;
                *(int *)(qq+0x24) = *out;
                func_002DCA70(g,m1);}
            }
        }
    }
    return 4;
}
