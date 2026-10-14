extern int D_0048C4B0;
extern int func_00303858(int, unsigned char);
int __attribute__((weak, section(".dtors_drop"))) func_002DCD00(unsigned int p0) { return 0; }
extern int func_002FC2E8(int, unsigned char);
extern int func_002E5008(int, int);
int func_002E1470(unsigned int a, int b)
{
    int r;
    if (a >= 4) return 0x17;
    if (!(a == 0 || a == 0xFFFF)) {
        r = func_002E5008(func_002FC2E8(func_002DCD00(a), b), 0x18);
        if (r) return r;
    } else {
        if (func_00303858(D_0048C4B0, b)) return 0x25;
    }
    return 0;
}

/* score: 1 insn diff (beql vs beq w/ lui in delay slot; reorg liveness) */
