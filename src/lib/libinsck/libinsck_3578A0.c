extern int *func_003583F0(void);
extern int func_00357938(int, int, int);
extern int func_003579D8(int, int, int);
extern int func_00357D40(void);
extern int *func_00123320(void);
int func_003578A0(int op, int a, int b, int c)
{
    int *e;
    switch (op) {
    case 2:
        return func_00357938(a, b, c);
    case 0x1C:
        return func_003579D8(a, b, c);
    }
    *func_003583F0() = 0x6A;
    if (func_00357D40() != 0) {
        e = func_00123320();
        *e = *func_003583F0();
    }
    return 0;
}