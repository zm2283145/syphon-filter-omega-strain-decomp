#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int a, b, c, time, e; } E2EDD88;
extern int func_002F5160(void);
extern void Net_AllocZeroed(void *, unsigned long);
extern int func_002FB3C0(void *);
extern void *memset(void *, int, unsigned int);
int func_002EDD88(void *s)
{
    E2EDD88 *old;
    int now, i;
    if (s == 0 || F(s, int, 0x58) != 0) return -1;
    now = func_002F5160();
    old = F(s, E2EDD88 *, 0x60);
    Net_AllocZeroed(&F(s, E2EDD88 *, 0x60), (unsigned int)(F(s, int, 0x5C) * 2 * sizeof(E2EDD88)));
    if (F(s, E2EDD88 *, 0x60) == 0) {
        F(s, E2EDD88 *, 0x60) = old;
        return -1;
    }
    for (i = 0; i < F(s, int, 0x5C); i++)
        F(s, E2EDD88 *, 0x60)[i] = old[i];
    func_002FB3C0(&old);
    F(s, int, 0x5C) *= 2;
    for (; i < F(s, int, 0x5C); i++) {
        memset(&F(s, E2EDD88 *, 0x60)[i], 0, sizeof(E2EDD88));
        F(s, E2EDD88 *, 0x60)[i].time = now;
    }
    return 0;
}
