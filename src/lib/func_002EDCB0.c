extern char *strncpy(char *, const char *, unsigned int);
extern unsigned short func_002F33D8(char *);
void func_002EDCB0(char *src, unsigned short *d)
{
    d[0] = *(unsigned short *)(src + 0xC);
    strncpy((char *)d + 4, src + 0x10, 0x3C);
    ((char *)d)[0x3F] = 0;
    d[1] = func_002F33D8(src + 0x50);
}