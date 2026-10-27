extern unsigned char D_00499C70[];
#define isspace(c) ((D_00499C70 + 1)[(unsigned)(c)] & 8)

typedef struct {
    char pad0[8];
    char name[0x100];
    char buf[0x100];
    int bufLen;
    unsigned char stop;
} Xml_30FD80;

typedef struct {
    char *p[4];
} Tags_30FD80;

extern Tags_30FD80 D_004B0A18;
extern char D_004B0828[];
extern char D_004B09F8[];
/* same-unit callee stub: weak, in a section the link discards; restores retail delay-slot choices */
/* same-unit callee stub: weak, in a section the link discards; restores retail delay-slot choices */
char * __attribute__((weak, section(".dtors_drop"))) func_0030F0E8(char *buf, int len) { return 0; }
extern int Libc_Strncmp(const char *a, const char *b, int n);
extern void func_0030FF20(Xml_30FD80 *p, const char *s, int len);

void func_0030FD80(const char *s, int len, Xml_30FD80 *p)
{
    unsigned int i = 0;
    Tags_30FD80 tags = D_004B0A18;
    char *e;

    if (p->stop) return;
    if (len == 0) return;
    if (isspace(*s)) return;
    e = func_0030F0E8(p->buf, p->bufLen);
    while (tags.p[i] && Libc_Strncmp(tags.p[i], e, 0x100))
        i++;
    switch (i) {
    case 0:
        if (Libc_Strncmp(D_004B0828, p->name, 0x100) || *s != '1')
            p->stop = 1;
        break;
    case 1:
        if (Libc_Strncmp(D_004B0828, p->name, 0x100) || *s != '0')
            p->stop = 1;
        break;
    case 2:
        if (Libc_Strncmp(D_004B09F8, p->name, 0x100) == 0) {
            func_0030FF20(p, s, len);
            p->name[0] = 0;
        }
        break;
    }
}
