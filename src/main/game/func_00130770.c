#pragma cplusplus on
extern "C" { extern char D_0049A9A0[]; extern char D_004FFB50[]; extern char D_0049A9B0[]; extern char D_0049A9D0[];
int func_00128E80(const char* a, const char* b); void func_001307F0(void* p); void String_Copy(char* d, const char* s); }
extern "C" int func_00130770(int n, char** args, char* out)
{
    if (n == 1) {
        if (!func_00128E80(D_0049A9A0, args[0])) {
            func_001307F0(D_004FFB50);
            return 1;
        }
        String_Copy(out, D_0049A9B0);
        return 0;
    }
    String_Copy(out, D_0049A9D0);
    return 0;
}