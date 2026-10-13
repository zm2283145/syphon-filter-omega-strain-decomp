typedef struct {
    char pad[8];
    char name[0x100];
    char buf108[0x100];
    char buf208[4];
    unsigned char found;
} SoapParse0598;

extern int String_CompareN(const char *, const char *, unsigned int);
extern char *func_00129C80(const char *searchee, const char *lookfor);
extern int func_0030EFD0(char *a, char *b, char *tag);
extern char *strncpy(char *, const char *, unsigned int);
extern unsigned int strlen(const char *);
extern char *D_004913BC;
extern char *D_004913C0;
extern char *D_004913C4;
extern char D_004B0D58[];
extern char D_004B0D68[];
extern char D_004B0DA0[];
extern char D_004B0820[];

void func_00310598(char *tag, char **attrs, SoapParse0598 *c)
{
    char *p;
    unsigned int i, j;

    if (c->found) return;
    if (func_0030EFD0(c->buf108, c->buf208, tag) == 0) c->found = 1;
    p = tag;
    while (*p != ':') p++;
    if (String_CompareN(D_004B0D58, p + 1, 0x100) == 0) {
        for (i = 0; attrs[i] != 0; i++) {
            switch (i) {
            case 0:
                if (String_CompareN(D_004B0820, attrs[i], 5)) c->found = 1;
                break;
            case 1:
                if (String_CompareN(D_004913BC, attrs[1], 0x100)) c->found = 1;
                break;
            case 2:
                p = attrs[2];
                while (*p != ':') p++;
                p++;
                if (String_CompareN(D_004B0D68, p, 0x100)) c->found = 1;
                break;
            case 3:
                if (String_CompareN(D_004913C0, attrs[3], 0x100)) c->found = 1;
                break;
            }
        }
    } else if (func_00129C80(D_004B0DA0, tag)) {
        strncpy(c->name, tag, 0x100);
        for (j = 0; attrs[j] != 0; j++) {
            switch (j) {
            case 1:
                if (String_CompareN(D_004B0820, attrs[1], 5)) c->found = 1;
                break;
            case 2:
                if (String_CompareN(D_004913C4, attrs[2], strlen(D_004913C4))) c->found = 1;
                break;
            }
        }
    }
}



