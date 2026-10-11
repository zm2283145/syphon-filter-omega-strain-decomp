typedef struct { char pad[0x30]; int bufsize; } NetCd_8D8;
extern unsigned int strlen(const char *s);
extern char *String_Copy(char *d, const char *s);
int func_0034A8D8(NetCd_8D8 *cd, char *buf, int idx, char *s)
{
    int room = cd->bufsize - idx * 4;
    int n;
    if (s == 0) return 0;
    n = strlen(s) + 1;
    if (n < 0 || room < n) return -0x21F;
    String_Copy(buf + idx * 4, s);
    return n;
}