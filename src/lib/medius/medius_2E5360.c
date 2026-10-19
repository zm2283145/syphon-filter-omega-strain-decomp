/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { int *v[256]; } T2E5360;
extern int func_002E51B8(unsigned int, T2E5360 **);
int * __attribute__((weak, section(".dtors_drop"))) Rt_MemoryAllocate(int a0) { return 0; }
int func_002E5360(unsigned int a, unsigned int b, int **out)
{
    T2E5360 *p = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 4) return 0x17;
    if (b >= 0x100) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    if (p->v[b] == 0) {
        p->v[b] = Rt_MemoryAllocate(0x2C);
        if (p->v[b] == 0) return 0x16;
    }
    *out = p->v[b];
    return 0;
}
