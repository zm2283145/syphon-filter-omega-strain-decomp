extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
extern void func_00127358(const char* a, const char* b, int line, const char* c);
int func_00311018(char* ctx, int v)
{
    if (ctx == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x148, D_004B0F28);
        return 3;
    }
    *(int*)(ctx + 0x8C18) = v;
    return 0;
}
