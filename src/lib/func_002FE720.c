typedef struct C2FE720 { char pad[6]; unsigned short id; } C2FE720;
typedef struct {
    unsigned short id; short pad;
    int f4;
    unsigned int f8;
    char pad2[0x78 - 0xC];
    C2FE720 *sub[2];
    C2FE720 *main;
} O2FE720;
extern int func_002FE8B0(C2FE720 *);
int func_002FE720(O2FE720 *o)
{
    unsigned int i;
    C2FE720 *p;
    if (o == 0) return 0;
    if (o->f8 < 2) return 0;
    if (!func_002FE8B0(o->main)) return 0;
    for (i = 0; i < 2; i++) {
        p = o->sub[i];
        if (p) {
            if (o->id != p->id) return 0;
            if (!func_002FE8B0(p)) return 0;
        }
    }
    return 1;
}
