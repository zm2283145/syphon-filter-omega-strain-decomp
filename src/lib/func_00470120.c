extern int sprintf(char* buf, const char* fmt, ...);
int func_00470120(int a, int b, int unused, char* buf)
{
    sprintf(buf, "%s.%d", a, b);
    return 0;
}
