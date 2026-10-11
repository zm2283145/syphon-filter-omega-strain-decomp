extern void func_002F4A38(int, int, char *, char *);
int func_002F4D00(int a, int b, char *src, char *dst, unsigned int len)
{
    int done = 0;
    while (len >= 0x40) {
        func_002F4A38(a, b, src, dst);
        src += 0x40;
        dst += 0x40;
        len -= 0x40;
        done += 0x40;
    }
    return done;
}
