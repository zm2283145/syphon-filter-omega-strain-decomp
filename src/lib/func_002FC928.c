typedef struct { unsigned char on; char pad[3]; int h; } S2FC928;
extern S2FC928 D_005297E0;
extern void func_002F5DB0(int);
int func_002FC928(void)
{
    if (D_005297E0.on != 1) return 5;
    func_002F5DB0(D_005297E0.h);
    D_005297E0.on = 0;
    return 0;
}