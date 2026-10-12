typedef struct { char pad[0x24]; void* serve; char pad2[0x14]; } Cd27C328;
extern Cd27C328 D_00504080;
int D_0048B374 = 0;
extern int func_00110358(Cd27C328* cd, unsigned int id, int mode);
extern int func_00110720(Cd27C328* cd);
int func_0027C328(void)
{
    int i;
    if (D_0048B374) return 0;
    while (1) {
        if (func_00110358(&D_00504080, 0x80001101, 1) < 0) return -1;
        while (func_00110720(&D_00504080));
        if (D_00504080.serve != 0) break;
        i = 0x10000;
        do { i--; __asm__ volatile ("nop"); __asm__ volatile ("nop"); __asm__ volatile ("nop"); __asm__ volatile ("nop"); } while (i != -1);
    }
    D_0048B374 = 1;
    return 0;
}