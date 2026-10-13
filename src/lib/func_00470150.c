extern char* strncpy(char* d, const char* s, int n);
extern int atoi(const char* s);
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
    v = atoi(p);
    *a = (v >> 7) & 0x1FF;
    *b = v & 0x7F;
    return 0;
}

