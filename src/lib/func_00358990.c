typedef struct { char pad[0x68]; int f60; } E358990;
extern int func_003581E0(int x);
extern E358990* func_00358480(int a);
extern int func_003583A0(int h, int c);
int func_00358990(int a, int b)
{
    int h = func_003581E0(0);
    E358990* e;
    if (h == 0) return -1;
    e = func_00358480(a);
    if (e == 0) return func_003583A0(h, 9);
    e->f60 = b;
    func_003583A0(h, 0);
    return 0;
}