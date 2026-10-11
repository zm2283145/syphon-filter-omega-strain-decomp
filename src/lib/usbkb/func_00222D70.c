extern int func_001161A0(void);
extern void func_001161F8(void);
extern int func_0010CE60(int, int);
extern int Alloc_Lock(int);
extern int func_0010D170(int);
extern int func_0010F388(const char *, ...);
extern int D_004F581C;
extern int D_0048AB18;
extern char D_004A4D00[];
extern char D_004A4D30[];

int sceUsbKbEnd(void)
{
    int err = 0;
    int s = func_001161A0();
    int r = func_0010CE60(3, D_004F581C);
    if (r == 0) Alloc_Lock(3);
    if (s) func_001161F8();
    if (r < 0) {
        err = 1;
        func_0010F388(D_004A4D00);
    }
    if (D_0048AB18 != -1) {
        if (func_0010D170(D_0048AB18) < 0) {
            err++;
            func_0010F388(D_004A4D30);
        } else {
            D_0048AB18 = -1;
        }
    }
    return err ? -1 : 0;
}