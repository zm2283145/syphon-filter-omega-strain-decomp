typedef struct { int x0, x4, x8, xC, x10; int (*x14)(void); int x18, x1C; } P00468500;
extern short D_00497CC0;
unsigned int D_00497D60[1] = { 0x0 };
extern int D_00497D70;
extern int D_00497CF4;
extern int D_00497DC4;
extern int D_00497CC8;
extern int D_00497CCC;
extern int func_00467DD0(int);
extern int func_002E9480(P00468500 *);
extern void func_004684E0(int);
extern int func_004684A0(void);
extern int func_002E94E0(P00468500 *, char *);
extern int func_002EBC48(int *);
extern int func_0046E790(void);
int func_00468500(int *cfg, int *out)
{
    P00468500 p;
    char buf[0x20];
    if (D_00497CC0 == 1) {
        *out = -1;
        return -0x12;
    }
    func_00467DD0(0);
    func_002E9480(&p);
    p.x8 = cfg[0];
    if (cfg[5]) {
        func_004684E0(cfg[5]);
        p.x18 = cfg[6];
    } else {
        func_004684E0(0);
    }
    p.x14 = func_004684A0;
    if (func_002E94E0(&p, buf)) {
        *out = -1;
        return -1;
    }
    (*(int*)D_00497D60) = cfg[1];
    D_00497D70 = cfg[2];
    D_00497CF4 = cfg[3];
    D_00497DC4 = cfg[4];
    D_00497CC8 = cfg[7];
    func_002EBC48(&D_00497CCC);
    if (func_0046E790()) {
        *out = -1;
        return -1;
    }
    D_00497CC0 = 1;
    *out = 0;
    return 0;
}
