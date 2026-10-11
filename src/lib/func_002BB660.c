extern void func_0010D190(int a);
extern int D_00518A04;
void func_002BB660(void)
{
    func_0010D190(D_00518A04);
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
}