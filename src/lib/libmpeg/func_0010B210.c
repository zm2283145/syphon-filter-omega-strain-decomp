typedef struct { char pad[0x40]; int h; } XB210;
extern void func_0010BDE8(int h, int a, int n);
int func_0010B210(XB210* p, int a, int n)
{
    func_0010BDE8(p->h, a, ((n + 0x13) / 16) * 16);
    return 1;
}
