extern int sceOpen(const char *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(const char *);

int func_00102A90(void)
{
    char buf[256];
    char *p;
    unsigned int i;
    int fd = sceOpen("rom0:ROMVER", 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        sceRead(fd, p, 1);
        if (*p++ == 0) break;
    }
    sceClose(fd);
    return atoi(buf + (i - 9)) > 0x1315670;
}