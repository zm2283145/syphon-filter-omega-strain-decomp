typedef struct { char pad[0x2410]; int time; } Net;
extern int func_003531B8(Net *);
extern void func_00451B00(Net *, int, const char *, int);
extern int func_00443E70(void);
extern void func_00452F70(Net *, int, int);
extern int ezNetCtlGetStatus(void *);
extern char D_004C0D70[];
extern int D_00585D00;
extern char D_00585D40[];
extern int D_00585D4C;

int func_0044BFF0(Net *a) {
    int t;
    if (func_003531B8(a) < 0) {
        func_00451B00(a, 0x20, D_004C0D70, 0x11A);
        return 0;
    }
    a->time = t = func_00443E70();
    D_00585D00 = t;
    for (;;) {
        func_00452F70(a, 0, 0);
        if (ezNetCtlGetStatus(D_00585D40) < 0 || D_00585D4C == 5) {
            break;
        }
        if (t - a->time > 60000) {
            func_00451B00(a, 2, D_004C0D70, 0x134);
            return 0;
        }
        t = func_00443E70();
    }
    return 1;
}
