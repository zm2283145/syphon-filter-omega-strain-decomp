/* strsep-style tokenizer: returns the current token and advances *sp past the next delimiter. */
char *func_0030B468(char **sp, const char *delim)
{
    char *s = *sp;
    const char *d;

    if (s == 0) return 0;
    if (delim == 0) return s;
    while (**sp != 0) {
        for (d = delim; *d != 0; d++) {
            if (**sp == *d) {
                **sp = 0;
                (*sp)++;
                return s;
            }
        }
        (*sp)++;
    }
    *sp = 0;
    return s;
}
