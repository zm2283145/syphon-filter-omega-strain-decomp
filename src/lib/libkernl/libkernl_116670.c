typedef struct { int a; int b; } Pair6670;
extern char *D_004865E0;
extern void kCopy_void_4();
static void * const dat_00487098[2] = { (void*)0x5A, (void*)kCopy_void_4 };
extern void setup_void_4(int, int);
extern int Copy_void_4(void *, void *, int);
extern int strlen(const char *);

char *SetArg(char *name, int argc, char **argv)
{
    char *base = D_004865E0;
    char *strp = base + 0x40;
    char *ret = strp;
    int len;
    setup_void_4((*(Pair6670*)dat_00487098).a, (*(Pair6670*)dat_00487098).b);
    if (argc >= 16) argc = 15;
    Copy_void_4(base, &strp, 4);
    base += 4;
    len = strlen(name) + 1;
    Copy_void_4(strp, name, len);
    strp += len;
    if (argc > 0) {
        char **p = argv;
        do {
            Copy_void_4(base, &strp, 4);
            base += 4;
            argc--;
            len = strlen(*p) + 1;
            Copy_void_4(strp, *p++, len);
            strp += len;
        } while (argc != 0);
    }
    return ret;
}