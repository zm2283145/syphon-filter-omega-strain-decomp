typedef struct { char pad[0x60]; int f60; } E358890;
extern int func_003581E0(int x);
extern E358890* func_00358480(int a);
extern int func_003583A0(int h, int c);
int func_00358890(int a, int b)
{
    int h = func_003581E0(0);
    E358890* e;
    if (h == 0) return -1;
    e = func_00358480(a);
    if (e == 0) return func_003583A0(h, 9);
    e->f60 = b;
    func_003583A0(h, 0);
    return 0;
}