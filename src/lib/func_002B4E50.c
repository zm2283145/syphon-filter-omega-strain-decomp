typedef struct { int x0; int x4; int x8; } T2B4E50;
extern int D_0048BD88;
extern int D_00506644;
extern T2B4E50 D_00506B60;
extern int func_0010D170(int);
extern int func_0010CFB0(int);
extern int func_0010CF70(int);
extern int func_0010F388(const char *, ...);
extern void func_002BB738(void);
int func_002B4E50(void)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (D_00506644) return 0x81010010;
    if (D_00506B60.x4 >= 0) func_0010D170(D_00506B60.x4);
    if (D_00506B60.x8 >= 0) func_0010D170(D_00506B60.x8);
    if (D_00506B60.x0 >= 0) {
        if (func_0010CFB0(D_00506B60.x0) < 0) func_0010F388("libmc2: TerminateTread faild\n");
        func_0010CF70(D_00506B60.x0);
    }
    func_002BB738();
    D_0048BD88 = 0;
    return 0;
}
