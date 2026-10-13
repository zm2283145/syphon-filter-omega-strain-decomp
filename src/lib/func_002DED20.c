struct Grp { char pad[6]; unsigned short start; unsigned short count; };
extern signed char D_0058C178[];
extern void func_002DB188(struct Grp **, unsigned int, unsigned int);
extern int func_002DD968(int *, unsigned int);
extern int strcmp(const char *, const char *);
int func_002DED20(const char *name, unsigned int a, unsigned int b)
{
    struct Grp *g;
    int e;
    int i;
    int ret = -1;
    if (name == 0) return ret;
    if (a >= 4) return ret;
    if (b >= 0x100) return ret;
    func_002DB188(&g, a, b);
    if (g != 0) {
        for (i = 0; i < g->count; ) {
            unsigned int id = i + g->start;
            i++;
            if (D_0058C178[id] == 2) {
                char *s;
                func_002DD968(&e, id);
                s = (char *)e + 0xC;
                if (s && strcmp(s, name) == 0) return id;
            }
        }
    }
    return -1;
}
