extern void func_00322C68(int, int, int);
extern void func_003227E0(int, int, int);
void func_003226E0(int a, int b, int n)
{
    int h = n / 2;
    func_00322C68(a, b, h);
    func_003227E0(b, a, h);
}
