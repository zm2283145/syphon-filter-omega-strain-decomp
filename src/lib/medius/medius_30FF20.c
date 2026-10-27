/*
 * lib/medius: 2 files, 0030FF20-00310238
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0030FF20 */
extern int Libc_Strncmp(const char *, const char *, unsigned int);

typedef struct {
    char *p[26];
} Names;

extern Names D_004B0C88;

typedef struct {
    int f0;
    int type;
    char pad8[0x208];
    unsigned int *flags;
} Obj;

void func_0030FF20(Obj *o, const char *s, unsigned int n)
{
    unsigned int *p = 0;
    int i = 0;
    Names names = D_004B0C88;

    if (o->type == 8) {
        p = o->flags;
    } else if (o->type == 7) {
        p = o->flags;
    }
    while (names.p[i] != 0 && Libc_Strncmp(names.p[i], s, n) != 0) {
        i++;
    }
    switch (i) {
    case 0:
        *p |= 0x1;
        break;
    case 1:
        *p |= 0x2;
        break;
    case 2:
        *p |= 0x4;
        break;
    case 3:
        *p |= 0x8;
        break;
    case 4:
        *p |= 0x10;
        break;
    case 5:
        *p |= 0x20;
        break;
    case 6:
        *p |= 0x40;
        break;
    case 7:
        *p |= 0x80;
        break;
    case 8:
        *p |= 0x100;
        break;
    case 9:
        *p |= 0x200;
        break;
    case 10:
        *p |= 0x400;
        break;
    case 11:
        *p |= 0x800;
        break;
    case 12:
        *p |= 0x1000;
        break;
    case 13:
        *p |= 0x2000;
        break;
    case 14:
        *p |= 0x4000;
        break;
    case 15:
        *p |= 0x8000;
        break;
    case 16:
        *p |= 0x10000;
        break;
    case 17:
        *p |= 0x20000;
        break;
    case 18:
        *p |= 0x40000;
        break;
    case 19:
        *p |= 0x80000;
        break;
    case 20:
        *p |= 0x100000;
        break;
    case 21:
        *p |= 0x200000;
        break;
    case 22:
        *p |= 0x400000;
        break;
    case 23:
        *p |= 0x800000;
        break;
    case 24:
        *p |= 0x1000000;
        break;
    }
}
/* merge_units: end func_0030FF20 */

/* merge_units: begin func_00310238 */
typedef struct {
    char pad[0x108];
    char a[0x100];
    char b[4];
    unsigned char bad;
} Up310238;
extern int func_0030EFD0(char *a, char *b, char *s);
#if 0 /* merge_units */
extern int Libc_Strncmp(char *a, char *b, int n);
#endif /* merge_units */
#define Libc_Strncmp(a0, a1, a2) (Libc_Strncmp((const char *)(a0), (const char *)(a1), (unsigned int)(a2))) /* merge_units */

extern char *D_004913BC;
extern char *D_004913C0;
extern char *D_004913C8;
extern char D_004B0820[];
extern char D_004B0D58[];
extern char D_004B0D68[];
extern char D_004B0D78[];
void func_00310238(char *name, char **argv, Up310238 *x)
{
    unsigned int i;
    unsigned int j;
    char *s;
    if (x->bad != 0)
        return;
    if (func_0030EFD0(x->a, x->b, name) == 0)
        x->bad = 1;
    s = name;
    while (*s != ':')
        s++;
    if (Libc_Strncmp(D_004B0D58, s + 1, 0x100) == 0) {
        for (i = 0; argv[i] != 0; i++) {
            switch (i) {
            case 0:
                if (Libc_Strncmp(D_004B0820, argv[i], 5) != 0)
                    x->bad = 1;
                break;
            case 1:
                if (Libc_Strncmp(D_004913BC, argv[i], 0x100) != 0)
                    x->bad = 1;
                break;
            case 2:
                s = argv[i];
                while (*s != ':')
                    s++;
                if (Libc_Strncmp(D_004B0D68, s + 1, 0x100) != 0)
                    x->bad = 1;
                break;
            case 3:
                if (Libc_Strncmp(D_004913C0, argv[i], 0x100) != 0)
                    x->bad = 1;
                break;
            }
        }
    } else if (Libc_Strncmp(D_004B0D78, name, 0x100) == 0) {
        for (j = 0; argv[j] != 0; j++) {
            switch (j) {
            case 1:
                if (Libc_Strncmp(D_004B0820, argv[j], 5) != 0)
                    x->bad = 1;
                break;
            case 2:
                if (Libc_Strncmp(D_004913C8, argv[j], 0x100) != 0)
                    x->bad = 1;
                break;
            }
        }
    }
}
#undef Libc_Strncmp /* merge_units */
/* merge_units: end func_00310238 */
