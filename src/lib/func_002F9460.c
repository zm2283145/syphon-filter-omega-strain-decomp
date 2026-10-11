extern int func_002F7D68(int);
extern int func_002F7ED8(int, int);
extern void func_002F7F10(int, int);
extern void func_002F7E20(int);
void func_002F9460(int a, int b)
{
    int l = func_002F7D68(a);
    int n = func_002F7ED8(l, b);
    if (n) {
        func_002F7F10(l, n);
        func_002F7E20(n);
    }
}