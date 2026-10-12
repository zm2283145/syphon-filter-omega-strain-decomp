extern int func_001115B0(const char *, int);
extern int func_00111BF0(int, void *, int);
extern int func_00111838(int);
extern int func_00121BC8(const char *);

int func_00102A90(void)
{
    char buf[256];
    char *p;
    unsigned int i;
    int fd = func_001115B0("rom0:ROMVER", 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        func_00111BF0(fd, p, 1);
        if (*p++ == 0) break;
    }
    func_00111838(fd);
    return func_00121BC8(buf + (i - 9)) > 0x1315670;
}