/*
 * lib/medius: 5 files, 0030EFD0-0030F298
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030EFD0 */
extern unsigned int strlen(const char *s);
extern char *strncpy(char *d, const char *s, unsigned int n);
int func_0030EFD0(char *buf, unsigned int *pos, char *s)
{
    unsigned int n = strlen(s) + 1;
    if (*pos + n >= 256) return 0;
    strncpy(buf + *pos, s, n);
    *pos += n;
    return 1;
}
/* merge_units: end func_0030EFD0 */

/* merge_units: begin func_0030F050 */
extern char *func_0030F0E8(char *buf, int len);
#if 0 /* merge_units */
extern int strlen(const char *s);
#endif /* merge_units */
#define strlen(a0) ((int)strlen((a0))) /* merge_units */

extern int String_CompareN(const char *a, const char *b, int n);
int func_0030F050(char *buf, int *len, const char *tag)
{
    char *e = func_0030F0E8(buf, *len);
    int n = strlen(tag);
    if (String_CompareN(tag, e, n) == 0) {
        *len = *len - n - 1;
        buf[*len] = 0;
        return 1;
    }
    return 0;
}
#undef strlen /* merge_units */
/* merge_units: end func_0030F050 */

/* merge_units: begin func_0030F0E8 */
/* Returns the start of the last NUL-terminated segment within s[0..n-1]. */
char *func_0030F0E8(char *s, int n)
{
    char *r = 0;
    if (s != 0) {
        if (n != 0) n--;
        for (; n != 0; n--) {
            if (s[n - 1] == 0) break;
        }
        r = s + n;
    }
    return r;
}
/* merge_units: end func_0030F0E8 */

/* merge_units: begin func_0030F150 */
#if 0 /* merge_units */
extern int String_CompareN(const char *, const char *, unsigned int);
#endif /* merge_units */
#define String_CompareN(a0, a1, a2) (String_CompareN((a0), (a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern char *strncpy(char *, const char *, unsigned int);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_0030EFD0(void *, void *, const char *);
#endif /* merge_units */
#define func_0030EFD0(a0, a1, a2) (func_0030EFD0((char *)(a0), (unsigned int *)(a1), (char *)(a2))) /* merge_units */

extern char *D_00491380;
extern char D_004B0818[];
extern char D_004B0820[];
extern char D_004B0828[];

typedef struct {
    char pad0[8];
    char name[0x100];
    char f108[0x100];
    char f208[4];
    unsigned char f20C;
} P_0030F150;

void func_0030F150(const char *el, const char **atts, P_0030F150 *p)
{
    int i;

    if (p->f20C)
        return;
    if (!func_0030EFD0(p->f108, p->f208, el))
        p->f20C = 1;
    if (!String_CompareN(D_004B0818, el, 0x100)) {
        for (i = 0; atts[i]; i++) {
            switch (i) {
            case 0:
                if (String_CompareN(D_004B0820, atts[0], 0x100))
                    p->f20C = 1;
                break;
            case 1:
                if (String_CompareN(D_00491380, atts[1], 0x100))
                    p->f20C = 1;
                break;
            }
        }
    } else if (!String_CompareN(D_004B0828, el, 0x100)) {
        strncpy(p->name, el, 0x100);
    }
}
#undef String_CompareN /* merge_units */
#undef strncpy /* merge_units */
#undef func_0030EFD0 /* merge_units */
/* merge_units: end func_0030F150 */

/* merge_units: begin func_0030F298 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
int String_CompareN(int *, int, int);
#endif /* merge_units */
#define String_CompareN(a0, a1, a2) (String_CompareN((const char *)(a0), (const char *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int func_0030F050(int, int, int);
#endif /* merge_units */
#define func_0030F050(a0, a1, a2) (func_0030F050((char *)(a0), (int *)(a1), (const char *)(a2))) /* merge_units */


void func_0030F298(int arg0, int arg1) {
    if (F_(arg1, 0x20C, unsigned char) == 0) {
        if (func_0030F050(arg1 + 0x108, arg1 + 0x208, arg0) == 0) {
            F_(arg1, 0x20C, unsigned char) = 1U;
        }
        if (String_CompareN(((int*)"service"), arg0, 0x100) == 0) {
            F_(arg1, 0x8, signed char) = 0;
        }
    }
}
#undef String_CompareN /* merge_units */
#undef func_0030F050 /* merge_units */
/* merge_units: end func_0030F298 */
