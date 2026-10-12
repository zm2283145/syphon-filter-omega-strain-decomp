extern char D_004AFA98[];
extern int func_0030B510(const char *a, const char *b, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern char *func_00129708(char *d, const char *s, unsigned int n);
int func_0030BA90(char *base, int kind, char *dst)
{
    char *src;
    if (base == 0) return 2;
    if (dst == 0) return 2;
    if (kind == 0x1000) src = base + 0x1004;
    else if (kind == 0x800) src = base + 0xC04;
    else return 2;
    if (func_0030B510(src, D_004AFA98, 4) == 0) {
        strncpy(dst, src, 0x800);
    } else {
        strncpy(dst, base + 4, 0x800);
        func_00129708(dst, src, 0x800);
    }
    return 0;
}
