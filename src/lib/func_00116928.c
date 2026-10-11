typedef struct { int a; int b; } Pair6928;
extern Pair6928 D_00487808[];
extern char D_004870A0[];
extern char D_004877E0[];
extern void func_001168C0(int, int);
extern int func_00116918(int);
extern void func_001168D0(unsigned int, void *, int);
extern void func_0010D3E0(int);

void func_00116928(void)
{
    Pair6928 *p;
    unsigned int i;
    if (!(*(volatile unsigned int *)0x10001810 & 0x100)) {
        func_001168C0(D_00487808[0].a, D_00487808[0].b);
        func_001168D0(0x80076000, D_004870A0, 0x740);
        func_001168D0(0x82000, D_004877E0, 0x28);
        func_0010D3E0(0);
        func_0010D3E0(2);
        func_001168C0(D_00487808[1].a, D_00487808[1].b);
        p = &D_00487808[2];
        for (i = 2; i < 8; i++, p++) {
            func_001168C0(p->a, func_00116918(p->a));
        }
    }
}