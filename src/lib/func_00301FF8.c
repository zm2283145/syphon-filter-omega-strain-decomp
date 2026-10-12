static unsigned char D_004AF5E8[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
extern unsigned int func_00301F40(void);
void func_00301FF8(char *buf, unsigned int n)
{
    unsigned int i = 0;
    if (n == 0) return;
    for (; i < n - 1; i++)
        buf[i] = D_004AF5E8[func_00301F40() & 0x3F];
    buf[n - 1] = 0;
}
