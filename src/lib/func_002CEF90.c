void (*D_0048C3E0)(int, int, int, char *) = 0;
extern void func_002CEC38(char *);
extern void func_002CECB0(char *);
int func_002CEF90(int a, int b, int c, char *d)
{
    if (d[0x15] == 0) {
        func_002CEC38(d + 0x90);
        func_002CECB0(d + 0x1C);
    }
    if (D_0048C3E0) D_0048C3E0(a, b, c, d);
    return 0xB4;
}
