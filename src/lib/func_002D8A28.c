typedef struct { char p0[0x74]; int x74; char p78[0x90 - 0x78]; int x90; int x94; char p98[0xBC - 0x98]; int xBC; char pC0[0xD4 - 0xC0]; int xD4; } T2D8A28;
extern void Net_AllocZeroed(void *, unsigned long);
extern void *memset(void *, int, unsigned int);
T2D8A28 *func_002D8A28(void)
{
    T2D8A28 *p = 0;
    Net_AllocZeroed(&p, sizeof(T2D8A28));
    if (p != 0) {
        memset(p, 0, sizeof(T2D8A28));
        p->x90 = 0;
        p->x94 = 0;
        p->xBC = 0;
        p->xD4 = 0;
        p->x74 = 0;
    }
    return p;
}
