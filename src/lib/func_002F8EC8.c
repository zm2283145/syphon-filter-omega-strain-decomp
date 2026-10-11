extern int func_002F7D28(unsigned char *);
extern int func_002F8DC8(int, int, unsigned char *);
int func_002F8EC8(int a, int b, unsigned char *n)
{
    unsigned char buf[0x40];
    int i;
    if (func_002F7D28(n)) return -1;
    if (func_002F8DC8(a, b, buf)) return 1;
    i = 0x3F;
    do {
        if (n[i] > buf[i]) return 1;
        if (n[i] < buf[i]) return -1;
    } while (i-- > 0);
    return 0;
}
