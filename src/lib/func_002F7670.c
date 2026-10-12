extern unsigned char D_004908A0;
extern char D_004908C0[];
extern void String_Copy(char *d, const char *s);
int func_002F7670(char *out)
{
    if (D_004908A0 != 1) return 5;
    if (out == 0) return 2;
    String_Copy(out, D_004908C0);
    return 0;
}
