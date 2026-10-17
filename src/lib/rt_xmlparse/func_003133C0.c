extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EA8[];
extern char D_004B0F38[];
extern char D_004B11B0[];
extern int printf(const char *, ...);
extern unsigned int strlen(const char *);
extern char *String_Copy(char *, const char *);
typedef struct { char pad[0x8414]; char buf[0x800]; int len; } Ctx3133C0;
typedef struct { int type; char *str; int len; char *attr[64]; } Node3133C0;
extern int func_003111E0(Ctx3133C0 *c, char **pstr, int size);
static inline int IsWs(char ch) { return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'; }
int func_003133C0(Ctx3133C0 *c, Node3133C0 *n)
{
    char *s = c->buf;
    char *p;
    unsigned int i;
    int r;
    if (n == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x4EE, D_004B11B0);
        return 3;
    }
    if (c == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x4EF, D_004B0EA8);
        return 3;
    }
    c->buf[c->len] = 0;
    while (*s != 0) {
        char ch = *s;
        if (ch == ' ') s++;
        else if (ch == '\t') s++;
        else if (ch == '\r') s++;
        else if (ch == '\n') s++;
        else goto done1;
    }
done1:
    for (p = &c->buf[c->len - 1]; s < p; p--) {
        if (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
            *p = 0;
        else
            goto done2;
    }
done2:
    for (i = 0; i < 64; i++) {
        if (n->attr[i] == 0) {
            r = func_003111E0(c, &n->attr[i], strlen(s) + 1);
            if (r) {
                printf(D_004B0DE0, D_004B0E18, 0x510, D_004B0F38);
                return r;
            }
            String_Copy(n->attr[i], s);
            break;
        }
    }
    c->buf[0] = 0;
    c->len = 0;
    return 0;
}
