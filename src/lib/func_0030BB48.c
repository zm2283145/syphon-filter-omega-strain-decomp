typedef unsigned int size_t;
extern char D_004AFA98[];
extern int func_0030B510(const char *a, const char *b, size_t n);
extern char *strncpy(char *d, const char *s, size_t n);
extern char *func_00129708(char *d, const char *s, size_t n);
extern size_t strlen(const char *s);
extern int func_0030BA90(char *base, int kind, char *dst);

/* Resolves the relative URL for kind against the base URL into dst. */
int func_0030BB48(char *base, int kind, char *dst)
{
    char *src;
    int slashes;
    unsigned int i;

    if (kind == 0x1000) src = base + 0x1104;
    else if (kind == 0x800) src = base + 0xD04;
    else return 2;
    if (func_0030B510(src, D_004AFA98, 4) == 0) {
        strncpy(dst, src, 0x800);
        return 0;
    }
    if (func_0030B510(base + 4, D_004AFA98, 4) == 0) {
        strncpy(dst, base + 4, 0x800);
        func_00129708(dst, src, 0x800);
        return 0;
    }
    func_0030BA90(base, kind, dst);
    slashes = 0;
    for (i = 0; i < strlen(dst); i++) {
        if (dst[i] == '/') {
            slashes++;
            if (slashes == 3) {
                strncpy(dst + i, src, 0x800 - i);
                break;
            }
        }
    }
    return 0;
}
