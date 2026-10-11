extern void func_0010D190(int a);
int func_0010E288(int a, int b, int c, int d)
{
    func_0010D190(d);
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}