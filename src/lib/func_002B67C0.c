int _get_dir_nest(char *s)
{
    int n = 0;
    while (*s) {
        if (*s == '/') n++;
        s++;
    }
    return n;
}