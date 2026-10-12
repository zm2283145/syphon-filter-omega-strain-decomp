#pragma cplusplus on
extern "C" {
extern char D_004FFB50[];
int String_CompareNoCase(const char* a, const char* b); void func_001307F0(void* p); void String_Copy(char* d, const char* s); }
extern "C" int func_00130770(int n, char** args, char* out)
{
    if (n == 1) {
        if (!String_CompareNoCase("INTERFACE", args[0])) {
            func_001307F0(D_004FFB50);
            return 1;
        }
        String_Copy(out, "Cannot reload that system.");
        return 0;
    }
    String_Copy(out, "Name your system.");
    return 0;
}