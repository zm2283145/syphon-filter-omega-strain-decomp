typedef struct { int a; int b; } Pair6670;
extern char *D_004865E0;
extern void func_00116630();
static void * const dat_00487098[2] = { (void*)0x5A, (void*)func_00116630 };
extern void func_00116660(int, int);
extern int func_00116620(void *, void *, int);
extern int strlen(const char *);

char *func_00116670(char *name, int argc, char **argv)
{
    char *base = D_004865E0;
    char *strp = base + 0x40;
    char *ret = strp;
    int len;
    func_00116660((*(Pair6670*)dat_00487098).a, (*(Pair6670*)dat_00487098).b);
    if (argc >= 16) argc = 15;
    func_00116620(base, &strp, 4);
    base += 4;
    len = strlen(name) + 1;
    func_00116620(strp, name, len);
    strp += len;
    if (argc > 0) {
        char **p = argv;
        do {
            func_00116620(base, &strp, 4);
            base += 4;
            argc--;
            len = strlen(*p) + 1;
            func_00116620(strp, *p++, len);
            strp += len;
        } while (argc != 0);
    }
    return ret;
}