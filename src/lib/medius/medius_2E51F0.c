/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_0051FED8[];
int __attribute__((weak, section(".dtors_drop"))) DMEmalloc(int a0) { return 0; }
int NetCreateConnInfo(unsigned int a, int *out)
{
    int v;
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 4) return 0x17;
    if (D_0051FED8[a] == 0) {
        v = DMEmalloc(0x450);
        D_0051FED8[a] = v;
        if (v == 0) return 0x16;
    }
    *out = D_0051FED8[a];
    return 0;
}
