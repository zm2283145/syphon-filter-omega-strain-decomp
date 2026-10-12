/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_0048C458;
extern int *D_0048C4A8;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern int func_002E5BA8(void);
extern int func_002E51B8(int, void **);
extern int func_002E4CA8(int);
int __attribute__((weak, section(".dtors_drop"))) func_002DF8E8(void) { return 0; }
extern int func_002DB3F0(void), func_002DB440(void), func_00305908(void);
extern int func_002E5F68(void);
extern int func_002DD328(void *);
extern int func_002E5420(int, int);
extern int func_002E5280(int);
extern int func_002E5158(void);
extern int func_003028E8(int);
extern int func_002FB840(void), func_003143E0(void);
int func_002E4EA8(void)
{
    void *p = 0;
    int i, j, r;
    if (D_0048C458 != 1) return 0x11;
    func_002E5BA8();
    for (j = 0; j < 4; j++) {
        r = func_002E51B8(j, &p);
        if (r != 0) return r;
        if (p != 0 && *(int *)((char *)p + 0x438) == 1) func_002E4CA8(j);
    }
    func_002DF8E8();
    func_002DB3F0();
    func_002DB440();
    func_00305908();
    if (D_0048C4A8) {
        func_002E5F68();
        func_002DD328(&D_0048C4A8);
        D_0048C4A8 = 0;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 0x100; j++) func_002E5420(i, j);
        func_002E5280(i);
    }
    func_002E5158();
    if (D_0048C4AC) {
        func_003028E8(D_0048C4B0);
        D_0048C4AC = 0;
    }
    func_002FB840();
    func_003143E0();
    D_0048C458 = 0;
    return 0;
}
