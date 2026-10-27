/*
 * lib/rt_xmlparse: 3 files, 00313200-003133C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00313200 */
extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F38[];
extern int printf(const char *, ...);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { char pad[0x8414]; char buf[0x800]; int len; } Ctx313200;
typedef struct { int type; char *str; int len; } Node313200;
extern int RtXml_Alloc(Ctx313200 *c, char **pstr, int size);
int func_00313200(Ctx313200 *c, Node313200 *n)
{
    int r = RtXml_Alloc(c, &n->str, c->len + 1);
    if (r) {
        printf(D_004B0DE0, D_004B0E18, 0x4C2, D_004B0F38);
        return r;
    }
    n->len = c->len;
    n->type = 2;
    memcpy(n->str, c->buf, c->len);
    c->buf[0] = 0;
    c->len = 0;
    return 0;
}
/* merge_units: end func_00313200 */

/* merge_units: begin func_003132E0 */
int func_003132E0(Ctx313200 *c, Node313200 *n)
{
    int r = RtXml_Alloc(c, &n->str, c->len + 1);
    if (r) {
        printf(D_004B0DE0, D_004B0E18, 0x4D8, D_004B0F38);
        return r;
    }
    n->len = c->len;
    n->type = 1;
    memcpy(n->str, c->buf, c->len);
    c->buf[0] = 0;
    c->len = 0;
    return 0;
}
/* merge_units: end func_003132E0 */

/* merge_units: begin func_003133C0 */
extern char D_004B0EA8[];
extern char D_004B11B0[];
extern unsigned int strlen(const char *);
extern char *Libc_Strcpy(char *, const char *);
typedef struct { char pad[0x8414]; char buf[0x800]; int len; } Ctx3133C0;
typedef struct { int type; char *str; int len; char *attr[64]; } Node3133C0;
#if 0 /* merge_units */
extern int RtXml_Alloc(Ctx3133C0 *c, char **pstr, int size);
#endif /* merge_units */
#define RtXml_Alloc(a0, a1, a2) (RtXml_Alloc((Ctx313200 *)(a0), (a1), (a2))) /* merge_units */

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
            r = RtXml_Alloc(c, &n->attr[i], strlen(s) + 1);
            if (r) {
                printf(D_004B0DE0, D_004B0E18, 0x510, D_004B0F38);
                return r;
            }
            Libc_Strcpy(n->attr[i], s);
            break;
        }
    }
    c->buf[0] = 0;
    c->len = 0;
    return 0;
}
#undef RtXml_Alloc /* merge_units */
/* merge_units: end func_003133C0 */
