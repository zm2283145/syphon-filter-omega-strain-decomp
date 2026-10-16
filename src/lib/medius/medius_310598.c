/*
 * lib/medius: 2 files, 00310598-00310820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00310598 */
typedef struct {
    char pad[8];
    char name[0x100];
    char buf108[0x100];
    char buf208[4];
    unsigned char found;
} SoapParse0598;

extern int String_CompareN(const char *, const char *, unsigned int);
extern char *strstr(const char *searchee, const char *lookfor);
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
    } else if (strstr(D_004B0DA0, tag)) {
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
/* merge_units: end func_00310598 */

/* merge_units: begin func_00310820 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
int strstr(int *, int);
#endif /* merge_units */
#define strstr(a0, a1) ((int)strstr((const char *)(a0), (const char *)(a1))) /* merge_units */
                        
int func_0030F050(int, int, int);                   
#if 0 /* merge_units */
extern int D_004B0DA0;
#endif /* merge_units */
#define D_004B0DA0 (*(int*)&D_004B0DA0) /* merge_units */


void func_00310820(int arg0, int arg1) {
    if (F_(arg1, 0x20C, unsigned char) == 0) {
        if (func_0030F050(arg1 + 0x108, arg1 + 0x208, arg0) == 0) {
            F_(arg1, 0x20C, unsigned char) = 1U;
        }
        if (strstr(&D_004B0DA0, arg0) != 0) {
            F_(arg1, 0x8, signed char) = 0xA;
        }
    }
}
#undef strstr /* merge_units */
#undef D_004B0DA0 /* merge_units */
/* merge_units: end func_00310820 */
