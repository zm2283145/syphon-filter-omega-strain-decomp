typedef struct { char pad[0x14]; unsigned short flags; } W356850;
typedef struct { char pad[0x50]; W356850 *w50; W356850 *w54; W356850 *w58; W356850 *w5C; char pad2[4]; int x64; int x68; } S356850;
typedef struct { char pad[0x25C]; int f25C; } Cfg356850;
extern Cfg356850 *D_004FFC04;
char D_004BB2E8[] = "0_%d_%d.tdx";
char D_004BB2F8[] = "AB_SPECIAL_%d";
extern char D_004BB308[];
extern char D_004BB310[];
extern int sprintf(char *buf, const char *fmt, ...);
extern void func_0043C890(W356850 *w, char *s, int v);
extern char *Loc_LookupText(char *key);
extern void func_0041BEB0(W356850 *w, char *s, int v);
extern void func_00441060(W356850 *w, int n);
void func_00356850(S356850 *self, int a, int n)
{
    char buf[0x40];
    char buf2[0x40];
    if (n >= 10000) {
        if (self->w5C) self->w5C->flags &= ~2;
        if (self->w54) {
            self->w54->flags |= 2;
            sprintf(buf, D_004BB2E8, 7, n - 9999);
            func_0043C890(self->w54, buf, D_004FFC04->f25C);
            if (self->w58) {
                char *t;
                self->w58->flags |= 2;
                sprintf(buf, D_004BB2F8, n - 10000);
                t = Loc_LookupText(buf);
                func_0041BEB0(self->w58, t ? t : D_004BB308, 0);
            }
        }
    } else {
        if (self->w5C) {
            self->w5C->flags |= 2;
            func_00441060(self->w5C, n);
        }
        if (self->w54) self->w54->flags &= ~2;
        if (self->w58) self->w58->flags &= ~2;
    }
    if (self->w50) {
        sprintf(buf2, D_004BB310, self->x64, a + self->x68);
        func_0043C890(self->w50, buf2, D_004FFC04->f25C);
    }
}