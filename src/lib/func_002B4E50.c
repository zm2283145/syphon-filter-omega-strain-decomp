typedef struct { int x0; int x4; int x8; } T2B4E50;
extern int D_0048BD88;
extern int D_00506644;
extern T2B4E50 D_00506B60;
extern int DeleteSema(int);
extern int TerminateThread(int);
extern int DeleteThread(int);
extern int scePrintf(const char *, ...);
extern void func_002BB738(void);
int func_002B4E50(void)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (D_00506644) return 0x81010010;
    if (D_00506B60.x4 >= 0) DeleteSema(D_00506B60.x4);
    if (D_00506B60.x8 >= 0) DeleteSema(D_00506B60.x8);
    if (D_00506B60.x0 >= 0) {
        if (TerminateThread(D_00506B60.x0) < 0) scePrintf("libmc2: TerminateTread faild\n");
        DeleteThread(D_00506B60.x0);
    }
    func_002BB738();
    D_0048BD88 = 0;
    return 0;
}
