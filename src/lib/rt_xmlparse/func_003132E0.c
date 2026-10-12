extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F38[];
extern int func_00127358(const char *, ...);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { char pad[0x8414]; char buf[0x800]; int len; } Ctx313200;
typedef struct { int type; char *str; int len; } Node313200;
extern int func_003111E0(Ctx313200 *c, char **pstr, int size);
int func_003132E0(Ctx313200 *c, Node313200 *n)
{
    int r = func_003111E0(c, &n->str, c->len + 1);
    if (r) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x4D8, D_004B0F38);
        return r;
    }
    n->len = c->len;
    n->type = 1;
    memcpy(n->str, c->buf, c->len);
    c->buf[0] = 0;
    c->len = 0;
    return 0;
}