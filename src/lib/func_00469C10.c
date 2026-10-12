extern short D_00497CC0;
extern int D_00497CC4;
int D_00497D3C = 0;
extern int D_0059857C;
extern int func_004700F8(char *, int);
extern int func_002EA8C8(char *);
extern void func_00467D90(char *);
extern void func_00467F38(void);
extern void func_00467DD0(int);
extern void func_00467F90(int, char *);
extern int func_002EA960(char *, char *);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00469C10(char *a, int b)
{
    char buf[0x20];
    char buf2[0x10];
    func_004700F8(a, 0x15);
    func_004700F8(a + 0x15, 0x11);
    func_004700F8(a + 0x30, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D3C = b;
    if (*(int *)(a + 0x50) == 2) {
        if (func_002EA8C8(buf)) return -2;
        func_00467D90(buf + 8);
        *(void (**)(void))(buf + 4) = func_00467F38;
        func_00467DD0(3);
        func_00467F90(0x2C, a);
        if (func_002EA960(buf, buf2)) {
            func_00467DD0(0);
            return -2;
        }
        return 0;
    }
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059857C, 0xC4, a) ? -5 : 0;
}
