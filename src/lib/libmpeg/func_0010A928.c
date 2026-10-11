extern void func_0010A008(int, int);
extern int func_00109F50(int, int);
int func_0010A928(int x)
{
    func_0010A008(x, 0x38);
    func_0010A008(x, 0x28);
    while (func_00109F50(x, 1) == 1) func_0010A008(x, 0x18);
    return 1;
}