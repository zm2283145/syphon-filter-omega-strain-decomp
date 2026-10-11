typedef struct { int a; int b; } Pair6570;
extern Pair6570 D_00487080[];
extern char D_004868D8[];
extern int func_00116508(void);
extern void func_001164A0(int, int);
extern int func_001164F8(int);
extern void func_001164B0(unsigned int, void *, int);
extern void func_0010D3E0(int);

void func_00116570(void)
{
    Pair6570 *p;
    unsigned int i;
    if (func_00116508()) {
        func_001164A0(D_00487080[0].a, D_00487080[0].b);
        func_001164B0(0x80074000, D_004868D8, 0x7A8);
        func_0010D3E0(0);
        func_0010D3E0(2);
        func_001164A0(D_00487080[1].a, D_00487080[1].b);
        p = &D_00487080[2];
        for (i = 2; i < 3; i++, p++) {
            func_001164A0(p->a, func_001164F8(p->a));
        }
    }
}