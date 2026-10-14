/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_0051FEE8[];
int __attribute__((weak, section(".dtors_drop"))) func_002DD2E8(int a0) { return 0; }
int func_002E50C8(unsigned int a, int *out)
{
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 0x100) return 0x17;
    if (D_0051FEE8[a] == 0 && (D_0051FEE8[a] = func_002DD2E8(0x1A0)) == 0) return 0x16;
    *out = D_0051FEE8[a];
    return 0;
}
