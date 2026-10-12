extern int D_0049147C;
extern int* D_00491478;
extern char D_004B7F20[];
extern int func_00127358(const char* fmt, ...);
int lgAudEnumHint(int *hint)
{
    if (D_0049147C == -1)
        return 0x8000000A;
    if (hint == 0) {
        func_00127358(D_004B7F20);
        return 0x80000004;
    }
    *hint = *D_00491478;
    *D_00491478 = 0;
    return 0;
}