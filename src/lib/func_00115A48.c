typedef struct { int a; int b; } Pair5A48;
extern Pair5A48 D_004865E8[];
extern char D_00486268[];
extern int D_004865E0;
extern void func_00115A38(int, int);
extern int func_00115A28(int);
extern void func_001159E0(unsigned int, void *, int);
extern void func_0010D3E0(int);

void func_00115A48(void)
{
    Pair5A48 *p;
    unsigned int i;
    func_00115A38(D_004865E8[0].a, D_004865E8[0].b);
    func_001159E0(0x80075000, D_00486268, 0x330);
    func_0010D3E0(0);
    func_0010D3E0(2);
    func_00115A38(D_004865E8[1].a, D_004865E8[1].b);
    func_00115A38(D_004865E8[2].a, D_004865E8[2].b);
    p = &D_004865E8[3];
    for (i = 3; i < 8; i++, p++) {
        func_00115A38(p->a, func_00115A28(p->a));
    }
    D_004865E0 = func_00115A28(3);
}