extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern char *func_00129C80(char *, const char *);
extern int atoi(const char *);
extern char D_004AD3C8[];
extern char D_004AD3D0[];
int func_002D0658(unsigned char *out, const char *s)
{
    char buf[16];
    char *p;
    int i = 0;
    buf[0] = D_004AD3C8[0];
    memset(buf + 1, 0, 15);
    p = buf;
    if (s != 0 && out != 0) {
        strncpy(buf, s, 16);
        for (; i < 3; i++) {
            char *q = func_00129C80(p, D_004AD3D0);
            *q = 0;
            out[i] = atoi(p);
            p = q + 1;
        }
        out[3] = atoi(p);
        return 0;
    }
    return -6;
}
