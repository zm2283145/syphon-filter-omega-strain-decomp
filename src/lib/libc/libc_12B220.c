extern unsigned char D_00499C70[];
char *Libc_Strupr(char *a)
{
    char *ret = a;
    while (*a != '\0') {
        if (((D_00499C70 + 1)[(unsigned)(*a)] & 2)) *a = ({ int __x = (*a); (((D_00499C70 + 1)[(unsigned)(__x)] & 2) ? (__x - 'a' + 'A') : __x); });
        ++a;
    }
    return ret;
}