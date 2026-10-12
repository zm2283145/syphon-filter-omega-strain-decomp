extern unsigned char D_00499C70[];
#define isspace(c) ((D_00499C70 + 1)[(unsigned)(c)] & 8)
typedef struct {
    char pad0[0x108];
    char buf[0x100];
    int bufLen;
    unsigned char stop;
    char pad1[3];
    char *dst;
} Xml04F8;
extern char *func_0030F0E8(char *buf, int len);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
void func_003104F8(const char *s, int len, Xml04F8 *p)
{
    char *dst = p->dst;
    if (p->stop) return;
    if (len == 0) return;
    if (isspace(*s)) return;
    if (String_CompareN(func_0030F0E8(p->buf, p->bufLen), "return", 0x100) == 0)
        strncpy(dst, s, len);
}
