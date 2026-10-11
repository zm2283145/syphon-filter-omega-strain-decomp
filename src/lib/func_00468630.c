extern short D_00497CC0;
extern int D_00497D60, D_00497D70, D_00497CF4, D_00497DC4, D_00497CC8, D_00497CCC;
extern void func_00467DD0(int);
extern void func_002EBC48(int *);
extern int func_0046E790(void);
int func_00468630(int *cfg, int *out)
{
    if (D_00497CC0 == 1) {
        *out = -1;
        return -0x13;
    }
    func_00467DD0(0);
    D_00497D60 = cfg[0];
    D_00497D70 = cfg[1];
    D_00497CF4 = cfg[2];
    D_00497DC4 = cfg[3];
    D_00497CC8 = cfg[4];
    func_002EBC48(&D_00497CCC);
    if (func_0046E790()) {
        *out = -1;
        return -1;
    }
    D_00497CC0 = 1;
    *out = 0;
    return 0;
}
