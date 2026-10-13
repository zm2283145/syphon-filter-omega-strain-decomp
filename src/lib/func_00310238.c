typedef struct {
    char pad[0x108];
    char a[0x100];
    char b[4];
    unsigned char bad;
} Up310238;
extern int func_0030EFD0(char *a, char *b, char *s);
extern int String_CompareN(char *a, char *b, int n);
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
    if (String_CompareN(D_004B0D58, s + 1, 0x100) == 0) {
        for (i = 0; argv[i] != 0; i++) {
            switch (i) {
            case 0:
                if (String_CompareN(D_004B0820, argv[i], 5) != 0)
                    x->bad = 1;
                break;
            case 1:
                if (String_CompareN(D_004913BC, argv[i], 0x100) != 0)
                    x->bad = 1;
                break;
            case 2:
                s = argv[i];
                while (*s != ':')
                    s++;
                if (String_CompareN(D_004B0D68, s + 1, 0x100) != 0)
                    x->bad = 1;
                break;
            case 3:
                if (String_CompareN(D_004913C0, argv[i], 0x100) != 0)
                    x->bad = 1;
                break;
            }
        }
    } else if (String_CompareN(D_004B0D78, name, 0x100) == 0) {
        for (j = 0; argv[j] != 0; j++) {
            switch (j) {
            case 1:
                if (String_CompareN(D_004B0820, argv[j], 5) != 0)
                    x->bad = 1;
                break;
            case 2:
                if (String_CompareN(D_004913C8, argv[j], 0x100) != 0)
                    x->bad = 1;
                break;
            }
        }
    }
}
