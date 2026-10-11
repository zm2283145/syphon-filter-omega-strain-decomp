extern char D_004BA7F8[];
extern int sprintf(char *s, const char *fmt, ...);
int func_0034C840(char *dst, unsigned char *ip)
{
    if (ip == 0 || dst == 0) return -0x200;
    sprintf(dst, D_004BA7F8, ip[7], ip[6], ip[5], ip[4]);
    return 0;
}