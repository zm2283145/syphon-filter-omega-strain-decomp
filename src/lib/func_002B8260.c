typedef struct { unsigned short mode; char pad[0x3E]; char name[0x20]; char rest[0x1A0]; } MC2Dirent;
extern char D_004AC1B0[];
extern char D_004AC1B8[];
extern int strcmp(const char *, const char *);
extern unsigned int strlen(const char *);
extern int func_002BB2D0(int, void *, int, int);
extern int _sceMcFatGetNextClust(int, int, int *);
int _SearchEntry(int idx, MC2Dirent *out, int *pos, char *name, int cl, int n)
{
    MC2Dirent buf[2];
    int err = 0;
    int first = 1;
    int k = 0;
    MC2Dirent *e;
    int i;
    /* do/while(0) keeps loop.c from moving the return blocks out of the loop */
    do {
    for (;;) {
        if (!func_002BB2D0(idx, buf, cl, 1)) return 0x8101006F;
        e = buf;
        if (first) {
            first = 0;
            if (strlen(e->name) >= 0x20) break;
            if (strcmp(e->name, D_004AC1B0)) return 0x81019002;
            e++;
            if (strlen(e->name) >= 0x20) return 0x81019002;
            if (strcmp(e->name, D_004AC1B8)) return 0x81019002;
            e = buf;
        }
        for (i = 0; i < 2 && n; i++, e++, k++) {
            if (e->mode & 0x8000) {
                e->name[0x1F] = 0;
                if (strcmp(name, e->name) == 0) {
                    if (out) *out = *e;
                    if (pos) *pos = k;
                    return 0;
                }
            }
            if (n > 0) n--;
        }
        cl = _sceMcFatGetNextClust(idx, cl, &err);
        if (err) return err;
        if (cl == -1) goto nf;
        cl &= 0x7FFFFFFF;
    }
    return 0x81019002;
nf:
    return 0x81010002;
    } while (0);
}






