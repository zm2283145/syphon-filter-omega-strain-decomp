extern char *strncpy(char *, const char *, unsigned int);
extern unsigned int strlen(const char *);
extern char *strstr(char *, const char *);
extern int atoi(const char *);
extern char D_004ADB50[];
int func_002DD380(unsigned char *out, const char *s)
{
    char buf[16];
    char *p;
    int i;
    p = buf;
    if (s != 0 && out != 0) {
        strncpy(buf, s, 16);
        i = 0;
        if (strlen(buf) == 0)
            return 0x17;
        for (; i < 3; i++) {
            char *q = strstr(p, D_004ADB50);
            if (q == 0)
                return 0xA;
            *q = 0;
            out[i] = atoi(p);
            p = q + 1;
        }
        out[3] = atoi(p);
        return 0;
    }
    return 0xA;
}
