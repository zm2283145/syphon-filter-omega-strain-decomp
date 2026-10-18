extern char D_00498B80[];
extern char D_00498B90[];
extern int scePrintf(const char *fmt, ...);
extern int func_0010FBC0(int);
extern void func_0010FD60(void);
extern int func_00115618(char *arg, int mode);
int sceSifRebootIop(const char *img)
{
    char param[80];
    const char *s = D_00498B80;
    char *q;
    const char *p = img;
    while (*p)
        p++;
    if ((unsigned int)(p + 11 - img) > 80) {
        scePrintf(D_00498B90, img);
        return 0;
    }
    func_0010FBC0(0);
    func_0010FD60();
    q = param;
    while (*s)
        *q++ = *s++;
    while (*img)
        *q++ = *img++;
    *q = 0;
    return func_00115618(param, 0);
}
