extern char *String_Copy(char *d, const char *s);
int func_0034A968(void *cd, char *dst, char *buf, int idx)
{
    if (dst == 0) return 0;
    String_Copy(dst, buf + idx * 4);
    return 0;
}