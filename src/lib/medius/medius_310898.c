extern unsigned char D_00499C70[];
#define isspace(c) ((D_00499C70 + 1)[(unsigned)(c)] & 8)
typedef struct {
    char names[12][0x100];
    char values[12][0x100];
    int count;
} Tbl0898;
typedef struct {
    char pad0[8];
    char tag[0x100];
    char buf[0x100];
    int bufLen;
    unsigned char stop;
    char pad1[3];
    Tbl0898 *tbl;
} Xml0898;
extern char D_004B0DA0[];
extern char *func_0030F0E8(char *buf, int len);
extern int strstr(const char *a, const char *b);
extern char *strncpy(char *d, const char *s, unsigned int n);
void func_00310898(const char *s, int len, Xml0898 *p)
{
    Tbl0898 *t = p->tbl;
    char *name;
    if (p->stop) return;
    if (len == 0) return;
    if (isspace(*s)) return;
    name = func_0030F0E8(p->buf, p->bufLen);
    if (strstr(D_004B0DA0, p->tag) == 0) return;
    strncpy(t->names[t->count], name, 0x100);
    strncpy(t->values[t->count], s, len);
    t->values[t->count][len] = 0;
    t->count++;
}
