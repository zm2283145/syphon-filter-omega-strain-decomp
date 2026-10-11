extern int sprintf(char* buf, const char* fmt, ...);
extern char D_004C3340[];
int func_00470120(int a, int b, int unused, char* buf)
{
    sprintf(buf, D_004C3340, a, b);
    return 0;
}
