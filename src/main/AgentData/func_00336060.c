extern char D_00532990[];
extern char D_00532991[];
extern char D_00532992[];
extern char D_00499C71[];
int strlen(const char *s);
char *func_00336060(int unused, char *s)
{
    int i = 0;
    int len = strlen(s) - 1;
    char c;
    D_00532990[0] = s[0];
    D_00532991[0] = s[1];
    D_00532992[0] = s[2];
    i += 3;
    c = s[len];
    if (D_00499C71[c] & 4) {
        D_00532990[i++] = c;
    }
    D_00532990[i] = 0;
    return D_00532990;
}

