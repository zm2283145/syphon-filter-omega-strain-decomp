extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int func_002E51B8(unsigned int, char **);
int func_002DDD50(char *dst, unsigned int idx)
{
    char *p = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (dst == 0) return 0x17;
    memset(dst, 0, 0x10);
    r = func_002E51B8(idx, &p);
    if (r) return r;
    if (p) {
        strncpy(dst, p + 0x418, 0x10);
        return 0;
    }
    return r;
}
