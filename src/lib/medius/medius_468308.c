/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_00497CC4, D_00598564, D_0059857C;
extern int func_00467DE0(void);
extern void func_00467DD0(int);
extern void func_00468148(int *);
void __attribute__((weak, section(".dtors_drop"))) func_00468158(void * a0) { }
extern void func_00467EC8(void *);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00468308(void)
{
    char a[0xC4];
    char b[0xEC];
    int t[1];
    int r = 0;
    if (func_00467DE0() == 2) {
        func_00467DD0(0);
        return -0xA;
    }
    if (func_00467DE0() == 1) {
        func_00467DD0(0);
        func_00468148(t);        switch (t[0]) {
        case 0x2C:
            func_00468158(a);
            func_00467EC8(a + 0x94);
            r = Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059857C, 0xC4, a);
            break;
        case 0x12:
            func_00468158(b);
            func_00467EC8(b + 0xBC);
            r = Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598564, 0xEC, b);
            break;
        }
    }
    if (r) return -0xA;
    return 0;
}
