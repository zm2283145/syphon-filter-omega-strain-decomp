extern char* strncpy(char* d, const char* s, int n);
extern int func_00121BC8(const char* s);
int func_00470150(char* s, char* out, int* a, int* b)
{
    char* p = s;
    int n = 0;
    unsigned int v;
    while (*p != '.') {
        p++;
        n++;
    }
    if (*p == '.') p++;
    strncpy(out, s, n - 1);
    v = func_00121BC8(p);
    *a = (v >> 7) & 0x1FF;
    *b = v & 0x7F;
    return 0;
}

