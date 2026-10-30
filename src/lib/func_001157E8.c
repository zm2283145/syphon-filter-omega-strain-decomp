extern char D_00498B80[];
extern char D_00498B90[];
extern int scePrintf(const char *fmt, ...);
extern int sceSifInitRpc(int);
extern void sceSifExitRpc(void);
extern int sceSifResetIop(char *arg, int mode);
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
    sceSifInitRpc(0);
    sceSifExitRpc();
    q = param;
    while (*s)
        *q++ = *s++;
    while (*img)
        *q++ = *img++;
    *q = 0;
    return sceSifResetIop(param, 0);
}
