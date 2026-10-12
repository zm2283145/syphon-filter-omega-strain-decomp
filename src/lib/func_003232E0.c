typedef int (*CopyFn3232E0)(void* dst, void* src, int n);
extern CopyFn3232E0 D_004E1D40;
extern char D_00476B00[];
extern char D_00477AE8[];
extern char D_004B6F90[];
void func_003232E0(void)
{
    D_004E1D40((void*)0x11000000, D_00476B00, D_00477AE8 - D_00476B00);
    D_004E1D40((void*)0x11004800, D_004B6F90, 0x7E0);
}