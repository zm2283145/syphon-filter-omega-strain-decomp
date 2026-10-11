extern void func_0031B9C0(void *a, int n);
extern void func_0031B248(void *a, int n);
extern void func_0031B780(void *a, int n);
void func_0031B140(void *a, int bits)
{
    func_0031B9C0(a, (1 << bits) >> 1);
    func_0031B248(a, bits - 1);
    func_0031B780(a, bits);
}