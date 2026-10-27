extern int Libc_Strncmp(const char *, const char *, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern int func_0030EFD0(void *, void *, const char *);
extern char *D_00491394;
extern char D_004B0820[];
extern char D_004B0828[];
extern char D_004B09F0[];
extern char D_004B09F8[];
extern char D_004B0A00[];

typedef struct {
    char pad0[8];
    char name[0x100];
    char f108[0x100];
    char f208[4];
    unsigned char f20C;
} P_0030FBA0;

void func_0030FBA0(const char *el, const char **atts, P_0030FBA0 *p)
{
    int i;

    if (p->f20C)
        return;
    if (!func_0030EFD0(p->f108, p->f208, el))
        p->f20C = 1;
    if (!Libc_Strncmp(D_004B09F0, el, 0x100)) {
        for (i = 0; atts[i]; i++) {
            switch (i) {
            case 0:
                if (Libc_Strncmp(D_004B0820, atts[0], 0x100))
                    p->f20C = 1;
                break;
            case 1:
                if (Libc_Strncmp(D_00491394, atts[1], 0x100))
                    p->f20C = 1;
                break;
            }
        }
    } else if (!Libc_Strncmp(D_004B0828, el, 0x100) || !Libc_Strncmp(D_004B09F8, el, 0x100)) {
        strncpy(p->name, el, 0x100);
    } else if (!Libc_Strncmp(D_004B0A00, el, 0x100)) {
        strncpy(p->name, el, 0x100);
    }
}