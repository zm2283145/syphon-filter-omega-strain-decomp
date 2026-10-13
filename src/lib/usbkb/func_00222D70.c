extern int func_001161A0(void);
extern void func_001161F8(void);
extern int RemoveIntcHandler(int, int);
extern int Alloc_Lock(int);
extern int DeleteSema(int);
extern int scePrintf(const char *, ...);
extern int D_004F581C;
extern int D_0048AB18;

int sceUsbKbEnd(void)
{
    int err = 0;
    int s = func_001161A0();
    int r = RemoveIntcHandler(3, D_004F581C);
    if (r == 0) Alloc_Lock(3);
    if (s) func_001161F8();
    if (r < 0) {
        err = 1;
        scePrintf("libusbkb.a : RemoveIntcHandler() --> error
");
    }
    if (D_0048AB18 != -1) {
        if (DeleteSema(D_0048AB18) < 0) {
            err++;
            scePrintf("libusbkb.a : DeleteSema() --> error
");
        } else {
            D_0048AB18 = -1;
        }
    }
    return err ? -1 : 0;
}