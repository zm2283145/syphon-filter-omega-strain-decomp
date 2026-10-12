const unsigned int D_00498C30[2] = { 0x0, 0x0 };
extern char *D_004865E0;
extern int func_00116670(void *, int, int);
extern void func_00116788(void);
extern int func_0010CDB0(int, int, int, char *);

int func_00116790(int a0, int a1, int a2, int a3)
{
    func_00116670(((char*)D_00498C30), a2, a3);
    func_00116788();
    return func_0010CDB0(a0, a1, a2, D_004865E0 + 4);
}