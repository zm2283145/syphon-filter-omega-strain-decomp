/* Returns the start of the last NUL-terminated segment within s[0..n-1]. */
char *func_0030F0E8(char *s, int n)
{
    char *r = 0;
    if (s != 0) {
        if (n != 0) n--;
        for (; n != 0; n--) {
            if (s[n - 1] == 0) break;
        }
        r = s + n;
    }
    return r;
}
