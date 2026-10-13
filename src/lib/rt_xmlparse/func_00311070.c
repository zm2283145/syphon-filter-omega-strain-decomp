extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
extern void printf(const char* a, const char* b, int line, const char* c);
int func_00311070(char* ctx, int v)
{
    if (ctx == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x157, D_004B0F28);
        return 3;
    }
    *(int*)(ctx + 0x8C20) = v;
    return 0;
}
