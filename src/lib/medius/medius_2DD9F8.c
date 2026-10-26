/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char b[0x44]; } E2DD9F8;
const unsigned int D_0048C4A8[1] = { 0x0 };
E2DD9F8 * __attribute__((weak, section(".dtors_drop"))) Rt_MemoryAllocate(int a0) { return 0; }
int NetGetStreamChannel(unsigned int id, E2DD9F8 **out)
{
    unsigned int i;
    E2DD9F8 *t;
    if (out == 0) return 0x17;
    *out = 0;
    if (id >= 0x800) return 8;
    if ((*(E2DD9F8 **)D_0048C4A8) == 0) {
        t = Rt_MemoryAllocate(0x22000);
        (*(E2DD9F8 **)D_0048C4A8) = t;
        if (t == 0) return 0x16;
        for (i = 0; i < 0x800; i++) (*(E2DD9F8 **)D_0048C4A8)[i].b[0] = 0;
    }
    *out = &(*(E2DD9F8 **)D_0048C4A8)[id];
    return 0;
}
